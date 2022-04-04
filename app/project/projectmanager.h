#pragma once

#include <QMainWindow>
#include <QFileInfo>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QStandardItemModel>

#include "projectCompiler.h"

class ProjectManager
{
public:

    ProjectManager();

    void loadProject(QString const& projFilePath);

    void createProject(QString const &projPath, const QString &projName);

    void recompileProject();

    QStandardItemModel* getProjModel(QMainWindow *mainWindow);

private:

    QJsonDocument loadFile();

    ProjectCompiler m_compiler;

    QFile m_projFile;
};
