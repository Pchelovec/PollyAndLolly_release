#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTranslator>
#include "game.h"
#include "Admob/QmlBanner.h"
#include"Admob/QmlInterstitialAd.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void drawScene0(QPaintEvent *event);

    void setDeveloperImages();
        
    
    GameTask * gameTaskForNextScene();

private slots:
    void on_label_prolog_clicked();

    void on_label_walk_clicked();

    void on_label_road_clicked();

    void on_label_journey_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    Game *game;
    QTranslator qtLanguageTranslator;

    QmlBanner *banner;
//    QmlInterstitialAd *interstitial;
    QLabel *loadingLevelProgressLabel;


    void setSceneByNewTask(GameTask * gameTask);
    void updateGameProgressUI();

    // QWidget interface
    void loadAds();
//    void loadInterstitialAd();

//    void levelEndAds();

    void loadLevel();


    void setLanguageLabelText();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);

    // QWidget interface
protected:
    void changeEvent(QEvent *);
};

#endif // WIDGET_H
