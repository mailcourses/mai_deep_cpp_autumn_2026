#include "header1.hpp"

int gVar1 = 1;
const int gVar2 = 2;
int gVar3;

int square(int num)
{
    return num * num;
}

double square(double num)
{
    return num * num;
}

extern "C" {

int square(long long num)
{
    return num * num;
}

}
