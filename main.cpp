/*
Program to receive data from from GPS module

Written by Colton Martin
cjmartin@eastex.net
*/
#include "mbed.h"

#define GPS_TX_PIN       p9
#define GPS_RX_PIN       p10

//Serial uGPS(p18, p19, 9600);
static BufferedSerial gpsSerial(GPS_TX_PIN, GPS_RX_PIN, 9600);
int main()
{
    while (true) {
        printf("test\n");
    }
}