#include "gametask.h"

GameTask::GameTask(QObject *parent) : QObject(parent)
{
    this->level=Level::PROLOG;
    this->screen=Prolog_scene::Prolog_SinglePollyScene;
    this->screenSize = QSize(default_w,default_h);
}

GameTask::GameTask(Level l, Screen s)
{
    this->level=l;
    this->screen=s;
    this->screenSize = QSize(default_w,default_h);
}
