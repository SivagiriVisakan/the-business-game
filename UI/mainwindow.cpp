#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Ui_board;

}

void MainWindow::Gameplay_ui()
{
    this->setWindowFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    Board.Setup_ui();
    Board.Players_ui_creater();
    Board.Board_rotate();
    Board.Player_animation(QVector3D(0,0,0),QVector3D(2,0,0),1);
    Board.Player_animation(QVector3D(0,0,0),QVector3D(2,0,0),0);

    ui->Ui_board= QWidget::createWindowContainer(Board.view,this);
    QSize screenSize = Board.view->screen()->size();
    ui->Ui_board->setMinimumSize(QSize(1470,1000));
    ui->Ui_board->setMaximumSize(screenSize);

    ui->Ui_board->show();



    this->show();
}


void MainWindow::on_RollDIces_clicked()
{
    cube=new Cube_ui (this);
    cube->Roll_Dices(1,1);
    cube->show();
}
