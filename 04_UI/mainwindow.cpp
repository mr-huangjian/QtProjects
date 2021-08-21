#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon icon = QIcon("/Users/mr.huangjian/Pictures/new.png");
    ui->actionNew->setIcon(icon);
    ui->actionOpen->setIcon(QIcon(":/image/open.png"));

    connect(ui->actionNew, &QAction::triggered, [=](){
        // 模态对话框 exec（不可以对其他窗口进行操作）
        QDialog dialog(this); // 对象存放在栈上，匿名函数执行完毕就会被释放(一闪而过)
        dialog.resize(400, 200);
        dialog.exec(); // 阻塞方法。直到对话框关闭，后面的代码才能执行下去
        qDebug() << "模态对话框已显示！";
    });

    connect(ui->actionOpen, &QAction::triggered, [=](){
        // 非模态对话框 show（可以对其他窗口进行操作）是
        QDialog * dialog = new QDialog(this); // 对象存放在堆上
        dialog->resize(400, 200);
        dialog->show(); // 阻塞方法。直到对话框关闭，后面的代码才能执行下去
        dialog->setAttribute(Qt::WA_DeleteOnClose, true); // 在对话框关闭后将对象释放掉，防止内存泄漏
        // dialog->setAttribute(Qt::WA_DeleteOnClose); // 方法第二个布尔参数默认为true
        qDebug() << "非模态对话框已显示！";
    });

    connect(ui->actionClose, &QAction::triggered, [=](){
//        QMessageBox::critical(this, "critical", "错误内容");

        QMessageBox::StandardButton infoDialog =
        QMessageBox::information(this, "information", "提示信息",
                                 QMessageBox::Save, QMessageBox::Cancel);

        if (infoDialog == QMessageBox::Save) {
            qDebug() << "点击了保存按钮";
        } else if (infoDialog == QMessageBox::Cancel) {
            qDebug() << "点击了取消按钮";
        }

//        QMessageBox::question(this, "question", "提问内容", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);

//        QColor color = QColorDialog::getColor(QColor(0, 255, 0, 255));
//        qDebug() << "选择的颜色 R 值为：" << color.red();
//        qDebug() << "选择的颜色 G 值为：" << color.green();
//        qDebug() << "选择的颜色 B 值为：" << color.blue();
//        qDebug() << "选择的颜色 A 值为：" << color.alpha();

        /**
         * @brief QFileDialog::getOpenFileName
         * 1. 对话框标题
         * 2. 默认打开目录
         * 3. 筛选出指定类型的文件
         */
//        QString path = QFileDialog::getOpenFileName(this, "打开文件", "/Users/mr.huangjian/", "*.c");
//        qDebug() << "文件路径：" << path;

//        bool flag;
//        QFont font = QFontDialog::getFont(&flag, this);
//        QFont font = QFontDialog::getFont(&flag, QFont("Menlo", 28));
//        qDebug() << "字体：" << font.family().toUtf8().data();
//        qDebug() << "字号：" << font.pointSize();
//        qDebug() << "是否加粗：" << font.bold();
//        qDebug() << "是否倾斜：" << font.italic();
    });

    /*
        QColorDialog 选择颜色
        QFileDialog 选择文件或目录
        QFontDialog 选择字体
        QInputDialog 允许用户输入一个值，并将其值返回
        QMessageBox 模态对话框，用于显示信息、询问问题等
        QProgressDialog 显示操作过程
     */
}

MainWindow::~MainWindow()
{
    delete ui;
}

