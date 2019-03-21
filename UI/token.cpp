#include "token.h"
#include "ui_token.h"

Token::Token(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Token)
{
    ui->setupUi(this);
}

Token::~Token()
{
    delete ui;
}
