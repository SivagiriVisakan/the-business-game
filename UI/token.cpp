#include "token.h"
#include "ui_token.h"

Token::Token(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Token)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
}

void Token::setCompanyName(QString m)
{
    ui->Companyname->setText(m);
}

Token::~Token()
{
    delete ui;
}

