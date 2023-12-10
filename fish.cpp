#include "fish.h"

Fish::Fish(FishAnimation *animation, int x, int y)
{
    this->animation = animation;
    this->x = x;
    this->y = y;
}

void Fish::nextStep()
{
    if(moveSteps)
    {
        x += moveX;
        y += moveY;
        moveSteps--;
    }


    if(!moveSteps && !staySteps)
    {
        staySteps = rand() % (stayStepsMAX - stayStepsMIN + 1) + stayStepsMIN;
    }

    if(staySteps)
    {
        staySteps--;
    }



    if(currentFrame == animation->frames.size() - 1)
    {
        currentFrame = 0;
    }
    else
    {
        currentFrame++;
    }
}

void Fish::moveTo(int x, int y)
{
    double distance = sqrt(pow(this->x - x, 2) + pow(this->y - y,2));
    moveSteps = distance / speed;
    moveX = (x - this->x) / (float)moveSteps;
    moveY = (y - this->y) / (float)moveSteps;
}

void Fish::draw(QPainter *painter)
{
    painter->drawImage( x - animation->frames[currentFrame].width() / 2,
                        y - animation->frames[currentFrame].height() / 2,
                       (moveX < 0 ? animation->frames[currentFrame] :  animation->frames[currentFrame].mirrored(true, false)));
}

bool Fish::isMoving()
{
    return moveSteps | staySteps;
}
