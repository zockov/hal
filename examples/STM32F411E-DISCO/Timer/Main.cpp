#include <timer.h>
#include <gpio.h>

using namespace hal;
using namespace timer;
using namespace gpio;

template<int TNO, gpio_pin_t PIN, int X>
struct example_t
{
    typedef timer_t<TNO> tim;
    typedef output_t<PIN> led;

    static void setup()
    {
        tim::setup(X, 65535);
        tim::update_interrupt_enable();
        led::setup();
    }

    static void isr()
    {
        tim::clear_uif();
        led::toggle();
    }
};

typedef example_t<1, PD12, 100> exa;
typedef example_t<3, PD13, 120> exb;
typedef example_t<4, PD14, 140> exc;
typedef example_t<5, PD15, 160> exd;

template<> void handler<interrupt::TIM1_UP_TIM10>()
{
    exa::isr();
}

template<> void handler<interrupt::TIM3>()
{
    exb::isr();
}

template<> void handler<interrupt::TIM4>()
{
    exc::isr();
}

template<> void handler<interrupt::TIM5>()
{
    exd::isr();
}

int main()
{
    exa::setup();
    exb::setup();
    exc::setup();
    exd::setup();

    hal::nvic<interrupt::TIM1_UP_TIM10>::enable();
    hal::nvic<interrupt::TIM3>::enable();
    hal::nvic<interrupt::TIM4>::enable();
    hal::nvic<interrupt::TIM5>::enable();
    interrupt::enable();

    for (;;);
}

