#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QObject::connect(ui->compileButton, &QPushButton::released, this, &MainWindow::compileButton);

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
    QObject::connect(openGadflyAct, &QAction::triggered, this, &MainWindow::openGadfly);

    openProjAct = new QAction(tr("Open Project"), this);
    QObject::connect(openProjAct, &QAction::triggered, this, &MainWindow::openProj);

    newProjAct = new QAction(tr("New Project"), this);
    QObject::connect(newProjAct, &QAction::triggered, this, &MainWindow::newProj);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(openGadflyAct);
    fileMenu->addAction(openProjAct);
    fileMenu->addAction(newProjAct);
}

void MainWindow::openGadfly()
{

}

void MainWindow::openProj()
{
    lastPath = QFileDialog::getOpenFileName(this, tr("Open Project"), QStandardPaths::standardLocations(QStandardPaths::StandardLocation::DesktopLocation)[0], tr("Project Files (*.json)"));
    m_projManager.loadProject(lastPath);
    auto treeModel = m_projManager.getProjModel(this);
    ui->treeView->setModel(treeModel);
}

void MainWindow::newProj()
{

}

void MainWindow::compileButton()
{
    m_projManager.recompileProject();
    m_projManager.loadProject(lastPath);
    auto treeModel = m_projManager.getProjModel(this);
    ui->treeView->setModel(treeModel);
}

void MainWindow::loadProject(QString const& projPath)
{
    
}