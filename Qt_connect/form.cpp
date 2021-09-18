#include "form.h"
#include "ui_form.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setWindowTitle("");


}

Form::~Form()
{
    delete ui;
}

void Form::on_nameEdit_textChanged(const QString &arg1)
{
    QString text = ui->nameEdit->text();
    qDebug() << "修改了[电影名字]：" << text;
}


void Form::on_timeEdit_textChanged(const QString &arg1)
{
    qDebug() << "修改了[观影时间]：" << arg1;
}


void Form::on_placeEdit_textChanged(const QString &arg1)
{
    qDebug() << "修改了[观影地点]：" << arg1;
}


void Form::on_buyButton_clicked()
{
    qDebug() << "点击了[购票]按钮";
}


void Form::on_watchButton_clicked()
{
    qDebug() << "点击了[观看]按钮";
}

void Form::mousePressEvent(QMouseEvent *event) {
    setFocus();
}
