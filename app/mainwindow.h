#pragma once

#include <QMainWindow>
#include <QTreeView>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QStandardPaths>
#include <QInputDialog>

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

private Q_SLOTS:

    void s_openGadfly();

    void s_openProj();

    void s_newProj();

    void s_compileButton();
};
