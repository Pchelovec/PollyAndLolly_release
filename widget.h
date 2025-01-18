#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
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

    void on_pushButton_clicked();

    void on_label_walk_clicked();

    void on_label_road_clicked();

    void on_label_journey_clicked();

private:
    Ui::Widget *ui;
    Game *game;
    QmlBanner *banner;
    QmlInterstitialAd *interstitial;
    QLabel *label;


    void setSceneByNewTask(GameTask * gameTask);
    void updateGameProgressUI();

    // QWidget interface
    void loadAds();
    void loadInterstitialAd();

    void levelEndAds();

    void loadLevel();


protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGET_H
