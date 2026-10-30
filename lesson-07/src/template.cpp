#include <array>

template<class T, class Y>
class Foo
{
    T data1;
    Y data2;
public:
    void fake()
    {
    }
};

int foo()
{
    Foo<int, int> a1;
    Foo<int, double> a2;
    a1.fake();
    a2.fake();
    //Foo<std::string, float> a3;
    std::array<int, 10> array;
    array[5] = 100500;
    return 0;
}
