#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#define LOG qDebug() << "[" << __PRETTY_FUNCTION__ << "][" << __LINE__ << "]"
#define LOG_START_SUNCTION LOG << "LOG_START_SUNCTION"

#endif // LOGGER_H
