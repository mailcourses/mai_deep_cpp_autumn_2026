#include <cstdint>
#include <string>

[[deprecated("Use fastcos instead of cos")]]
double cos(double)
{
    return 0.0;
}

[[gnu::fastcall]]
double fastcos(double)
{
    return 0.0;
}

[[nodiscard]]
uint32_t get_status([[maybe_unused]] const std::string& url)
{
    return 404;
}


int main()
{
    cos(10.4);
    [[maybe_unused]] auto status = get_status("https://vk.ru");
    if (status != 200) [[unlikely]]
    {
        return 0;
    }
    else 
    {
        fastcos(status);
    }
    return 0;
}
