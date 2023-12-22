/*
Program to receive data from from GPS module

Written by Colton Martin
cjmartin@eastex.net
*/
#include "mbed.h"
#include "Mbed_Adafruit_GPS.h"
#include "stdio.h"

#define GPS_TX_PIN       p9
#define GPS_RX_PIN       p10

char abuf[1];
static BufferedSerial ultimateGPS(GPS_TX_PIN, GPS_RX_PIN, 9600);
static BufferedSerial pc(USBTX, USBRX, 9600); 
    
//Adafruit_GPS gps(&ultimateGPS);

int main() {

    DigitalOut led1(LED1);

    char c;
    int i,d;
    float latt;
    //gps.begin(9600);
    while (true) {
        //char msg[] = "Testing Serial Write...\n";
        //pc.write(msg, sizeof(msg));
        //printf("Testing printf...\n");
        char sent[] = "_____________________________________________________________________\n";
        ultimateGPS.read(&sent, sizeof(sent));
        pc.write(&sent, sizeof(sent));
        for (int i = 0; i<3; i++) {
			led1 = 1;
			ThisThread::sleep_for( 10 );
			led1 = 0;
			ThisThread::sleep_for( 45 );
		}

        /*
        for(int i=0; i<20; i++) {
            if (gps.newNMEAreceived()){
                printf("Yes\n");
            }
            else
                printf("No\n");
            printf("%c", gps.lastNMEA()[i]);
        }
        printf("\n");
        //if( gps.newNMEAreceived() ) {
         //   printf("Yes!\n");
          //  gps.parse( );
        //}
        //else {
         //   print("\tNo Data\n");
          //  {}


        //gps.sendCommand(PMTK_SET_BAUD_9600);
        //latt = gps.latitude; 
	    //i = int(latt);
	    //d = abs(int((latt - float(i)) * 10.0));
        //printf("Lattitude %i.%i", i, d);
        ThisThread::sleep_for(100ms);
        */
    }
}