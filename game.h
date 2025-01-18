#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPixmap>
#include "state.h"
#include "gametask.h"
#include "progress.h"
#include "loader.h"
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    Loader loader;
    Scene *lastPainted;
    Scene* drawMeScene(GameTask *task);
    void debugScene(GameTask *task);
    bool changed;

    bool isLastSceneInLevel();
    void saveProgress();
    void loadProgress();

private:
    QPixmap firstBackground;
    QPixmap polly;
    QPixmap lolly;
    QPixmap trolly;
    QPixmap getBacgroundMainScene(QSize screen_size);
    QPixmap getSheepPolly(QSize screen_size);
    QPixmap getSheepLolly(QSize screen_size);
    QPixmap getSheepTrolly(QSize screen_size);

    QPixmap getResImg(QString path,QSize screen_size);

    //level 1(prolog) scenes
    void taskInfo(GameTask * task);
    QPixmap* drawScene0_Prolog(GameTask *task);
    QPixmap* getSinglePolly(GameTask *task);
    QPixmap* getCoupleSheep(GameTask *task);
    QPixmap* getPollySunOrRainImg(GameTask *task);
    QPixmap* getPollySunImg(GameTask *task);
    QPixmap* drawPollyBeeHouse(GameTask *task);
    QPixmap* drawPollyHoneyDiller(GameTask *task);

    //level 2(tea_walk) scenes
    QPixmap* drawSceneSheepsWithBallActivity_TeaWalk(GameTask *task);
    QPixmap* drawSceneSheepsFindCoin1_TeaWalk(GameTask *task);
    QPixmap* getCoupleSheepOngoingToCafe(GameTask *task);
    QPixmap* caffeIntro(GameTask *task);
    QPixmap* caffeIntroWithCoin(GameTask *task);
    QPixmap* caffeInterer(GameTask *task);

    //level 3(zoo) scenes
    QPixmap* drawCompaimgScene(GameTask *task,bool isFinalScene);
    QPixmap* drawZoo(GameTask *task);
    QPixmap* mainHeroWithElephant(GameTask *task);
    QPixmap* mainHeroWithLion(GameTask *task);
    QPixmap* mainHeroWithBird(GameTask *task);
    QPixmap* PollyWithLollyInZoo(GameTask *task);
    QPixmap* drawZooDirector(GameTask *task);
    QPixmap* drawPollyLollyTrollyInZoo(GameTask *task);
    QPixmap* drawZooSummary(GameTask *task);

    //level 4(voyage) scenes
    QPixmap* sheepsPackSuitcases(GameTask *task);
    QPixmap* sheepPollyItem(GameTask *task);
    QPixmap* sheepLollyItem(GameTask *task);
    QPixmap* sheepTrollyItem(GameTask *task);


    Scene* drawByTask(GameTask *task);
    Scene* drawProlog(GameTask *task);
    Scene* drawTeaWalkLevel(GameTask *task);
    Scene* drawZooLevel(GameTask *task);
    Scene* drawVoyageLevel(GameTask *task);
};

#endif // GAME_H
