#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->treeView->setHeaderHidden(true);

    QObject::connect(ui->compileButton, &QPushButton::released, this, &MainWindow::s_compileButton);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    openGadflyAct = new QAction(tr("&Open Gadfly"), this);
    QObject::connect(openGadflyAct, &QAction::triggered, this, &MainWindow::s_openGadfly);

    openProjAct = new QAction(tr("Open Project"), this);
    QObject::connect(openProjAct, &QAction::triggered, this, &MainWindow::s_openProj);

    newProjAct = new QAction(tr("New Project"), this);
    QObject::connect(newProjAct, &QAction::triggered, this, &MainWindow::s_newProj);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(openGadflyAct);
    fileMenu->addAction(openProjAct);
    fileMenu->addAction(newProjAct);
}

void MainWindow::s_openGadfly()
{

}

void MainWindow::s_openProj()
{
    auto projFIleName = QFileDialog::getOpenFileName(this, tr("Open Project"),
                                            QStandardPaths::standardLocations(QStandardPaths::StandardLocation::DesktopLocation)[0],
                                            tr("Project Files (*.json)"));
    if (projFIleName == "")
        return;
    m_projManager.loadProject(projFIleName);
    auto treeModel = m_projManager.getProjModel(this);
    ui->treeView->setModel(treeModel);
}

void MainWindow::s_newProj()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QStandardPaths::standardLocations(QStandardPaths::StandardLocation::DesktopLocation)[0],
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dir.isEmpty())
        return;
    bool ok;
    QString projName = QInputDialog::getText(this, tr("Enter project name"),
                                         tr("Project name"), QLineEdit::Normal,
                                         "MyProject", &ok);
    if (!ok || projName.isEmpty())
        return;
    m_projManager.createProject(dir, projName);
    ui->treeView->setModel(  m_projManager.getProjModel(this));
}

void MainWindow::s_compileButton()
{
    m_projManager.recompileProject();
    auto treeModel = m_projManager.getProjModel(this);
    ui->treeView->setModel(treeModel);
}

void MainWindow::loadProject(QString const& projPath)
{

}