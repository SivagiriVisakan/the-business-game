#include "Start_page.h"
#include "ui_Start_page.h"

Start_page::Start_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start_page)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    music=new MusicControls(this);
    Ui_Player=new Player_selection();
    Ui_Player->hide();
}

Start_page::~Start_page()
{
    delete ui;

}

void Start_page::on_Start_button_clicked()
{
    this->hide();
    Ui_Player->show();
    this->close();
}

void Start_page::on_Settings_button_clicked()
{
       music->show();
}
