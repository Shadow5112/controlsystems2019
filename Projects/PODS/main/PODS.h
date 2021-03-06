#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "Servo_Control.hpp"


#ifndef PODS_H_
#define PODS_H_

#ifdef _cplusplus
extern "C" {
#endif

struct ParamsStruct{
	char name[40];
	int id;
	int angle;
	String type;
};



void initServer(AsyncWebServer* server, ParamsStruct* params);

void dispenseFluid(int x);// dispenses fluid for pod x

void sealPODS(int x, bool open); //seals POD x 
								// open = true -> open lid
								// open = false -> close lid

void moveServo(int id, int angle, String type); //id = POD id
												// string = "lid" or "fluid"
												//angle = +- 90

void startPOD(bool start, int x);//takes boolean to start/stop gygercounter  and pod id ->x

double getPercent(int angle);//maps -+90 to 0 - 100

int gygerPin(int id); // returns pin number for gyger counter take POD ID parameter(0-6)

String writeData(bool type, int id, int val, u_long time_stamp); //TRUE to write data to global string. 
											//will return -1 
											//FALSE to return data string
											// id -> PODS identifier (0-6) val -> cpm
											//String format "Pod: <ID> cpm: <cpm>;<timestamp> <cpm>;<timestamp> ..."
void resetString(int id); //resets string that writeData() writes to to "POD: <id> cpm: "

int servoInoculationPin(int x); //returns servo pin for PODS #x that controls the incoculationi fluid

int servoLidPin(int x);// returns servo pin on PODS #x that seals the PODS

//interupt finctions that count the number of emmisions detected
void emissionCount(void* id); // writes <id> to queue when an interrupt is detected


#ifdef _cplusplus
}
#endif

#endif

