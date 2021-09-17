#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->setValBtn, &QPushButton::clicked, [=] {
        ui->myWidget->setValue(50);
    });

    connect(ui->getValBtn, &QPushButton::clicked, [=] {
        int value = ui->myWidget->getValue();

        /**
         * QMessageBox
         * Usage
         *      https://blog.csdn.net/qq_42250189/article/details/105178379
         */
        QMessageBox box;
        box.setText(QString("当前值为：%1").arg(value));
        box.exec();
    });
}

Widget::~Widget()
{
    delete ui;
}
