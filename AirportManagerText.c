

#include <stdio.h>

#include <errno.h>
#include "AirportManagerText.h"
#include "AirportText.h"

int writeAirportManagerToTextFile(const char *fileName, AirportManager *airportManager) {
    FILE *fp;
    fp = fopen(fileName, "w");
    if (!fp) {

        return 0;
    }

    fprintf(fp, "%d\n", airportManager->airportsCount);
    writeAirportArrToTextFile(fp, airportManager->airportsArr, airportManager->airportsCount);
    fclose(fp);
    return 1;

}

int readAirportManagerFromTextFile(const char *fileName, AirportManager *airportManager) {
    FILE *fp;
    fopen_s(&fp, fileName, "r");
    if (!fp) {

        return 0;
    }
    if (fscanf_s(fp, "%d\n", &airportManager->airportsCount) != 1) {
        fclose(fp);
        return 0;
    }
    airportManager->airportsArr = readAirportArrFromTextFile(fp, airportManager->airportsCount);
    if (airportManager->airportsArr == NULL) {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}