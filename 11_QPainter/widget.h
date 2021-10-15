#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int posX = 0;
    void paintEvent(QPaintEvent *event);
};
#endif // WIDGET_H
