#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVariant var;
    var.setValue(12);
    int data= var.toInt();
    qDebug() << "var is " << data << endl;
}

Widget::~Widget()
{
    delete ui;
}

