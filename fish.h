#ifndef FISH_H
#define FISH_H
#include <QVector>
#include <QImage>
#include <QPainter>


class FishAnimation
{
public:
    QVector<QImage> frames;
};


class Fish
{
private:
    static const int stayStepsMAX = 20;
    static const int stayStepsMIN = 5;
    int currentFrame = 0;
    FishAnimation* animation;
    float x;
    float y;
    float moveX = 0;
    float moveY = 0;
    float speed = 3;
    int moveSteps = 0;
    int staySteps = 0;
public:
    Fish(FishAnimation* animation, int x = 0, int y = 0);
    void nextStep();
    void moveTo(int x, int y);
    void draw(QPainter* painter);
    bool isMoving();
};

#endif // FISH_H
