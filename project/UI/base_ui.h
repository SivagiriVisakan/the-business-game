#ifndef BASE_UI_H
#define BASE_UI_H

#include<QPropertyAnimation>
#include"resources_ui.h"

class Base_ui: public QObject
{
    Q_OBJECT

public:
     explicit Base_ui();

    void Setup_ui();

    void Board_rotate();

    void Players_ui_creater(int number_male1=0,int number_male2=0,int number_female=0);

    void Player_animation(QVector3D Current_pos, QVector3D Final_pos, int Player_number );
    ~Base_ui();

     Qt3DExtras::Qt3DWindow *view;
private:
    Resources_ui *BaseBoard;
    Resources_ui *Table;
    Resources_ui *Player[3];

private:

    Qt3DCore::QEntity *sceneRoot ;

    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity ;
    Qt3DExtras::QFirstPersonCameraController *camController;

    QPropertyAnimation * Playeranimation;

};

#endif // BASE_UI_H
