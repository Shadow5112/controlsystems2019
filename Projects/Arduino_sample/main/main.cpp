#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "Arduino.h"
#include "EEPROM.h"

#define EEPROM_SIZE 64
extern "C" void app_main()
{
    initArduino();
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);

    EEPROM.begin(0x64);
/*
    if (!EEPROM.begin(EEPROM.length()))
    {
        printf("failed to initialize EEPROM\n");
    	vTaskDelay(1000);
    }
*/    
    char temp[13];
    EEPROM.writeString(0,"Hello, world");
    EEPROM.commit();
    EEPROM.readString(0).toCharArray(temp, 13);
    char *message = temp;
    printf(message);
    printf("\n");
    
    for (int i = 10; i>=0; i--)
    {
        printf("Restarting in %d seconds...\n", i);
	vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
