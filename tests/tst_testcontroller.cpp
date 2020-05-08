#include <QCoreApplication>
#include <QtTest>

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
	QCOMPARE(1, 1);
}

QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
