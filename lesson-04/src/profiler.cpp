#include <iostream>
#include <chrono>
#include <thread>
#include <source_location>

class Profiler
{
public:
    Profiler(std::source_location location = std::source_location::current())
    {
        start_ = std::chrono::system_clock::now();
        location_ = location;
    }

    ~Profiler()
    {
        end_ = std::chrono::system_clock::now();
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>( end_ - start_ ).count();
        std::cout << "Execution of function '" << location_.function_name() << "' is " << microseconds << " microseconds." << std::endl;
    }
private:
   std::chrono::time_point<std::chrono::system_clock> start_;
   std::chrono::time_point<std::chrono::system_clock> end_;
   std::source_location location_;
};

void foo()
{
    Profiler profiler;
    std::this_thread::sleep_for(std::chrono::microseconds{12});
}

void boo()
{
    Profiler profiler;
    for(size_t i = 0; i < 100000000; ++i);
}
int main()
{
    foo();
    boo();
    foo();
    return 0;
}
