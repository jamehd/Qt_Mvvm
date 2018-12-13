#ifndef DBUS_COMMUNICATION_H
#define DBUS_COMMUNICATION_H

#include <communication_adaptor.h>
#include <communication_interface.h>

#include <QObject>

class Dbus_Communication_Listener : public QObject
{
    Q_OBJECT
    InterfaceAdaptor* m_interfaceAdaptor;
public:
    Dbus_Communication_Listener();
    virtual ~Dbus_Communication_Listener();

public slots:
    // Call back function
    void backScene();
    void sendData(int msgID, const QString &data);
};

class Dbus_Communication : public QObject
{
    Q_OBJECT
    jamehd::example::mvvmstructure::interface*  m_interface;
    Dbus_Communication_Listener*                m_listener;

    Dbus_Communication();
public:
    virtual ~Dbus_Communication();

    static Dbus_Communication* getInstance();

    void initialize();


};

#endif // DBUS_COMMUNICATION_H
