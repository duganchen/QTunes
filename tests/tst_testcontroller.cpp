#include <QtTest>
#include <QCoreApplication>
#include "../src/controller.h"
#include "mockhostinfo.h"
#include "mockmpdsettings.h"
#include "mockmpdsettingsfactory.h"

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
    void test_controller();
    void test_mockSettings();
    void test_mockSettingsFactory();
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


void TestController::test_mockSettings()
{
    MockMPDSettings settings(nullptr, 0, 0, nullptr, nullptr);
    QCOMPARE("localhost", settings.host());
}

void TestController::test_mockSettingsFactory()
{
    MockMPDSettingsFactory settingsFactory;
    auto settings = settingsFactory.createSettings(nullptr, 0, 0, nullptr, nullptr, nullptr);
    QCOMPARE(settings->host(), "localhost");
    delete settings;
}

void TestController::test_controller()
{
    MockHostInfo hostInfo;
    MockMPDSettingsFactory settingsFactory;
    Controller controller(&hostInfo, &settingsFactory);
    QVERIFY(true);
}

QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
