#ifndef ABSTRACTMPDSETTINGS_H
#define ABSTRACTMPDSETTINGS_H

#include <QSharedPointer>

template <typename T> class AbstractMPDSettings
{
public:
	AbstractMPDSettings(QSharedPointer<T> settings): m_settings(settings) {}
	virtual const char *host() const = 0;
	virtual unsigned port() const = 0;
	virtual unsigned timeout_ms() const = 0;
	virtual const char *password() const = 0;
private:
	QSharedPointer<T> m_settings;
};

#endif // ABSTRACTMPDSETTINGS_H
