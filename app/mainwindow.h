#pragma once

#include <QMainWindow>
#include <QTreeView>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QStandardPaths>

#include "ui_mainwindow.h"
#include "project/projectmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void createActions();

    void createMenus();

    void loadProject(QString const& projPath);

    Ui::MainWindow *ui;

    /* menu section */
    QMenu* fileMenu;
    QAction* openGadflyAct;
    QAction* openProjAct;
    QAction* newProjAct;

    /* project maneger */
    ProjectManager m_projManager;

    QString lastPath;

private Q_SLOTS:

    void openGadfly();

    void openProj();

    void newProj();

    void compileButton();
};
