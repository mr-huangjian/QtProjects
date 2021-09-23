#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>

#include <iostream>
#include <ctime>

using namespace std;

char * currentTime() {
    time_t now = time(0);
    char * dt = ctime(&now);
    dt[strlen(dt) - 1] = 0;
    return dt;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /** 两种定时器
        timerId = startTimer(1000);

        qDebug() << "start at: " << currentTime();

        QTimer * timer = new QTimer(this);
        timer->start(2000);
        connect(timer, &QTimer::timeout, []{
            qDebug() << "running at: " << currentTime();
        });
    */
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent * ev) {
    if (ev->timerId() == timerId) {
        static int num = 1;
        ui->label->setText(QString::number(num++));
    }
}

