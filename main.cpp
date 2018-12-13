#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include "TransitionScreen.h"
#include "Model.h"
#include "Enums.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Init
    QQuickView viewer;
    TransitionScreen    _transitionScreen(&viewer, nullptr);

    // Register to QML Layer
    qmlRegisterUncreatableType<Enums>("ENUMS",1,0,"ENUMS","Enums for QML Layer and C++ Layer");
    viewer.rootContext()->setContextProperty("TRANSITION_SCREEN", &_transitionScreen);


    viewer.setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    viewer.show();

    return app.exec();
}
