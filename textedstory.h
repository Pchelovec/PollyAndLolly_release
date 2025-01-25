#ifndef TEXTEDSTORY_H
#define TEXTEDSTORY_H
#include<QObject>
#include<QDebug>
namespace  {
enum supportedLanguage{
    EN,RU,UA
};
inline const char* ToString(supportedLanguage v)
{
    switch (v)
    {
        case EN:   return "En";
        case RU:   return "Ru";
        case UA:    return "Ua";
        default:      return "[Unknown supportedLanguage]";
    }
}

class textedStory
{
private:
    textedStory() {}
    textedStory(textedStory const&);              // Don't Implement
    void operator=(textedStory const&); // Don't implement
public:

    supportedLanguage language;
    static textedStory& getInstance(){
        static textedStory instance;
        return instance;
    }

    static QStringList prologTextEn;
    static QStringList prologTextRu;
    static QStringList prologTextUa;
    static QString getPrologText(int row){
        if (getInstance().language==supportedLanguage::UA){return prologTextUa.at(row);}
        if(getInstance().language==supportedLanguage::RU){return  prologTextRu.at(row);}
        return prologTextEn.at(row);
    }

    static QStringList teaWalkTextEn;
    static QStringList teaWalkTextRu;
    static QStringList teaWalkTextUa;
    static QString getTeaWalkText(int row){
        if (getInstance().language==supportedLanguage::UA){return teaWalkTextUa.at(row);}
        if (getInstance().language==supportedLanguage::RU){return teaWalkTextRu.at(row);}
        return teaWalkTextEn.at(row);
    }

    static QStringList zooTextEn;
    static QStringList zooTextRu;
    static QStringList zooTextUa;
    static QString getZooText(int row){
        if (getInstance().language==supportedLanguage::UA){return zooTextUa.at(row);}
        if (getInstance().language==supportedLanguage::RU){return zooTextRu.at(row);}
        return zooTextEn.at(row);
    }

    static QStringList voyageTextEn;
    static QStringList voyageTextRu;
    static QStringList voyageTextUa;
    static QString getVoyageText(int row){
        if (getInstance().language==supportedLanguage::UA){return voyageTextUa.at(row);}
        if (getInstance().language==supportedLanguage::RU){return voyageTextRu.at(row);}
        return voyageTextEn.at(row);
    }
};
QStringList textedStory::prologTextEn=QStringList({"Once Polly walk on the field",
                                        "She was wery tired",
                                        "She looking for a friends for a long time",
                                        "But can't find friends nowhere",
                                        "",
                                        "When it was rain Polly walk under tent",
                                        "When it was sunny Polly walk with umbrella",
                                        "On his own bee garden Polly collect honey",
                                        "On the market near Polly's house Polly sell honey",
                                        "",
                                        "Polly was alone for a long time",
                                        "But once on the street Polly find a new friend.",
                                        "Look! It is a Lolly - very good friend,\n for our Polly!"});

QStringList textedStory::teaWalkTextEn=QStringList({"Polly and Lolly walk by fields",
                                                 "Polly and Lolly looking for adventure",
                                                 "On the fields Polly and Molly find a coin",
                                                 "So, Polly and Lolly going to caffe",
                                                 "",
                                                 "Wnen Polly and Lolly arrived to caffe",
                                                 "They find one more coin",
                                                 "",
                                                 "They ordered tea from the giraffe",
                                                 "And pay coin to the giraffe",
                                                 "",
                                                 "When tea was served",
                                                 "Polly and Lolly going to drink tea \nnear the window",
                                                 "After a short talk",
                                                 "They are ordered a second tea",
                                                 "",
                                                 "When they drink all tea in small caffe",
                                                 "Polly and Lolly going to home",
                                                 "",
                                                 "Because someone is waiting him!"});

QStringList textedStory::zooTextEn=QStringList({"Polly and Molly going to campaign",
                                             "But firstable decided entere to the zoo",
                                             "This day all zoo door's was opened",
                                             "Polly and Lolly observe by the animals",
                                             "",
                                             "It was elephant in the zoo",
                                             "It was lions in the zoo",
                                             "It was birds in the zoo",
                                             "It was zoo director in the zoo",
                                             "",
                                             "zoo director love animals",
                                             "zoo director make food for animals",
                                             "",
                                             "It was a lot of animals that day",
                                             "And near fence \nthey find one more animal",
                                             "It was a sheep, that leave zoo",
                                             "So they going together",
                                             "",
                                             "Thirt sheep name is Trolly.",
                                             "And they leave zoo without ticket too"});

QStringList textedStory::voyageTextEn=QStringList({"Polly, Lolly and Trolly pack suitcases",
                                                "They are going to rest",
                                                "",
                                                "Polly's suitcases was well packed",
                                                "Polly take map and compas, \nbut forgot for a glasses",
                                                "Lolly take glasses for Polly",
                                                "But forgot other items",
                                                "Trolly pack suitcases more that all",
                                                "And take only Polly and Molly."});
//===================================ru------------------------------------------------
QStringList textedStory::prologTextRu=QStringList({"Однажды Polly по травке на поле гуляла",
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

QStringList textedStory::teaWalkTextRu=QStringList({"Polly и Lolly на поле гуляли",
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

QStringList textedStory::zooTextRu=QStringList({"Polly и Molly в поход пошли",
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

QStringList textedStory::voyageTextRu=QStringList({"Polly, Lolly и Trolly паковали чемоданы",
                                                "Через неделю они в теплые страны улетали",
                                                "",
                                                "Polly в путешествие хорошо собралась",
                                                "Взяла карту и компас, но забыла очки",
                                                "Lolly взяла для Polly очки",
                                                "Но забыла взять все остальное",
                                                "Trolly в поездку дольше всех собиралась",
                                                "А взяла с собой только Polly и Molly."});

//===========================UA++++++++++++++++++++++++++++++++++++++++++++++++++++
QStringList textedStory::prologTextUa=QStringList({"Якось Polly травкою полем блукала",
                                        "Одна вона ,здається, сильно втомилась",
                                        "Друзів вона довго для прогулянки шукала",
                                        "Але ніде не могла їх знайти",
                                        "",
                                        "Коли йшов дощ Polly під навісом гуляла",
                                        "Коли пекло сонце Polly із парасолькою \nвідпочивала",
                                        "На своїй пасіці Polly мед збирала",
                                        "На базарі біля свого будинку Polly \nмед продавала",
                                        "",
                                        "Довго наша Polly блукала",
                                        "Аж одного разу на вулиці нового \nдруга знашла.",
                                        "Знайомтесь! Це Lolly - друг дуже хороший,\n який є у нашої Polly!"});

QStringList textedStory::teaWalkTextUa=QStringList({"Polly та Lolly полем гуляли",
                                                 "Polly та Lolly пригод шукали",
                                                 "На полі Polly та Molly монетку знашли",
                                                 "Polly та Lolly до кав'ярні чай пити пішли",
                                                 "",
                                                 "Коли Polly та Lolly до кафе підішли",
                                                 "Вони ще монетку знашли",
                                                 "",
                                                 "У жирафи вони чай замовили",
                                                 "Одну монетку жирафі дали",
                                                 "",
                                                 "Коли чай принесли",
                                                 "До вікна Polly та Lolly чай пити пішли",
                                                 "Чай допили",
                                                 "другий чай замовили",
                                                 "",
                                                 "Коли увесь чай у кафе випили",
                                                 "Polly та Lolly додому пішли",
                                                 "",
                                                 "Адже їх вдома вже чекали!"});

QStringList textedStory::zooTextUa=QStringList({"Polly та Molly в похід пішли",
                                             "По дорозі у зоопарк зайшли",
                                             "У той день у зоопарк \nбез білетів пускали",
                                             "Polly та Lolly за тваринами \nспостерігали",
                                             "",
                                             "У зоопарку були слони",
                                             "У зоопарку були леви",
                                             "У зоопарку були птиці",
                                             "В цей день у зоопарку був і директор",
                                             "",
                                             "Директор тваринок любив",
                                             "Мавп директор бананами кормив",
                                             "",
                                             "Багато тварин вони того дня \nпобачили",
                                             "Біля довгого забору ще одну тваринку \nзустріли",
                                             "Вони вівцю, що втекла з вольера знайшли",
                                             "Та разом далі блукати по світу пішли",
                                             "",
                                             "Третью вівцю назвали Trolly.",
                                             "A їз зоопарку у той день \nі так выпускали"});

QStringList textedStory::voyageTextUa=QStringList({"Polly, Lolly та Trolly збирали валізи",
                                                "Через тждень вони у теплі країни вирушали",
                                                "",
                                                "Polly у мандрівку добре зібралась",
                                                "Взяла карту і компас, але забула окуляри",
                                                "Lolly узяла для Polly окуляри",
                                                "Але забула узяти решту речей",
                                                "Trolly у мандрівку довше за всіх збиралась",
                                                "А взяла із собою тільки Polly та Molly."});
}
#endif // TEXTEDSTORY_H
