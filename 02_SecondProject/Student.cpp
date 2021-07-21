#include "Student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::eat() {
    qDebug() << "去食堂吃饭";
}

void Student::eat(QString food) {
    // QString 转 char *
    qDebug() << "去食堂吃饭:" << food.toUtf8().data();
}
