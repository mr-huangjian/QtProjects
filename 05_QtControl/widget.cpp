#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->radioButtonMan->setChecked(true);

    connect(ui->radioButtonMan, &QRadioButton::toggled, [=](bool checked) {
        qDebug() << "男被选中" << checked;
    });

    connect(ui->radioButtonWomen, &QRadioButton::clicked, [=](bool checked) {
        qDebug() << "女被选中" << checked;
    });

    connect(ui->checkBox_3, &QCheckBox::stateChanged, [=](int state) {
        // qDebug() << Qt::CheckState::Checked;
        // 0 未勾选    1 半选    2 勾选
        qDebug() << "第三个复选框的选中状态：" << state;
    });

    QListWidgetItem  * item = new QListWidgetItem("锄禾日当午");
    item->setTextAlignment(Qt::AlignCenter);
    ui->listWidget->addItem(item);

    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

