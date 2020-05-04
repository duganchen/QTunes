#include <QtTest>
#include <QCoreApplication>
#include "../src/controller.h"
#include "mockhostinfo.h"

// Note: The error message for a host not being found is
// Host not found

// The error message from MPD the connection is lost is:
// Connection closed by the server

#include "../src/abstractmpdsettings.h"

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

class TestController : public QObject
{
    Q_OBJECT

public:
    TestController();
    ~TestController();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
	void test_case2();
};

TestController::TestController()
{

}

TestController::~TestController()
{

}

void TestController::initTestCase()
{

}

void TestController::cleanupTestCase()
{

}

void TestController::test_case1()
{
	QSharedPointer<MPDSettings> settings_data(new MPDSettings());
	MockMPDSettings settings(settings_data);
	QCOMPARE(settings.host(), "localhost");

    MockHostInfo hostInfo;
    Controller viewmodel(&hostInfo);
    QCOMPARE(viewmodel.isConnecting(), false);
}

void TestController::test_case2()
{
	// This doesn't get executed. Why?
	QCOMPARE(1, 2);
	QCOMPARE(1, 2);
}

QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
