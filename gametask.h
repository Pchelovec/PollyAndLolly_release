#ifndef GAMETASK_H
#define GAMETASK_H

#include <QObject>
#include <QSize>
#include "level.h"
#include"state.h"
class GameTask : public QObject
{
    Q_OBJECT
public:
    explicit GameTask(QObject *parent = nullptr);
    GameTask(Level l,Screen s);
    Level level;
    Screen screen;
    QSize screenSize;

private:
    int default_w=400;
    int default_h=600;
};

#endif // GAMETASK_H
