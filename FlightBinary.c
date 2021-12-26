#include <string.h>
#include <stdlib.h>
#include "FlightBinary.h"
#include "PlaneBinary.h"
#include "DateBinary.h"


int writeFlightToBFile(FILE *fp, Flight *flight) {
    int len = (int) strlen(flight->nameDest) + 1;
    if (fwrite(&len, sizeof(int), 1, fp) != 1)
        return 0;
    if (fwrite(flight->nameDest, sizeof(char), len, fp) != len)
        return 0;
    len = (int) strlen(flight->nameSource) + 1;
    if (fwrite(&len, sizeof(int), 1, fp) != 1)
        return 0;
    if (fwrite(flight->nameSource, sizeof(char), len, fp) != len)
        return 0;
    if (writePlaneToBFile(fp, &flight->thePlane) != 1)
        return 0;
    if (writeDateToBFile(fp, &flight->date) != 1)
        return 0;
    return 1;
}

int readFlightFromBFile(FILE *fp, Flight *flight) {
    int len;
    int len1;
    if (fread(&len, sizeof(int), 1, fp) != 1)
        return 0;
    flight->nameSource = (char *) calloc(len, sizeof(char));
    if (!flight->nameSource)
        return 0;
    if (fread(flight->nameSource, sizeof(char), len, fp) != len) {
        free(flight->nameSource);
        return 0;
    }

    if (fread(&len1, sizeof(int), 1, fp) != 1)
        return 0;
    flight->nameDest = (char *) calloc(len1, sizeof(char));
    if (!flight->nameDest)
        return 0;

    if (fread(flight->nameDest, sizeof(char), len1, fp) != len1) {
        free(flight->nameSource);
        free(flight->nameDest);
        return 0;
    }
    if (readPlaneFromBFile(fp, &flight->thePlane) != 1)
        return 0;
    if (readDateFromBFile(fp, &flight->date) != 1)
        return 0;
    return 1;

}

int writeFlightArrToBFile(FILE *fp, Flight **flight, int count) {

    int i;
    for (i = 0; i < count; i++) {
        if (!writeFlightToBFile(fp, flight[i])) {
            return 0;
        }
    }
    return 1;
}

Flight **readFlightArrFromBFile(FILE *fp, int *pCount) {
    Flight **arrFlight = NULL;


    arrFlight = (Flight **) malloc(*pCount * sizeof(Flight *));
    if (!arrFlight)
        return NULL;
    int i;
    for (i = 0; i < *pCount; i++) {
        Flight *flight = (Flight *) malloc(sizeof(Flight));
        arrFlight[i] = flight;
        if (!readFlightFromBFile(fp, arrFlight[i])) {

            free(arrFlight);
            return NULL;
        }
    }
    return arrFlight;
}
