#include "projectCompiler.h"


void ProjectCompiler::redefCheck(std::vector<std::pair<QString, int>> names) {
    if (names.size() < 2) {
        return;
    }
    for (int i = 0; i < names.size() - 1; ++i) {
        for (int j = i + 1; j < names.size(); ++j) {
            if (names[i] == names[j]) {
                logger_.log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_REDEF, "class " + names[i].first);
            }
        }
    }  
}

void ProjectCompiler::nodefCheck(std::vector<std::pair<QString, int>> names, std::vector<QString> uNames) {
    for (int i = 0; i < uNames.size(); ++i) {
        int j;
        for (j = 0; j < names.size(); ++j) {
            if (uNames[i] == names[j].first) {
                break;
            }
        }
        if (j == names.size()) {
            logger_.log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_NODEF, "class " + uNames[i]);
        }
    }
}

QJsonArray ProjectCompiler::getObjArr(std::vector<std::pair<QString, int>> info, std::vector<QString> packages) const {
    QJsonArray arr;
    for(int i = 0; i < info.size(); ++i) {
        QJsonObject obj;
        obj.insert("name",  info[i].first);
        obj.insert("package",  packages[info[i].second]);
        arr.push_back(obj);
    }
    return arr;
}

void ProjectCompiler::createMainJson() {
    QDir dir(projectPath_ + c_jsonPath);

    QFileInfoList fileInfos = dir.entryInfoList(QDir::Files);

    std::vector<std::pair<QString, int>> classNames;
    std::vector<std::pair<QString, int>> enumNames;
    std::vector<std::pair<QString, int>> activityNames;
    std::vector<QString> usedClassNames;
    std::vector<QString> usedActivityNames;

    std::vector<QString> packageNames;
    int index = 0;

    if (fileInfos.size() == 0) {
        logger_.log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_NO_MATCH_FILES, projectPath_ + c_jsonPath);
        return;
    }

    for (int i = 0; i < fileInfos.size(); ++i) {
        QFile file;
        file.setFileName(fileInfos[i].absoluteFilePath());

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            logger_.log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_CANT_OPEN, file.fileName());
        }

        QString file_text = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(file_text.toUtf8());

        QJsonObject packageObj = doc.object();

        packageNames.push_back(packageObj["name"].toString());

        QJsonArray classArray = packageObj["Class"].toArray();
        for (int j = 0; j < classArray.size(); ++j) {
            classNames.push_back({ classArray[j].toObject()["name"].toString(), index });
        }
        QJsonArray activityArray = packageObj["Activity"].toArray();
        for (int j = 0; j < activityArray.size(); ++j) {
            activityNames.push_back({ activityArray[j].toObject()["name"].toString(), index });
        }
        QJsonArray enumArray = packageObj["Enumeration"].toArray();
        for (int j = 0; j < enumArray.size(); ++j) {
            enumNames.push_back({ enumArray[j].toObject()["name"].toString(), index });
        }
        QJsonArray uClassArray = packageObj["Used Сlasses"].toArray();
        for (int j = 0; j < uClassArray.size(); ++j) {
            usedClassNames.push_back(uClassArray[j].toString());
        }
        QJsonArray uActivityArray = packageObj["Used Activities"].toArray();
        for (int j = 0; j < uActivityArray.size(); ++j) {
            usedActivityNames.push_back(uActivityArray[j].toString());
        }
        index++;
    }

    redefCheck(classNames);
    nodefCheck(classNames, usedClassNames);
    redefCheck(activityNames);
    nodefCheck(activityNames, usedActivityNames);

    if (!logger_.status()) {
        return;
    }

    QJsonObject mainJson;

    if(!packageNames.empty()) {
        QJsonArray pArr;
        for(int i = 0; i < packageNames.size(); ++i) {
            QJsonObject obj;
            obj.insert("name",  packageNames[i]);
            pArr.push_back(obj);
        }
        mainJson.insert("Packages", pArr);
    }

    if (!classNames.empty()) { 
        mainJson.insert("Classes", getObjArr(classNames, packageNames));
    }

    if (!activityNames.empty()) {
        mainJson.insert("Activities", getObjArr(activityNames, packageNames));
    }

    if (!enumNames.empty()) {
        mainJson.insert("Enumerations", getObjArr(enumNames, packageNames));
    }
    
    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainJson);
    auto json = jsonDoc.toJson();

    dir = QDir(projectPath_);
    QFile file(projectPath_ + "/" + dir.dirName() + c_format);
    if (!file.open(QIODevice::WriteOnly)) {
        logger_.log(CompErrorLevel::CEL_ERROR, CompErrorType::CE_CANT_OPEN, file.fileName());
        return;
    }
    file.write(json);
    file.close();
}

void ProjectCompiler::createPackageFiles() {
    QDir dir(projectPath_ + c_srcPath);
    QStringList nameFilters;
    nameFilters << c_filter;

    QFileInfoList fileInfos = dir.entryInfoList(nameFilters, QDir::Files);

    ontologyBaseVisitor visitor(&logger_);
    
    if (fileInfos.size() == 0) {
        logger_.log(CompErrorLevel::CEL_WARNING, CompErrorType::CE_NO_MATCH_FILES, projectPath_ + c_srcPath);
        return;
    }

    for (int i = 0; i < fileInfos.size(); ++i) {
        std::ifstream stream;
        std::string str = fileInfos.at(i).filePath().toStdString();
        stream.open(str);
        antlr4::ANTLRInputStream input(stream);

        ontologyLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        ontologyParser parser(&tokens);
        ontologyParser::FileContext* tree = parser.file();

        QJsonDocument jsonDoc;
        jsonDoc.setObject(visitor.getJson(tree));

        if (!logger_.status()) {
            break;
        }

        auto json = jsonDoc.toJson();

        QFile file(projectPath_ + c_jsonPath + fileInfos.at(i).fileName().split(QLatin1Char('.'))[0] + c_format);
        file.open(QIODevice::WriteOnly);
        file.write(json);
        file.close();
    }
}

void ProjectCompiler::setProjPath(const QString& projectPath) {
    projectPath_ = projectPath;
    logger_.setLogFilePath(projectPath + c_logPath);
}

void ProjectCompiler::compile() {
    logger_.log(CompErrorLevel::CEL_INFO, CompErrorType::CE_OK, "Compiling at " + projectPath_);
    createPackageFiles();

    if (logger_.status()) {
        createMainJson();
    }
    if (logger_.status()) {
        logger_.log(CompErrorLevel::CEL_INFO, CompErrorType::CE_OK, "Success");
    }
    logger_.resetStatus();
}