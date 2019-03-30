#include "token.h"
#include "ui_token.h"

Token::Token(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Token)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
}

Token::~Token()
{
    delete ui;
}

void Token::on_BuySell_clicked()
{
    QString source;

   source="qrc:/board_";
   source+=char(1+'0');
   source+=".obj";
    ui->Companyname->setText(source);
}
