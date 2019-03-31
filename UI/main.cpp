
#include<QApplication>
#include<QDebug>
#include"Start_page.h"

#include"mainwindow.h"

#include"musiccontrols.h"
#include"token.h"



int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MusicControls music;
//     music=new MusicControls();

    Start_page w(music);
    w.show();

    return app.exec();
}
