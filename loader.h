#ifndef LOADER_H
#define LOADER_H

#include <QObject>
#include<QThread>
#include<QCoreApplication>
#include <QMap>
#include<QPixmap>
#include<QDebug>
#include"level.h"
class Loader : public QObject
{
    Q_OBJECT
public:
    explicit Loader(QObject *parent = nullptr);

    void loadLevel1(Level level){
//        for(int i=0;i<100;i++){
//            QThread::msleep(20);
//            QCoreApplication::instance()->processEvents(QEventLoop::AllEvents);
//        }
        qDebug()<<"Loading "<<level;
        map->clear();
        if (level==Level::PROLOG){
            load(":/img/level0/cloud.png");
            load(":/img/level0/garden-refuge-captivating-bee-house-scenes-ai-generative-free-png.webp");

            load(":/img/level0/heart-background-photography.png");

            load(":/img/level0/honey-and-honeycombs-illustration.png");

            load(":/img/level0/rain.png");

            load(":/img/level0/sun.png");

            load(":/img/level0/tablo2_with_sale_text.png");

            load(":/img/level0/tent.png");

            load(":/img/level0/umbrella.png");
        }
        if (level==Level::TEA_WALK){
            load(":/img/level1/ball_activity.png");
            load(":/img/level1/barmen.png");

            load(":/img/level1/caffe.png");

            load(":/img/level1/coin1.png");

            load(":/img/level1/coin2.png");

            load(":/img/level1/interer.webp");

            load(":/img/level1/pretty_caffe.png");

        }
        if (level==Level::ZOO){
            load(":/img/level2/bird.png");
            load(":/img/level2/campaing.png");

            load(":/img/level2/elephant.png");

            load(":/img/level2/lion.png");

            load(":/img/level2/zoo.png");

            load(":/img/level2/zoo_derector.webp");

        }

        if (level==Level::VOYAGE){
            load(":/img/level3/suitcase.webp");
            load(":/img/level3/PollyList.webp");

            load(":/img/level3/LollyList.webp");

            load(":/img/level3/TrollyList.webp");

        }

    }

    QPixmap getRes(QString resPath){
        return map->find(resPath).value();
    }
    bool contains(QString resPath){
        return map->contains(resPath);
    }
private:
    QMap<QString,QPixmap> *map;
    void load(QString resPath){
        //insert to map
        QPixmap img;
        img.load(resPath);
        map->insert(resPath, img);
        //for progress resolving
        QCoreApplication::instance()->processEvents(QEventLoop::AllEvents);
    }



};

#endif // LOADER_H
