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

void Token::setDetails(Company c)
{
    ui->Companyname->setText(c.getName());
    ui->Cost->setText("Cost: $ "+QString::number(c.getCost()));
    ui->Rent->setText("Rent: $ "+QString::number(c.getRent()));

}
Token::~Token()
{
    delete ui;
}

