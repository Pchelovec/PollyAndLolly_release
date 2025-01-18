#include "loader.h"

Loader::Loader(QObject *parent) : QObject(parent)
{
    map=new QMap<QString,QPixmap>;
}
