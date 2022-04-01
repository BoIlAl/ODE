#include "projectmanager.h"

ProjectManager::ProjectManager(){}

bool ProjectManager::loadProject(QString const& projFilePath)
{
    m_projFile.setFileName(projFilePath);
    if (!m_projFile.exists())
        return false;

    m_projFilePath = projFilePath;
    m_compiler = new ProjectCompiler(QFileInfo(m_projFilePath).path());

    m_projFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString file_text = m_projFile.readAll();
    m_projFile.close();

    m_projDoc = QJsonDocument::fromJson(file_text.toUtf8());
    if (!m_projDoc.isObject())
        return false;
    return true;
}

QStandardItemModel* ProjectManager::getProjModel(QMainWindow *mainWindow) const
{
    auto treeModel = new QStandardItemModel(mainWindow);
    if (!m_projDoc.isObject())
        return treeModel;
    
    QJsonObject mainObj = m_projDoc.object();

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