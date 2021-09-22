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


    /**
     * lambda 匿名函数
     * = 表示局部变量值传递
     * & 表示局部变量引用传递
     *
     * mutable 放在参数()后面
     * 表示值传递过来的变量，可以在匿名函数内修改值，且只在匿名函数内有效，不影响变量本身的值
     * 即修改的是拷贝，不是本体
     * 可以作为 connect 的槽函数等
     */

    [=]()mutable {
        button->setText("新标题");
    }();

    int ret = [] () -> int {
        return 0;
    }();

    connect(button, &QPushButton::clicked, this, [=](){
        this->close();
    });

    connect(button, &QPushButton::clicked, [=](){
        emit teacher->hungry("tomato");
    });


    /*
    Lambda 函数对象参数有以下形式：
    1. []，没有使用任何函数对象参数。
    2. [=]，函数体内可以使用Lambda所在作用范围内所有可见的局部交量（包括Lambda所在类的this),并且是值传递方式（相当于编译器自动为我们按值传递了所有局部变量）。
    3. [&]，函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this),并且是引用传递方式（相当于编译器自动为我们按引用传递了所有局部变量）。
    4. [this]，函数体内可以使用Lambda所在类中的成员变量。
    5. [a]，将a按值进行传递。按值进行传递时，函数体内不能修改传递进来的a的拷贝，因为默认情况下函数是const的。要修改传递进来的a的拷贝，可以添加mutable修饰符。
    6. [&a]，将a按引用进行传递。
    7. [a,&b]，将a按值进行传递，b按引用进行传递。
    8. [=,&a,&b]，除a和b按引用进行传递外，其他参数都按值进行传递。
    9. [&,a,b]，除a和b按值进行传递外，其他参数都按引用进行传递。
     */
}

void Widget::overClass() {
    // emit teacher->hungry(); // 触发信号
    emit teacher->hungry("tomato");
}

Widget::~Widget()
{
    delete ui;
}

