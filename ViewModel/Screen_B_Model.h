#ifndef SCREEN_B_MODEL_H
#define SCREEN_B_MODEL_H

#include <QObject>
#include "Logger.h"

class Screen_B_Model : public QObject
{
    Q_OBJECT
public:
    explicit Screen_B_Model(QObject *parent = nullptr);
    ~Screen_B_Model();

signals:

public slots:
};

#endif // SCREEN_B_MODEL_H
