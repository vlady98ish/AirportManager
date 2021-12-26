#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include "AirlineBinary.h"
#include "FlightBinary.h"


int writeAirlineToBFile(const char *fileName, Airline *airline) {
    FILE *fp;
    fp = fopen(fileName, "wb");
    if (!fp)
        return 0;
    int len = (int) strlen(airline->name) + 1;
    if (fwrite(&len, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        return 0;
    }
    if (fwrite(airline->name, sizeof(char), len, fp) != len) {
        fclose(fp);
        return 0;
    }
    if (fwrite(&airline->s_type, sizeof(int), 1, fp) != 1)
        return 0;
    if (fwrite(&airline->flightCount, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        return 0;
    }
    if (writeFlightArrToBFile(fp, airline->flightArr, airline->flightCount) != 1) {
        fclose(fp);

        return 0;
    }
    fclose(fp);
    return 1;
}

int readAirlineFromBFile(const char *fileName, Airline *airline) {
    FILE *fp;
    fp = fopen(fileName, "rb");
    if (!fp)
        return 0;
    int len;
    if (fread(&len, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        return 0;
    }
    airline->name = (char *) malloc(len * sizeof(char));
    if (!airline->name) {
        fclose(fp);
        return 0;
    }
    if (fread(airline->name, sizeof(char), len, fp) != len) {
        fclose(fp);
        free(airline->name);
        return 0;
    }
    if (fread(&airline->s_type, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        free(airline->name);
        return 0;
    }
    if (fread(&airline->flightCount, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        free(airline->name);
        return 0;
    }
    airline->flightArr = readFlightArrFromBFile(fp, &airline->flightCount);
    if (airline->flightArr == NULL) {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}
