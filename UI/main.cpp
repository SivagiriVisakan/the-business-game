
#include<QApplication>
#include<QDebug>
#include"Start_page.h"








int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Start_page w;
    w.show();

    return app.exec();
}
