#ifndef HW_3_AIRPORTMANAGERTEXT_H
#define HW_3_AIRPORTMANAGERTEXT_H

#include "AirportManager.h"

int writeAirportManagerToTextFile(const char *fileName, AirportManager *airportManager);

int readAirportManagerFromTextFile(const char *fileName, AirportManager *airportManager);

#endif //HW_3_AIRPORTMANAGERTEXT_H
