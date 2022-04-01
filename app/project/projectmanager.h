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

    bool loadProject(QString const& projFilePath);

    bool createProject(QString const& projFilePath);

    void recompileProject();

    QStandardItemModel* getProjModel(QMainWindow *mainWindow) const;

private:

    ProjectCompiler* m_compiler = nullptr;

    QString m_projFilePath;

    QFile m_projFile;

    QJsonDocument m_projDoc;
};
