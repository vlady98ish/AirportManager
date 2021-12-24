#ifndef HW_3_FLIGHTBINARY_H
#define HW_3_FLIGHTBINARY_H

#include <stdio.h>
#include "Flight.h"

int writeFlightToBFile(FILE *fp, Flight *flight);

int readFlightFromBFile(FILE *fp, Flight *flight);

int writeFlightArrToBFile(FILE *fp, Flight **flight, int count);

Flight **readFlightArrFromBFile(FILE *fp, int *pCount);


#endif
