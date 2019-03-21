#include "base_ui.h"

Base_ui::Base_ui()
{
    sceneRoot = new Qt3DCore::QEntity();
    City=new Resources_ui(sceneRoot);

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

    Animation= new QSequentialAnimationGroup(this);
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
    cameraEntity->setPosition(QVector3D(0.0f, 10.0f, 1.0f));

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
    camController = new Qt3DExtras::QFirstPersonCameraController(sceneRoot);
    camController->setCamera(cameraEntity);

    view->setRootEntity(sceneRoot);

}

void Base_ui::Players_ui_creater()
{


    Player_Position[0]=QVector3D(-8,0.1f,0.125f);
    Camera_Position[0]=QVector3D(-11.5,1.20f,0.125);
    Camera_Viewcenter[0]=QVector3D(-7,-0.05f,0.125f);


    Player_Position[1]=QVector3D(0,0.1f,0);
    Camera_Position[1]=QVector3D(-0.5,0.25f,0);
    Camera_Viewcenter[1]=QVector3D(1,0,0);


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

void Base_ui::Player_movement(int Position, int Player_number)
{
    Player_animation(QVector3D(-6.62f,0.1f,0.125f),0);

    count=1;
    fun();

    Animation->start();
}

void Base_ui::Player_animation(QVector3D Final_pos, int Player_number)
{
    Playeranimation =new QPropertyAnimation(Player[Player_number]->Resources_transform,"translation");
    Playeranimation->setDuration(5000);
    Playeranimation->setStartValue(Player_Position[Player_number]);
    Playeranimation->setEndValue(Final_pos);

    Cameraanimation =new QPropertyAnimation(cameraEntity,"viewCenter");
    Cameraanimation->setDuration(5000);
    Cameraanimation->setStartValue(Camera_Viewcenter[Player_number]);
    Cameraanimation->setEndValue((Final_pos-Player_Position[Player_number])+Camera_Viewcenter[Player_number]);

    Cameraanimation1 =new QPropertyAnimation(cameraEntity,"position");
    Cameraanimation1->setDuration(5000);
    Cameraanimation1->setStartValue(Camera_Position[Player_number]);
    Cameraanimation1->setEndValue((Final_pos-Player_Position[Player_number])+Camera_Position[Player_number]);

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
    Rotationplayer=new QPropertyAnimation(Player[Player_Number]->Resources_transform,"rotationY");
    Rotationplayer->setDuration(100);
    Rotationplayer->setStartValue(0);

    Rotationcamera =new QPropertyAnimation(cameraEntity,"viewCenter");
    Rotationcamera->setDuration(100);
    Rotationcamera->setStartValue(Camera_Viewcenter[Player_Number]);

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

void Base_ui::fun()
{
    if(count)
  {
    Rotation_Player(-90,0);
    Player_animation(QVector3D(-6.62f,0.1f,0.125f+3.8f),0);

    }

    if(count)
    {
        Rotation_Player(0,0);
        Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f),0);

     }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(1.55f,0.1f,0.125f+3.8f-1.8f),0);


    }
    if(count)
    {
        Rotation_Player(180,0);
        Player_animation(QVector3D(-1.7f,0.1f,0.125f+3.8f-1.8f),0);

    }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(-1.7f,0.1f,0.125f),0);

    }
    if(count)
    {
        Rotation_Player(0,0);
        Player_animation(QVector3D(1.95f,0.1f,0.125f),0);
    }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(1.95f,0.1f,-1.7f),0);

    }
    if(count)
    {
        Rotation_Player(180,0);
        Player_animation(QVector3D(-5.80f,0.1f,-1.7f),0);
    }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(-5.80f,0.1f,-1.7f-1.866f),0);
    }
    if(count)
    {
        Rotation_Player(0,0);
        Player_animation(QVector3D(5.8f,0.1f,-1.7f-1.866f),0);
    }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(5.8f,0.1f,-1.7f-3.8f),0);
    }
    if(count)
    {
        Rotation_Player(180,0);
        Player_animation(QVector3D(1.9f,0.1f,-1.7f-3.8f),0);
    }
    if(count)
    {
        Rotation_Player(-90,0);
        Player_animation(QVector3D(1.9f,0.1f,-1.7f-2.8f),0);
    }
    if(count)
    {
        Rotation_Player(180,0);
        Player_animation(QVector3D(-4.5f,0.1f,-1.7f-2.8f),0);

    }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(-4.5f,0.1f,-1.7f-4.1f),0);

    }
    if(count)
    {
        Rotation_Player(0,0);
        Player_animation(QVector3D(2.0f,0.1f,-1.7f-4.1f),0);
    }
    if(count)
    {
        Rotation_Player(90,0);
        Player_animation(QVector3D(2.0f,0.1f,-1.7f-6.1f),0);
         timer.stop();
    }

}


//dice  = 5
//count = 0
//position = 3
//data[] =
//        10
//for(int i=10; <index+5)
//if()
// move(data[i])

