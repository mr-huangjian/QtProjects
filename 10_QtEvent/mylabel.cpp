#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event) {
    qDebug() << "捕捉到鼠标进入了 MyLabel";
}

void MyLabel::leaveEvent(QEvent *event) {
    qDebug() << "捕捉到鼠标离开了 MyLabel";
}


void QWidget::mousePressEvent(QMouseEvent *event) {
    qDebug() << "捕捉到鼠标在 MyLabel 内摁下";
}

void QWidget::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "捕捉到鼠标在 MyLabel 内抬起";
}

void QWidget::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "捕捉到鼠标在 MyLabel 内移动";
}
