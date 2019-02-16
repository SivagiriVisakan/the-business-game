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


}

Player_selection::~Player_selection()
{
    delete ui;
    delete Ui_Window;
}



void Player_selection::on_pushButton_clicked()
{
    this->close();

}

void Player_selection:: on_Gameplay_button_clicked()
{
    this->hide();
    Ui_Window->show();
    this->close();
}
