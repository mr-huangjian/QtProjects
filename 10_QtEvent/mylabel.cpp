#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置鼠标追踪状态
    setMouseTracking(true);
    // 安装事件过滤器
    // 第一个 this: watched    (给组件自己 watched 在 filterObj 上安装事件过滤器)
    // 第二个 this: filterObj  (在 filterObj 的 eventFilter 重写方法中处理组件的事件过滤)
    this->installEventFilter(this);
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
    qDebug() << "捕捉到鼠标在 MyLabel 内抬起";
}

void MyLabel::mouseMoveEvent(QMouseEvent *event) {
//    qDebug() << "捕捉到鼠标在 MyLabel 内移动";
}

// 事件分发
bool MyLabel::event(QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent * ev = static_cast<QMouseEvent *>(event);
        qDebug() << "[鼠标摁下]" << QStringLiteral("widgetX: %1, widgetY: %2.").arg(ev->x()).arg(ev->y());
        return true; // true, 表示用户要处理该事件，不继续向下分发事件了
    }
    return QLabel::event(event);
}

// 事件过滤（比事件分发更早执行，即事件过滤方法先走，事件分发方法后走）
bool MyLabel::eventFilter(QObject *watched, QEvent *event) {
    if (watched == this) {
        if (event->type() == QEvent::MouseButtonPress) {
            qDebug() << "MyLabel MouseButtonPress";
            return true;  // true, 表示用户要处理该事件，不继续向下分发事件了
        }
    }
    return QLabel::eventFilter(watched, event);
}



