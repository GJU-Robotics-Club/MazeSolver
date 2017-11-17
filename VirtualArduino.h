#ifndef VIRTUALARDUINO_H_INCLUDED
#define VIRTUALARDUINO_H_INCLUDED

#include <thread>
#include <chrono>
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#include <Arduino.h>
#else

#define HIGH 1;
#define LOW 0;

void delay(uint32_t time_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
}

void digitalWrite(uint8_t pin, uint8_t val) {

}

void analogWrite(uint8_t pin, uint8_t val) {

}


class SerialImp {
public:
    void begin(uint32_t baudrate) {
        printf("starting serial interface at %d baudrate\n", baudrate);
    }

    void print(const char *str) {
        printf("%s", str);
    }
    void print(char c) {
        printf("%c", c);
    }
    void print(float f) {
        printf("%f", f);
    }
    void print(int i) {
        printf("%d", i);
    }
    void println(const char *str) {
        printf("%s\n", str);
    }
    void println(char c) {
        printf("%c\n", c);
    }
    void println(float f) {
        printf("%f\n", f);
    }
    void println(int i) {
        printf("%d\n", i);
    }
}Serial;
#endif


#endif // VIRTUALARDUINO_H_INCLUDED
