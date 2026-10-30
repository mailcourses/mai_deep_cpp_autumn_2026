#pragma once

#include <stddef.h>

namespace my
{

template<class T>
class vector
{
public:
    vector(size_t size): size_(size), data_(new T[size_])
    {
    }

    size_t size() const;
    void push_back(const T& rhs);
private:
    size_t size_;
    T* data_;
};

/*
template<class T>
size_t vector<T>::size() const
{
    return size_;
}

template<class T>
void vector<T>::push_back(const T& rhs)
{
    data_[0] = rhs;
}*/

} // namespace my

#include "vector.tpp"
