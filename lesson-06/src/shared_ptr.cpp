#include <iostream>

struct A
{
    int a1;
    int a2;
    int b3;
    std::string s1;
    A& operator=(A&& rhs)
    {
        a1 = rhs.a1;
        a2 = rhs.a2;
        b3 = std::move(rhs.b3);
        s1 = std::move(rhs.s1);
        return *this;
    }
};

class shared_ptr
{
public:
    using T = int32_t;
private:
    struct wrapper_
    {
        T* data_ = nullptr;
        size_t counter_ = 0;
    };
public:
    shared_ptr() = default;
    shared_ptr(T* data) : obj_(new wrapper_{data, 1}) {}
    shared_ptr(const shared_ptr& rhs) : obj_(rhs.obj_)
    {
        increment();
    }

    shared_ptr(shared_ptr&& rhs) : obj_(rhs.obj_)
    {
        rhs.obj_ = nullptr;
    }

    shared_ptr& operator=(const shared_ptr& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        decrement();
        obj_ = rhs.obj_;
        increment();
        return *this;
    }

    shared_ptr& operator=(shared_ptr&& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        decrement();
        obj_ = rhs.obj_;
        rhs.obj_ = nullptr;
        return *this;
    }

    ~shared_ptr()
    {
        decrement();
    }
private:
    void increment()
    {
        if (obj_)
        {
            obj_->counter_ += 1;
        }
    }

    void decrement()
    {
        if (obj_ && obj_->counter_ != 0)
        {
            obj_->counter_ -= 1;
            if (obj_->counter_ == 0)
            {
                delete obj_->data_;
                delete obj_;
            }
        }
    }
private:
    wrapper_* obj_ = nullptr;
};

int main()
{
    {
        shared_ptr sp1(new shared_ptr::T{10});
        shared_ptr sp2{sp1};
        shared_ptr sp3(new shared_ptr::T{100500});
        sp1 = sp2;
        sp3 = sp3; // ???
    }

    {
        shared_ptr sp1(new shared_ptr::T{10});
        shared_ptr sp2{std::move(sp1)};
        shared_ptr sp3(new shared_ptr::T{100500});
        sp1 = std::move(sp3);
    }
}
