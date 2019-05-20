#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    void changeButton();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:

    void on_Buttondislike_clicked();

    void on_Buttonlike_clicked();

    void mouseMoveEvent(QMouseEvent *event);



private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
