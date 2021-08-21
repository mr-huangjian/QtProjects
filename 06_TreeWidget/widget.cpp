#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄简介");

    {
        QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << "力量");
        ui->treeWidget->addTopLevelItem(item);

        QStringList string1;
        string1 << "力量1" << "力量说明";

        QTreeWidgetItem * sub1 = new QTreeWidgetItem(string1);
        item->addChild(sub1);

        QTreeWidgetItem * sub2 = new QTreeWidgetItem(QStringList() << "力量2" << "力量说明");
        item->addChild(sub2);
    }

    {
        QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << "敏捷");
        ui->treeWidget->addTopLevelItem(item);
    }

}

Widget::~Widget()
{
    delete ui;
}

