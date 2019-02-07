#include "mainwindow.h"

#include <QHeaderView>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 480);
    initUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);
    sandBoxModel = new SandBoxItemModel();

    QFile file(":/sandbox.txt");              //sandbox locations are read from the text file
    file.open(QIODevice::ReadOnly);
    sandBoxModel->setSandBoxDetails(file.readAll());

    treeView = new QTreeView();
    treeView->setModel(sandBoxModel);
    treeView->header()->hide();
    connect(treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(onSelected(QModelIndex)));

    this->setCentralWidget(treeView);
}

/*
 This slot will get the accessible dewcription from the current selected item and show it in the status bar.
*/
void MainWindow::onSelected(QModelIndex index)
{
    QStandardItem *item = sandBoxModel->itemFromIndex(index);
    QString data = item->accessibleDescription();
    statusBar->showMessage(data);
}
