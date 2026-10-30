#include <iostream>
#include <vector>

template<class Container, class Index>
auto authAndGet(Container& c, Index i) -> decltype(c[i])
{
    // auth();
    return c[i];
}

int main()
{
    std::vector<int> arr(10, -230);
    std::cout << authAndGet(arr, 0) << std::endl;
}
