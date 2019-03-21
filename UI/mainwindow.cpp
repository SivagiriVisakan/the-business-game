#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m=new Map();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Ui_board;
    delete m;

}

void MainWindow::Gameplay_ui()
{
    this->setWindowFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    Board.Setup_ui();
    Board.Players_ui_creater();

    ui->Ui_board= QWidget::createWindowContainer(Board.view,this);
    QSize screenSize = Board.view->screen()->size();
    ui->Ui_board->setMinimumSize(QSize(1470,1000));
    ui->Ui_board->setMaximumSize(screenSize);

    ui->Ui_board->show();



    this->show();
}

void MainWindow::Updatefun(QString a, QString b)
{
    ui->label->setText(a);
    ui->label_2->setText(b);
}


void MainWindow::on_RollDIces_clicked()
{
    cube=new Cube_ui (this);
    cube->show();
    cube->Roll_Dices(4,6);
    Board.Player_movement(0,0);


}

void MainWindow::on_Map_Button_clicked()
{
    m->show();
}
