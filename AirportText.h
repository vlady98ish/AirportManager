#define _CRT_SECURE_NO_WARNINGS
#ifndef HW_3_AIRPORTTEXT_H
#define HW_3_AIRPORTTEXT_H

#include <stdio.h>
#include "AirportText.h"
#include "Airport.h"

void writeAirportToTextFile(FILE *fp, Airport *airport);

int readAirportFromTextFile(FILE *fp, Airport *airport);

int writeAirportArrToTextFile(FILE *fp, Airport *airport, int count);

Airport *readAirportArrFromTextFile(FILE *fp, int pCount);

#endif
