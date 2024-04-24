#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPainter>

gamewidget::gamewidget(QWidget *parent):QWidget(parent),ui(new UI::gamewidget)
{

    for(int i=0;i<15;++i){//棋盘左上角点为(20,20),每格间距为30
        for(int j=0;j<15;++j){
            chessboard[i][j].setX(20+30*i);
            chessboard[i][j].setY(20+30*j);

        }
        setMouseTracking(true);
    }
}

gamewidget::~gamewidget()
{
    delete ui;
}

void gamewidget::paintEvent(QPaintEvent *event){
    //定义画笔，绘画对象为this
    QPainter painter(this);

    //画棋盘
    painter.setPen(Qt::black);
    for(int i=0;i<15;++i){
        painter.drawLine(chessboard[0][i],chessboard[14][i]);
        painter.drawLine(chessboard[i][0],chessboard[i][14]);

        if(turn==T_BLACK)painter.setBrush(Qt::black);
        else painter.setBrush(Qt::white);//根据当前是黑棋落子还是白棋落子确定画刷的颜色
        //画鼠标光标
        if(cursorRow!=-1&&cursorCol!=-1){
            //8为光标边长
            QRect rec(chessboard[cursorCol][cursorRow].x()-8/2,chessboard[cursorCol][cursorRow].y()-8/2,8,8);
            painter.drawRect(rec);
            }

    }
}

void gamewidget::mouseMoveEvent(QMouseEvent *event){

    //判断鼠标是否在棋盘内
    if(event->x()>=0&&event->x()<=455&&event->y()>=5&&event->y()<=455){//5=20-15,455=20+14*30+15
        //如果在棋盘内，则把鼠标设置为空白
        setCursor(Qt::BlankCursor);
        for(int i=0;i<15;++i)
            for(int j=0;j<15;++j){
                //鼠标位置
                float x=event->x(),y=event->y();
                //判断鼠标落在哪一个点附近(正方形范围)
                if((x>=(chessboard[i][j].x()-15))&&(x<(chessboard[i][j].x()+15))&&
                   (y>=(chessboard[i][j].y()-15))&&(y<(chessboard[i][j].y()+15))){
                    cursorRow=j;
                    cursorCol=i;

            }
        }
    }
    //如果在棋盘外，显示鼠标
    else setCursor(Qt::ArrowCursor);
    update();//更新界面

}
