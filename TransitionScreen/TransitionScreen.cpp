#include "TransitionScreen.h"
#include <QQmlContext>
#include "Logger.h"

#define PATH_SCENE_A QString("qrc:/qml/Screen/Screen_A.qml")
#define PATH_SCENE_B QString("qrc:/qml/Screen/Screen_B.qml")

TransitionScreen::TransitionScreen(QQuickView *viewer, QObject *parent) : QObject(parent)
{
    m_viewer = viewer;
    mapSceneInfo =
    {
        {Enums::SCENE::SCENE_A, {[](bool isPrepare){this->prepare_destroy_Scene_A(isPrepare);}, PATH_SCENE_A}},
        {Enums::SCENE::SCENE_B, {[](bool isPrepare){this->prepare_destroy_Scene_B(isPrepare);}, PATH_SCENE_B}},
    };
}

void TransitionScreen::showScene(const int &scene_ID)
{
    LOG_START_SUNCTION;
    if(!m_scene_history.isEmpty())
    {
        if(m_scene_history.back() == scene_ID)
        {
            LOG << "Next Scene is same current Scene, so not change scene";
            return;
        }
    }
    LOG << "Check Scene in a map";
    if(mapSceneInfo.contains(scene_ID))
    {
        LOG << "Scene is defined, Save scene to queue";
        m_scene_history.push_back(scene_ID);

        LOG << "Prepare to change scene";
        funcPtr func = mapSceneInfo.value(scene_ID).f;
        if(func)
            func(true);
        LOG << "Change Scene in QML Layer";
        emit changeScene(mapSceneInfo.value(scene_ID).pathScene, scene_ID);
    }
    else
    {
        LOG << "Scene is not define";
        return;
    }
}

void TransitionScreen::hideScene(const int &scene_ID)
{
    LOG_START_SUNCTION;
    if(mapSceneInfo.contains(scene_ID))
    {
        funcPtr func = mapSceneInfo.value(scene_ID).f;
        if(func)
            func(false);
    }
    else
    {
        LOG << "Scene is not define";
        return;
    }
}

void TransitionScreen::backScene()
{
    if(!m_scene_history.isEmpty())
    {
        LOG << "Remove Last scene in Queue";
        m_scene_history.pop_back();
        if(!m_scene_history.isEmpty())
        {
            LOG << "Prepare to change scene";
            funcPtr func = mapSceneInfo.value(m_scene_history.last()).f;
            if(func)
                func(true);
            LOG << "Change Scene in QML Layer";
            emit changeScene(mapSceneInfo.value(m_scene_history.last()).pathScene, m_scene_history.last());
        }
        else
            LOG << "Back to Previous Application";
    }
    else
    {
        LOG << "Scene queue is empty, Impossible";
        return;
    }
}

void TransitionScreen::prepare_destroy_Scene_A(bool isPrepare)
{
    if(isPrepare)
    {
        LOG << "PREPARE";
        s_model_scr_A = new Screen_A_Model();
        m_viewer->rootContext()->setContextProperty("scene_A_model_view", s_model_scr_A);
    }
    else
    {
        LOG << "DESTROY";
        delete s_model_scr_A;
    }
}

void TransitionScreen::prepare_destroy_Scene_B(bool isPrepare)
{
    if(isPrepare)
    {
        LOG << "PREPARE";
        m_viewer->rootContext()->setContextProperty("scene_B_model_view", s_model_scr_B);
        s_model_scr_B = new Screen_B_Model();
    }
    else
    {
        LOG << "DESTROY";
        s_model_scr_B->deleteLater();
    }
}

