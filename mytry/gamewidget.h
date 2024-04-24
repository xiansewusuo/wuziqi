#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include<QWidget>
#include<QMouseEvent>

namespace UI{
    class gamewidget{};
}

using namespace std;

enum gameTurn{T_BLACK,T_WHITE};//轮到谁下

//游戏运行界面
class gamewidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamewidget(QWidget *parent = nullptr);
    ~gamewidget()override;
protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
       UI::gamewidget *ui;
       QPoint chessboard[15][15];//前一个代表列，后一个代表行
       int cursorRow=0;//光标位置
       int cursorCol=0;
       gameTurn turn;

};

#endif // GAMEWIDGET_H
