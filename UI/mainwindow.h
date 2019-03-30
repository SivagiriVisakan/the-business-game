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


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Gameplay_ui();
     Map *m;
    void Updatefun(QString,QString);
private slots:
    void on_RollDIces_clicked();
    void on_Map_Button_clicked();
    void Dice_fun();
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;

    QWidget *Ui_board ;
    QTimer *DicesTimer;
    Base_ui Board;
    GameManager game;
    Cube_ui *cube;
};

#endif // UI_FOR_MAINWINDOW_H
