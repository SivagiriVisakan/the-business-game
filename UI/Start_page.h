#ifndef START_PAGE_H
#define START_PAGE_H

#include <QMainWindow>
#include"player_selection.h"
#include"musiccontrols.h"
#include<QCursor>
#include<QPixmap>
#include<QGraphicsBlurEffect>

namespace Ui {
class Start_page;
}

class Start_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start_page(MusicControls &,QWidget *parent = nullptr);
    ~Start_page();

private slots:
    void on_Start_button_clicked();
    void on_Settings_button_clicked();
    void off_blurness();


private:

    QGraphicsBlurEffect *effect;
    MusicControls *music;
    Ui::Start_page *ui;
    Player_selection *Ui_Player;
};

#endif // START_PAGE_H
