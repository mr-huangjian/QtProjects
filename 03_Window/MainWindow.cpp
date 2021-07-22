#include "MainWindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>

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

}

MainWindow::~MainWindow()
{
}

