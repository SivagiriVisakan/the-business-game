#ifndef PLAYER_SELECTION_H
#define PLAYER_SELECTION_H

#include <QDialog>
#include"mainwindow.h"
#include "resources_ui.h"
#include<QPropertyAnimation>
namespace Ui {
class Player_selection;
}

class Player_selection : public QDialog
{
    Q_OBJECT

public:
    explicit Player_selection(QWidget *parent = nullptr);
    ~Player_selection();

private slots:


    void on_Gameplay_button_clicked();

    void on_pushButton_clicked();



private:
    Ui::Player_selection *ui;
    MainWindow *Ui_Window;


};

#endif // PLAYER_SELECTION_H
