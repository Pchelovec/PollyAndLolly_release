#include "widget.h"
#include "ui_widget.h"
#include "gametask.h"
#include <QDebug>
#include <QPainter>
#include<QMovie>
#include"level.h"
#include<QScreen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    game=new Game();
    ui->stackedWidget->setCurrentIndex(0);
    updateGameProgressUI();
    loadAds();
    loadInterstitialAd();
    loadingLevelProgressLabel = new QLabel(this);
    qDebug()<<"Welcome to Polly And Lolly Lyric Story!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadAds()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    banner=new QmlBanner();
    banner->setUnitId("ca-app-pub-4983713911887668/7311173522");
    banner->setBannerSize(QmlBanner::LARGE_BANNER);
    banner->setX(40);
    banner->setY((height/4)*3);
    banner->setTestDeviceId("41E647017EBEBB0650DAE627391B7A43");
    banner->loadBanner();
    banner->setVisible(true);
}

void Widget::loadInterstitialAd()
{
    interstitial=new QmlInterstitialAd();
    interstitial->setInterstitialAdUnitId("ca-app-pub-4983713911887668/8108710871");
    interstitial->setInterstitialAdTestDeviceId("41E647017EBEBB0650DAE627391B7A43");
    interstitial->loadInterstitialAd();
}
void Widget::drawScene0(QPaintEvent *pe)
{
    GameTask *gameTask =new GameTask(Level::PROLOG,Prolog_scene::Prolog_StartMenuScreen);
    gameTask->screenSize=QSize(width(),height());

    QPainter paint(this);
    QPixmap pixmap = game->drawMeScene(gameTask)->img;
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}

void Widget::paintEvent(QPaintEvent *event)
{
    if (ui->stackedWidget->currentIndex()==2){return;}
    if (game->changed){
        qDebug()<<"Widget paint for changed screen!";
        drawScene0(event);
    }
    game->changed=false;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    game->changed=true;
    QWidget::update();
}

GameTask * Widget::gameTaskForNextScene()
{
    game->lastPainted->incrementScene();
    GameTask *gameTask =new GameTask(game->lastPainted->level,game->lastPainted->screen);
    gameTask->screenSize=QSize(width(),height());

    return gameTask;
}

void Widget::levelEndAds()
{
    interstitial->loadInterstitialAd();
    interstitial->showInterstitialAd();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Mouse pressed";
    if (ui->stackedWidget->currentIndex()==2){return;}//if settings menu then return
    if (ui->stackedWidget->currentIndex()==1){
        if (game->isLastSceneInLevel()){
            ui->stackedWidget->setCurrentIndex(0);
            levelEndAds();
            banner->loadBanner();
            banner->setVisible(true);
            game->saveProgress();
            updateGameProgressUI();
        }
        else{
            //todo update incrementation by new mitod like 'next'
            GameTask *gameTask = gameTaskForNextScene();
            setSceneByNewTask(gameTask);
        }
    }
    game->changed=true;
    QWidget::update();
}

void Widget::changeEvent(QEvent * event)
{
    qDebug()<<event->type();
    qDebug()<<(event->type() == QEvent::LanguageChange);

    if (event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
        updateGameProgressUI();
        game->changed=true;
        QWidget::update();
    }
    if ((event->type() == QEvent::WindowStateChange)or
            (event->type() == QEvent::ActivationChange)){
        game->changed=true;
        QWidget::update();
    }
    // remember to call base class implementation
    QWidget::changeEvent(event);
}

void Widget::setDeveloperImages()
{
    QMovie *movie = new QMovie(":/img/developer/3ball_shower_man.gif");
    ui->scene_img_label->setMovie(movie);
    ui->scene_img_label->setScaledContents(true);
    ui->scene_img_label->setToolTip("Developer photo(colorized)");
    movie->start();
}

void Widget::setSceneByNewTask(GameTask *gameTask)
{
    GameTask *task=gameTask;
    if (task==NULL){
        task=new GameTask(Level::PROLOG,Prolog_scene::Prolog_StartMenuScreen);
    }
    gameTask->screenSize=QSize(ui->scene_img_label->width(),ui->scene_img_label->height());
    Scene *s=game->drawMeScene(task);
    game->lastPainted=s;
    ui->scene_img_label->setPixmap(s->img);
    ui->scene_text_label->setText(s->gameText);
}

void Widget::loadLevel()
{
    QMovie *movie = new QMovie(":/img/developer/load.gif");
    loadingLevelProgressLabel->setMovie(movie);
    loadingLevelProgressLabel->setAlignment(Qt::AlignCenter);
    loadingLevelProgressLabel->setVisible(true);
    loadingLevelProgressLabel->setGeometry(0,0,this->width(),this->height());
    movie->start();
    loadingLevelProgressLabel->raise();
    loadingLevelProgressLabel->show();

    game->loader.loadLevel1(game->lastPainted->level);

    loadingLevelProgressLabel->setVisible(false);
}


void Widget::on_label_prolog_clicked()
{
    //important
    if (game->lastPainted->level>Level::PROLOG) return;
    if (game->lastPainted->level==Level::PROLOG and game->lastPainted->screen.getScreen()!=0)return;//already painted

    loadLevel();

    ui->stackedWidget->setCurrentIndex(1);
    banner->setVisible(false);

    game->lastPainted->setLevelAndScene(Level::PROLOG,Screen(0));
    setDeveloperImages();

    game->changed=true;
    QWidget::update();
}

void Widget::updateGameProgressUI()
{
    ui->label_prolog->setText(QObject::tr("Beginning"));
    ui->label_walk->setText(QObject::tr("Tea walk"));
    ui->label_road->setText(QObject::tr("In the zoo"));
    ui->label_journey->setText(QObject::tr("Voyage"));
    if (Progress::progressExist()){
        //load from file
        game->loadProgress();
        switch (game->lastPainted->level) {
        case(Level::VOYAGE):{ui->label_journey->setText(QObject::tr("Voyage🗸"));}
        case(Level::ZOO):{ui->label_road->setText(QObject::tr("In the zoo🗸"));}
        case(Level::TEA_WALK):{ui->label_walk->setText(QObject::tr("Tea walk🗸"));}
        case(Level::PROLOG):{ui->label_prolog->setText(QObject::tr("Beginning🗸"));}
        }
    }
}


void Widget::on_label_walk_clicked()
{
    //check prev level
    if ((game->isLastSceneInLevel())and (game->lastPainted->level==Level::PROLOG)){
        game->lastPainted->incrementLevel();
        loadLevel();

        if (game->lastPainted->level==Level::TEA_WALK){
            ui->stackedWidget->setCurrentIndex(1);
            banner->setVisible(false);

            game->lastPainted->setLevelAndScene(Level::TEA_WALK,Screen(0));
            setSceneByNewTask(new GameTask(game->lastPainted->level,game->lastPainted->screen));
        }
        game->changed=true;
        QWidget::update();
    }
}

void Widget::on_label_road_clicked()
{
    if ((game->isLastSceneInLevel())and(game->lastPainted->level==Level::TEA_WALK))
    {
        game->lastPainted->incrementLevel();
        loadLevel();

        if (game->lastPainted->level==Level::ZOO){
            ui->stackedWidget->setCurrentIndex(1);
            banner->setVisible(false);

            game->lastPainted->setLevelAndScene(Level::ZOO,Screen(0));
            setSceneByNewTask(new GameTask(game->lastPainted->level,game->lastPainted->screen));
        }
        game->changed=true;
        QWidget::update();
    }
}

void Widget::on_label_journey_clicked()
{
    if (game->isLastSceneInLevel()and game->lastPainted->level==Level::ZOO){
        game->lastPainted->incrementLevel();
        loadLevel();

        if (game->lastPainted->level==Level::VOYAGE)
        {
            ui->stackedWidget->setCurrentIndex(1);
            banner->setVisible(false);

            game->lastPainted->setLevelAndScene(Level::VOYAGE,Screen(0));
            setSceneByNewTask(new GameTask(game->lastPainted->level,game->lastPainted->screen));
        }
        game->changed=true;
        QWidget::update();
    }
}

void Widget::on_pushButton_2_clicked()
{
    //settings menu
    ui->stackedWidget->setCurrentIndex(2);
    banner->setVisible(false);
}

void Widget::setLanguageLabelText()
{
    qDebug()<<"game language is "<<ToString(game->story->language);
    ui->currentLanguageLE->setText(ToString(game->story->language));
}

void Widget::on_pushButton_clicked()
{
    //change language
    qDebug()<<ui->comboBox->currentText();
    if (ui->comboBox->currentText()=="RU"){
        qDebug()<<"Ru";
        qtLanguageTranslator.load(":/language/lang_ru.qm");
        QApplication::installTranslator(&qtLanguageTranslator);
        game->story->language=supportedLanguage::RU;
    }
    if (ui->comboBox->currentText()=="UA"){
        qDebug()<<"Ua";
        qtLanguageTranslator.load(":/language/lang_ua.qm");
        QApplication::installTranslator(&qtLanguageTranslator);
        game->story->language=supportedLanguage::UA;
    }
    if (ui->comboBox->currentText()=="EN"){
        qDebug()<<"En";
        qtLanguageTranslator.load(":/language/default_en.qm");
        QApplication::installTranslator(&qtLanguageTranslator);
        game->story->language=supportedLanguage::EN;
    }
    if (Progress::progressExist()){game->saveProgress();}//update language too
    setLanguageLabelText();
    //to main pages and enable ads
    ui->stackedWidget->setCurrentIndex(0);
    banner->setVisible(true);
    //fix background
    game->changed=true;
    QWidget::update();
}

void Widget::on_pushButton_3_clicked()
{
    //go to main menu without changes
    ui->stackedWidget->setCurrentIndex(0);
    banner->setVisible(true);
    //fix background
    game->changed=true;
    QWidget::update();
}
