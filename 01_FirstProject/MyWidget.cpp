#include "MyWidget.h"
#include <QPushButton>
#include <QDebug>
#include "MyPushButton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "@ MyWidget::MyWidget";

    {
        QPushButton * button = new QPushButton;
        // button->show(); // show 方法，以顶层独立窗口显示控件
        button->setParent(this); // 将按钮添加到本控件
        button->setText("关闭");
        button->resize(80, 35);

        /**
         * 处理按钮的点击事件
         *
         * connect(
         *   const typename QtPrivate::FunctionPointer<Func1>::Object *sender, 信号的发送者
         *   Func1 signal, 触发信号的事件(信号、函数的地址)
         *   const QObject *context, 信号的接收者
         *   Func2 slot, 处理信号的函数(槽、函数的地址)
         *   Qt::ConnectionType type = Qt::AutoConnection
         * )
         */
        connect(button, &QPushButton::clicked, this, &QWidget::close);
        // connect(button, &MyPushButton::clicked, this, &MyWidget::close);
    }

    {
        QPushButton * button = new QPushButton("登录", this);
        button->move(100, 0);
    }

    {
        MyPushButton * button = new MyPushButton(this);
        button->setText("注册");
        button->move(200, 0);
    }

    resize(320, 500);
    setFixedSize(320, 500); // 设置固定的窗体尺寸
    setWindowTitle("我是窗口");

}

MyWidget::~MyWidget()
{
    qDebug() << "@ MyWidget::~MyWidget";
}

