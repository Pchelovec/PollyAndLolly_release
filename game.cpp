#include "game.h"
#include"patched_game_painter.h"
#include <QWidget>
#include <QPainter>
#include<QPixmap>
#include <QLabel>
#include <QDebug>
Game::Game(QObject *parent) : QObject(parent)
{
    lastPainted=new Scene();
    story=&textedStory::getInstance();

    //load main backgrounds
    firstBackground.load(":/img/background0.webp");

    //load main persons
    polly.load(":/img/sheeps/Polly.png");
    lolly.load(":/img/sheeps/Lolly.png");
    trolly.load(":/img/sheeps/Trolly.png");
}

QPixmap Game::getBacgroundMainScene(QSize screen_size)
{
    return firstBackground.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getSheepPolly(QSize screen_size)
{
    return polly.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getSheepLolly(QSize screen_size)
{
    return lolly.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getSheepTrolly(QSize screen_size)
{
    return trolly.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getResImg(QString path, QSize screen_size)
{
    QPixmap pixmap;
    if (loader.contains(path)){pixmap=loader.getRes(path);}
    else {qDebug()<<path<<" LOAD FROM DISK";pixmap.load(path);}
    return pixmap.scaled(screen_size.width(),screen_size.height());
}

void Game::taskInfo(GameTask *task)
{
    qDebug()<<"--------------New task !----------------------";
    qDebug()<<"Level:"<<task->level;
    qDebug()<<"Scene:"<<task->screen.getScreen();
    qDebug()<<"Screen_size"<<task->screenSize;
}

QPixmap* Game::drawScene0_Prolog(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize pollyScreen=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getBacgroundMainScene(task->screenSize));
    gamePainter->draw(0, (task->screenSize.height()/4)*3, getSheepPolly(pollyScreen));
    return gamePainter->process();
}

QPixmap* Game::getSinglePolly(GameTask* task){
    //prepare extra screenSize calculation
    QSize pollyScreen=QSize((task->screenSize.width()),task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0, 0, getSheepPolly(pollyScreen));
    return gamePainter->process();
}

QPixmap *Game::getCoupleSheep(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize polly_lolly_screen=QSize((task->screenSize.width()/2),task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level0/heart-background-photography.png",task->screenSize));
    gamePainter->draw(0, 0, getSheepPolly(polly_lolly_screen));
    gamePainter->draw((task->screenSize.width()/2),0,getSheepLolly(polly_lolly_screen));
    return gamePainter->process();
}

QPixmap *Game::getPollySunOrRainImg(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize pollySize=QSize((task->screenSize.width())/3,task->screenSize.height()/3);
    QSize cloudSize=QSize((task->screenSize.width())/4,task->screenSize.height()/4);
    QSize tentSize=QSize(task->screenSize.width()/2,task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0, 0, getResImg(":/img/level0/rain.png",task->screenSize));//
    gamePainter->draw(0, 0,getResImg(":/img/level0/cloud.png",cloudSize));//
    gamePainter->draw(task->screenSize.width()/4*2, 0,getResImg(":/img/level0/cloud.png",cloudSize));//
    gamePainter->draw(0, 0,getResImg(":/img/level0/tent.png",tentSize));
    gamePainter->draw(0, (task->screenSize.height()/3)*2, getSheepPolly(pollySize));
    return gamePainter->process();
}

QPixmap *Game::getPollySunImg(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize pollySize=QSize((task->screenSize.width())/3,task->screenSize.height()/3);
    QSize cloudSize=QSize((task->screenSize.width())/4,task->screenSize.height()/4);
    QSize umbrellaSize=QSize(task->screenSize.width()/4,task->screenSize.height()/4);

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(task->screenSize.width()/2,0,getResImg(":/img/level0/sun.png",cloudSize));
    gamePainter->draw(task->screenSize.width()/2, 0,getResImg(":/img/level0/cloud.png",cloudSize));//
    gamePainter->draw(task->screenSize.width()/4, task->screenSize.height()-umbrellaSize.height()-20,getResImg(":/img/level0/umbrella.png",umbrellaSize));
    gamePainter->draw(0, (task->screenSize.height()/3)*2, getSheepPolly(pollySize));
    return gamePainter->process();
}

QPixmap *Game::drawPollyBeeHouse(GameTask *task)
{
    QSize beeHomeSize=QSize((task->screenSize.width())/2,task->screenSize.height());
    QSize pollySize=QSize((task->screenSize.width())/2,task->screenSize.height()/2);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level0/garden-refuge-captivating-bee-house-scenes-ai-generative-free-png.webp",beeHomeSize));
    gamePainter->draw(task->screenSize.width()/2,task->screenSize.height()/2,getSheepPolly(pollySize));
    return gamePainter->process();
}

QPixmap *Game::drawPollyHoneyDiller(GameTask *task)
{
    QSize pollySize=QSize((task->screenSize.width())/2,task->screenSize.height()/2);
    QSize tabloSize=QSize((task->screenSize.width())/4,task->screenSize.height()/3);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level0/honey-and-honeycombs-illustration.png",task->screenSize));
    gamePainter->draw(task->screenSize.width()/2,task->screenSize.height()/2,getSheepPolly(pollySize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()-tabloSize.height()),getResImg(":/img/level0/tablo2_with_sale_text.png",tabloSize));
    return gamePainter->process();
}

QPixmap* Game::drawSceneSheepsWithBallActivity_TeaWalk(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);
    QSize ballImgSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);
    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/grassBackground.webp",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getResImg(":/img/level1/ball_activity.png",ballImgSize));
    gamePainter->draw(0,((task->screenSize.height()/4)*3),getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4),((task->screenSize.height()/4)*3),getSheepLolly(sheepSize));
    return gamePainter->process();
}

QPixmap* Game::drawSceneSheepsFindCoin1_TeaWalk(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);
    QSize ballImgSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);
    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/grassBackground.webp",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getResImg(":/img/level1/coin1.png",ballImgSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getResImg(":/img/level1/ball_activity.png",ballImgSize));
    gamePainter->draw(0,((task->screenSize.height()/4)*3),getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4),((task->screenSize.height()/4)*3),getSheepLolly(sheepSize));
    return gamePainter->process();
}

//todo shheps in moving
QPixmap *Game::getCoupleSheepOngoingToCafe(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize polly_lolly_screen=QSize((task->screenSize.width()/2),task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0, 0, getSheepPolly(polly_lolly_screen));
    gamePainter->draw((task->screenSize.width()/2),0,getSheepLolly(polly_lolly_screen));
    return gamePainter->process();
}

QPixmap *Game::caffeIntro(GameTask *task)
{
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level1/pretty_caffe.png",task->screenSize));
    return gamePainter->process();
}

QPixmap *Game::caffeIntroWithCoin(GameTask *task)
{
    QSize coins=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level1/pretty_caffe.png",task->screenSize));
    gamePainter->draw(0,(task->screenSize.height()/4)*3,getResImg(":/img/level1/coin2.png",coins));
    return gamePainter->process();
}

QPixmap *Game::caffeInterer(GameTask *task)
{
    QSize barmenSize=QSize(task->screenSize.width()/2,task->screenSize.height());
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level1/interer.webp",task->screenSize));
    gamePainter->draw(0,0,getResImg(":/img/level1/barmen.png",barmenSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    return gamePainter->process();
}

QPixmap *Game::drawCompaimgScene(GameTask *task,bool isFinalScene)
{
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/campaing.png",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    if (isFinalScene){gamePainter->draw((task->screenSize.width()/4),(task->screenSize.height()/4)*3,getSheepTrolly(sheepSize));}
    return gamePainter->process();
}

QPixmap *Game::drawZoo(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/zoo.png",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    return gamePainter->process();
}

QPixmap *Game::mainHeroWithElephant(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/elephant.png",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    return gamePainter->process();
}

QPixmap *Game::mainHeroWithLion(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/lion.png",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4),(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw(0,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    return gamePainter->process();
}

QPixmap *Game::mainHeroWithBird(GameTask *task)
{
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/bird.png",task->screenSize));
    return gamePainter->process();
}

QPixmap *Game::PollyWithLollyInZoo(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize polly_lolly_screen=QSize((task->screenSize.width()/2),task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0, 0, getSheepPolly(polly_lolly_screen));
    gamePainter->draw((task->screenSize.width()/2),0,getSheepLolly(polly_lolly_screen));
    return gamePainter->process();
}

QPixmap *Game::drawZooDirector(GameTask *task)
{
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/zoo_derector.webp",task->screenSize));
    return gamePainter->process();
}

QPixmap *Game::drawPollyLollyTrollyInZoo(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/background.webp",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4),(task->screenSize.height()/4)*3,getSheepTrolly(sheepSize));
    return gamePainter->process();
}

QPixmap *Game::drawZooSummary(GameTask *task)
{
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level2/zoo.png",task->screenSize));
    return gamePainter->process();
}

QPixmap *Game::sheepsPackSuitcases(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/img/level3/suitcase.webp",task->screenSize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()/4)*3,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4)*2,(task->screenSize.height()/4)*3,getSheepLolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/4),(task->screenSize.height()/4)*3,getSheepTrolly(sheepSize));
    return gamePainter->process();
}

QPixmap *Game::sheepPollyItem(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/2),task->screenSize.height());

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getSheepPolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/2),0,getResImg(":/img/level3/PollyList.webp",sheepSize));
    return gamePainter->process();
}

QPixmap *Game::sheepLollyItem(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/2),task->screenSize.height());

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getSheepLolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/2),0,getResImg(":/img/level3/LollyList.webp",sheepSize));
    return gamePainter->process();
}

QPixmap *Game::sheepTrollyItem(GameTask *task)
{
    QSize sheepSize=QSize((task->screenSize.width()/2),task->screenSize.height());

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getSheepTrolly(sheepSize));
    gamePainter->draw((task->screenSize.width()/2),0,getResImg(":/img/level3/TrollyList.webp",sheepSize));
    return gamePainter->process();
}
Scene* Game::drawProlog(GameTask *task)
{
    Scene* sceneToPaint=new Scene();
    sceneToPaint->level=task->level;
    sceneToPaint->screen=task->screen;
    //    QPixmap *result;
    switch (task->screen.getScreen()) {
    case Prolog_StartMenuScreen:{sceneToPaint->img=*drawScene0_Prolog(task);break;}//
    case Prolog_SinglePollyScene:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(0);break;}
    case Prolog_TiredPolly:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(1);break;}
    case Prolog_PollyLookingForAFriend:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(2);break;}
    case Prolog_PollyDisaster:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(3);break;}
    case Prolog_PollyUnderRain:{sceneToPaint->img=*getPollySunOrRainImg(task);sceneToPaint->gameText=textedStory::getPrologText(5);break;}
    case Prolog_PollyUnderSun:{sceneToPaint->img=*getPollySunImg(task);sceneToPaint->gameText=textedStory::getPrologText(6);break;}
    case Prolog_PollyPasekaMod:{sceneToPaint->img=*drawPollyBeeHouse(task);sceneToPaint->gameText=textedStory::getPrologText(7);break;}
    case Prolog_PollyRealizatorMod:{sceneToPaint->img=*drawPollyHoneyDiller(task);sceneToPaint->gameText=textedStory::getPrologText(8);break;}
    case Prolog_PollyFindLolly:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(10);break;}
    case Prolog_LollyMeetPolly:{sceneToPaint->img=*getCoupleSheep(task);sceneToPaint->gameText=textedStory::getPrologText(11);break;}
    case Prolog_FinalPrologFrase:{sceneToPaint->img=*getCoupleSheep(task);sceneToPaint->gameText=textedStory::getPrologText(12);break;}
    }

    return sceneToPaint;
}

Scene *Game::drawTeaWalkLevel(GameTask *task)
{
    Scene* sceneToPaint=new Scene();
    sceneToPaint->level=task->level;
    sceneToPaint->screen=task->screen;
    //    QPixmap *result;
    switch (task->screen.getScreen()) {
    case TeaWalk_levelIintro:{sceneToPaint->img=*drawSceneSheepsWithBallActivity_TeaWalk(task);sceneToPaint->gameText=textedStory::getTeaWalkText(0);break;}
    case TeaWalk_LookingForAdventure:{sceneToPaint->img=*drawSceneSheepsWithBallActivity_TeaWalk(task);sceneToPaint->gameText=textedStory::getTeaWalkText(1);break;}
    case TeaWalk_FindCoin1:{sceneToPaint->img=*drawSceneSheepsFindCoin1_TeaWalk(task);sceneToPaint->gameText=textedStory::getTeaWalkText(2);break;}
    case TeaWalk_goingToTheCaffe:{sceneToPaint->img=*getCoupleSheepOngoingToCafe(task);sceneToPaint->gameText=textedStory::getTeaWalkText(3);break;}
    case TeaWalk_arriveToCaffe:{sceneToPaint->img=*caffeIntro(task);sceneToPaint->gameText=textedStory::getTeaWalkText(5);break;}
    case TeaWalk_findCoin2:{sceneToPaint->img=*caffeIntroWithCoin(task);sceneToPaint->gameText=textedStory::getTeaWalkText(6);break;}
    case TeaWalk_teaOrder:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(8);break;}
    case TeaWalk_payCoin:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(9);break;}
    case TeaWalk_teaArrived:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(11);break;}
    case TeaWalk_toTheWindow:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(12);break;}
    case TeaWalk_preOrderTea2:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(13);break;}
    case TeaWalk_orderTea2:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(14);break;}
    case TeaWalk_allTeaOrdered:{sceneToPaint->img=*caffeInterer(task);sceneToPaint->gameText=textedStory::getTeaWalkText(16);break;}
    case TeaWalk_leaveCaffe:{sceneToPaint->img=*caffeIntro(task);sceneToPaint->gameText=textedStory::getTeaWalkText(17);break;}
    case TeaWalk_homeWaitingScene:{sceneToPaint->img=*caffeIntro(task);sceneToPaint->gameText=textedStory::getTeaWalkText(19);break;}
    }
    return sceneToPaint;
}

Scene *Game::drawZooLevel(GameTask *task)
{
    Scene *sceneToPaint=new Scene();
    sceneToPaint->level=task->level;
    sceneToPaint->screen=task->screen;

    //    QPixmap *result;
    switch (task->screen.getScreen()) {
    case ZOO_plans:{sceneToPaint->img=*drawCompaimgScene(task,false);sceneToPaint->gameText=textedStory::getZooText(0);break;}
    case ZOO_enteredToTheZoo:{sceneToPaint->img=*drawZoo(task);sceneToPaint->gameText=textedStory::getZooText(1);break;}
    case ZOO_openDayPromo:{sceneToPaint->img=*drawZoo(task);sceneToPaint->gameText=textedStory::getZooText(2);break;}
    case ZOO_observing:{sceneToPaint->img=*drawZoo(task);sceneToPaint->gameText=textedStory::getZooText(3);break;}
    case ZOO_elephant:{sceneToPaint->img=*mainHeroWithElephant(task);sceneToPaint->gameText=textedStory::getZooText(5);break;}
    case ZOO_lion:{sceneToPaint->img=*mainHeroWithLion(task);sceneToPaint->gameText=textedStory::getZooText(6);break;}
    case ZOO_birds:{sceneToPaint->img=*mainHeroWithBird(task);sceneToPaint->gameText=textedStory::getZooText(7);break;}
    case ZOO_director:{sceneToPaint->img=*PollyWithLollyInZoo(task);sceneToPaint->gameText=textedStory::getZooText(8);break;}
    case ZOO_directorLoveAnimals:{sceneToPaint->img=*drawZooDirector(task);sceneToPaint->gameText=textedStory::getZooText(10);break;}
    case ZOO_directoroveMonkeys:{sceneToPaint->img=*drawZooDirector(task);sceneToPaint->gameText=textedStory::getZooText(11);break;}
    case ZOO_animalsObserving:{sceneToPaint->img=*PollyWithLollyInZoo(task);sceneToPaint->gameText=textedStory::getZooText(13);break;}
    case ZOO_aroundWall:{sceneToPaint->img=*PollyWithLollyInZoo(task);sceneToPaint->gameText=textedStory::getZooText(14);break;}
    case ZOO_TrollyIntro:{sceneToPaint->img=*drawPollyLollyTrollyInZoo(task);sceneToPaint->gameText=textedStory::getZooText(15);break;}
    case ZOO_PollyLollYTrollyCompany:{sceneToPaint->img=*drawPollyLollyTrollyInZoo(task);sceneToPaint->gameText=textedStory::getZooText(16);break;}
    case ZOO_3SSheepName:{sceneToPaint->img=getSheepTrolly(task->screenSize);sceneToPaint->gameText=textedStory::getZooText(18);break;}
    case ZOO_Summary:{sceneToPaint->img=*drawCompaimgScene(task,true);sceneToPaint->gameText=textedStory::getZooText(19);break;}
    }
    return sceneToPaint;
}

Scene *Game::drawVoyageLevel(GameTask *task)
{
    Scene *sceneToPaint=new Scene();
    sceneToPaint->level=task->level;
    sceneToPaint->screen=task->screen;

    switch (task->screen.getScreen()) {
    case voyage_packSuitcase:{sceneToPaint->img=*sheepsPackSuitcases(task);sceneToPaint->gameText=textedStory::getVoyageText(0);break;}
    case voyage_packSuitcaseDescription:{sceneToPaint->img=*sheepsPackSuitcases(task);sceneToPaint->gameText=textedStory::getVoyageText(1);break;}
    case voyaje_PollyPack:{sceneToPaint->img=getSheepPolly(task->screenSize);sceneToPaint->gameText=textedStory::getVoyageText(3);break;}
    case voyage_PollyPackItems:{sceneToPaint->img=*sheepPollyItem(task);sceneToPaint->gameText=textedStory::getVoyageText(4);break;}
    case voyage_LollyPack:{sceneToPaint->img=getSheepLolly(task->screenSize);sceneToPaint->gameText=textedStory::getVoyageText(5);break;}
    case voyage_LollyPackItems:{sceneToPaint->img=*sheepLollyItem(task);sceneToPaint->gameText=textedStory::getVoyageText(6);break;}
    case voyage_TrollyPack:{sceneToPaint->img=getSheepTrolly(task->screenSize);sceneToPaint->gameText=textedStory::getVoyageText(7);break;}
    case voyage_TrollyPackItems:{sceneToPaint->img=*sheepTrollyItem(task);sceneToPaint->gameText=textedStory::getVoyageText(8);break;}
    }

    return sceneToPaint;
}

bool Game::isLastSceneInLevel()
{
    //todo check for level
    if ((lastPainted->level==Level::PROLOG) and(lastPainted->screen.getScreen()==Prolog_scene::Prolog_FinalPrologFrase)){return true;}
    if ((lastPainted->level==Level::TEA_WALK) and (lastPainted->screen.getScreen()==TeaWalk_scene::TeaWalk_homeWaitingScene)){return true;}
    if ((lastPainted->level==Level::ZOO)and (lastPainted->screen.getScreen()==zoo_scene::ZOO_Summary)){return true;}
    if ((lastPainted->level==Level::VOYAGE)and (lastPainted->screen.getScreen()==voyage_scene::voyage_TrollyPackItems)){return true;}
    return false;
}

void Game::saveProgress()
{
    supportedLanguage lang = story->language;
    Progress::saveProgress(lastPainted, lang);
}

void Game::loadProgress()
{
    //todo refactoring
    story->language=(supportedLanguage)Progress::loadProgress(lastPainted);
}

Scene* Game::drawByTask(GameTask *task)
{
    Scene *sceneToPaint;
    if (task->level==Level::PROLOG)
        sceneToPaint=drawProlog(task);
    if (task->level==Level::TEA_WALK)
        sceneToPaint=drawTeaWalkLevel(task);
    if (task->level==Level::ZOO)
        sceneToPaint=drawZooLevel(task);
    if (task->level==Level::VOYAGE)
        sceneToPaint=drawVoyageLevel(task);
    return sceneToPaint;
}

Scene* Game::drawMeScene(GameTask *task)
{
    taskInfo(task);
    return drawByTask(task);
}

void Game::debugScene(GameTask *task)
{
    //debug info
    taskInfo(task);

    //label for output
    QLabel *label=new QLabel();

    //extract drawed images
    QPixmap *pixmap = &drawByTask(task)->img;

    //set images to label and show
    label->setPixmap(*pixmap);
    label->resize(task->screenSize);
    label->show();
}
