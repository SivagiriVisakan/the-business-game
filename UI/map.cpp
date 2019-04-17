#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    this->setGeometry(235,0,990,1000);
    this->setWindowFlags(Qt::FramelessWindowHint);

    for(int i=0; i < 5; i++)
    {
        for(int j=0; j < 6; j++)
        {
            int index = (i*6) + j + 1;
            btns[index] = (QPushButton*)ui->map_grid_layout->itemAtPosition(i,j)->widget();
            btns[index]->setMinimumHeight(150);

            QString path = "border-image: url(:/new/prefix1/Logos/" + QString::number(index-1) +".png);";
            btns[index]->setStyleSheet(path);
            btns[index]->setText("");
        }
    }
    for(int j=0; j < 3; j++)
    {
        int index = (5*6) + j + 1;
        btns[index] = (QPushButton*)ui->map_grid_layout->itemAtPosition(5,j)->widget();
        btns[index]->setMinimumHeight(150);

        QString path = "border-image: url(:/new/prefix1/Logos/" + QString::number(index-1) +".png);";
        btns[index]->setStyleSheet(path);
        btns[index]->setText("");
    }

}



Map::~Map()
{
    delete ui;
}

void Map::on_ok_clicked()
{
    this->close();
    emit close_();
}

