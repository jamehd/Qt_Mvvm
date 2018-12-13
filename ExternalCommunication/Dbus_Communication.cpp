#include "Dbus_Communication.h"
#include "Logger.h"

Dbus_Communication_Listener::Dbus_Communication_Listener()
{
    m_interfaceAdaptor = new InterfaceAdaptor(this);

    connect(m_interfaceAdaptor, &InterfaceAdaptor::sendData, this, &Dbus_Communication_Listener::sendData, Qt::QueuedConnection);

    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/dbusA", m_interfaceAdaptor);
    connection.registerService("jamehd.example.mvvmstructure");
}

Dbus_Communication_Listener::~Dbus_Communication_Listener()
{

}

void Dbus_Communication_Listener::backScene()
{
    LOG_START_SUNCTION;
}

void Dbus_Communication_Listener::sendData(int msgID, const QString &data)
{
    LOG_START_SUNCTION  << msgID << data;
}

Dbus_Communication::Dbus_Communication()
{
    m_interface = new jamehd::example::mvvmstructure::interface("jamehd.example.mvvmstructure", "/dbusA",
                                                                QDBusConnection::sessionBus(), this);
}

Dbus_Communication::~Dbus_Communication()
{
    delete m_interface;
    delete m_listener;
}

Dbus_Communication *Dbus_Communication::getInstance()
{
    static Dbus_Communication inst;
    return &inst;
}

void Dbus_Communication::initialize()
{
    m_listener = new Dbus_Communication_Listener();
}


