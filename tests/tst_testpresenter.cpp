#include "../src/presenter.h"
#include "mockhostinfo.h"
#include "mockmpdconnectionfactory.h"
#include "mockmpdsettings.h"
#include "mockmpdsettingsfactory.h"
#include <QCoreApplication>
#include <QtTest>

// Note: The error message for a host not being found is
// Host not found

// The error message from MPD the connection is lost is:
// Connection closed by the server

class TestPresenter : public QObject
{
    Q_OBJECT

public:
    TestPresenter();
    ~TestPresenter();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_controller();
    void test_mockSettings();
    void test_mockSettingsFactory();
};

TestPresenter::TestPresenter()
{
}

TestPresenter::~TestPresenter()
{
}

void TestPresenter::initTestCase()
{
}

void TestPresenter::cleanupTestCase()
{
}

void TestPresenter::test_mockSettings()
{
    MockMPDSettings settings(nullptr, 0, 0, nullptr, nullptr);
    QCOMPARE("localhost", settings.host());
}

void TestPresenter::test_mockSettingsFactory()
{
    MockMPDSettingsFactory settingsFactory;
    auto settings = settingsFactory.createSettings(nullptr, 0, 0, nullptr, nullptr, nullptr);
    QCOMPARE(settings->host(), "localhost");
    delete settings;
}

void TestPresenter::test_controller()
{
    MockHostInfo hostInfo;
    MockMPDSettingsFactory settingsFactory;
    MockMPDConnectionFactory connectionFactory;
    Presenter controller(&hostInfo, &settingsFactory, &connectionFactory);
    QVERIFY(true);
}

QTEST_MAIN(TestPresenter)

#include "tst_testpresenter.moc"
