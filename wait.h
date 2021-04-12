#pragma once

#include <stdint-gcc.h>

/**Prost biblioteka do odmierzania czasu
 * Każda funkcja wstrzymuje program na okresloną liczbę 
 * us, ms, s (funkcje nie działają tak jak delay_ms
 * czyli nie usypiają całego uC, w czasie kiedy funkcja wywołana
 * jest, np. w pętli głównej możliwa jest obsługa przerwać itd...)
 * Biblioteka korzysta z dowolnego timera 
 * Testowana na uC Atmega328PU i taktowaniu procesora równym:
 * 16MHz i 8Mhz. Powinna jeszcze obsużyć taktowania równe:
 * 4Mhz i 1Mhz.
 **/

#define CLOCK_SPEED               16
#define COM_REG                   OCR1A
#define CTC_BIT                   WGM12
#define TCCRxA                    TCCR1A
#define TCCRxB                    TCCR1B
#define INTERUPT_FLAG             OCF1A
#define TIFR_REG                  TIFR1
#define RESET_FLAG                TIFR_REG |= (1 << INTERUPT_FLAG)

#define PRESCALER_1               (1 << CS10)
#define PRESCALER_8               (1 << CS11)
#define PRESCALER_64              (1 << CS10) | (1 << CS11)
#define PRESCALER_256             (1 << CS12)
#define PRESCALER_1024            (1 << CS12) | (1 << CS10)
#define PRESCALER_64_BITS_OFF    ~(1 << CS10) & ~(1 << CS11)
#define PRESCALER_1024_BITS_OFF  ~(1 << CS12) & ~(1 << CS10)

#define SET_PRESCALER_1           TCCRxB |= PRESCALER_1    | (1 << CTC_BIT)
#define SET_PRESCALER_8           TCCRxB |= PRESCALER_8    | (1 << CTC_BIT)
#define SET_PRESCALER_64          TCCRxB |= PRESCALER_64   | (1 << CTC_BIT)
#define SET_PRESCALER_256         TCCRxB |= PRESCALER_256  | (1 << CTC_BIT)
#define SET_PRESCALER_1024        TCCRxB |= PRESCALER_1024 | (1 << CTC_BIT) 

#define UN_SET_PRESCALER_1        TCCRxB &= ~PRESCALER_1              & ~(1 << CTC_BIT)
#define UN_SET_PRESCALER_8        TCCRxB &= ~PRESCALER_8              & ~(1 << CTC_BIT)
#define UN_SET_PRESCALER_64       TCCRxB &=  PRESCALER_64_BITS_OFF    & ~(1 << CTC_BIT)
#define UN_SET_PRESCALER_256      TCCRxB &= ~PRESCALER_256            & ~(1 << CTC_BIT)
#define UN_SET_PRESCALER_1024     TCCRxB &=  PRESCALER_1024_BITS_OFF  & ~(1 << CTC_BIT)

void wait_us(uint32_t us);
void wait_ms(uint32_t ms);
void wait_s(uint32_t s);




