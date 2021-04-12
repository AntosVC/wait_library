#include <avr/io.h>

#include "wait.h"

void wait_us(uint32_t us)
{
    #if CLOCK_SPEED == 16

        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 16;
            SET_PRESCALER_1;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_1;
            RESET_FLAG;

            if(counter == us)
            {
                counter = 0;
                break;
            }   
        }
    #endif

    #if CLOCK_SPEED == 8
        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 8;
            SET_PRESCALER_1;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_1;
            RESET_FLAG;

            if(counter == us)
            {
                counter = 0;
                break;
            }   
        }
    #endif

    #if CLOCK_SPEED == 4

        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 4;
            SET_PRESCALER_1;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_1;
            RESET_FLAG;

            if(counter == us)
            {
                counter = 0;
                break;
            }   
        }
    #endif

    #if CLOCK_SPEED == 1

        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 1;
            SET_PRESCALER_1;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_1;
            RESET_FLAG;

            if(counter == us)
            {
                counter = 0;
                break;
            }   
        }
    #endif
}

void wait_ms(uint32_t ms)
{
    #if CLOCK_SPEED == 16

        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 2000;
            SET_PRESCALER_8;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_8;
            RESET_FLAG;

            if(counter == ms)
            {
                counter = 0;
                break;
            }   
        }
    #endif

    #if CLOCK_SPEED == 8
        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 1000;
            SET_PRESCALER_8;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_8;
            RESET_FLAG;

            if(counter == ms)
            {
                counter = 0;
                break;
            }   
        }
    #endif

    #if CLOCK_SPEED == 4

        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 500;
            SET_PRESCALER_8;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_8;
            RESET_FLAG;

            if(counter == ms)
            {
                counter = 0;
                break;
            }   
        }
    #endif

    #if CLOCK_SPEED == 1

        static uint32_t counter;

        while(1)
        {
            counter++;
            COM_REG = 125;
            SET_PRESCALER_8;
    
            while(!(TIFR_REG & (1 << INTERUPT_FLAG)));

            UN_SET_PRESCALER_8;
            RESET_FLAG;

            if(counter == ms)
            {
                counter = 0;
                break;
            }   
        }
    #endif
}

void wait_s(uint32_t s)
{
    wait_ms(s*1000);
}