#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QStatusBar>

#include "sandboxitemmodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initUI();

private:
    QTreeView* treeView;
    SandBoxItemModel* sandBoxModel;
    QStatusBar* statusBar;

private slots:
    void onSelected(QModelIndex index);
};

#endif // MAINWINDOW_H
