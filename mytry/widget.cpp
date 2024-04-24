#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    game = new gamewidget;
    game->hide();

    ui->setupUi(this);
    connect(this->ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(a()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::a(){
    this->hide();
    game->show();
}
