
#include<QApplication>
#include<QDebug>
#include"Start_page.h"

#include"mainwindow.h"


#include"token.h"



int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
//    MainWindow *Ui_Window;
//    Ui_Window=new MainWindow();
//    Ui_Window->Gameplay_ui();
//    Ui_Window->show();
    Start_page w;
    w.show();
    Token a;
    a.show();
    return app.exec();
}
