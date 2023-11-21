/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
DigitalOut led1(LED1);

Mutex printf_mutex;

void ping() {
    for(int i = 0; i < 100; i++) {
        printf_mutex.lock();
        printf("ping\n");
        printf_mutex.unlock();

    }
}

void pong() {
    for(int i = 0; i < 100; i++) {
        printf_mutex.lock();
        printf("pong\n");
        printf_mutex.unlock();

    }
}

int main() {
    Thread ping_thread;
    Thread pong_thread;

    ping_thread.start(ping);
    pong_thread.start(pong);
	ping_thread.set_priority(osPriorityRealtime1);
	pong_thread.set_priority(osPriorityRealtime2);

    while(1) {
        led1 = !led1;
        printf_mutex.lock();
        printf("Alive\n");
        printf_mutex.unlock();
        ThisThread::sleep_for(1000ms);
    }
}
