#include "musiccontrols.h"
#include "ui_musiccontrols.h"

MusicControls::MusicControls(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusicControls)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    player1 = new QMediaPlayer(this);
    player2 = new QMediaPlayer(this);

    playlist = new QMediaPlaylist(this);

    playlist->addMedia(QUrl("qrc:/Theme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player1->setPlaylist(playlist);
    player1->play();
}

MusicControls::~MusicControls()
{
    delete ui;
}


void MusicControls::playmusic(QUrl url)
{
     player2->setMedia(url);
     player2->play();
}

void MusicControls::pause(int i)
{
    if(i==1)
        player1->pause();
    else if(i==2)
        player2->pause();
}

void MusicControls::play(int i)
{
    if(i==1)
        player1->play();
    else if(i==2)
        player2->play();
}

void MusicControls::on_sliderVolume_sliderMoved(int position)
{
    player1->setVolume(position);
    player2->setVolume(position);
}

void MusicControls::on_pushButton_clicked()
{
    emit close_();
    this->hide();
}
