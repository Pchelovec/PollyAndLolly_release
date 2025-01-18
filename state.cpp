#include "state.h"

Scene::Scene(QObject *parent) : QObject(parent)
{
    this->level=Level::PROLOG;
    this->screen=Prolog_scene::Prolog_StartMenuScreen;
}

Scene::Scene(Level l, Screen s)
{
    this->level=l;
    this->screen=s;
}

void Scene::setLevelAndScene(Level l, Screen s)
{
    screen=s;
    level=l;
}

void Scene::incrementScene()
{
    screen++;
}

void Scene::incrementLevel()
{
    screen=Screen(0);
    level = static_cast<Level>((level + 1));
}
