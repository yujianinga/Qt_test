#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QMessageBox>

QRect buttonlike,buttondislike,button;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
    QPixmap picture;
    picture.load("65.jpg");
    ui->label->setText("做我女朋友吧");
    ui->label_2->setPixmap(picture);
    buttonlike = ui->Buttonlike->geometry();
    buttondislike = ui->Buttondislike->geometry();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Buttondislike_clicked()
{
    QMessageBox *msgBox;
    msgBox = new QMessageBox("伤心",                     //--这里是设置消息框标题
            "你这个狗子竟然不同意",                        //--这里是设置消息框显示的内容
            QMessageBox::Critical,                      //--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,     //---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	//---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
    msgBox->show();
}

void Widget::on_Buttonlike_clicked()
{
   QMessageBox *msgBox;
   msgBox = new QMessageBox("开心",                     //--这里是设置消息框标题
           "太好了你竟然同意了",                        //--这里是设置消息框显示的内容
           QMessageBox::Critical,                      //--这里是在消息框显示的图标
           QMessageBox::Ok | QMessageBox::Default,     //---这里是显示消息框上的按钮情况
           QMessageBox::Cancel | QMessageBox::Escape,	//---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
           0);
   msgBox->show();
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
