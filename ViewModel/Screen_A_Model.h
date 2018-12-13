#ifndef SCREEN_A_MODEL_H
#define SCREEN_A_MODEL_H

#include <QObject>
#include "Logger.h"

class Screen_A_Model : public QObject
{
    Q_OBJECT
public:
    explicit Screen_A_Model(QObject *parent = nullptr);
    ~ Screen_A_Model();

signals:

public slots:
};

#endif // SCREEN_A_MODEL_H
