#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this); // 在 Widget 作画


    QPen pen(QColor(255,0,0)); // 画笔（线条）
    pen.setWidth(3);
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen); // 让画家使用该画笔


    QBrush brush(Qt::cyan); // 画刷（填充）
    painter.setBrush(brush); // 让画家使用该画刷


    painter.drawLine(QPoint(0,0), QPoint(100,100));
    painter.drawEllipse(QPoint(100,100), 50,50);
    painter.drawRect(QRect(20,20,50,50));
    painter.drawText(QRect(10,200,150,50), "好好学习，天天向上");
}

Widget::~Widget()
{
    delete ui;
}
