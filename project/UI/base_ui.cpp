#include "base_ui.h"

Base_ui::Base_ui()
{
    sceneRoot = new Qt3DCore::QEntity();
    Table=new Resources_ui(sceneRoot);

    Table-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/123.obj")));

    Table->Resources_transform->setScale(1.00f);       // size
    Table->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    Table->Resources_transform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Table->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/Palette.jpg")));

    Table->Add_resources_components();


    BaseBoard=new Resources_ui(Table->Resources_Entity);

    BaseBoard-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/tab.obj")));

    BaseBoard->Resources_transform->setScale(1.00f);       // size
    BaseBoard->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
    BaseBoard->Resources_transform->setTranslation(QVector3D(0.0f, 0.07f, 0.0f));

    BaseBoard->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/519187-PJUJ2Y-348.jpg")));

//    BaseBoard->Add_resources_components();



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
    cameraEntity->setViewCenter(QVector3D(0.0f, -0.75f, 0.0f));
    cameraEntity->setPosition(QVector3D(0.0f, 15.0f, 22.0f));
    cameraEntity->rotate(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), -3.0f));

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
    Table->Resources_transform->setRotationY(90+90);
}

void Base_ui::Players_ui_creater(int number_male1, int number_male2, int number_female)
{
        if(number_male1)
        {
            Player[0]=new Resources_ui(BaseBoard->Resources_Entity);

            Player[0]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/man1.obj")));

            Player[0]->Resources_transform->setScale(1.00f);       // size
            Player[0]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f),- 90.0f)); // x,y,z axis and degree rotation
            Player[0]->Resources_transform->setTranslation(QVector3D(0.0f, 0.14f, 0.0f));

            Player[0]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/man1_texture.jpg")));

            Player[0]->Add_resources_components();
        }
        if(number_male2)
        {

            Player[1]=new Resources_ui(BaseBoard->Resources_Entity);

            Player[1]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/man_2.obj")));

            Player[1]->Resources_transform->setScale(1.80f);       // size
            Player[1]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90.0f)); // x,y,z axis and degree rotation
            Player[1]->Resources_transform->setTranslation(QVector3D(-0.7f, 0.14f, 0.0f));

            Player[1]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/man_2.jpg")));

            Player[1]->Add_resources_components();

        }
        if(number_female)
        {
            Player[2]=new Resources_ui(BaseBoard->Resources_Entity);

            Player[2]-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/man_2.obj")));

            Player[2]->Resources_transform->setScale(1.80f);       // size
            Player[2]->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f)); // x,y,z axis and degree rotation
            Player[2]->Resources_transform->setTranslation(QVector3D(-0.7f, 0.14f, 0.30f));

            Player[2]->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/man_2.jpg")));

            Player[2]->Add_resources_components();

        }
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
    delete BaseBoard;
    delete Player[3];
    delete Playeranimation;
    delete sceneRoot;
    delete cameraEntity;
    delete lightEntity;
    delete camController;
}
