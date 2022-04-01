#include "projectmanager.h"




ProjectManager::ProjectManager(){}

void ProjectManager::loadProject(QString const& projFilePath)
{
    m_projFile.setFileName(projFilePath);
    if (!m_projFile.exists())
        return;

    delete m_compiler; // some shit
    m_compiler = new ProjectCompiler(QFileInfo(projFilePath).path());
}

QStandardItemModel* ProjectManager::getProjModel(QMainWindow *mainWindow)
{
    auto treeModel = new QStandardItemModel(mainWindow);
    auto projDoc = loadFile();

    if (!projDoc.isObject())
        return treeModel;
    
    QJsonObject mainObj = projDoc.object();

    QStandardItem* rootNode = treeModel->invisibleRootItem();

    for (auto key : mainObj.keys()){
        if (!mainObj[key].isArray())
            continue;
        QJsonArray values = mainObj[key].toArray();
        QStandardItem* nextItem = new QStandardItem(key);
        for (auto value : values){
            QString name;
            
            if (value.isString())
                name = value.toString();
            else if (value.isObject() && value.toObject().contains("name"))
                name = value.toObject()["name"].toString();
            else
                continue;
            
            nextItem->appendRow(new QStandardItem(name));
        }
        rootNode->appendRow(nextItem);
    }

    return treeModel;
}

void ProjectManager::recompileProject() {
    m_compiler->compile();
}

QJsonDocument ProjectManager::loadFile()
{
    m_projFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString file_text = m_projFile.readAll();
    m_projFile.close();

    auto projDoc = QJsonDocument::fromJson(file_text.toUtf8());
    return projDoc;
}

void ProjectManager::createProject(QString const &projPath, const QString &projName)
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