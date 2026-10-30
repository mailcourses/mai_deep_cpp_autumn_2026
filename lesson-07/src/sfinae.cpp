#include <iostream>

struct A
{
    int cached() const
    {
        return 10000;
    }
};

struct B
{
    double cached() const
    {
        return 10000.9;
    }
};

template<class T>
struct has_cached
{
    static void checked(...);

    template<class U>
    static auto checked(U* u) -> decltype(u->cached());

    static const bool value = std::is_same<decltype(has_cached<T>::checked(static_cast<T*>(nullptr))), int>::value;
};

template<class T>
int calculate(const T& t,
              typename std::enable_if<has_cached<T>::value>::type* = nullptr)
{
    std::cout << "fast calculate" << std::endl;
    return t.cached();
}

template<class T>
int calculate(const T& t,
              typename std::enable_if<!has_cached<T>::value>::type* = nullptr)
{
    int res = 0;
    std::cout << "looooooong calculate" << std::endl;
    // Долгие вычисления res
    return res;
}


int main()
{
    A a;
    calculate(a);
    int c;
    calculate(c);
    B b;
    calculate(b);
}
