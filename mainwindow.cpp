#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    animations[0] = new FishAnimation;
    animations[0]->frames.append(QImage(":/frames/fish1frame1.png"));
    animations[0]->frames.append(QImage(":/frames/fish1frame2.png"));
    animations[0]->frames.append(QImage(":/frames/fish1frame3.png"));

    animations[1] = new FishAnimation;
    animations[1]->frames.append(QImage(":/frames/fish2frame1.png"));
    animations[1]->frames.append(QImage(":/frames/fish2frame2.png"));
    animations[1]->frames.append(QImage(":/frames/fish2frame3.png"));

    animations[2] = new FishAnimation;
    animations[2]->frames.append(QImage(":/frames/fish3frame1.png"));
    animations[2]->frames.append(QImage(":/frames/fish3frame2.png"));
    animations[2]->frames.append(QImage(":/frames/fish3frame3.png"));

    for(int i = 0; i < COUNT; i++)
    {
        fishes[i] = new Fish(animations[rand() % 3], rand() % this->width(), rand() % this->height());
    }
    startTimer(50);
}

void MainWindow::paintEvent(QPaintEvent *pe)
{
    QPainter* painter = new QPainter(this);
    painter->fillRect(0, 0, pe->rect().width(), pe->rect().height(), Qt::cyan);
    for(int i = 0; i < COUNT; i++)
    {
        fishes[i]->draw(painter);
    }
    painter->end();
    delete painter;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    for(int i = 0; i < COUNT; i++)
    {
        if(!fishes[i]->isMoving() && rand() % 20 < 3)
        {
            fishes[i]->moveTo(rand() % this->width(), rand() % this->height());
        }
        fishes[i]->nextStep();
    }
    update();
}

MainWindow::~MainWindow()
{
    for(int i = 0; i < COUNT; i++)
    {
        delete fishes[i];
    }

    for(int i = 0; i < 3; i++)
    {
        delete animations[i];
    }

    delete ui;
}

