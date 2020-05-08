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
	void test_case1();
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

void TestPresenter::test_case1()
{
	QCOMPARE(1, 1);
}

QTEST_MAIN(TestPresenter)

#include "tst_testpresenter.moc"
