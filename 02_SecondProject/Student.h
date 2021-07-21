#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots: // 槽函数，也可以写到public下（返回值void，需声明和实现，可以重载）
    void eat();
    void eat(QString food);
};

#endif // STUDENT_H
