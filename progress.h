#ifndef PROGRESS_H
#define PROGRESS_H

#include <QString>
#include<QFile>
#include<QTextStream>
#include<QFileInfo>
#include "state.h"
namespace  {

class Progress
{
private:

public:
    Progress(){}
    static QString filename;

    static bool saveProgress(Scene *state){
        bool result;
        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            qDebug()<<"Progerss save level"<<state->level<<" scene-"<<state->screen.getScreen();
            QTextStream stream( &file );
            stream << state->level <<endl;
            stream<<state->screen.getScreen();
            result=true;
        }
        file.close();
        return result;
    }

    static bool loadProgress(Scene *state){

        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            int level; int scene;
            QTextStream stream( &file );
            stream>>level;
            stream>>scene;
            qDebug()<<"Dessirialized level-"<<level<<" ,scene-"<<scene;
            state->setLevelAndScene((Level)level,Screen(scene));
            return true;
        }
        return false;
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
