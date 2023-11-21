/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */



#include "mbed.h"
DigitalOut led1(LED1);
namespace{
	#define PERIOD_MS 1000ms
}

void ping(){

	for(int i = 0; i < 100; i++){
		printf("ping\n");
	}
}

void pong(){
	for(int i = 0; i < 100; i++){
		printf("pong\n");
	}
}

int main() {

	Thread ping_thread;
	Thread pong_thread;
	ping_thread.start(ping);
	pong_thread.start(pong);
	while(1){
		led1 = !led1;
		printf("Alive\n");
		ThisThread::sleep_for(PERIOD_MS);
	}


}