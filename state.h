#ifndef STATE_H
#define STATE_H

#include <QObject>
#include<QPixmap>
#include<QString>
#include "level.h"
class Screen{
private:
    int screen;

public:
    Screen(){}
    Screen(int s){screen=s;}
    Screen(Prolog_scene prolog){this->screen=(int)prolog;}
    Screen(TeaWalk_scene teawalk){this->screen=(int)teawalk;}
    Screen(zoo_scene zoo){this->screen=(int)zoo;}
    int getScreen(){return screen;}

};
inline Screen& operator++(Screen& mode, const int){
    mode = static_cast<Screen>((mode.getScreen() + 1));
    return mode;
}
class Scene: public QObject{
    Q_OBJECT
public:
        explicit Scene(QObject *parent = nullptr);
        Scene(Level l,Screen s);
    Level level;
    Screen screen;
    QString gameText;
    QPixmap img;

    void setLevelAndScene(Level l, Screen s);
    void incrementScene();
    void incrementLevel();
};
#endif // STATE_H
