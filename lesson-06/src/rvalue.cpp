#include <iostream>

void increment(long long&& a)
{
    std::cout << "rvalue ++" << std::endl;
    ++a;
}

void increment(long long& a)
{
    std::cout << "lvalue ++" << std::endl;
    ++a;
}

struct Foo
{
    Foo(int a) : x(a) {}
    Foo(const Foo&) = default;
    Foo(Foo&&) = default;
    ~Foo() = default;
    int x;
};

const Foo& create(const Foo& foo)
{
    return foo;
};

int main()
{
    int x = 5;
    increment(x);
    std::cout << x << std::endl; //?
    increment(std::move(x));
    std::cout << x << std::endl; //?
    {
        Foo foo = create(5);
        std::cout << foo.x << std::endl; //?
    }
    {
        const Foo &foo = create(5);
        std::cout << foo.x << std::endl; //?
    }
}
