#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
};
#endif // MYWIDGET_H

/*
 * CMD + B  编译
 * CMD + R  运行
 * CMD + I  自动对齐
 * CMD + SHIFT + ↑或↓    移动整行
 * F1   查看帮助文档
 * F4   同名.h/.cpp切换
 */
