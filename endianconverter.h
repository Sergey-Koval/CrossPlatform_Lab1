#ifndef ENDIANCONVERTER_H
#define ENDIANCONVERTER_H
#include <QString>

class EndianConverter
{
public:
    EndianConverter();
    QString toHex(int n);
    int ChangeEndiannes(int n);
};

#endif // ENDIANCONVERTER_H
