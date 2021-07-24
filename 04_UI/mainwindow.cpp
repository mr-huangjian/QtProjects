#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon icon = QIcon("/Users/mr.huangjian/Pictures/new.png");
    ui->actionNew->setIcon(icon);

    ui->actionOpen->setIcon(QIcon(":/image/open.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

