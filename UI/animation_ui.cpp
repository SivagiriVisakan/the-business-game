#include "animation_ui.h"

Animation_ui::Animation_ui()
{

}
//void Base_ui::Player_movement(int Position, int Player_number)
//{
//    count=0;
//    Player_animation(QVector3D(-6.62f,0.1f,0.125f),0);
////    connect(&timer,SIGNAL(timeout()),this,SLOT(fun()));
////    timer.start(103);

//}

//void Base_ui::Player_animation(QVector3D Final_pos, int Player_number)
//{
////        count+=1;

//    Playeranimation =new QPropertyAnimation(Player[Player_number]->Resources_transform,"translation");
//    Playeranimation->setDuration(1000);
//    Playeranimation->setStartValue(Player_Position[Player_number]);
//    Playeranimation->setEndValue(Final_pos);

//    Cameraanimation =new QPropertyAnimation(cameraEntity,"viewCenter");
//    Cameraanimation->setDuration(1000);
//    Cameraanimation->setStartValue(Camera_Viewcenter[Player_number]);
//    Cameraanimation->setEndValue((Final_pos-Player_Position[Player_number])+Camera_Viewcenter[Player_number]);

//    Cameraanimation1 =new QPropertyAnimation(cameraEntity,"position");
//    Cameraanimation1->setDuration(1000);
//    Cameraanimation1->setStartValue(Camera_Position[Player_number]);
//    Cameraanimation1->setEndValue((Final_pos-Player_Position[Player_number])+Camera_Position[Player_number]);

//    group = new QParallelAnimationGroup(this);
//    group->addAnimation(Playeranimation);
//    group->addAnimation(Cameraanimation);
//    group->addAnimation(Cameraanimation1);

//    N= new QSequentialAnimationGroup(this);
//    N->addAnimation(group);
//    N->start();



//    Player_Position[Player_number]=Final_pos;
//    Camera_Viewcenter[Player_number]=(Final_pos-Player_Position[Player_number])+Camera_Viewcenter[Player_number];
//    Camera_Position[Player_number]=(Final_pos-Player_Position[Player_number])+Camera_Position[Player_number];
//}

//void Base_ui::Rotation_Player(int degree,int Player_Number)
//{
//    switch (degree)
//    {
//        case 0:
//     {
//        Player[Player_Number]->Resources_transform->setRotationY(degree);
//        Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(1,-0.10f,0);
//        Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(-0.5f,0.10f,0);
//        break;
//     }
//       case 90:
//    {

//       Player[Player_Number]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90.0f));
//        Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(0,-0.1f,-1);
//        Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(0,0.10f,0.5f);
//        break;
//    }

//    case -90:
//  {


//     x=new QPropertyAnimation(Player[Player_Number]->Resources_transform,"rotation");
//     x->setDuration(100);
////     Playeranimation->setStartValue(Player_Position[Player_number]);
//     x->setEndValue(-90);

//       N->addAnimation(x);

////     Player[Player_Number]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90.0f));
////     Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(0,-0.1f,1);
////     Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(0,0.10f,-0.5f);
//    break;
//    }
//    case 180:
// {
//    Player[Player_Number]->Resources_transform->setRotationY(degree);
//    Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(-1,-0.1f,0);
//    Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(0.5f,0.10f,0);
//    break;
//    }

//    }
//}

//// Camera Note important:
////     Object Car in 0,0,0
////     Make that to 0,0.15,0 height (increased)

////     For camera works ...... view center
////       For 0 degree rotation is (1,0,0)
////       then position of camera (-0.5,0.25,0)

////       For -90 degree rotation viewcenter(0,0,1)
////       position of camera (0,0.25,-0.5)

////        For 180 degree rortation viewceenter(-1,0,0)
////        position of camera (0.5,0.25,0)

////        For 90 deg rot viewcenter(0,0,-1)
////        pos of cam (0,0.25,0.5)



////DATAS


////INITIAL
////Player_Position[0]=QVector3D(-8,0.1f,0.125f);
////Camera_Position[0]=QVector3D(-8.5,0.20f,0.125);
////Camera_Viewcenter[0]=QVector3D(-7,-0.05f,0.125f);

////Player_animation(QVector3D(-6.62,0.1f,0.125),0);

////1
////Rotation_Player(-90,0);
////Player_animation(QVector3D(-6.62f,0.1f,0.125f+3.8f),0);

////2
////Rotation_Player(0,0);
////Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f),0);

////3
////Rotation_Player(90,0);
////Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f-1.8f),0);

////4
////Rotation_Player(180,0);
////Player_animation(QVector3D(-1.7f,0.1f,0.125f+3.8f-1.8f),0);

////5
////Rotation_Player(90,0);
////Player_animation(QVector3D(-1.7f,0.1f,0.125f),0);

////6
////Rotation_Player(0,0);
////Player_animation(QVector3D(1.95f,0.1f,0.125f),0);

////7
////Rotation_Player(90,0);
////Player_animation(QVector3D(1.95f,0.1f,-1.7f),0);

////8
////Rotation_Player(180,0);
////Player_animation(QVector3D(-5.80f,0.1f,-1.7f),0);

////9
////Rotation_Player(90,0);
//// Player_animation(QVector3D(-5.80f,0.1f,-1.7f-1.866f),0);

////10
////Rotation_Player(0,0);
////Player_animation(QVector3D(5.8f,0.1f,-1.7f-1.866f),0);

////11
////Rotation_Player(90,0);
////Player_animation(QVector3D(5.8f,0.1f,-1.7f-3.8f),0);

////12
////Rotation_Player(180,0);
////Player_animation(QVector3D(1.9f,0.1f,-1.7f-3.8f),0);

////13
////Rotation_Player(-90,0);
////Player_animation(QVector3D(1.9f,0.1f,-1.7f-2.8f),0);

////14
////Rotation_Player(180,0);
////Player_animation(QVector3D(-4.5f,0.1f,-1.7f-2.8f),0);

////15
////Rotation_Player(90,0);
////Player_animation(QVector3D(-4.5f,0.1f,-1.7f-4.1f),0);

////16
////Rotation_Player(0,0);
////Player_animation(QVector3D(2.0f,0.1f,-1.7f-4.1f),0);

////17
////Rotation_Player(90,0);
////Player_animation(QVector3D(2.0f,0.1f,-1.7f-6.1f),0);

//Base_ui::~Base_ui()
//{
//    delete view;
//    delete Prison;
//    delete Player[2];
//    delete Playeranimation;
//    delete sceneRoot;
//    delete cameraEntity;
//    delete lightEntity;
//    delete camController;
//    delete group;
//    delete Playeranimation;
//    delete Cameraanimation;
//    delete Cameraanimation1;
//}

//void Base_ui::fun()
//{
//    if(count==1)
//  {
//    Rotation_Player(-90,0);
//    Player_animation(QVector3D(-6.62f,0.1f,0.125f+3.8f),0);

//    }

//    if(count==2)
//    {
//        Rotation_Player(0,0);
//        Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f),0);

//     }
//    if(count==3)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f-1.8f),0);


//    }
//    if(count==4)
//    {
//        Rotation_Player(180,0);
//        Player_animation(QVector3D(-1.7f,0.1f,0.125f+3.8f-1.8f),0);

//    }
//    if(count==5)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(-1.7f,0.1f,0.125f),0);

//    }
//    if(count==6)
//    {
//        Rotation_Player(0,0);
//        Player_animation(QVector3D(1.95f,0.1f,0.125f),0);
//    }
//    if(count==7)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(1.95f,0.1f,-1.7f),0);

//    }
//    if(count==8)
//    {
//        Rotation_Player(180,0);
//        Player_animation(QVector3D(-5.80f,0.1f,-1.7f),0);
//    }
//    if(count==9)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(-5.80f,0.1f,-1.7f-1.866f),0);
//    }
//    if(count==10)
//    {
//        Rotation_Player(0,0);
//        Player_animation(QVector3D(5.8f,0.1f,-1.7f-1.866f),0);
//    }
//    if(count==11)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(5.8f,0.1f,-1.7f-3.8f),0);
//    }
//    if(count==12)
//    {
//        Rotation_Player(180,0);
//        Player_animation(QVector3D(1.9f,0.1f,-1.7f-3.8f),0);
//    }
//    if(count==13)
//    {
//        Rotation_Player(-90,0);
//        Player_animation(QVector3D(1.9f,0.1f,-1.7f-2.8f),0);
//    }
//    if(count==14)
//    {
//        Rotation_Player(180,0);
//        Player_animation(QVector3D(-4.5f,0.1f,-1.7f-2.8f),0);

//    }
//    if(count==15)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(-4.5f,0.1f,-1.7f-4.1f),0);

//    }
//    if(count==16)
//    {
//        Rotation_Player(0,0);
//        Player_animation(QVector3D(2.0f,0.1f,-1.7f-4.1f),0);
//    }
//    if(count==17)
//    {
//        Rotation_Player(90,0);
//        Player_animation(QVector3D(2.0f,0.1f,-1.7f-6.1f),0);
//         timer.stop();
//    }

//}


////dice  = 5
////count = 0
////position = 3
////data[] =
////        10
////for(int i=10; <index+5)
////if()
//// move(data[i])

