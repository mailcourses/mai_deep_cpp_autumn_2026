#include <iostream>

#include "header.hpp"

static int local = 0;

void foo()
{
    static int j = 0;
    std::cout << "foo:j=" << j << std::endl;
    ++j;
    ++local;
}

void f(int i)
{
    std::cout << "f(int)" << std::endl;
}

void f(char *s)
{
    std::cout << "f(char*)" << std::endl;
}

int main()
{
    /*uint64_t arr[2000000];
    arr[0] = 0;*/
    for(size_t i = 0; i < 5; ++i)
    {
        foo();
    }

    int a = 100500;
    int* b = &a;
    int** c = &b;
    int*** d = &c;
    std::string* sptr = nullptr;
    char* ch = nullptr;
    std::cout << sizeof(b) << " " << sizeof(c) << " " << sizeof(sptr) << " " << sizeof(ch) << std::endl;

    //f(NULL);
    f(nullptr);

    int* i1 = new int{1};
    int* i2 = i1;
    delete i1;
    delete i2;

    return local;
}
