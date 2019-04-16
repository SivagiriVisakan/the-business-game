#ifndef TOKEN_H
#define TOKEN_H

#include "../core/Company.h"
#include "../core/NonBuyableField.h"
#include <QDialog>

namespace Ui {
class Token;
}

class Token : public QDialog
{
    Q_OBJECT

public:
    explicit Token(QWidget *parent = nullptr);
    void setCompanyName(QString);
    ~Token();

    void setDetails(BuyableField*,bool);
    void setDetails(NonBuyableField*);

private slots:
    void on_BuySell_clicked();

signals:
    void buySignal();


private:
    Ui::Token *ui;

    friend class Base_ui;
};

#endif // TOKEN_H
