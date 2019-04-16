#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MusicControls &m,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    token=new Token(this);
    ui->setupUi(this);

    music=&m;

    Board=new Base_ui(game);

    map=new Map();

    effect=new QGraphicsBlurEffect(this);

    setGraphicsEffect(effect);
    effect->setEnabled(false);

    message=new QMessageBox(this);
    message->setStyleSheet("background-color:white");
    connect(token,&Token::buySignal,this,&MainWindow::buyclicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete Ui_board;
    delete map;
    delete token;
    delete message;
}

void MainWindow::Gameplay_ui()
{
    this->setWindowFlag(Qt::FramelessWindowHint,Qt::KeepAspectRatio);
    Board->Setup_ui();
    Board->Players_ui_creater();

    ui->Ui_board= QWidget::createWindowContainer(Board->view,this);
    QSize screenSize = Board->view->screen()->size();
    ui->Ui_board->setMinimumSize(QSize(1470,1000));
    ui->Ui_board->setMaximumSize(screenSize);

    ui->Ui_board->show();
    this->show();
}

void MainWindow::UpdateMoney()
{
    ui->Money_1->setText(QString::number(game.getPlayerFromId(0).getMoney()));
    ui->Money_2->setText(QString::number(game.getPlayerFromId(1).getMoney()));
}

void MainWindow::Updatefun(QString Name1, QString Name2)
{
    game.addPlayer(Name1.toStdString());
    game.addPlayer(Name2.toStdString());
    ui->Name_1->setText(Name1);
    ui->Name_2->setText(Name2);
    game.initializeGame(); // Call this method to reset the game.
}


void MainWindow::on_RollDIces_clicked()
{

    cube=new Cube_ui (this);

    effect->setEnabled(true);

    cube->show();

    cube->setWindowState(Qt::WindowActive);
    cube->setFocus();

    dice1 = game.rollDice();
    dice2= game.rollDice();

    cube->Roll_Dices(dice1,dice2);

    DicesTimer=new QTimer(cube);
    DicesTimer->start(3500);
    connect(DicesTimer,SIGNAL(timeout()),this,SLOT(Dice_fun()));
}

void MainWindow::on_Map_Button_clicked()
{
    effect->setEnabled(true);

    map->setGeometry(0,0,1470,1000);
    map->show();

     connect(map,SIGNAL(close_()),this,SLOT(off_blurness()));

}

void MainWindow::Dice_fun()
{
    DicesTimer->stop();
    cube->close();
    effect->setEnabled(false);
    delete cube;
    int b = game.getBoard().getIndexOfField(game.getFieldOfCurrentPlayer());
    game.updateCurrentPlayerPosition(dice1+dice2);
    int m=game.getBoard().getIndexOfField(game.getFieldOfCurrentPlayer());
    Board->Player_movement(b+1,m,game.getCurrentPlayer().getId());
    UpdateMoney();
    if(game.getCurrentPlayer().getId()==0)
        ui->field_name_1->setText(game.getFieldOfCurrentPlayer()->getName());
    else if(game.getCurrentPlayer().getId()==1)
        ui->field_name_2->setText(game.getFieldOfCurrentPlayer()->getName());

    Field *f=game.getFieldOfCurrentPlayer();
    if(dynamic_cast<NonBuyableField*>(f))
    {
        NonBuyableField *nbf = dynamic_cast<NonBuyableField*>(f);
         message->setText(QString(nbf->getHelpText()));
         message->show();
     }

}



void MainWindow::on_Volume_button_clicked()
{
    effect->setEnabled(true);
    music->show();
    connect(music,SIGNAL(close_()),this,SLOT(off_blurness()));

}

void MainWindow::buyclicked()
{
    try{

    Field *f=game.getFieldOfCurrentPlayer();
    if(dynamic_cast<BuyableField*>(f))
    {
        BuyableField *bf = dynamic_cast<BuyableField*>(f);

         game.buyCompany(game.getCurrentPlayer().getId(), *bf);

         message->setText("Congrats You Have Succesfully Bought "+QString(bf->getName()));
         message->show();

         }
    }
        catch(int i){
            if(i == 1)
            {
                message->setText("Sorry,Not Buyable (Already Owned)");
                message->show();
            }
            else if (i==2) {

                message->setText("Sorry You Don't Have Sufficient Balance");
                message->show();

            }
        }
        catch(...)
        {
            message->setText("Sufficient Balance");
            message->show();

        }
        UpdateMoney();



}

void MainWindow::off_blurness()
{
      effect->setEnabled(false);
}

void MainWindow::on_Turn_button_clicked()
{
    game.changeTurn();
}


void MainWindow::on_CurrentToken_1_clicked()
{
    Field *f=game.getBoard().getCurrentFieldOfPlayer(0);

//    if(dynamic_cast<Company*>(f))
//    {
//        Company *c=dynamic_cast<Company*>(f);
//        token->setDetails(*c, game.getCurrentPlayer().getId() == 0);
//        token->show();
//      }
    if(dynamic_cast<BuyableField*>(f))
    {

        BuyableField *c=dynamic_cast<BuyableField*>(f);
        token->setDetails(c, game.getCurrentPlayer().getId() == 0);
        token->show();
    }
    else if(dynamic_cast<NonBuyableField*>(f))
    {

        NonBuyableField *nbf=dynamic_cast<NonBuyableField*>(f);
        token->setDetails(nbf);
        token->show();
    }
}


void MainWindow::on_CurrentToken_2_clicked()
{
    Field *f=game.getBoard().getCurrentFieldOfPlayer(1);
    if(dynamic_cast<BuyableField*>(f))
    {

        BuyableField *c=dynamic_cast<BuyableField*>(f);
        token->setDetails(c, game.getCurrentPlayer().getId() == 1);
        token->show();
    }
    else if(dynamic_cast<NonBuyableField*>(f))
    {

        NonBuyableField *nbf=dynamic_cast<NonBuyableField*>(f);
        token->setDetails(nbf);
        token->show();
    }
}
