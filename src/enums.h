#ifndef _ENUMS
#define _ENUMS

#include <QObject>

namespace ConnectionState {
  Q_NAMESPACE
  enum class State : quint8 {Disconnected, Connecting, Connected};
  Q_ENUM_NS(State)
}

#endif
