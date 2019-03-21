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
    ~Token();

private:
    Ui::Token *ui;
};

#endif // TOKEN_H
