#ifndef LEVEL_H
#define LEVEL_H

#include<QDebug>
enum Level{
    PROLOG,
    TEA_WALK,
    ZOO,
    VOYAGE
};

//Scenes for prolog
enum Prolog_scene{
    Prolog_StartMenuScreen,
    Prolog_SinglePollyScene,
    Prolog_TiredPolly,
    Prolog_PollyLookingForAFriend,
    Prolog_PollyDisaster,
    Prolog_PollyUnderRain,
    Prolog_PollyUnderSun,
    Prolog_PollyPasekaMod,
    Prolog_PollyRealizatorMod,
    Prolog_PollyFindLolly,
    Prolog_LollyMeetPolly,
    Prolog_FinalPrologFrase
};
inline Prolog_scene& operator++(Prolog_scene& mode, const int){
        qDebug()<<"Increment prolog SCENE"<<mode;
        mode = static_cast<Prolog_scene>((mode + 1));
        return mode;
}

//Scenes for teaWalk
enum TeaWalk_scene{
    TeaWalk_levelIintro,
    TeaWalk_LookingForAdventure,
    TeaWalk_FindCoin1,
    TeaWalk_goingToTheCaffe,
    TeaWalk_arriveToCaffe,
    TeaWalk_findCoin2,
    TeaWalk_teaOrder,
    TeaWalk_payCoin,
    TeaWalk_teaArrived,
    TeaWalk_toTheWindow,
    TeaWalk_preOrderTea2,
    TeaWalk_orderTea2,
    TeaWalk_allTeaOrdered,
    TeaWalk_leaveCaffe,
    TeaWalk_homeWaitingScene
};
inline TeaWalk_scene& operator++(TeaWalk_scene& mode, const int){
        qDebug()<<"Increment TeaWalk SCENE"<<mode;
        mode = static_cast<TeaWalk_scene>((mode + 1));
        return mode;
}

enum zoo_scene{
    ZOO_plans,
    ZOO_enteredToTheZoo,
    ZOO_openDayPromo,
    ZOO_observing,
    ZOO_elephant,
    ZOO_lion,
    ZOO_birds,
    ZOO_director,
    ZOO_directorLoveAnimals,
    ZOO_directoroveMonkeys,
    ZOO_animalsObserving,
    ZOO_aroundWall,
    ZOO_TrollyIntro,
    ZOO_PollyLollYTrollyCompany,
    ZOO_3SSheepName,
    ZOO_Summary
};
inline zoo_scene& operator++(zoo_scene& mode, const int){
        qDebug()<<"Increment zoo_scene SCENE"<<mode;
        mode = static_cast<zoo_scene>((mode + 1));
        return mode;
}

enum voyage_scene{
    voyage_packSuitcase,
    voyage_packSuitcaseDescription,
    voyaje_PollyPack,
    voyage_PollyPackItems,
    voyage_LollyPack,
    voyage_LollyPackItems,
    voyage_TrollyPack,
    voyage_TrollyPackItems
};
inline voyage_scene& operator++(voyage_scene& mode, const int){
        qDebug()<<"Increment voyage_scene SCENE"<<mode;
        mode = static_cast<voyage_scene>((mode + 1));
        return mode;
}
#endif // LEVEL_H
