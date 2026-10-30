#include <iostream>


class Origin
{
public:
    Origin() { std::cout << "Origin()" << std::endl; }
    ~Origin() { std::cout << "~Origin()" << std::endl; }
};

class A
{
public:
    explicit A(int a_): a(a_) { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }

    friend std::ostream& operator<<(std::ostream& os, const A& rhs);

protected:
    int a = 0;
    double b = 0.0;
    char c = '\0';
};

class B : public A, public Origin
{
public:
    B() : A(100500)
    {
        std::cout << "B()" << std::endl;
    }
    ~B() { std::cout << "~B()" << std::endl; }

    void help()
    {
        a += static_cast<int>(d);
    }

private:
    bool d = false;
};

std::ostream& operator<<(std::ostream& os, const A& rhs)
{
    os << "A(" << rhs.a << ", " << rhs.b << ", " << rhs.c << ")";
    return os;
}

void fake(A obj)
{
    //...
}

struct C
{
// TODO: почему sizeof(C) == 4?
    int32_t val1 : 4;
    bool flag1 : 1;
};

struct D
{
    int32_t val3;
    int32_t val1;
    double val2;
};


int main()
{
    {
        A obj = A(1);
        //fake(10);
        std::cout << obj << std::endl;
    }

    {
        B obj;
        std::cout << obj << std::endl;
    }

    {
        std::cout << sizeof(C) << std::endl;
    }
    {
        std::cout << sizeof(D) << std::endl;
    }
    return 0;
}
