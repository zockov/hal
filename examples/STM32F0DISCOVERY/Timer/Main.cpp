#include <timer.h>
#include <gpio.h>

using namespace hal::timer;
using namespace hal::gpio;

typedef timer_t<1> tim_a;
typedef timer_t<3> tim_b;

typedef output_t<PC8> led_a;
typedef output_t<PC9> led_b;

template<> void handler<interrupt::TIM1_BRK_UP_TRG_COM>()
{
    tim_a::clear_uif();
    led_a::toggle();
}

template<> void handler<interrupt::TIM3>()
{
    tim_b::clear_uif();
    led_b::write(!led_a::read());
}

int main()
{
    tim_a::setup(100, 65535);
    tim_a::update_interrupt_enable();

    tim_b::setup(120, 65535);
    tim_b::update_interrupt_enable();

    led_a::setup();
    led_b::setup();

    hal::nvic<interrupt::TIM1_BRK_UP_TRG_COM>::enable();
    hal::nvic<interrupt::TIM3>::enable();
    interrupt::enable();

    for (;;);
}

