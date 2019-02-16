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

    void Players_ui_creater();

    void Player_animation(QVector3D Current_pos, QVector3D Final_pos, int Player_number );
    ~Base_ui();

     Qt3DExtras::Qt3DWindow *view;
private:
    Resources_ui *Prison,*Ufo,*Stadium,*Nuclear,*Buildingnearnuclear,*Buildingnearstadium,*smallchest,*chest,*Buildingnearprison,*buldingnearchest,*buldingneartrain;
    Resources_ui *City;
    Resources_ui *Player[3];

private:

    Qt3DCore::QEntity *sceneRoot ;

    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity ;
    Qt3DExtras::QFirstPersonCameraController *camController;

    QPropertyAnimation * Playeranimation;

};

#endif // BASE_UI_H
