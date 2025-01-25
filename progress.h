#ifndef PROGRESS_H
#define PROGRESS_H

#include <QString>
#include<QFile>
#include<QTextStream>
#include<QFileInfo>
#include "state.h"
#include"textedstory.h"
namespace  {

class Progress
{
private:

public:
    Progress(){}
    static QString filename;

    static bool saveProgress(Scene *state, supportedLanguage lang){
        bool result;
        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            qDebug()<<"Applicaction language is "<<lang;
            qDebug()<<"Progerss save level"<<state->level<<" scene-"<<state->screen.getScreen();
            QTextStream stream( &file );
            stream << lang <<endl;
            stream << state->level <<endl;
            stream<<state->screen.getScreen();
            result=true;
        }
        file.close();
        return result;
    }

    //load level and last painted scene to state
    //return language
    static int loadProgress(Scene *state){

        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            int lang; int level; int scene;
            QTextStream stream( &file );
            stream>>lang;
            stream>>level;
            stream>>scene;
            qDebug()<<"Dessirialized level-"<<level<<" ,scene-"<<scene;
            qDebug()<<"restored lang "<<lang;
            state->setLevelAndScene((Level)level,Screen(scene));
            return lang;
        }
        return 0;
    }

    static bool removeProgress(){
        QFile::remove(filename);
    }

    static bool progressExist(){
        QFileInfo check_file(filename);
        // check if file exists and if yes: Is it really a file and not a directory?
        if (check_file.exists() && check_file.isFile()) {
            return true;
        }
        return false;
    }
};
QString Progress::filename="finished.txt";
}

#endif // PROGRESS_H
