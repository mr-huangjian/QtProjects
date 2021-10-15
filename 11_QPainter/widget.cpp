#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [=]{
        on_pushButton_clicked();
    });
}

void Widget::paintEvent(QPaintEvent *event) {
    /**
    QPainter painter(this); // 在 Widget 作画


    QPen pen(QColor(255,0,0)); // 画笔（线条）
    pen.setWidth(3);
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen); // 让画家使用该画笔


    QBrush brush(Qt::cyan); // 画刷（填充）
    brush.setStyle(Qt::Dense1Pattern);
    painter.setBrush(brush); // 让画家使用该画刷


    painter.drawLine(QPoint(0,0), QPoint(100,100));
    painter.drawEllipse(QPoint(100,100), 50,50);
    painter.drawRect(QRect(20,20,50,50));
    painter.drawText(QRect(10,200,150,50), "好好学习，天天向上");
    */

    /**
    QPainter painter(this);
//    // 设置抗锯齿能力，效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(100,50), 50,50);
//    painter.drawEllipse(QPoint(200,50), 50,50);

    painter.drawRect(QRect(50,50,100,100));
    painter.translate(200,0); // 移动作画的原点
    painter.save(); // 保存作画的状态
    painter.drawRect(QRect(50,50,100,100));
    painter.translate(200,0);
    painter.restore(); // 还原作画的保存状态
    painter.drawRect(QRect(50,50,100,100));
    */

    QPainter painter(this);
    painter.drawRect(QRect(20, 20, 200, 200));

    QPixmap pixmap = QPixmap(":/images/keyboard.png").scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    if (posX > width()) {
        posX = 0;
    }
    painter.drawPixmap(posX, 20, pixmap);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    posX += 20;
//    repaint();
    update();
}

