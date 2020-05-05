#include "abstractmpdconnection.h"

AbstractMPDConnection::AbstractMPDConnection(QObject *parent) : QObject(parent), m_state(ConnectionState::Disconnected)
{
}
