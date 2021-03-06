#include <gpio.h>

using hal::sys_tick;
using namespace hal::gpio;

typedef output_t<PC8> led_a;
typedef output_t<PC9> led_b;

void loop();

int main()
{
    led_a::setup();
    led_b::setup();

    for (;;)
        loop();
}

void loop()
{
    led_a::toggle();

    if (led_a::read())
        led_b::toggle();

    sys_tick::delay_ms(250);
}

