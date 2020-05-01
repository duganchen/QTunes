#include <QtTest>
#include <QCoreApplication>
#include "../src/controller.h"
#include "mockhostinfo.h"

// Note: The error message for a host not being found is
// Host not found

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

QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
