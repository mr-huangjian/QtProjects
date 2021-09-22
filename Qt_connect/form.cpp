#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QFont>
#include "model.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setWindowTitle("");

    // 设置字间距
    QFont font = ui->buyButton->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);
    ui->buyButton->setFont(font);

    // connect / disconnect / lambda
    // https://juejin.cn/post/7010652538223460388/

    // QVariant
    // https://zhuanlan.zhihu.com/p/97827443
    // https://www.pianshen.com/article/7905818190/
    // https://blog.csdn.net/h1530687053/article/details/114979702
    // https://blog.csdn.net/zhangbinsijifeng/article/details/50686753

    // QSignalMapper
    // https://www.cnblogs.com/kongbursi-2292702937/p/15016769.html
    // http://www.cppblog.com/gaimor/archive/2014/12/14/209183.html

    connect(ui->buyButton, &QPushButton::clicked, this, [=] {
        Model model;
        model.name = "购票按钮被点击了";

        // QVariant variant;
        // variant.setValue(model);
        watchMovie(QVariant::fromValue(model));
    });
}

Form::~Form()
{
    delete ui;
}

void Form::on_nameEdit_textChanged(const QString &arg1)
{
    QString text = ui->nameEdit->text();
    qDebug() << "修改了[电影名字]：" << text;
}


void Form::on_timeEdit_textChanged(const QString &arg1)
{
    qDebug() << "修改了[观影时间]：" << arg1;
}


void Form::on_placeEdit_textChanged(const QString &arg1)
{
    qDebug() << "修改了[观影地点]：" << arg1;
}


void Form::on_buyButton_clicked()
{
    qDebug() << "点击了[购票]按钮";
}


void Form::on_watchButton_clicked()
{
    qDebug() << "点击了[观看]按钮";
}

void Form::mousePressEvent(QMouseEvent *event) {
    setFocus();
}

void Form::watchMovie(QVariant variant) {
    Model model = variant.value<Model>();
    qDebug() << "variant.value: " << model.name;
}
