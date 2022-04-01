#include "projectCompiler.h"

void ProjectCompiler::createMainJson(ontologyBaseVisitor& visitor) {
    QJsonObject mainJson;

    std::vector<std::string> framesArr = visitor.getFrames();
    QJsonArray frames;

    for(int i = 0; i < framesArr.size(); ++i) {
        frames.push_back(framesArr[i].c_str());
    }
    mainJson.insert("Frame", frames);

    
    std::vector<std::pair<std::string, std::string>> classesPairs = visitor.getClasses();
    if (!classesPairs.empty()) {
        QJsonArray classes;
        for(int i = 0; i < classesPairs.size(); ++i) {
            QJsonObject pair;
            pair.insert("name", classesPairs[i].second.c_str());
            pair.insert("frame", classesPairs[i].first.c_str());
            classes.push_back(pair);
        }
        mainJson.insert("Class", classes);
    }   

    std::vector<std::pair<std::string, std::string>> activitiesPairs = visitor.getActivities();
    if (!activitiesPairs.empty()) {
        QJsonArray activities;
        
        for(int i = 0; i < activitiesPairs.size(); ++i) {
            QJsonObject pair;
            pair.insert("name", activitiesPairs[i].second.c_str());
            pair.insert("frame", activitiesPairs[i].first.c_str());
            activities.push_back(pair);
        }
        mainJson.insert("Activity", activities);
    }

    std::vector<std::pair<std::string, std::string>> enumsPairs = visitor.getEnums();
    if (!enumsPairs.empty()) {
         QJsonArray enums;
        for(int i = 0; i < enumsPairs.size(); ++i) {
            QJsonObject pair;
            pair.insert("name", enumsPairs[i].second.c_str());
            pair.insert("frame", enumsPairs[i].first.c_str());
            enums.push_back(pair);
        }
        mainJson.insert("Enums", enums);
    }

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainJson);
    auto json = jsonDoc.toJson();

    QFile file(projectPath_ + "/project_I.json");
    file.open(QIODevice::WriteOnly);
    file.write(json);
    file.close();
}


ProjectCompiler::ProjectCompiler(const QString& projectPath) {
    projectPath_ = projectPath;
}

void ProjectCompiler::compile() {
    QDir dir(projectPath_ + c_srcPath);
    QStringList nameFilters;
    nameFilters << c_filter;

    QFileInfoList fileInfos = dir.entryInfoList(nameFilters, QDir::Files);

    CompilerLogger logger =  CompilerLogger(projectPath_ + c_logPath);
    ontologyBaseVisitor visitor(logger);

    for (int i = 0; i < fileInfos.size(); ++i) {
        std::ifstream stream;
        std::string str = fileInfos.at(i).filePath().toStdString();
        std::cout << str;
        stream.open(str);
        antlr4::ANTLRInputStream input(stream);

        ontologyLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        ontologyParser parser(&tokens);
        ontologyParser::FileContext* tree = parser.file();

        QJsonDocument jsonDoc;
        jsonDoc.setObject(visitor.getJson(tree));
        auto json = jsonDoc.toJson();

        QFile file(projectPath_ + c_jsonPath + fileInfos.at(i).fileName().split(QLatin1Char('.'))[0] + ".json");
        file.open(QIODevice::WriteOnly);
        file.write(json);
        file.close();
    }
    createMainJson(visitor);
}