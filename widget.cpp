#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
QRect buttonlike,buttondislike,button;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
    buttonlike = ui->Buttonlike->geometry();
    buttondislike = ui->Buttondislike->geometry();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Buttondislike_clicked()
{
    ui->textBrowser->append("你这个狗子竟然不同意");
}

void Widget::on_Buttonlike_clicked()
{
   ui->textBrowser->append("我就知道你会选这个的");
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if((event->pos().x()>=buttondislike.x()-10)&&(event->pos().y()>=buttondislike.y()-10)&&(event->pos().x()<=buttondislike.x()+100)&&(event->pos().y()<=buttondislike.y()+40))
        changeButton();
}

void Widget::changeButton()
{
    ui->Buttondislike->setGeometry(buttonlike);
    ui->Buttonlike->setGeometry(buttondislike);
    button = buttondislike;
    buttondislike = buttonlike;
    buttonlike = button;
}
