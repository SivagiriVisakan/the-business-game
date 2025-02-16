#ifndef CUBE_UI_H
#define CUBE_UI_H

#include"resources_ui.h"
#include <QDialog>
#include<QTimer>

namespace Ui {
class Cube_ui;
}

class Cube_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Cube_ui(QWidget *parent = nullptr);
    ~Cube_ui();

    void Setup_ui();
    void Roll_Dices(int number1,int number2);
public slots:
    void Rolling_fun();

private:
    Ui::Cube_ui *ui;
    Resources_ui *Dice1,*Dice2;
    QWidget *Dice_widget;
    int roll,count,x1,x2,z1,z2;

    Qt3DCore::QEntity *sceneRoot ;
    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity ;
    Qt3DExtras::QFirstPersonCameraController *camController;
     Qt3DExtras::Qt3DWindow *view;
    QTimer * Diceanimation;
};

#endif // CUBE_UI_H
