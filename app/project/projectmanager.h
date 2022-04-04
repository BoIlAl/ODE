#pragma once

#include <QMainWindow>
#include <QFileInfo>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QStandardItemModel>

#include "projectCompiler.h"

class ProjectManager : public QObject
{
    Q_OBJECT
public:

    ProjectManager();

    void loadProject(QString const& projFilePath);

    void createProject(QString const &projPath, QString const &projName);

    void recompileProject();

    QJsonObject getGInfo(QAbstractItemModel *model, QModelIndex const& index);

    QStandardItemModel* getProjModel(QMainWindow *mainWindow);

private:

    QJsonDocument loadFile();

    ProjectCompiler m_compiler;

    QFile m_projFile;

};
