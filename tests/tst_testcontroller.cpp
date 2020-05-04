#include <QtTest>
#include <QCoreApplication>
#include "../src/controller.h"
#include "mockhostinfo.h"
#include "mockmpdsettings.h"

// Note: The error message for a host not being found is
// Host not found

// The error message from MPD the connection is lost is:
// Connection closed by the server


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
    MockHostInfo hostInfo;
    Controller viewmodel(&hostInfo);
    QCOMPARE(viewmodel.isConnecting(), false);
}

void TestController::test_case2()
{
	// Qt Creator isn't executing this. But "make check" works.
	QSharedPointer<MPDSettings> settings_data(new MPDSettings());
	MockMPDSettings settings(settings_data);
	QCOMPARE(settings.host(), "localhost");
}

QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
