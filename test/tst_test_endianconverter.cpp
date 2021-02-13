#include <QtTest>


#include <../endianconverter.cpp>

// add necessary includes here

class Test_EndianConverter : public QObject
{
    Q_OBJECT

public:
    Test_EndianConverter();
    ~Test_EndianConverter();
private:
    EndianConverter * conv;
private slots:
    void test_case1();
    void test_case2();

};

Test_EndianConverter::Test_EndianConverter()
{
    conv = new EndianConverter;
}

Test_EndianConverter::~Test_EndianConverter()
{

}

void Test_EndianConverter::test_case1()
{
    QVERIFY(conv->toHex(1) == conv->toHex(1));
}

void Test_EndianConverter::test_case2(){

    QVERIFY(conv->ChangeEndiannes(conv->ChangeEndiannes(1)) == 1);
}

QTEST_APPLESS_MAIN(Test_EndianConverter)

#include "tst_test_endianconverter.moc"
