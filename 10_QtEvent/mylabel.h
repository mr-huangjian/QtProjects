#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入事件
    void enterEvent(QEvent *event);

    // 鼠标离开事件
    void leaveEvent(QEvent *event);


signals:

};

#endif // MYLABEL_H
