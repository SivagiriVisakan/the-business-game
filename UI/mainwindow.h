#ifndef UI_FOR_MAINWINDOW_H
#define UI_FOR_MAINWINDOW_H

#include <QMainWindow>
#include"base_ui.h"

#include "cube_ui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Gameplay_ui();

private slots:
    void on_RollDIces_clicked();

private:
    Ui::MainWindow *ui;

    QWidget *Ui_board ;

    Base_ui Board;

    Cube_ui *cube;
};

#endif // UI_FOR_MAINWINDOW_H