#ifndef TRANSITIONSCREEN_H
#define TRANSITIONSCREEN_H

#include <QObject>
#include <QMap>
#include <QStack>
#include <QQuickView>

#include "Enums.h"
#include "Screen_A_Model.h"
#include "Screen_B_Model.h"

typedef void (*funcPtr)(bool);
struct SCENE_DATA
{
    funcPtr     f;
    QString     pathScene;
};

class TransitionScreen : public QObject
{
    Q_OBJECT
    QStack<int>                     m_scene_history;
    QQuickView*                     m_viewer;
    QMap<int, SCENE_DATA>           mapSceneInfo;
public:
    explicit TransitionScreen(QQuickView* viewer, QObject *parent = nullptr);

    Q_INVOKABLE void showScene(const int& scene_ID);
    Q_INVOKABLE void hideScene(const int& scene_ID);
    Q_INVOKABLE void backScene();

    void prepare_destroy_Scene_A(bool isPrepare);
    void prepare_destroy_Scene_B(bool isPrepare);

signals:
    void changeScene(QString pathScene, int scene_ID);

public slots:

private:
    // Model
    Screen_A_Model* s_model_scr_A;
    Screen_B_Model* s_model_scr_B;
};

#endif // TRANSITIONSCREEN_H
