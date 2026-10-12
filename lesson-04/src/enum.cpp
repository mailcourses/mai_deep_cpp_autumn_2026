#include <iostream>

enum class COLOR
{
    RED,
    BLACK,
    UNKNOWN
};

enum class HttpCode
{
    SWITCH_PROTOCOL=101,
    OK=200,
    NOT_FOUND=404,
    UNKNOWN=-1
    
};

union Jack
{
    char a;
    int32_t b;
};

struct UnionJack
{
    char a;
    int32_t b;
};

int main()
{
    COLOR color = COLOR::RED;
    HttpCode status = HttpCode::NOT_FOUND;
    Jack gb;
    gb.a = 'a';
    std::cout << gb.a << std::endl;
    std::cout << gb.b << std::endl;
    gb.b = 100500;
    std::cout << gb.a << std::endl;
    std::cout << gb.b << std::endl;
    std::cout << sizeof(gb) << std::endl;
    std::cout << sizeof(UnionJack) << std::endl;
    return 0;
}
