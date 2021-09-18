#include "widget.h"
#include "ui_widget.h"
#include <QCheckBox>
#include <QPushButton>
#include <QDebug>
#include <QSignalMapper>
#include <QMessageBox>
#include <QElapsedTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "应用名称" << "操作");
    ui->tableWidget->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableWidget->setShowGrid(false); // 隐藏网格线
    ui->tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection); // 禁止选中单元格
    ui->tableWidget->setAlternatingRowColors(true); // 隔行换色
    ui->tableWidget->verticalHeader()->setHidden(true); // 隐藏垂直方向的序号
    ui->tableWidget->verticalHeader()->setVisible(false); // 隐藏垂直方向的序号
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(55); // 设置行高
    ui->tableWidget->verticalHeader()->setSectionsClickable(false); // 禁止点击垂直方向头部
    ui->tableWidget->horizontalHeader()->setSectionsClickable(false); // 禁止点击水平方向头部
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); // 表头左对齐
    ui->tableWidget->horizontalHeader()->setFixedHeight(60); // 设置表头行高
    ui->tableWidget->horizontalHeader()->setFont(QFont("Helvetica", 16, QFont::ExtraBold)); // 设置表头字体
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // 设置第一列占满
    ui->tableWidget->horizontalHeader()->setStyleSheet(""
        "QHeaderView::section { "
            "padding-left: 25px; "
            "border: 0; "
            "background-color: rgb(230,230,230); "
            "/*border-top: 1px solid rgb(200,200,200); */"
        "}"
    );
    ui->tableWidget->setStyleSheet(""
        "QTableWidget { "
            "background-color: white; "
        "}"
        "QTableWidget::item { "
            "height: 100px; "
            "margin-left: 20px; "
            "border: 0; "
            "text-align: center;"
            "font-size: 30px; "
        "}"
    );
    ui->tableWidget->setColumnWidth(1, 160);


    QStringList strList;
    strList.append("浮生为卿歌");
    strList.append("熹妃传");
    strList.append("京门风月");
    strList.append("熹妃 Q 传");
    strList.append("宫廷计");
    strList.append("凌云诺");
    strList.append("杜拉拉");
    this->strList = strList;

    this->updateTable();
}

void Widget::updateTable() {
    ui->tableWidget->clearContents();

    QSignalMapper * signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(killApp(QString)));

    int nCount = strList.size();

    ui->tableWidget->setRowCount(nCount);

    for (int i = 0; i < nCount; i++) {
        QTableWidgetItem  * title = new QTableWidgetItem(strList.at(i));
        QFont font = title->font();
        font.setPointSize(15);
        title->setFont(font);
        title->setTextColor(QColor(50,50,50));
        ui->tableWidget->setItem(i, 0, title);

        QPushButton * button = new QPushButton;
        button->setParent(this); // 将按钮添加到本控件
        button->setText("结束进程");
        button->setAccessibleDescription(strList.at(i));
        button->setMaximumWidth(70);
        button->setMaximumHeight(20);
        button->setStyleSheet(
            "QPushButton{ color: rgb(37,147,252); border:none; font-size: 15px; } "
            "QPushButton:hover{ color: rgb(0,98,255); }"
        );
        button->setCursor(Qt::PointingHandCursor);

        QWidget * widget = new QWidget;
        QVBoxLayout * vLayout = new QVBoxLayout();
        vLayout->addWidget(button);
        vLayout->setMargin(0);
        vLayout->setAlignment(widget, Qt::AlignCenter);
        vLayout->setContentsMargins(0, 0, 0, 0);
        widget->setLayout(vLayout);
        ui->tableWidget->setCellWidget(i, 1, widget);

        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, strList.at(i));
    }
}

void Widget::killApp(QString bundleId)
{
    qDebug() << "结束进程：" << bundleId;

    this->strList.removeOne(bundleId);
    this->updateTable();
}

Widget::~Widget()
{
    delete ui;
}

