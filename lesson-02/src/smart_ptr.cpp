#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> sp1{new int{100500}};
    std::shared_ptr<int> sp2{sp1};
    {
        std::shared_ptr<int> sp3;
        sp3 = sp2;
    }
    return 0;
}
