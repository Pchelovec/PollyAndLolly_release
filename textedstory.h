#ifndef TEXTEDSTORY_H
#define TEXTEDSTORY_H
#include<QObject>
namespace  {
class textedStory : public QObject
{
    Q_OBJECT
public:
    textedStory() {}
    virtual ~textedStory() {}

    static QStringList prologText;
    static QString getPrologText(int row){
        return prologText.at(row);
    }

    static QStringList teaWalkText;
    static QString getTeaWalkText(int row){
        return teaWalkText.at(row);
    }

    static QStringList zooText;
    static QString getZooText(int row){
        return zooText.at(row);
    }

    static QStringList voyageText;
    static QString getVoyageText(int row){
        return voyageText.at(row);
    }
};

QStringList textedStory::prologText=QStringList({"Однажды Polly по травке на поле гуляла",
                                        "Одна она кажется очень устала",
                                        "Друзей она долго для совместной прогулки искала",
                                        "Но нигде не могла их найти",
                                        "",
                                        "Когда шел дождь Polly под навесом гуляла",
                                        "Когда пекло солнце Polly с зонтиком отдыхала",
                                        "На своей пасеке Polly мед собирала",
                                        "На рынке около дома Polly мед продавала",
                                        "",
                                        "Долго наша Polly ходила-бродила",
                                        "Пока однажды на улице нового друга нашла.",
                                        "Знакомтесь! Это Lolly - друг очень хороший,\n который есть у нашей Polly!"});

QStringList textedStory::teaWalkText=QStringList({"Polly и Lolly на поле гуляли",
                                                 "Polly и Lolly развлечений искали",
                                                 "На поле Polly и Molly монетку нашли",
                                                 "Polly и Lolly в кафе чай пить пошли",
                                                 "",
                                                 "Когда Polly и Lolly к кафе пришли",
                                                 "Они еще монетку нашли",
                                                 "",
                                                 "У жирафа они чай заказали",
                                                 "Одну монетку жирафу отдали",
                                                 "",
                                                 "Когда чай принесли",
                                                 "К окну Polly и Lolly чай пить пошли",
                                                 "Чай допивали",
                                                 "Второй чай заказали",
                                                 "",
                                                 "Когда весь чай в кафе повыпивали",
                                                 "Polly и Lolly домой поскакали",
                                                 "",
                                                 "Ведь их дома уже ждали!"});

QStringList textedStory::zooText=QStringList({"Polly и Molly в поход пошли",
                                             "По пути в зоопарк зашли",
                                             "В этот день в зоопарк \nбез билетов пускали",
                                             "Polly и Lolly за животными наблюдали",
                                             "",
                                             "В зоопарке были слоны",
                                             "В зоопарке были львы",
                                             "В зоопарке били стрижи",
                                             "В этот день в зоопарке был директор",
                                             "",
                                             "Директор животных любил",
                                             "Мартышек директор бананом кормил",
                                             "",
                                             "За многими животными они наблюдали",
                                             "Около длинного забора собрата повстречали",
                                             "Они из вальера сбежавшую овечку нашли",
                                             "И дальше по миру вместе пошли",
                                             "",
                                             "Третьей овчечке дали имя Trolly.",
                                             "A из зоопарка в тот день \nи так выпускали"});

QStringList textedStory::voyageText=QStringList({"Polly, Lolly и Trolly паковали чемоданы",
                                                "Через неделю они в теплые страны улетали",
                                                "",
                                                "Polly в путешествие хорошо собралась",
                                                "Взяла карту и компас, но забыла очки",
                                                "Lolly взяла для Polly очки",
                                                "Но забыла взять все остальное",
                                                "Trolly в поездку дольше всех собиралась",
                                                "А взяла с собой только Polly и Molly."});
}
#endif // TEXTEDSTORY_H
