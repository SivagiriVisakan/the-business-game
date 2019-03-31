#include "player_selection.h"
#include "ui_player_selection.h"

Player_selection::Player_selection(MusicControls &m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Player_selection)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    Ui_Window=new MainWindow(m);
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
    Ui_Window->Updatefun(ui->name1->text(),ui->name2->text());
    this->hide();
    Ui_Window->show();
    this->close();
}
