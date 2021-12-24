#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "stdlib.h"

#define SIZE 255

void writeAirportToTextFile(FILE *fp, Airport *airport) {
    fprintf(fp, "%s\n%s\n", airport->name, airport->address);
}

int readAirportFromTextFile(FILE *fp, Airport *airport) {
    char tempName[SIZE];
    char tempAddress[SIZE];
    if (fgets(tempName, SIZE, fp)) {
        tempName[strcspn(tempName, "\n")] = '\0';
    }
    if (fgets(tempAddress, SIZE, fp)) {
        tempAddress[strcspn(tempAddress, "\n")] = '\0';
    }

    airport->name = _strdup(tempName);
    if (!airport->name)
        return 0;
    airport->address = _strdup(tempAddress);
    if (!airport->address) {
        free(airport->name);
        return 0;
    }
    return 1;
}

int writeAirportArrToTextFile(FILE *fp, Airport *airport, int count) {


    int i;
    for (i = 0; i < count; i++)
        writeAirportToTextFile(fp, &airport[i]);
    return 1;
}

Airport *readAirportArrFromTextFile(FILE *fp, int pCount) {
    Airport *airportArr = NULL;
    airportArr = (Airport *) malloc(pCount * sizeof(Airport));


    int i;
    for (i = 0; i < pCount; i++) {

        if (!readAirportFromTextFile(fp, &airportArr[i])) {
            free(airportArr);
            return NULL;
        }
    }

    return airportArr;
}
