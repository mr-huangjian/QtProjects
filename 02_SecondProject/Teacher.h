#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals: // 自定义信号（返回值void，只需声明不需实现，可以重载）
    void hungry();
    void hungry(QString food);
};

#endif // TEACHER_H
