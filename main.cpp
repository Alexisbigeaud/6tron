/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
InterruptIn button(BUTTON1);
DigitalOut led(LED1);
Ticker ticker;
namespace {
#define PERIOD_MS 2000ms
}
void toggleLED() {
    led = !led;
}

void changeFrequency() {
    static int frequency = 1;
    ticker.detach();
    ticker.attach(toggleLED, PERIOD_MS / frequency);
    frequency *= 2;
    if (frequency > 16) {
        frequency = 1;
    }
}

int main()
{
    button.rise(&changeFrequency);
    ticker.attach(toggleLED, PERIOD_MS);
    while (true) {
        ThisThread::sleep_for(100ms);
    }
}
