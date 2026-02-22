/*
What's next:
-understand proper use of Bufferred/Unbuffered serial
-reintegrate updates to all files
*/



/*
Program to receive data from from GPS module

Written by Colton Martin
cjmartin@eastex.net
*/
#include "mbed.h"
__FPU_PRvvjj
#include "./Adafruit_GPS/Mbed_Adafruit_GPS.h"
#include "USBSerial.h"
#include "stdio.h"

#define GPS_TX_PIN       p9
#define GPS_RX_PIN       p10

char abuf[1];
static BufferedSerial pc(USBTX, USBRX, 9600);
static UnbufferedSerial * ultimateGPS; 
//UnbufferedSerial ultimateGPS(GPS_TX_PIN, GPS_RX_PIN, 9600);
ultimateGPS(GPS_TX_PIN, GPS_RX_PIN, 9600);
Adafruit_GPS gpsInstance(&ultimateGPS);

int main() {
    DigitalOut led1(LED1);

    char c;
    int i,d;
    float latt;
    bool status;
    gpsInstance.begin(9600);
    float testFloat = 1.22;
    int reset_counter = 0; 
    
    char msg[] = "Starting Program...\nTesting Serial Write...\n";
    printf("Testing printf...\n");
    pc.write(msg, sizeof(msg));
    //char command[] = "$PMTK010,002*2D";

    Timer refresh_Timer; //sets up a timer for use in loop; how often do we print GPS info?
    const int refresh_Time = 2000; //refresh time in ms
    
    gpsInstance.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    gpsInstance.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
    gpsInstance.sendCommand(PGCMD_ANTENNA);
    //gpsInstance.sendCommand(PMTK_Q_RELEASE);

    while (true) {
        c = gpsInstance.read();

        if (c) { } //this line will echo the GPS data if not paused

        //check if we recieved a new message from GPS, if so, attempt to parse it,
        if ( gpsInstance.newNMEAreceived() ) {
            if ( !gpsInstance.parse(gpsInstance.lastNMEA()) ) {
                continue;   
            }    
        }

       //check if enough time has passed to warrant printing GPS info to screen
       //note if refresh_Time is too low or pc.baud is too low, GPS data may be lost during printing
        ThisThread::sleep_for( 700ms );
        printf("Time: %d:%d:%d.%u\n", gpsInstance.hour, gpsInstance.minute, gpsInstance.seconds, gpsInstance.milliseconds);
        printf("Date: %d/%d/20%d\n", gpsInstance.day, gpsInstance.month, gpsInstance.year);
        printf("Fix: %i\n", (int) gpsInstance.fix);
        printf("Quality: %i\n", (int) gpsInstance.fixquality);
        if (gpsInstance.fix) {
            printf("Location: %5.2f%c, %5.2f%c\n", gpsInstance.latitude, gpsInstance.lat, gpsInstance.longitude, gpsInstance.lon);
            printf("Speed: %5.2f knots\n", gpsInstance.speed);
            printf("Angle: %5.2f\n", gpsInstance.angle);
            printf("Altitude: %5.2f\n", gpsInstance.altitude);
            printf("Satellites: %d\n", gpsInstance.satellites);
        }
        printf("Update keyword: goose\n\n");
        /*
        if (gpsInstance.newNMEAreceived()){
            printf("Status update received\n");
            printf("%c", gpsInstance.lastNMEA()[i]);
        }
        else
            printf("No status update\n");
        printf("\n");
        */
        //ThisThread::sleep_for( 200ms );
        //gpsInstance.sendCommand(PMTK_SET_NMEA_OUTPUT_ALLDATA);
        /*
        if (gpsInstance.waitForSentence("$PMTK314", 50))
            printf("waitForSentence: true\n");
        else
            printf("waitForSentence: false\n");
        if (gpsInstance.waitForSentence(PMTK_Q_RELEASE))
            printf("PMTK Awake: true\n");
        else
            printf("PMTK Awake: false\n");
        if (gpsInstance.wakeup())
            printf("Standby mode was on\n");
        else
            printf("Standby mode was off\n");
        printf("\n");
        //question - does read or waitForSentence come first
        if (msg[0] == '0')
            printf("Read returned \'0\' status\n"); 
        //printf("String from read: %s\n", msg, sizeof(msg)); 
        printf("Iteration %i Testing Lattitude: %d\n", reset_counter, gpsInstance.latitude);
        if(reset_counter > 15){
            printf("LPC1768 resettings...\n\n\n\n\n");
            NVIC_SystemReset();
        }
        reset_counter += 1; 
        */
    }
}