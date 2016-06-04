#ifndef READ_H
#define READ_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<time.h>
#include<malloc.h>
#include<string.h>
#include<read.h>
#define MAX_TIME 85

#define DELAY_TIME 500

struct sensor
{

double temp, hum;

};




struct sensor read(int DHT11PIN)
{
  struct sensor val;int erc=0;

    if (wiringPiSetup() == -1)
        {
            exit(1);
        }

do{
int dht11_val[5] = { 0,0,0,0,0 };
int returnValue = 0;

    uint8_t lststate = HIGH;
    uint8_t counter = 0;
    uint8_t j = 0, i = 0;
    float farenheit = 0;

    float *res;
    res=(float*)malloc(2*sizeof(float));

    // ***
    // *** Initialize the values
    // ***
    for (i = 0; i < 5; i++)
    {
        dht11_val[i] = 0;
    }

    // ***
    // *** Signal the sensor to send data
    // ***
    pinMode(DHT11PIN, OUTPUT);
    digitalWrite(DHT11PIN, LOW);

    // ***
    // *** Datasheet states that we should wait 18ms
    // ***
    delay(18);

    // ***
    // *** Set the pin to high and switch to input mode
    // ***
    digitalWrite(DHT11PIN, HIGH);
    delayMicroseconds(40);
    pinMode(DHT11PIN, INPUT);

    // ***
    // *** Get the bits
    // ***
    for (i = 0; i < MAX_TIME; i++)
    {
        counter = 0;
        while (digitalRead(DHT11PIN) == lststate)
        {
            counter++;
            delayMicroseconds(1);

            if (counter == 255)
            {
                break;
            }
        }

        lststate = digitalRead(DHT11PIN);

        if (counter == 255)
        {
            break;
        }

        // ***
        // *** Top 3 transitions are ignored
        // ***
        if ((i >= 4) && (i % 2 == 0))
        {
            dht11_val[j / 8] <<= 1;

            if (counter > 16)
            {
                dht11_val[j / 8] |= 1;
            }

            j++;
        }
    }

    // ***
    // *** Verify checksum and print the verified data
    // ***
    if ((j >= 40) && (dht11_val[4] == ((dht11_val[0] + dht11_val[1] + dht11_val[2] + dht11_val[3]) & 0xFF)))
    {
        //farenheit = dht11_val[2] * 9. / 5. + 32;
        //printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n", dht11_val[0], dht11_val[1], dht11_val[2], dht11_val[3], farenheit);
        val.hum=dht11_val[0]+0.01*dht11_val[1];
        val.temp=dht11_val[2]+0.01*dht11_val[3];
     erc=1;

    }
    else
    {
       // printf("Invalid Data!!\n");
        erc = 0;
        val.hum=-1;
        val.temp=-1;
    }

if(erc==20)
break;
erc++;
 }while(erc==0);
    return val;
}

struct sensor test_read(){
    struct sensor res;
    res.hum=rand()%100;
    res.temp=rand()%30 +20;
    return res;
}
#endif // READ_H

