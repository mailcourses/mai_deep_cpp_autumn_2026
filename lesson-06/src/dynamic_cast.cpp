#include <iostream>

struct A
{
    virtual void voice()
    {
        std::cout << "A::voice" << std::endl;
    }

    void foo() &
    {
        std::cout << "lvalue foo" << std::endl;
    }

    void foo() &&
    {
        std::cout << "rvalue foo" << std::endl;
    }
};

struct B: A
{
    virtual void voice() override
    {
        std::cout << "B::voice" << std::endl;
    }

    void methodSpecificToB()
    {
        std::cout << "B::methodSpecificToB" << std::endl;
    }

};

void foo(A* a)
{
    B* b = dynamic_cast<B*>(a);
    if (b)
        b -> methodSpecificToB();
    else
        std::cerr << "Этот объект не является объектом типа B" << std::endl;
}

void foo(A& a)
{
    try
    {
        B& b = dynamic_cast<B&>(a);
        b.methodSpecificToB();
    }
    catch(std::bad_cast& ex)
    {
        std::cerr << "Этот объект не является объектом типа B" << std::endl;
    }
}

int main()
{
    A* a = new B;

    A a1;
    a1.foo();
    A().foo();

    foo(a);
    foo(*a);
}
