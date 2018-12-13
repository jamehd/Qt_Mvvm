#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject
{
    Q_OBJECT
    Q_ENUMS(SCENE)
public:
    enum SCENE {
        SCENE_A = 0,
        SCENE_B,
    };

};

#endif // ENUMS_H
