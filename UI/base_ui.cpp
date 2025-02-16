#include "base_ui.h"
#include<string>
#include<QDebug>


Base_ui::Base_ui(GameManager & Game)
{
    sceneRoot = new Qt3DCore::QEntity();
    City=new Resources_ui(sceneRoot);
    Animation= new QSequentialAnimationGroup(this);
    timer=new QTimer();
    token=new Token();
    this->Game=&Game;
    count=1;
    Position=0;

    City-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/cityfinal_.obj")));

    City->Resources_transform->setScale(1.00f);       // size
    City->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    City->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    City->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

    City->Add_resources_components();


    Prison=new Resources_ui(City->Resources_Entity);

    Prison-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/jail.obj")));

    Prison->Resources_transform->setScale(1.0f);       // size
    Prison->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Prison->Resources_transform->setTranslation(QVector3D(-0.05f, 0.0f, -0.15f));

    Prison->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/jail.jpg")));

    Prison->Add_resources_components();
//x-4.845 z-2.4183 y-0.19540


    Ufo=new Resources_ui(City->Resources_Entity);

    Ufo-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/spaceship.obj")));

    Ufo->Resources_transform->setScale(1.0f);       // size
    Ufo->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Ufo->Resources_transform->setTranslation(QVector3D(4.0f, -1.0f, -7.0f));

    Ufo->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/spaceship_tex.png")));

    Ufo->Add_resources_components();


    Stadium=new Resources_ui(City->Resources_Entity);

    Stadium-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/stadium.obj")));

    Stadium->Resources_transform->setScale(1.0f);       // size
    Stadium->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Stadium->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    Stadium->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/10093_Wembley_stadion_V1_Diffuse.jpg")));

    Stadium->Add_resources_components();


    Nuclear=new Resources_ui(City->Resources_Entity);

    Nuclear-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/nuclear.obj")));

    Nuclear->Resources_transform->setScale(1.0f);       // size
    Nuclear->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Nuclear->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    Nuclear->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/10078_Nuclear_Power_Plant_v1_Diffuse.jpg")));

    Nuclear->Add_resources_components();

    Buildingnearnuclear=new Resources_ui(City->Resources_Entity);

    Buildingnearnuclear-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/Buildingnearnuclear.obj")));

    Buildingnearnuclear->Resources_transform->setScale(1.0f);       // size
    Buildingnearnuclear->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Buildingnearnuclear->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    Buildingnearnuclear->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/buildnearnuclear.jpg")));

    Buildingnearnuclear->Add_resources_components();


    Buildingnearstadium=new Resources_ui(City->Resources_Entity);

    Buildingnearstadium-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/Buildingnearstadium.obj")));

    Buildingnearstadium->Resources_transform->setScale(1.0f);       // size
    Buildingnearstadium->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Buildingnearstadium->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    Buildingnearstadium->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/tex_06.jpg")));

    Buildingnearstadium->Add_resources_components();

    smallchest=new Resources_ui(City->Resources_Entity);

    smallchest-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/smallchest.obj")));

    smallchest->Resources_transform->setScale(1.0f);       // size
    smallchest->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    smallchest->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    smallchest->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/chest.jpg")));

    smallchest->Add_resources_components();


    chest=new Resources_ui(City->Resources_Entity);

    chest-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/chest.obj")));

    chest->Resources_transform->setScale(1.0f);       // size
    chest->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    chest->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    chest->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/chest.jpg")));

    chest->Add_resources_components();

    Buildingnearprison=new Resources_ui(City->Resources_Entity);

    Buildingnearprison-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/Buildingnearprison.obj")));

    Buildingnearprison->Resources_transform->setScale(1.0f);       // size
    Buildingnearprison->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Buildingnearprison->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    Buildingnearprison->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/buildingnearprison.jpg")));

    Buildingnearprison->Add_resources_components();



    buldingnearchest=new Resources_ui(City->Resources_Entity);

    buldingnearchest-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/buildingnearchest.obj")));

    buldingnearchest->Resources_transform->setScale(1.0f);       // size
    buldingnearchest->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    buldingnearchest->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    buldingnearchest->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/buildnearchest.jpg")));

    buldingnearchest->Add_resources_components();


    buldingneartrain=new Resources_ui(City->Resources_Entity);

    buldingneartrain-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/buildingneartrain.obj")));

    buldingneartrain->Resources_transform->setScale(1.0f);       // size
    buldingneartrain->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    buldingneartrain->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

    buldingneartrain->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/tex_06.jpg")));

    buldingneartrain->Add_resources_components();


  for(int i=1;i<34;i++)
   {

       Board[i]=new Resources_ui(City->Resources_Entity);

        QString source;

       source="qrc:/board_";
       source+=QString::number(i);
       source+=".obj";
       Board[i]-> Resources_ui_mesh->setSource(QUrl(QString(source)));

       Board[i]->Resources_transform->setScale(1.0f);       // size
       Board[i]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
       Board[i]->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, -0.0f));

       QString path = "qrc:/new/prefix1/Logos/" + QString::number(i-1) +".png";
       Board[i]->Texture_loader->setSource(QUrl(path));

       Board[i]->Add_resources_components();

   }

}

void Base_ui::Setup_ui()
{

    view = new Qt3DExtras::Qt3DWindow();  // 3d window
    view->defaultFrameGraph()->setClearColor(QColor("black"));
    view->setFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    view->setWidth(1470);
    view->setHeight(1000);

     cameraEntity = view->camera();

    cameraEntity->lens()->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    cameraEntity->setUpVector(QVector3D(0.0f, 1.0f,0.0f));
    cameraEntity->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));
//    cameraEntity->setPosition(QVector3D(0.0f, 10.0f, -35.0f));
    cameraEntity->setPosition(QVector3D(-25.0f, 10.0f, 1.0f));

    //Add A Starting Animation To the close up car

    lightEntity = new Qt3DCore::QEntity(sceneRoot);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("yellow");
    light->setIntensity(2);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
   lightEntity->addComponent(lightTransform);

//    For camera controls
//    camController = new Qt3DExtras::QFirstPersonCameraController(sceneRoot);
//    camController->setCamera(cameraEntity);

    view->setRootEntity(sceneRoot);

}

void Base_ui::tokenFunction()
{

    QString m=QString::fromStdString(Game->getPlayerFromId(0).getName());
    token->setCompanyName(m);
    timer->stop();
    token->show();

}

void Base_ui::Players_ui_creater()
{


    Player_Position[0]=QVector3D(-8,0.1f,0.125f);
    Camera_Position[0]=QVector3D(-11.5,1.20f,0.125);
    Camera_Viewcenter[0]=QVector3D(-7,-0.05f,0.125f);


    Player_Position[1]=QVector3D(-8,0.1f,0.1f);
    Camera_Position[1]=QVector3D(-11.5,1.20f,0.1f);
    Camera_Viewcenter[1]=QVector3D(-7,-0.05f,0.1f);

            Player[0]=new Resources_ui(City->Resources_Entity);

            Player[0]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/car1_1.obj")));

            Player[0]->Resources_transform->setScale(1.00f);       // size
            Player[0]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 180.0f)); // x,y,z axis and degree rotation
            Player[0]->Resources_transform->setTranslation(Player_Position[0]);

            Player[0]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

            Player[0]->Add_resources_components();



            Player[1]=new Resources_ui(City->Resources_Entity);

            Player[1]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/car1_2.obj")));

            Player[1]->Resources_transform->setScale(1.0f);       // size
            Player[1]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), -90.0f)); // x,y,z axis and degree rotation
            Player[1]->Resources_transform->setTranslation(Player_Position[1]);

            Player[1]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

            Player[1]->Add_resources_components();

}

void Base_ui::Player_animation(QVector3D Final_pos, int Player_number)
{
//    delete Playeranimation;
    Playeranimation =new QPropertyAnimation(Player[Player_number]->Resources_transform,"translation");
    Playeranimation->setDuration(5000);
    Playeranimation->setStartValue(Player_Position[Player_number]);
    Playeranimation->setEndValue(Final_pos);

//    delete Cameraanimation;
    Cameraanimation =new QPropertyAnimation(cameraEntity,"viewCenter");
    Cameraanimation->setDuration(5000);
    Cameraanimation->setStartValue(Camera_Viewcenter[Player_number]);
    Cameraanimation->setEndValue((Final_pos-Player_Position[Player_number])+Camera_Viewcenter[Player_number]);

//    delete Cameraanimation1;
    Cameraanimation1 =new QPropertyAnimation(cameraEntity,"position");
    Cameraanimation1->setDuration(5000);
    Cameraanimation1->setStartValue(Camera_Position[Player_number]);
    Cameraanimation1->setEndValue((Final_pos-Player_Position[Player_number])+Camera_Position[Player_number]);

//    delete group;
    group = new QParallelAnimationGroup(this);
    group->addAnimation(Playeranimation);
    group->addAnimation(Cameraanimation);
    group->addAnimation(Cameraanimation1);


    Animation->addAnimation(group);

    Player_Position[Player_number]=Final_pos;
    Camera_Viewcenter[Player_number]=(Final_pos-Player_Position[Player_number])+Camera_Viewcenter[Player_number];
    Camera_Position[Player_number]=(Final_pos-Player_Position[Player_number])+Camera_Position[Player_number];
}

void Base_ui::Rotation_Player(int degree,int Player_Number)
{
//    delete Rotationplayer;
    Rotationplayer=new QPropertyAnimation(Player[Player_Number]->Resources_transform,"rotationY");
    Rotationplayer->setDuration(100);
    Rotationplayer->setStartValue(0);

//    delete Rotationcamera;
    Rotationcamera =new QPropertyAnimation(cameraEntity,"viewCenter");
    Rotationcamera->setDuration(100);
    Rotationcamera->setStartValue(Camera_Viewcenter[Player_Number]);

//    delete Rotationcamera1;
    Rotationcamera1 =new QPropertyAnimation(cameraEntity,"position");
    Rotationcamera1->setDuration(100);
    Rotationcamera1->setStartValue(Camera_Position[Player_Number]);

    switch (degree)
    {
        case 0:
     {
        Rotationplayer->setEndValue(0);

       Rotationcamera->setEndValue(Player_Position[Player_Number]+QVector3D(1,-0.10f,0));

       Rotationcamera1->setEndValue(Player_Position[Player_Number]+QVector3D(-3.5f,1.10f,0));

//        delete group;
        group = new QParallelAnimationGroup(this);
        group->addAnimation(Rotationplayer);
        group->addAnimation(Rotationcamera);
        group->addAnimation(Rotationcamera1);

        Animation->addAnimation(group);

        Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(1,-0.10f,0);
        Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(-3.5f,1.10f,0);

        break;

    }
       case 90:
    {

        Rotationplayer->setEndValue(90);

        Rotationcamera->setEndValue(Player_Position[Player_Number]+QVector3D(0,-0.1f,-1));

        Rotationcamera1->setEndValue(Player_Position[Player_Number]+QVector3D(0,1.10f,3.5f));

//        delete group;
        group = new QParallelAnimationGroup(this);
        group->addAnimation(Rotationplayer);
        group->addAnimation(Rotationcamera);
        group->addAnimation(Rotationcamera1);


        Animation->addAnimation(group);

        Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(0,-0.1f,-1);
        Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(0,1.10f,3.5f);

        break;
    }

    case -90:
  {
     Rotationplayer->setEndValue(-90);

     Rotationcamera->setEndValue(Player_Position[Player_Number]+QVector3D(0,-0.1f,1));

     Rotationcamera1->setEndValue(Player_Position[Player_Number]+QVector3D(0,1.10f,-3.5f));

//     delete group;
     group = new QParallelAnimationGroup(this);
     group->addAnimation(Rotationplayer);
     group->addAnimation(Rotationcamera);
     group->addAnimation(Rotationcamera1);


     Animation->addAnimation(group);

     Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(0,-0.1f,1);
     Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(0,1.10f,-3.5f);

     break;
    }
    case 180:
 {
        Rotationplayer->setEndValue(-180);

        Rotationcamera->setEndValue(Player_Position[Player_Number]+QVector3D(-1,-0.1f,0));

        Rotationcamera1->setEndValue(Player_Position[Player_Number]+QVector3D(3.5f,1.10f,0));

//        delete group;
        group = new QParallelAnimationGroup(this);
        group->addAnimation(Rotationplayer);
        group->addAnimation(Rotationcamera);
        group->addAnimation(Rotationcamera1);


        Animation->addAnimation(group);

        Camera_Viewcenter[Player_Number]=Player_Position[Player_Number]+QVector3D(-1,-0.1f,0);
        Camera_Position[Player_Number]=Player_Position[Player_Number]+QVector3D(3.5f,1.10f,0);

        break;
    }

    }
}

void Base_ui::Focus_fun()
{
        QVector3D camera,viewcenter;
        if(Position==1)
        {             
            camera=QVector3D(-10.6091f,1.18844f,-1.09134f);
            viewcenter=QVector3D(-0.743342f,-0.724871f,-1.0214f);
        }
        else if(Position==2)
        {
            camera=QVector3D(-9.86903f,0.907853f,1.60327f);
            viewcenter=QVector3D(0.148583f,0.103621f,1.58552f);
        }
        else if(Position==3)
        {
            camera=QVector3D(1.32027,1.13159,2.96968);
            viewcenter=QVector3D(-8.61664 , -0.366024 , 2.85075);
        }
        else if(Position==4)
        {
            camera=QVector3D(1.11162,0.615859,3.18632);
            viewcenter=QVector3D(-8.3078,-1.97612,0.829338);
        }
        else if(Position==5)
        {
            camera=QVector3D(0.957589,0.61731,5.66483);
            viewcenter=QVector3D(0.560174,-1.01106,-5.60963);
        }
        else if(Position==6)
        {
            camera=QVector3D(3.1634,0.384199,1.21364);
            viewcenter=QVector3D(-8.19258,-0.575477,1.41997);
        }
        else if(Position==7)
        {
            camera=QVector3D(-0.758443,1.06487,3.80751);
            viewcenter=QVector3D(-0.773723,-2.56131,-6.99859);
        }
        else if(Position==8)
        {
            camera=QVector3D(2.00864,1.34568,2.46504);
            viewcenter=QVector3D(-8.43265,0.467119,-2.02143);
        }
        else if(Position==9)
        {
            camera=QVector3D(-4.94334,2.19515,4.97319);
            viewcenter=QVector3D(-5.34813,-0.286287,-6.14438);
        }
        else if(Position==10)
        {
            camera=QVector3D(0.168288,1.49312,2.77687);
            viewcenter=QVector3D(-5.135,-0.686269,-5.47697);
        }
        else if(Position==11)
        {
            camera=QVector3D(0.767038,1.89839,3.91843);
            viewcenter=QVector3D(0.816497,-0.260814,-5.89662);
        }
        else if(Position==12)
        {
            camera=QVector3D(3.83725,2.12004,-6.60825);
            viewcenter=QVector3D(4.18172,-1.10816,2.90282);
        }
        else if(Position==13)
        {
            camera=QVector3D(3.55948,1.52994,-0.367244);
            viewcenter=QVector3D(-4.04476,-1.36256,-6.26721);
        }
        else if(Position==14)
        {
            camera=QVector3D(-0.121579,1.12314,-0.821237);
            viewcenter=QVector3D(-7.0059,-2.55552,-7.15179);
        }
        else if(Position==15)
        {
            camera=QVector3D(-4.4301,1.27764,-6.60172);
            viewcenter=QVector3D(-5.962,-0.799368,3.11122);
        }
        else if(Position==16)
        {
            camera=QVector3D(-2.04428,1.58185,-4.94547);
            viewcenter=QVector3D(-11.6201,-1.27764,-3.88356);
        }
        else if(Position==17)
        {
            camera=QVector3D(-2.9829,0.737188,-3.96037);
            viewcenter=QVector3D(-12.1066,-3.44596,-4.47023);
        }
        else if(Position==18)
        {
            camera=QVector3D(-3.09001,0.649038,-2.70574);
            viewcenter=QVector3D(-3.30165,-2.19055,-12.3438);
        }
        else if(Position==19)
        {
            camera=QVector3D(-0.661295,0.804417,-4.17732);
            viewcenter=QVector3D(-9.48275,-3.96527,-3.52032);
        }
        else if(Position==20)
        {
            camera=QVector3D(-0.787485,0.466134,-2.7973);
            viewcenter=QVector3D(-1.36356,-1.2575,-12.6815);
        }
        else if(Position==21)
        {
            camera=QVector3D(1.36574,0.648306,-3.99323 );
            viewcenter=QVector3D(-7.99514,-3.00347,-4.18418);
        }
        else if(Position==22)
        {
            camera=QVector3D(1.23533,0.284254,-2.70672);
            viewcenter=QVector3D(1.299,0.166743,-12.7556);
        }
        else if(Position==23)
        {
            camera=QVector3D(-0.00480022,1.06998,-4.02715);
            viewcenter=QVector3D(9.65029,-0.707407,-6.17595);
        }
        else if(Position==24)
        {
            camera=QVector3D(2.90591,0.502012,-4.1377);
            viewcenter=QVector3D(-5.60886,-1.1464,-9.21503);
        }
        else if(Position==25)
        {
            camera=QVector3D(1.99336,0.772804,-4.61329);
            viewcenter=QVector3D(-7.4361,-2.18237,-6.44362);
        }
        else if(Position==26)
        {
            camera=QVector3D(0.0567086,0.437845,-3.85513);
            viewcenter=QVector3D(-6.33851,-0.721688,-11.5203);
        }
        else if(Position==27)
        {
            camera=QVector3D(-3.32188,0.498531,-4.50355);
            viewcenter=QVector3D(6.0745,-0.871058,-7.79468);
        }
        else if(Position==28)
        {
            camera=QVector3D(-1.54411,0.464574,-4.51213);
            viewcenter=QVector3D(-11.2606,-2.56041,-9.34027);
        }
        else if(Position==29)
        {
            camera=QVector3D(-3.12112,0.656287,-4.40034);
            viewcenter=QVector3D(-0.743342f,-0.724871f,-1.0214f);
        }
        else if(Position==30)
        {
            camera=QVector3D(-1.53784,1.12576,-4.57018);
            viewcenter=QVector3D(-9.54724,-0.212723,-10.4914);
        }
        else if(Position==31)
        {
            camera=QVector3D(-1.95341,1.3927,-2.18263);
            viewcenter=QVector3D(-2.27149,-0.395029,-12.0673);
        }
        else if(Position==32)
        {
            camera=QVector3D(0.870971,1.58411,-3.09956);
            viewcenter=QVector3D(1.06022,-1.01318,-12.8063);
        }
        else if(Position==33)
        {
            camera=QVector3D(4.60635,1.41334,-2.4292);
            viewcenter=QVector3D(3.67184,-0.376278,-12.2743);
        }

        cameraEntity->setPosition(camera);
        cameraEntity->setViewCenter(viewcenter);


//        timer->start(1500);

//        connect(timer,SIGNAL(timeout()),this,SLOT(tokenFunction()));

}

QVector3D Base_ui::function_getpos()
{
    return cameraEntity->position();
}

QVector3D Base_ui::function_getview()
{
    return cameraEntity->viewCenter();
}

void Base_ui::function_setpos(QVector3D m,QVector3D n)
{
    cameraEntity->setPosition(m);
    cameraEntity->setViewCenter(n);
}




// Camera Note important:
//     Object Car in 0,0,0
//     Make that to 0,0.15,0 height (increased)

//     For camera works ...... view center
//       For 0 degree rotation is (1,0,0)
//       then position of camera (-0.5,0.25,0)

//       For -90 degree rotation viewcenter(0,0,1)
//       position of camera (0,0.25,-0.5)

//        For 180 degree rortation viewceenter(-1,0,0)
//        position of camera (0.5,0.25,0)

//        For 90 deg rot viewcenter(0,0,-1)
//        pos of cam (0,0.25,0.5)



//DATAS


//INITIAL
//Player_Position[0]=QVector3D(-8,0.1f,0.125f);
//Camera_Position[0]=QVector3D(-8.5,0.20f,0.125);
//Camera_Viewcenter[0]=QVector3D(-7,-0.05f,0.125f);

//Player_animation(QVector3D(-6.62,0.1f,0.125),0);

//1
//Rotation_Player(-90,0);
//Player_animation(QVector3D(-6.62f,0.1f,0.125f+3.8f),0);

//2
//Rotation_Player(0,0);
//Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f),0);

//3
//Rotation_Player(90,0);
//Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f-1.8f),0);

//4
//Rotation_Player(180,0);
//Player_animation(QVector3D(-1.7f,0.1f,0.125f+3.8f-1.8f),0);

//5
//Rotation_Player(90,0);
//Player_animation(QVector3D(-1.7f,0.1f,0.125f),0);

//6
//Rotation_Player(0,0);
//Player_animation(QVector3D(1.95f,0.1f,0.125f),0);

//7
//Rotation_Player(90,0);
//Player_animation(QVector3D(1.95f,0.1f,-1.7f),0);

//8
//Rotation_Player(180,0);
//Player_animation(QVector3D(-5.80f,0.1f,-1.7f),0);

//9
//Rotation_Player(90,0);
// Player_animation(QVector3D(-5.80f,0.1f,-1.7f-1.866f),0);

//10
//Rotation_Player(0,0);
//Player_animation(QVector3D(5.8f,0.1f,-1.7f-1.866f),0);

//11
//Rotation_Player(90,0);
//Player_animation(QVector3D(5.8f,0.1f,-1.7f-3.8f),0);

//12
//Rotation_Player(180,0);
//Player_animation(QVector3D(1.9f,0.1f,-1.7f-3.8f),0);

//13
//Rotation_Player(-90,0);
//Player_animation(QVector3D(1.9f,0.1f,-1.7f-2.8f),0);

//14
//Rotation_Player(180,0);
//Player_animation(QVector3D(-4.5f,0.1f,-1.7f-2.8f),0);

//15
//Rotation_Player(90,0);
//Player_animation(QVector3D(-4.5f,0.1f,-1.7f-4.1f),0);

//16
//Rotation_Player(0,0);
//Player_animation(QVector3D(2.0f,0.1f,-1.7f-4.1f),0);

//17
//Rotation_Player(90,0);
//Player_animation(QVector3D(2.0f,0.1f,-1.7f-6.1f),0);

Base_ui::~Base_ui()
{
    delete view;
    delete Prison;
    delete Player[2];
    delete Playeranimation;
    delete sceneRoot;
    delete cameraEntity;
    delete lightEntity;
    delete camController;
    delete group;
    delete Playeranimation;
    delete Cameraanimation;
    delete Cameraanimation1;
}

void Base_ui::Player_movement(int Position , int End,int Player_number)  //Get the current player position and final position
{

    this->Position=End;
    this->count=Position;
    delete Animation;
    Animation= new QSequentialAnimationGroup(this);

//    Animation_fun(Player_number);

//    Animation->start();
//    QObject::connect(Animation,SIGNAL(finished()),this,SLOT(Focus_fun()));
    Focus_fun();

}


void Base_ui::Animation_fun(int Number)
{
    int Position;
    Position=this->Position;

    if(count<=Position)
    {
       Player_animation(QVector3D(-6.62f,0.1f,0.125f),Number);
       count++;
    }
    if(count<=Position)
    {
        Rotation_Player(-90,Number);
        Player_animation(QVector3D(-6.62f,0.1f,0.125f+3.8f),Number);
        Position-=1;
        count++;
    }

    if(count<=Position)
    {
        Rotation_Player(0,Number);
        Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f),Number);
        count++;
     }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f-1.8f),Number);
        count++;

    }
    if(count<=Position)
    {
        Rotation_Player(180,Number);
        Player_animation(QVector3D(-1.7f,0.1f,0.125f+3.8f-1.8f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(-1.7f,0.1f,0.125f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(0,Number);
        Player_animation(QVector3D(1.95f,0.1f,0.125f),Number);
        count++;

    }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(1.95f,0.1f,-1.7f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(180,Number);
        Player_animation(QVector3D(-5.80f,0.1f,-1.7f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(-5.80f,0.1f,-1.7f-1.866f),Number);
        count++;

    }
    if(count<=Position)
    {
        Rotation_Player(0,Number);
        Player_animation(QVector3D(5.8f,0.1f,-1.7f-1.866f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(5.8f,0.1f,-1.7f-3.8f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(180,Number);
        Player_animation(QVector3D(1.9f,0.1f,-1.7f-3.8f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(-90,Number);
        Player_animation(QVector3D(1.9f,0.1f,-1.7f-2.8f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(180,Number);
        Player_animation(QVector3D(-4.5f,0.1f,-1.7f-2.8f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(-4.5f,0.1f,-1.7f-4.1f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(0,Number);
        Player_animation(QVector3D(2.0f,0.1f,-1.7f-4.1f),Number);
        count++;
    }
    if(count<=Position)
    {
        Rotation_Player(90,Number);
        Player_animation(QVector3D(2.0f,0.1f,-1.7f-6.1f),Number);
        count++;
    }

}




