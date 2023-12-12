#ifndef UNTITLED1_BIGINTEGER_H
#define UNTITLED1_BIGINTEGER_H
#include <iostream>
#include <string>
using namespace std;//add std to define string
class BigDecimalInt {
    string BigInteger;
public:
    int value_checker(string str1,string str2);
    BigDecimalInt (string decStr);
    BigDecimalInt (int decInt);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    friend ostream& operator << (ostream& out, BigDecimalInt b);
    int size();
    int sign();
};
#endif //UNTITLED1_BIGINTEGER_H
