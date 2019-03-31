#ifndef MAP_H
#define MAP_H

#include <QDialog>

namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

private slots:
    void on_ok_clicked();

signals:
    void close_();


private:
    Ui::Map *ui;
};

#endif // MAP_H
