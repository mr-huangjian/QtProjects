#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置鼠标追踪状态
    setMouseTracking(true);
}

void MyLabel::enterEvent(QEvent *event) {
//    qDebug() << "捕捉到鼠标进入了 MyLabel";
}

void MyLabel::leaveEvent(QEvent *event) {
//    qDebug() << "捕捉到鼠标离开了 MyLabel";
}


void MyLabel::mousePressEvent(QMouseEvent *event) {
    qDebug() << "捕捉到鼠标在 MyLabel 内摁下";

    if (event->buttons() & Qt::LeftButton) {
        qDebug() << "鼠标左键摁下";
    }
    if (event->buttons() & Qt::RightButton) {
        qDebug() << "鼠标右键摁下";
    }

    // 相对自身组件的坐标系
    qDebug() << QStringLiteral("widgetX: %1, widgetY: %2.").arg(event->x()).arg(event->y());
    // 相对电脑屏幕的坐标系
    qDebug() << QStringLiteral("globalX: %1, globalY: %2.").arg(event->globalX()).arg(event->globalY());
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event) {
//    qDebug() << "捕捉到鼠标在 MyLabel 内抬起";
}

void MyLabel::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "捕捉到鼠标在 MyLabel 内移动";
}
