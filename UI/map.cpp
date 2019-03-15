#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    this->setGeometry(235,0,990,1000);
    this->setWindowFlags(Qt::FramelessWindowHint);

}

Map::~Map()
{
    delete ui;
}
