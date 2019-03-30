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

void MainWindow::Updatefun(QString Name1, QString Name2)
{
    game.addPlayer("hi");
    game.addPlayer("bye");
    ui->label->setText(Name1);
    ui->label_2->setText(Name2);
    game.initializeGame(); // Call this method to reset the game.
}


void MainWindow::on_RollDIces_clicked()
{
    cube=new Cube_ui (this);
    cube->show();

    int dice1 = game.rollDice();
    int dice2= game.rollDice();

    cube->Roll_Dices(dice1,dice2);

    DicesTimer=new QTimer(cube);
    DicesTimer->start(3500);
    connect(DicesTimer,SIGNAL(timeout()),this,SLOT(Dice_fun()));

}

void MainWindow::on_Map_Button_clicked()
{
    m->show();
}

void MainWindow::Dice_fun()
{
    DicesTimer->stop();
    cube->close();
    delete cube;
    Board.Player_movement(0,0);
    game.updateCurrentPlayerPosition(1+1);
}

void MainWindow::on_pushButton_7_clicked()
{

    Board.function_setpos(QVector3D((ui->lineEdit->displayText()).toFloat(),(ui->lineEdit_3->displayText()).toFloat(),(ui->lineEdit_4->displayText()).toFloat()),QVector3D((ui->lineEdit_2->displayText()).toFloat(),(ui->lineEdit_5->displayText()).toFloat(),(ui->lineEdit_6->displayText()).toFloat()));
}

void MainWindow::on_pushButton_8_clicked()
{
    QVector3D m=Board.function_getpos();

    QString n="x=";
    n+=QString::number(m.x());
    n+="\ny=";
    n+=QString::number(m.y());
    n+="\nz=";
    n+=QString::number(m.z());


    ui->label_8->setText(QString(n));
    ui->label_8->setTextInteractionFlags(Qt::TextSelectableByMouse);

    QVector3D k=Board.function_getview();

    QString l="x=";
    l+=QString::number(k.x());
    l+="\ny=";
    l+=QString::number(k.y());
    l+="\nz=";
    l+=QString::number(k.z());

    ui->label_9->setText(QString(l));
    ui->label_9->setTextInteractionFlags(Qt::TextSelectableByMouse);

}
