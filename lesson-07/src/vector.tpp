#include "vector.hpp"


namespace my
{

template<class T>
size_t vector<T>::size() const
{
    return size_;
}

template<class T>
void vector<T>::push_back(const T& rhs)
{
    data_[0] = rhs;
}

template class vector<int32_t>;
template class vector<std::string>;

} // namespace my
