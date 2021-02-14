#include <QtTest>

#include <../endianconverter.cpp>

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
    void test_case3();
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

void Test_EndianConverter::test_case3(){
    QVERIFY(conv->toHex(conv->ChangeEndiannes(100)) == QString("64 0 0 0"));
    QVERIFY(conv->toHex(conv->ChangeEndiannes(-100)) == QString("9C FF FF FF"));
}

QTEST_APPLESS_MAIN(Test_EndianConverter)

#include "tst_test_endianconverter.moc"
