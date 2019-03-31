#ifndef UI_FOR_MAINWINDOW_H
#define UI_FOR_MAINWINDOW_H

#include <QMainWindow>
#include"base_ui.h"
#include"map.h"
#include "cube_ui.h"
#include     "../core/Board.h "
#include "../core/Company.h "
#include "../core/GameManager.h"
#include <iostream>
#include"musiccontrols.h"
#include<QGraphicsBlurEffect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(MusicControls &,QWidget *parent = nullptr);
    ~MainWindow();

    void Gameplay_ui();
     Map *map;
    void Updatefun(QString,QString);
private slots:
    void on_RollDIces_clicked();
    void on_Map_Button_clicked();
    void Dice_fun();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void off_blurness();
    void on_Volume_button_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsBlurEffect *effect;
    MusicControls *music;
    QWidget *Ui_board ;
    QTimer *DicesTimer;
    Base_ui *Board;
    GameManager game;
    Cube_ui *cube;
};

#endif // UI_FOR_MAINWINDOW_H
