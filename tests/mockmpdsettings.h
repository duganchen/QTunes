#ifndef MOCKMPDSETTINGS_H
#define MOCKMPDSETTINGS_H

#include "../src/abstractmpdsettings.h"

// Mock *mpd_settings struct.
struct MPDSettings
{
};

class MockMPDSettings: AbstractMPDSettings<MPDSettings>
{
public:
	MockMPDSettings(QSharedPointer<MPDSettings> settings): AbstractMPDSettings<MPDSettings>(settings) {}
	virtual const char *host() const override
	{
		return "localhost";
	}
	virtual unsigned port() const override
	{
		return 6600;
	}
	virtual unsigned int timeout_ms() const override
	{
		return 0;
	}

	virtual const char *password() const override
	{
		return "";
	}
};

#endif // MOCKMPDSETTINGS_H
