/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

//Récupérer la température et l'afficher sur la sortie standard
#include "mbed.h";
I2C i2c(I2C1_SDA, I2C1_SCL);
const int addre7bit = 0x76;
const int addr8bit = 0x76 << 1;

namespace {
#define PERIOD_MS 2000ms;
}

char data[3];
int main(){
	while (1)
	{
		data[0] = 0xD0;
		i2c.write(addr8bit, data, 1);
		i2c.read(addr8bit, data, 1);
		printf("Chip ID: %x\n", data[0]);
		ThisThread::sleep_for(500ms);
		//température
		data[0] = 0xFA;
		data[1] = 0xFB;
		data[2] = 0xFC;
		i2c.write(addr8bit, data, 1);
		i2c.read(addr8bit, data, 3);
		printf("température: %x %x %x\n", data[0], data[1], data[2]);
		ThisThread::sleep_for(500ms);
	}
}
