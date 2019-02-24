#ifndef BASE_UI_H
#define BASE_UI_H

#include<QPropertyAnimation>
#include"resources_ui.h"
#include<QVector3D>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>

class Base_ui: public QObject
{
    Q_OBJECT

public:
     explicit Base_ui();

    void Setup_ui();

    void Players_ui_creater();

    void Player_movement(int Position,int Player_number);

    void Player_animation(QVector3D Final_pos, int Player_number );

    void Rotation_Player(int degree,int Player_Number);
    ~Base_ui();

     Qt3DExtras::Qt3DWindow *view;
private:
    Resources_ui *Prison,*Ufo,*Stadium,*Nuclear,*Buildingnearnuclear,*Buildingnearstadium,*smallchest,*chest,*Buildingnearprison,*buldingnearchest,*buldingneartrain;
    Resources_ui *City;
    Resources_ui *Player[2];
private slots:
    void fun();
private:

    Qt3DCore::QEntity *sceneRoot ;
    QParallelAnimationGroup *group;
    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity ;
    Qt3DExtras::QFirstPersonCameraController *camController;
    QVector3D Player_Position[2],Camera_Position[2],Camera_Viewcenter[2];
    QPropertyAnimation * Playeranimation,* Cameraanimation,* Cameraanimation1;
    QTimer timer;
    int count;
};

#endif // BASE_UI_H
