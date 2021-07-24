#include "MainWindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 200);

    // 创建菜单栏，最多有一个
    QMenuBar * wMenuBar = menuBar();
    setMenuBar(wMenuBar);

    // 创建菜单
    QMenu * fileMenu = wMenuBar->addMenu("文件");
    QAction * newAction = fileMenu->addAction("新建");
    fileMenu->addAction("打开");
    fileMenu->addSeparator();
    fileMenu->addAction("关闭");
    QMenu * editMenu = wMenuBar->addMenu("编辑");
    editMenu->addAction("复制");
    editMenu->addAction("粘贴");

    // 创建工具栏，可以有多个
    QToolBar * wToolBar = new QToolBar(this);
    wToolBar->setAllowedAreas(Qt::BottomToolBarArea);
    wToolBar->setFloatable(false);
    wToolBar->setMovable(false);
    wToolBar->addAction("字数");
    wToolBar->addSeparator();
    wToolBar->addAction(newAction);
    QPushButton * button = new QPushButton("按钮", this);
    wToolBar->addWidget(button);
    addToolBar(Qt::BottomToolBarArea, wToolBar);

    // 状态栏，最多一个
    QStatusBar * wStatusBar = statusBar();
    QLabel * label = new QLabel("提示信息", this);
    wStatusBar->addWidget(label);
    QLabel * label2 = new QLabel("右侧提示信息", this);
    wStatusBar->addPermanentWidget(label2);
    setStatusBar(wStatusBar);

    // 浮动窗口，可以有多个
    QDockWidget * dock = new QDockWidget("浮动", this);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    // 设置中心部件，只有一个
    QTextEdit * textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // addxx 可以添加多个
    // setxx 只可以添加一个


}

MainWindow::~MainWindow()
{
}







