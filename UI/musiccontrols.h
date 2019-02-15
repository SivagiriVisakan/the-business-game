#ifndef MUSICCONTROLS_H
#define MUSICCONTROLS_H

#include <QDialog>
#include<QMediaPlayer>
#include<QMediaPlaylist>

namespace Ui {
class MusicControls;
}

class MusicControls : public QDialog
{
    Q_OBJECT

public:
    explicit MusicControls(QWidget *parent = nullptr);
    ~MusicControls();

    void playmusic(QUrl);
    void pause(int);
    void play(int);


private slots:

    void on_sliderVolume_sliderMoved(int position);

    void on_pushButton_clicked();

private:
    Ui::MusicControls *ui;
    QMediaPlayer* player1,* player2;
    QMediaPlaylist *playlist;
};

#endif // MUSICCONTROLS_H
