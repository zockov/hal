#pragma once

namespace hal
{
namespace cordic
{

struct cordic_t
{
    enum operation_t
        { cosine
        , sine
        , phase
        , modulus
        , arctangent
        , hyperbolic_cosine
        , hyperbolic_sine
        , arctanh
        , natural_logarithm
        , square_root
        };

    template
        < operation_t   operation
        , uint8_t       precision
        >
    static void setup()
    {
        typedef device::cordic_t _;
        using namespace device;
        
        /*
    static constexpr uint32_t CSR_IEN = 0x10000;        // IEN
    static constexpr uint32_t CSR_DMAREN = 0x20000;     // DMAREN
    static constexpr uint32_t CSR_DMAWEN = 0x40000;     // DMAWEN
    static constexpr uint32_t CSR_NRES = 0x80000;       // NRES
    static constexpr uint32_t CSR_NARGS = 0x100000;     // NARGS
    static constexpr uint32_t CSR_RESSIZE = 0x200000;   // RESSIZE
    static constexpr uint32_t CSR_ARGSIZE = 0x400000;   // ARGSIZE
    static constexpr uint32_t CSR_RRDY = 0x80000000;    // RRDY
    static const uint32_t CSR_RESET_VALUE = 0x0;
    */
        peripheral_traits<_>::enable();                 // enable peripheral
        CORDIC.CSR = _::CSR_RESET_VALUE                 // reset register
                   | _::CSR_FUNC<operation>             // select function
                   | _::CSR_PRECISION<precision>        // iterations / 4
                   ;
    }

    __attribute__((always_inline))
    static inline int32_t compute(int32_t x)
    {
        using namespace device;

        CORDIC.WDATA = x;
        return CORDIC.RDATA;
    }
};

} // namespace cordic

} // namespace hal

