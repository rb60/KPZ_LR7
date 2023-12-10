#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fish.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent* pe);
    virtual void timerEvent(QTimerEvent*);
    ~MainWindow();
    static const int COUNT = 300;

private:
    Fish* fishes[COUNT];
    FishAnimation* animations[3];
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
