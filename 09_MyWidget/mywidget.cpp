#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSpinBox>
#include <QSlider>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 自定义控件

    void(QSpinBox:: *spinSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spinSignal, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

void MyWidget::setValue(int value)
{
    ui->spinBox->setValue(value);
}

int MyWidget::getValue()
{
    return ui->spinBox->value();
}

MyWidget::~MyWidget()
{
    delete ui;
}
