#include "Widget.h"
#include "ui_Widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->teacher = new Teacher(this);
    this->student = new Student(this);

    // 1. 信号和槽函数的参数类型必须一一对应
    // 2. 信号的参数个数可以多于槽函数的参数个数


    // 无参信号与无参槽函数
    // connect(teacher, &Teacher::hungry, student, &Student::eat);
    // overClass();

    QPushButton * button = new QPushButton("下课", this);

    // 有参信号与有参槽函数
    // void(Teacher:: *hungrySignal)(QString) = &Teacher::hungry;
    // void(Student:: *eatSlot)(QString) = &Student::eat;
    // connect(teacher, hungrySignal, student, eatSlot);
    // connect(button, &QPushButton::clicked, this, &Widget::overClass);

    // 有参信号与有参槽函数、信号连接信号
    void(Teacher:: *hungryVoidSignal)(void) = &Teacher::hungry;
    void(Student:: *eatVoidSlot)(void) = &Student::eat;
    // Qt4的写法(已不可用!)
    // [x] connect(teacher, SIGNAL(hangry()), student, SLOT(eat()));
    connect(teacher, hungryVoidSignal, student, eatVoidSlot);
    connect(button, &QPushButton::clicked, teacher, hungryVoidSignal);
    // 不符合顶部说明的信号和槽函数参数的规定，下面的语句编译会报错！
    // clicked(bool) 其槽函数只能是 slot(bool) 或 slot()
    // [x]connect(button, &QPushButton::clicked, teacher, hungrySignal);

    // 断开连接(把connect换成disconnect)
    // disconnect(button, &QPushButton::clicked, teacher, hungryVoidSignal);
}

void Widget::overClass() {
    // emit teacher->hungry(); // 触发信号
    emit teacher->hungry("tomato");
}

Widget::~Widget()
{
    delete ui;
}

