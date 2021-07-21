#include "MyPushButton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "@ MyPushButton::MyPushButton";
}

MyPushButton::MyPushButton()
{

}

MyPushButton::~MyPushButton()
{
    qDebug() << "@ MyPushButton::~MyPushButton";
}
