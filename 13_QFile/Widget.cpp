#include "Widget.h"
#include "ui_Widget.h"
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>
#include <QTextCodec>
#include <QDateTime>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFont font = ui->textEdit->font();
    font.setFamily("Andale Mono");
    ui->textEdit->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_selectFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "打开文件", "/Users/huangjian/Desktop");
    ui->lineEdit->setText(path);

    // 编码格式
    QTextCodec * codec = QTextCodec::codecForName("utf-8");

    // QFile 默认支持UTF8编码的文件格式，可以先判断文件的编码格式，如读第一个字符的编码格式
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    // 文件信息
    QFileInfo info(path);
    qDebug() << "文件路径：" << info.filePath();
    qDebug() << "文件名称：" << info.fileName();
    qDebug() << "文件后缀：" << info.suffix();
    qDebug() << "文件大小：" << info.size();
    qDebug() << "文件是否存在：" << info.exists();
    qDebug() << "是否是文件：" << info.isFile();

    QDateTime time = info.lastModified();
    qDebug() << "上次修改时间：" << time.toString("yyyy/MM/dd hh:mm:ss");


    // QByteArray array = file.readAll();

    QByteArray array;
    while (!file.atEnd()) {
        array += file.readLine();
    }

    // ui->textEdit->setText(array);
    ui->textEdit->setText(codec->toUnicode(array));

    file.close();


    /**
    file.open(QIODevice::Append);
    file.write("\n// 这是追加的注释");
    file.close();
    */

}









