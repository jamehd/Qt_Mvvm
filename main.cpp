#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include "TransitionScreen.h"
#include "Model.h"
#include "Enums.h"
#include "Dbus_Communication.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Init
    QQuickView viewer;
    TransitionScreen    _transitionScreen(&viewer, nullptr);

    // External Communication
    Dbus_Communication::getInstance();


    // Register to QML Layer
    qmlRegisterUncreatableType<Enums>("ENUMS",1,0,"ENUMS","Enums for QML Layer and C++ Layer");
    viewer.rootContext()->setContextProperty("TRANSITION_SCREEN", &_transitionScreen);



    // Show Base Screen
    viewer.setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    viewer.show();

    return app.exec();
}
