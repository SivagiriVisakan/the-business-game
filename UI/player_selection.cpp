#include "player_selection.h"
#include "ui_player_selection.h"

Player_selection::Player_selection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Player_selection)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    Ui_Window=new MainWindow();
    Ui_Window->Gameplay_ui();
    Ui_Window->hide();

    Display_object1();
}

Player_selection::~Player_selection()
{
    delete ui;
    delete view1;
    delete view2;
    delete man_1;
    delete man_2;
    delete Playeranimation1;
    delete sceneRoot1;
    delete cameraEntity1;
    delete lightEntity1;
    delete camController1;
    delete Playeranimation2;
    delete sceneRoot2;
    delete cameraEntity2;
    delete lightEntity2;
    delete camController2;
    delete Ui_Window;
}

void Player_selection::Display_object1()
{
    sceneRoot1=new Qt3DCore::QEntity();
    view1 = new Qt3DExtras::Qt3DWindow();  // 3d window
    view1->defaultFrameGraph()->setClearColor(QColor("black"));
    view1->setFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    view1->setWidth(651);
    view1->setHeight(911);
    view1->setPosition(30,260);
    cameraEntity1 = view1->camera();

    cameraEntity1->lens()->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    cameraEntity1->setUpVector(QVector3D(0.0f, 1.0f,0.0f));
    cameraEntity1->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));
    cameraEntity1->setPosition(QVector3D(0.0f, 3.5f, 25.0f));
    cameraEntity1->rotate(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), -3.0f));

    lightEntity1 = new Qt3DCore::QEntity(sceneRoot1);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity1);
    light->setColor("white");
    light->setIntensity(5);
    lightEntity1->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity1);
    lightTransform->setTranslation(cameraEntity1->position());
   lightEntity1->addComponent(lightTransform);

//    For camera controls
    camController1 = new Qt3DExtras::QFirstPersonCameraController(sceneRoot1);
    camController1->setCamera(cameraEntity1);
    view1->setRootEntity(sceneRoot1);
    man_1=new Resources_ui(sceneRoot1);
    man_1-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/man1.obj")));
    man_1->Resources_transform->setScale(4.00f);       // size
    man_1->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f),0.0f)); // x,y,z axis and degree rotation
    man_1->Resources_transform->setTranslation(QVector3D(0.0f, -2.5f, 0.0f));
    man_1->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/man1_texture.jpg")));
    man_1->Add_resources_components();

    ui->Man_1= QWidget::createWindowContainer(view1,this);
    ui->Man_1->setGeometry(30,261,0,0);
    QSize screenSize = view1->screen()->size();
    ui->Man_1->setMinimumSize(QSize(911,651));
    ui->Man_1->setMaximumSize(screenSize);

    Playeranimation1 =new QPropertyAnimation(man_1->Resources_transform,"rotationY");
    Playeranimation1->setDuration(5000);
    Playeranimation1->setStartValue(0);
    Playeranimation1->setEndValue(360);
    Playeranimation1->setLoopCount(-1);
    Playeranimation1->start();
   Display_object2();
}

void Player_selection::Display_object2()
{

    sceneRoot2=new Qt3DCore::QEntity();
    view2 = new Qt3DExtras::Qt3DWindow();  // 3d window
    view2->defaultFrameGraph()->setClearColor(QColor("black"));
    view2->setFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    view2->setWidth(651);
    view2->setHeight(911);
    view2->setPosition(1000,260);
    cameraEntity2 = view2->camera();

    cameraEntity2->lens()->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    cameraEntity2->setUpVector(QVector3D(0.0f, 1.0f,0.0f));
    cameraEntity2->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));
    cameraEntity2->setPosition(QVector3D(0.0f, 3.5f, 25.0f));
    cameraEntity2->rotate(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), -3.0f));

    lightEntity2 = new Qt3DCore::QEntity(sceneRoot2);
    Qt3DRender::QPointLight *light1 = new Qt3DRender::QPointLight(lightEntity2);
    light1->setColor("white");
    light1->setIntensity(5);
    lightEntity2->addComponent(light1);
    Qt3DCore::QTransform *lightTransform1 = new Qt3DCore::QTransform(lightEntity2);
    lightTransform1->setTranslation(cameraEntity2->position());
   lightEntity2->addComponent(lightTransform1);

//    For camera controls
    camController2 = new Qt3DExtras::QFirstPersonCameraController(sceneRoot2);
    camController2->setCamera(cameraEntity2);
    view2->setRootEntity(sceneRoot2);
    man_2=new Resources_ui(sceneRoot2);
    man_2-> Resources_ui_mesh->setSource(QUrl(QStringLiteral("qrc:/man_2.obj")));
    man_2->Resources_transform->setScale(7.20f);       // size
    man_2->Resources_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f),0.0f)); // x,y,z axis and degree rotation
    man_2->Resources_transform->setTranslation(QVector3D(0.0f, -3.1f, 2.0f));
    man_2->Texture_loader->setSource(QUrl(QStringLiteral("qrc:/man_2.jpg")));
    man_2->Add_resources_components();

    ui->Man_2= QWidget::createWindowContainer(view2,this);
    ui->Man_2->setGeometry(1000,261,0,0);
    QSize screenSize1 = view2->screen()->size();
    ui->Man_2->setMinimumSize(QSize(911,651));
    ui->Man_2->setMaximumSize(screenSize1);

    Playeranimation2 =new QPropertyAnimation(man_2->Resources_transform,"rotationY");
    Playeranimation2->setDuration(5000);
    Playeranimation2->setStartValue(0);
    Playeranimation2->setEndValue(360);
    Playeranimation2->setLoopCount(-1);
    Playeranimation2->start();

}

void Player_selection::on_Gameplay_button_clicked()
{
    this->hide();
    Ui_Window->show();
    this->close();
}

void Player_selection::on_pushButton_clicked()
{
    this->close();
}
