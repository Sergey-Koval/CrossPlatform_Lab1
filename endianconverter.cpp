#include "endianconverter.h"

EndianConverter::EndianConverter()
{

}

QString EndianConverter::toHex(int n){
    int a = (n >> 24) & 0xFF;
    int b = (n >> 16) & 0xFF;
    int c = (n >>  8) & 0xFF;
    int d =  n        & 0xFF;
    return QString("%1").arg(a,0,16).toUpper() + " " +
           QString("%1").arg(b,0,16).toUpper() + " " +
           QString("%1").arg(c,0,16).toUpper() + " " +
           QString("%1").arg(d,0,16).toUpper();
}

int EndianConverter::ChangeEndiannes(int n){
    uint32_t res = 0;
    res |= (n & 0x000000FF) << 24u;
    res |= (n & 0x0000FF00) << 8u;
    res |= (n & 0x00FF0000) >> 8u;
    res |= (n & 0xFF000000) >> 24u;
    return res;
}
