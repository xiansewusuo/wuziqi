#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//游戏初始化界面
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    gamewidget *game;

private slots:
    void a();
};
#endif // WIDGET_H
