#include "Start_page.h"
#include "ui_Start_page.h"

Start_page::Start_page(MusicControls &m,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start_page)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    music=&m;
    Ui_Player=new Player_selection(m);
    Ui_Player->hide();

    effect = new QGraphicsBlurEffect(this) ;
    setGraphicsEffect(effect);
    effect->setEnabled(false);
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

     effect->setEnabled(true);



      music->show();
      connect(music,SIGNAL(close_()),this,SLOT(off_blurness()));

}

void Start_page::off_blurness()
{
        effect->setEnabled(false);
}
