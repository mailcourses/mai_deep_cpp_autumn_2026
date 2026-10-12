#include <iostream>
#include <vector>
#include <unordered_map>



class Boo
{
// private
public:
    Boo(int32_t /*a*/)
    {
    }
};

struct Foo
{
//public
    /*Foo()
    {
        std::cout << "default ctr" << std::endl;
    }*/
    Foo() = default;

    //Foo(const Foo& rhs); //<-- конструктор копирования
    

    Foo(int32_t a) : size_(a), data_(new int[size_]), boo_(100500), ref(a)
    {
        std::cout << "user ctr" << std::endl;
    }

    ~Foo()
    {
        if (data_) 
        {
            //delete[] data_;
        }
        std::cout << "default dctr {ref=" << ref << "}" << std::endl;
    }

    void clear(/*Foo* this*/)
    {
        if (this->data_)
        {
            delete[] this->data_;
            data_ = nullptr;
        }
    }

    int calculate(/*const Foo* const this*/) const
    {
        std::cout << "size of hash_ is " << hash_.size() << std::endl;
        auto res = size_ * 10 - hash_["default"].size();
        std::cout << "size of hash_ is " << hash_.size() << std::endl;
        return res;
    }

    static void get()
    {
        // Запрещено обращаться к this
        return;
    }
private:
    size_t size_;
    int32_t *data_ = nullptr;
    Boo boo_;
    int32_t& ref;
    mutable std::unordered_map<std::string, std::vector<int>> hash_;
};

int main()
{
    Foo foo{10}; // == Foo foo(); = Foo foo; foo.Foo();
    Foo foo2{foo};
    foo2.calculate();
    //Foo foo3{-10};
    //foo3.clear();
    Foo::get();
    return 0;
}
