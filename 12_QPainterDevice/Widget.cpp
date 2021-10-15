#include "Widget.h"
#include "ui_Widget.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /**
    QPixmap pixmap(300, 300); // QPixmap 绘图设备
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap); // 声明画家
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    bool success = pixmap.save("/Users/huangjian/Desktop/QPixmap.png"); // 绝对路径保存到电脑
    qDebug() << success;
     */


    /**
    QImage image(300, 300, QImage::Format_RGB32); // QImage 绘图设备（可以对像素进行访问）
    image.fill(Qt::white);

    QPainter painter(&image); // 声明画家
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    bool success = image.save("/Users/huangjian/Desktop/QImage.png"); // 绝对路径保存到电脑
    qDebug() << success;
     */

    // QPicture 绘图设备，可以记录指令和重现指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    QPen pen(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();
    pic.save("/Users/huangjian/Desktop/QPicture.pic");
}

void Widget::paintEvent(QPaintEvent *ev) {

    /**
    QPainter painter(this);

    QImage image; // 利用 QImage 对像素进行修改
    image.load(":/images/bajiao.jpg");
    image.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    for (int i = 50; i < 120; i++) {
        for (int j = 50; j < 120; j++) {
            QRgb value =  qRgb(255, 2 * i, 2 * j);
            image.setPixel(i, j, value); // 修改像素点
        }
    }

    painter.drawImage(0, 0, image);
     */


    // 重现 QPicture 的绘图指令
    QPainter painter(this);
    QPicture pic;
    pic.load("/Users/huangjian/Desktop/QPicture.pic");
    painter.drawPicture(0,0,pic);



}

Widget::~Widget()
{
    delete ui;
}

