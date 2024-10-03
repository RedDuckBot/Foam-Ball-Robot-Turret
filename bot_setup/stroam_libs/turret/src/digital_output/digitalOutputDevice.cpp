#include "digitalOutputDevice.hpp"

namespace outputDevice
{
    DigitalOutputDevice::~DigitalOutputDevice() 
    {
        fmt::print("Closing GPIO pin {}\n",device_GPIO_pin_);
        off();
    }

    DigitalOutputDevice::DigitalOutputDevice(unsigned int gpioPin)
    {
        this -> device_GPIO_pin_ = gpioPin;
        gpioSetMode(gpioPin, PI_OUTPUT);
        off();
    }

    void DigitalOutputDevice::on()
    {
        gpioWrite(device_GPIO_pin_, 1);
    }

    void DigitalOutputDevice::off()
    {
        gpioWrite(device_GPIO_pin_, 0);
    }
}
