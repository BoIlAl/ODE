#include "projectmanager.h"
#include <iostream>

ProjectManager::ProjectManager(){}

void ProjectManager::loadProject(QString const& projFilePath)
{
    m_projFile.setFileName(projFilePath);
    if (!m_projFile.exists())
        return;

    m_compiler.setProjPath(QFileInfo(projFilePath).path());
}

QStandardItemModel* ProjectManager::getProjModel(QMainWindow* mainWindow)
{
    auto treeModel = new QStandardItemModel(mainWindow);
    auto projDoc = loadFile();

    if (!projDoc.isObject())
        return treeModel;

    QJsonObject mainObj = projDoc.object();

    QStandardItem* rootNode = treeModel->invisibleRootItem();

    auto packages = mainObj["Packages"];
    auto getPath = [&](QString const& name){
        for (auto pObj : packages.toArray())
            if (pObj.toObject()["name"].toString() == name)
                return pObj.toObject()["filename"].toString();
        return tr("");
    };

    for (auto key : mainObj.keys()){
        if (!mainObj[key].isArray())
            continue;
        QJsonArray values = mainObj[key].toArray();
        QStandardItem* nextItem = new QStandardItem(key);

        for (auto value : values){
            QString name;
            if (value.isObject() && value.toObject().contains("name"))
                name = value.toObject()["name"].toString();
            else
                continue;

            auto subItem = new QStandardItem(name);
            nextItem->appendRow(subItem);
            if (value.toObject().contains("package")) {
                auto s = getPath(value.toObject()["package"].toString());
                subItem->setData(QVariant(s));
            }
        }
        rootNode->appendRow(nextItem);
    }

    return treeModel;
}

void ProjectManager::recompileProject() {
    m_compiler.compile();
}

QJsonDocument ProjectManager::loadFile()
{
    m_projFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString file_text = m_projFile.readAll();
    m_projFile.close();

    auto projDoc = QJsonDocument::fromJson(file_text.toUtf8());
    return projDoc;
}

void ProjectManager::createProject(QString const &projPath,  QString const &projName)
{
    QDir rootDir(projPath);
    rootDir.mkdir(projName);
    rootDir.mkpath(projName + "/.gldata");
    rootDir.mkpath(projName + "/src");
    rootDir.mkpath(projName + "/log");

    QString projFileName = projPath + "/" + projName + "/" + projName + ".json";
    m_projFile.setFileName(projFileName);
    m_projFile.open(QIODevice::WriteOnly);
    m_projFile.close();

    loadProject(projFileName);
}

QJsonObject ProjectManager::getGInfo(QAbstractItemModel *model, QModelIndex const& index)
{
    QStandardItem* item = qobject_cast<QStandardItemModel*>(model)->itemFromIndex(index);

    QString filePath = QFileInfo(m_projFile).absolutePath() + "/.gldata/" + item->data().toString();
    auto s = filePath.toStdString();
    std::cout << s << std::endl;
    QFile file(filePath);

    QJsonObject obj;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //////////////////////
        return obj;
    }

    QString file_text = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(file_text.toUtf8());
    QJsonObject packageObj = doc.object();

    for(auto key: packageObj.keys()) {
        if (key == "name") {
            continue;
        }
        if (key == "Association") {
            continue;
        }
        QJsonArray jsonArr = packageObj[key].toArray();
        for (int j = 0; j < jsonArr.size(); ++j) {
            if (jsonArr[j].toObject()["name"].toString() == item->text()) {
                obj = jsonArr[j].toObject();
                obj.insert("type", key);
                std::cout << key.toStdString() << endl;
                return obj;
            }
        }
    }


    /////////////

    return obj;
}
