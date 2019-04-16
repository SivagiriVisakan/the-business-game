#ifndef TOKEN_H
#define TOKEN_H

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


private:
    Ui::Token *ui;

    friend class Base_ui;
};

#endif // TOKEN_H
