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
    void Display_object1();
    void Display_object2();

    void on_Gameplay_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Player_selection *ui;
    MainWindow *Ui_Window;

    QWidget *Man_1,*Man_2;
    Resources_ui *man_1,*man_2;

    Qt3DExtras::Qt3DWindow *view1,*view2;
    Qt3DCore::QEntity *sceneRoot1 ,*sceneRoot2;
    Qt3DRender::QCamera *cameraEntity1,*cameraEntity2;
    Qt3DCore::QEntity *lightEntity1,*lightEntity2 ;
    Qt3DExtras::QFirstPersonCameraController *camController1,*camController2;
    QPropertyAnimation *Playeranimation1,*Playeranimation2;
};

#endif // PLAYER_SELECTION_H
