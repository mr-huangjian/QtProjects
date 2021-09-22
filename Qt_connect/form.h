#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_nameEdit_textChanged(const QString &arg1);
    void on_timeEdit_textChanged(const QString &arg1);
    void on_placeEdit_textChanged(const QString &arg1);
    void on_buyButton_clicked();
    void on_watchButton_clicked();

private:
    Ui::Form *ui;
    void watchMovie();
    void watchMovie(QVariant variant);
    void watchMovie(QString movieName);
    void watchMovie(QString movieName, QString time, QString place);
};

#endif // FORM_H
