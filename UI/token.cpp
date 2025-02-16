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

void Token::setDetails(BuyableField *c,bool id)
{
    ui->Companyname->setText(c->getName());
    ui->Cost->setText("Cost: $ "+QString::number(c->getCost()));
    ui->Rent->setText("Rent: $ "+QString::number(c->getRent()));
    if(c->getOwnerId()!=-1 || !id)
    {
        ui->BuySell->hide();
    }
    else
    {
         ui->BuySell->show();
    }
    if(c->getOwnerId()==-1)
    {
        ui->OwnerLabel->setText("Not Yet Bought");
    }
    else {
        ui->OwnerLabel->setText("Owned by Player " + QString::number(c->getOwnerId()));
    }

}


void Token::setDetails(NonBuyableField *nbf)
{
    ui->Companyname->setText(nbf->getName());
    ui->Cost->setText("");
    if(nbf->getRent() < 0)
    {
        ui->Rent->setText("Rent: $ "+QString::number(nbf->getRent()));

    }
    else {
        ui->Rent->setText("You earned: $ "+QString::number(-nbf->getRent()));

    }
    ui->OwnerLabel->setText(nbf->getHelpText());
    ui->BuySell->hide();
\
}


void Token::on_BuySell_clicked()
{
    emit buySignal();
}

