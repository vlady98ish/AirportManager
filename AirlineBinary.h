#ifndef HW_3_AIRLINEBINARY_H
#define HW_3_AIRLINEBINARY_H

#include "Airline.h"
#include <stdio.h>

int writeAirlineToBFile(const char *fileName, Airline *airline);

int readAirlineFromBFile(const char *fileName, Airline *airline);


#endif
