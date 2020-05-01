#include <QtTest>
#include <QCoreApplication>
#include "../src/viewmodel.h"

// add necessary includes here

class TestViewModel : public QObject
{
    Q_OBJECT

public:
    TestViewModel();
    ~TestViewModel();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TestViewModel::TestViewModel()
{

}

TestViewModel::~TestViewModel()
{

}

void TestViewModel::initTestCase()
{

}

void TestViewModel::cleanupTestCase()
{

}

void TestViewModel::test_case1()
{
    ViewModel viewmodel;
    QCOMPARE(viewmodel.isConnecting(), false);
}

QTEST_MAIN(TestViewModel)

#include "tst_testviewmodel.moc"
