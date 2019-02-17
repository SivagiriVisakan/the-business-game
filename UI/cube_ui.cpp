#include "cube_ui.h"
#include "ui_cube_ui.h"

Cube_ui::Cube_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cube_ui)
{
    ui->setupUi(this);

    sceneRoot = new Qt3DCore::QEntity();


    Dice1=new Resources_ui(sceneRoot);

    Dice1-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/dices.obj")));

    Dice1->Resources_transform->setScale(3.0f);       // size
    Dice1->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 90.0f)); // x,y,z axis and degree rotation
    Dice1->Resources_transform->setTranslation(QVector3D(-4.0f, 2.0f, -0.0f));

    Dice1->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

    Dice1->Add_resources_components();


    Dice2=new Resources_ui(sceneRoot);

    Dice2-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/dices.obj")));

    Dice2->Resources_transform->setScale(3.0f);       // size
    Dice2->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 1.0f, 1.0f), 360.0f)); // x,y,z axis and degree rotation
    Dice2->Resources_transform->setTranslation(QVector3D(3.0f, 2.0f, -0.0f));

    Dice2->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/Palette.jpg")));

    Dice2->Add_resources_components();

    Setup_ui();
}

Cube_ui::~Cube_ui()
{
    delete ui;
}

void Cube_ui::Setup_ui()
{
    view = new Qt3DExtras::Qt3DWindow();  // 3d window
    view->defaultFrameGraph()->setClearColor(QColor("black"));
    view->setFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    view->setWidth(700);
    view->setHeight(500);

     cameraEntity = view->camera();

    cameraEntity->lens()->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    cameraEntity->setUpVector(QVector3D(0.0f, 1.0f,0.0f));
    cameraEntity->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));
    cameraEntity->setPosition(QVector3D(5.0f,  24.0f, 25.0f));


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



    ui->Dice_widget= QWidget::createWindowContainer(view,this);
    QSize screenSize = view->screen()->size();
    ui->Dice_widget->setMinimumSize(QSize(700,500));
    ui->Dice_widget->setMaximumSize(screenSize);

    view->setRootEntity(sceneRoot);

    ui->Dice_widget->show();
}

// ///////rotate 90 with z  1
///Dices present Number 2
///Dices rotate 90 with x 3
///       270 with x 4
///      180 with x 5
///      270 with z 6

void Cube_ui::Roll_Dices(int number1,int number2)
{

    Playeranimation =new QPropertyAnimation(Dice1->Resources_transform,"rotation");
    Playeranimation->setDuration(200);
    Playeranimation->setStartValue(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 90.0f));
    Playeranimation->setEndValue(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 90.0f));
    Playeranimation->setEasingCurve(QEasingCurve::InBounce);
    Playeranimation->setLoopCount(-1);
    Playeranimation->start();

//    Playeranimation =new QPropertyAnimation(Player[Player_number]->Resources_transform,"translation");
//    Playeranimation->setDuration(5000);
//    Playeranimation->setStartValue(0);
//    Playeranimation->setEndValue(90);
//    Playeranimation->setEasingCurve(QEasingCurve::InBounce);
//    Playeranimation->setLoopCount(10);
//    Playeranimation->start();

}
