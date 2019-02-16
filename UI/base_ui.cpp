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
}

void Base_ui::Setup_ui()
{

    view = new Qt3DExtras::Qt3DWindow();  // 3d window
    view->defaultFrameGraph()->setClearColor(QColor("black"));
    view->setFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    view->setWidth(1470);
    view->setHeight(1000);
//    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
//   view->registerAspect(input);

     cameraEntity = view->camera();

    cameraEntity->lens()->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    cameraEntity->setUpVector(QVector3D(0.0f, 1.0f,0.0f));
    cameraEntity->setViewCenter(QVector3D(0.0f, -0.0f, 0.0f));
    cameraEntity->setPosition(QVector3D(0.0f, 5.0f, 5.0f));
    cameraEntity->rotate(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), -3.0f));

    lightEntity = new Qt3DCore::QEntity(sceneRoot);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(5);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
   lightEntity->addComponent(lightTransform);

//    For camera controls
    camController = new Qt3DExtras::QFirstPersonCameraController(sceneRoot);
    camController->setCamera(cameraEntity);

    view->setRootEntity(sceneRoot);
//    view->show();

}

void Base_ui::Board_rotate()
{
    City->Resources_transform->setRotationY(180);
}

void Base_ui::Players_ui_creater()
{

            Player[0]=new Resources_ui(Prison->Resources_Entity);

            Player[0]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/car2_1.obj")));

            Player[0]->Resources_transform->setScale(1.00f);       // size
            Player[0]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f),- 90.0f)); // x,y,z axis and degree rotation
            Player[0]->Resources_transform->setTranslation(QVector3D(0.0f, 0.14f, 0.0f));

            Player[0]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

            Player[0]->Add_resources_components();

            Player[1]=new Resources_ui(Prison->Resources_Entity);

            Player[1]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/car2_2.obj")));

            Player[1]->Resources_transform->setScale(1.80f);       // size
            Player[1]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90.0f)); // x,y,z axis and degree rotation
            Player[1]->Resources_transform->setTranslation(QVector3D(-0.7f, 0.14f, 0.0f));

            Player[1]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

            Player[1]->Add_resources_components();


}

void Base_ui::Player_animation(QVector3D Current_pos, QVector3D Final_pos, int Player_number)
{
    Playeranimation =new QPropertyAnimation(Player[Player_number]->Resources_transform,"translation");
    Playeranimation->setDuration(5000);
    Playeranimation->setStartValue(Current_pos);
    Playeranimation->setEndValue(Final_pos);
    Playeranimation->setEasingCurve(QEasingCurve::InBounce);
    Playeranimation->setLoopCount(10);
    Playeranimation->start();
}

Base_ui::~Base_ui()
{
    delete view;
    delete Prison;
    delete Player[3];
    delete Playeranimation;
    delete sceneRoot;
    delete cameraEntity;
    delete lightEntity;
    delete camController;
}
