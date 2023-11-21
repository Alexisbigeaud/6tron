/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

//Récupérer la température et l'afficher sur la sortie standard

#include "mbed.h"
#include "BME280.h" // Inclure la bibliothèque BME280
using namespace sixtron;
I2C bus(I2C1_SDA, I2C1_SCL); // Créer une instance de capteur BME280


int main() {
	BME280 sensor(&bus);
    sensor.initialize(); // Initialiser le capteur

    while (1) {
        float temperature, humidity, pressure;      
		sensor.set_sampling(); // Mettre le capteur en mode normal

        temperature = sensor.temperature();
		humidity = sensor.humidity();
		pressure = sensor.pressure();

        printf("Température: %.2f°C\n", temperature);
		printf("Humidité: %.2f%%\n", humidity);
		printf("Pression: %.2fPa\n", pressure);

        ThisThread::sleep_for(500ms);
    }
}