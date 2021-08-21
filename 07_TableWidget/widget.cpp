#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "年龄");
    ui->tableWidget->setRowCount(3);

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("黄健"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(18)));

    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("小妮儿"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(3)));
}

Widget::~Widget()
{
    delete ui;
}

