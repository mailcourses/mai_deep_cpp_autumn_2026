#include <iostream>

using Log = int;

class Device
{
public:
    Device() : logger(new Log{1})
    {
        std::cout << "Device()" << std::endl;
    }
    virtual void write(const std::string& message)
    {
        std::cout << "Device: " << message << std::endl;
    }
    virtual ~Device()
    {
        std::cout << "~Device()" << std::endl;
        delete logger;
    }
private:
    Log* logger = nullptr;
};

class Printer : public Device
{
public:
    Printer() : data_(new char[1024])
    {
        std::cout << "Printer()" << std::endl;
    }

    void write(const std::string& message) override
    {
        std::cout << "Printer: " << message << std::endl;
    }

    ~Printer()
    {
        std::cout << "~Printer()" << std::endl;
        delete[] data_;
    }
private:
    char* data_;
};

class Terminal : public Device
{
public:
    void write(const std::string& message) override
    {
        std::cout << "Terminal: " << message << std::endl;
    }
};

Device* detectDevice(const std::string& device_str)
{
    if (device_str == "terminal")
    {
        return new Terminal;
    }
    if (device_str == "printer")
    {
        return new Printer;
    }
    return nullptr;
}

int main(int argc, char** argv)
{
    std::string device_str{argv[1]};
    std::string message{argv[2]};
    Device* device = detectDevice(device_str);
    device->write(message);

    std::cout << "sizeof(Device): " << sizeof(Device) << std::endl;
    //Terminal* terminal = static_cast<Terminal*>(device);
    //terminal->write(message);
    delete device;
    return 0;
}
