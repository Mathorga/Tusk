#include "Timer.h"

volatile bool timerFlag;

ISR (TIMER1_COMPA_vect) {
    timerFlag = true;
}

namespace Tusk {
    Timer::Timer(){
        timerFlag = false;
    }

    void Timer::setupFrequency(int frequency) {
        // Disable interrupts.
        cli();

        // Set entire TCCR1A register to 0.
        TCCR1A = 0;

        // Same for TCCR1B.
        TCCR1B = 0;

        // Initialize counter value to 0.
        TCNT1 = 0;

        // Set compare match register.
        // OCR1A = (16 * 2 ^ 20) / (100 * PRESCALER) - 1 (must be < 65536)
        // Assuming a prescaler of 1024 => OCR1A = (16 * 2 ^ 10) / frequency.
        OCR1A = 16 * 1024 / frequency;

        // Set CTC mode.
        TCCR1B |= (1 << WGM12);

        // Set CS11 for 8 prescaler.
        TCCR1B |= (1 << CS12) | (1 << CS10);

        // Enable timer compare interrupt.
        TIMSK1 |= (1 << OCIE1A);

        // Enable interrupts.
        sei();
    }

    void Timer::setupPeriod(int period) {
        // Disable interrupts.
        cli();

        // Set entire TCCR1A register to 0.
        TCCR1A = 0;

        // Same for TCCR1B.
        TCCR1B = 0;

        // Initialize counter value to 0.
        TCNT1 = 0;

        // Set compare match register.
        // OCR1A = (16 * 2 ^ 20) / (100 * PRESCALER) - 1 (must be < 65536)
        // Assuming a prescaler of 1024 => OCR1A = (16 * 2 ^ 10) * period / 1000 (being in ms).
        OCR1A = 16.384 * period;

        // Set CTC mode.
        TCCR1B |= (1 << WGM12);

        // Set CS11 for 8 prescaler.
        TCCR1B |= (1 << CS12) | (1 << CS10);

        // Enable timer compare interrupt.
        TIMSK1 |= (1 << OCIE1A);

        // Enable interrupts.
        sei();
    }

    void Timer::waitForNextTick(){
        // Wait for timer signal.
        while (!timerFlag) {}

        // Reset flag.
        timerFlag = false;
    }
}
