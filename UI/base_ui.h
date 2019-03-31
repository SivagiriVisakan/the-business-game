#ifndef BASE_UI_H
#define BASE_UI_H

#include<QPropertyAnimation>
#include"resources_ui.h"
#include<QVector3D>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>
#include"../core/GameManager.h"
#include"token.h"

class Base_ui: public QObject
{
    Q_OBJECT

public:
    Base_ui(GameManager &);

    void Setup_ui();

    void tokenFunction();

    void Players_ui_creater();

    void Player_movement(int Position,int Player_number);

    void Player_animation(QVector3D Final_pos, int Player_number );

    void Rotation_Player(int degree,int Player_Number);




    QVector3D function_getpos();
     QVector3D function_getview();

     void function_setpos(QVector3D,QVector3D);

    ~Base_ui();

     Qt3DExtras::Qt3DWindow *view;
private:
    Resources_ui *Prison,*Ufo,*Stadium,*Nuclear,*Buildingnearnuclear,*Buildingnearstadium,*smallchest,*chest,*Buildingnearprison,*buldingnearchest,*buldingneartrain;
    Resources_ui *City;
    Resources_ui *Player[2];
    Resources_ui *Board[34];
private slots:
    void Focus_fun();
    void Animation_fun();
private:

    Qt3DCore::QEntity *sceneRoot ;
    QParallelAnimationGroup *group;
    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity ;
    Qt3DExtras::QFirstPersonCameraController *camController;
    QVector3D Player_Position[2],Camera_Position[2],Camera_Viewcenter[2];
    QPropertyAnimation * Playeranimation,* Cameraanimation,* Cameraanimation1,*Rotationplayer,*Rotationcamera,*Rotationcamera1;
    int count,Position,player;
    QSequentialAnimationGroup *Animation;
    Token *token;
    GameManager *Game;
};

#endif // BASE_UI_H
