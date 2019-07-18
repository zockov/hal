////
//
//        STM32F411 vectors
//
////

template<> void handler<isr::NMI>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::HARDFAULT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::MEMMANAGE>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::BUSFAULT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::USAGEFAULT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SVCALL>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::DEBUG>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::PENDSV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SYSTICK>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::PVD>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TAMP_STAMP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::RTC_WKUP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::FLASH>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::RCC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::ADC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI9_5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM1_BRK_TIM9>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM1_UP_TIM10>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM1_TRG_COM_TIM11>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM1_CC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::I2C1_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::I2C1_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::I2C2_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::I2C2_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SPI1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SPI2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::EXTI15_10>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::RTC_ALARM>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::OTG_FS_WKUP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SDIO>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::TIM5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SPI3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::OTG_FS>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::I2C3_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::I2C3_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::FPU>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<isr::SPI4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));

void (*vectors[])(void) __attribute__ ((section(".vectors"))) =
    { (void(*)(void)) &__estack     // -16: Initial stack pointer
    , handler<isr::RESET>                     // -15: Reset [fixed]
    , handler<isr::NMI>                       // -14: Non maskable interrupt [fixed]
    , handler<isr::HARDFAULT>                 // -13: All class of fault [fixed]
    , handler<isr::MEMMANAGE>                 // -12: Memory management [settable]
    , handler<isr::BUSFAULT>                  // -11: Pre-fetch fault, memory access fault [settable]
    , handler<isr::USAGEFAULT>                // -10: Undefined instruction or illegal state [settable]
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::SVCALL>                    // -5: System service call via SWI instruction [settable]
    , handler<isr::DEBUG>                     // -4: Monitor Debug Monitor [settable]
    , 0x0
    , handler<isr::PENDSV>                    // -2: Pendable request for system service [settable]
    , handler<isr::SYSTICK>                   // -1: System tick timer [settable]
    , 0x0
    , handler<isr::PVD>                       // 1: PVD through EXTI line detection interrupt
    , handler<isr::TAMP_STAMP>                // 2: Tamper and TimeStamp interrupts through the EXTI line
    , handler<isr::RTC_WKUP>                  // 3: RTC Wakeup interrupt through the EXTI line
    , handler<isr::FLASH>                     // 4: FLASH global interrupt
    , handler<isr::RCC>                       // 5: RCC global interrupt
    , handler<isr::EXTI0>                     // 6: EXTI Line0 interrupt
    , handler<isr::EXTI1>                     // 7: EXTI Line1 interrupt
    , handler<isr::EXTI2>                     // 8: EXTI Line2 interrupt
    , handler<isr::EXTI3>                     // 9: EXTI Line3 interrupt
    , handler<isr::EXTI4>                     // 10: EXTI Line4 interrupt
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::ADC>                       // 18: ADC1 global interrupt
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::EXTI9_5>                   // 23: EXTI Line[9:5] interrupts
    , handler<isr::TIM1_BRK_TIM9>             // 24: TIM1 Break interrupt and TIM9 global interrupt
    , handler<isr::TIM1_UP_TIM10>             // 25: TIM1 Update interrupt and TIM10 global interrupt
    , handler<isr::TIM1_TRG_COM_TIM11>        // 26: TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
    , handler<isr::TIM1_CC>                   // 27: TIM1 Capture Compare interrupt
    , handler<isr::TIM2>                      // 28: TIM2 global interrupt
    , handler<isr::TIM3>                      // 29: TIM3 global interrupt
    , handler<isr::TIM4>                      // 30: TIM4 global interrupt
    , handler<isr::I2C1_EV>                   // 31: I2C1 event interrupt
    , handler<isr::I2C1_ER>                   // 32: I2C1 error interrupt
    , handler<isr::I2C2_EV>                   // 33: I2C2 event interrupt
    , handler<isr::I2C2_ER>                   // 34: I2C2 error interrupt
    , handler<isr::SPI1>                      // 35: SPI1 global interrupt
    , handler<isr::SPI2>                      // 36: SPI2 global interrupt
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::EXTI15_10>                 // 40: EXTI Line[15:10] interrupts
    , handler<isr::RTC_ALARM>                 // 41: RTC Alarms (A and B) through EXTI line interrupt
    , handler<isr::OTG_FS_WKUP>               // 42: USB On-The-Go FS Wakeup through EXTI line interrupt
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::SDIO>                      // 49: SDIO global interrupt
    , handler<isr::TIM5>                      // 50: TIM5 global interrupt
    , handler<isr::SPI3>                      // 51: SPI3 global interrupt
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::OTG_FS>                    // 67: USB On The Go FS global interrupt
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::I2C3_EV>                   // 72: I2C3 event interrupt
    , handler<isr::I2C3_ER>                   // 73: I2C3 error interrupt
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<isr::FPU>                       // 81: FPU interrupt
    , 0x0
    , 0x0
    , handler<isr::SPI4>                      // 84: SPI4 global interrupt
    };

