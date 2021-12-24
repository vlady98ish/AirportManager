#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include "Airline.h"

#include "General.h"
#include "Compare.h"

void initAirline(Airline *pComp) {
    printf("-----------  Init Airline Airline\n");
    pComp->name = getStrExactName("Enter Airline name");

    pComp->flightArr = NULL;
    pComp->flightCount = 0;
}

int addFlight(Airline *pComp, const AirportManager *pManager) {
    if (pManager->airportsCount < 2) {
        printf("There are not enough airport to set a flight\n");
        return 0;
    }
    pComp->flightArr = (Flight **) realloc(pComp->flightArr, (pComp->flightCount + 1) * sizeof(Flight *));
    if (!pComp->flightArr)
        return 0;
    pComp->flightArr[pComp->flightCount] = (Flight *) calloc(1, sizeof(Flight));
    if (!pComp->flightArr[pComp->flightCount])
        return 0;
    initFlight(pComp->flightArr[pComp->flightCount], pManager);
    pComp->flightCount++;
    return 1;
}

void printCompany(const Airline *pComp) {
    printf("Airline %s\n", pComp->name);
    printf("Has %d flights\n", pComp->flightCount);

    generalArrayFunction(pComp->flightArr, pComp->flightCount, sizeof(Flight *), printFlight);

}


void doCountFlightsFromName(const Airline *pComp) {
    if (pComp->flightCount == 0) {
        printf("No flight in company\n");
        return;
    }

    char *tempName = getStrExactName("Please enter origin airport name");

    int count = 0;
    for (int i = 0; i < pComp->flightCount; i++) {
        if (isFlightFromSourceName(pComp->flightArr[i], tempName))
            count++;
    }

    free(tempName);

    if (count != 0)
        printf("There are %d ", count);
    else
        printf("There are No ");

    printf("flights from this airport\n");
}

void doPrintFlightsWithPlaneCode(const Airline *pComp) {
    char code[MAX_STR_LEN];
    getPlaneCode(code);
    printf("All flights with plane code %s:\n", code);
    for (int i = 0; i < pComp->flightCount; i++) {
        if (isPlaneCodeInFlight(pComp->flightArr[i], code))
            printFlight(pComp->flightArr[i]);
    }
    printf("\n");

}

void doPrintFlightsWithPlaneType(const Airline *pComp) {
    ePlaneType type = getPlaneType();
    printf("All flights with plane type %s:\n", PlaneTypeStr[type]);
    for (int i = 0; i < pComp->flightCount; i++) {
        if (isPlaneTypeInFlight(pComp->flightArr[i], type))
            printFlight(pComp->flightArr[i]);
    }
    printf("\n");
}

void freeFlightArr(Flight **arr, int size) {
    for (int i = 0; i < size; i++) {
        freeFlight(arr[i]);
    }
}

void freeCompany(Airline *pComp) {
    freeFlightArr(pComp->flightArr, pComp->flightCount);
    free(pComp->flightArr);
    free(pComp->name);
}

void sortFlights(Airline *pComp) {
    printf("In which way you want to sort the flights? \n");
    pComp->s_type = getSortType();
    if (pComp->s_type == eSortByNameSource)
        qsort(pComp->flightArr, pComp->flightCount, sizeof(Flight *), compareSourceName);
    if (pComp->s_type == eSortByNameDest)
        qsort(pComp->flightArr, pComp->flightCount, sizeof(Flight *), compareDestName);
    if (pComp->s_type == eSortByDate)
        qsort(pComp->flightArr, pComp->flightCount, sizeof(Flight *), compareDate);
    if (pComp->s_type == eSortByCode)
        qsort(pComp->flightArr, pComp->flightCount, sizeof(Flight *), comparePlaneCode);
}

Flight *searchFlights(Airline *pComp) {
    Flight *pFlight = NULL;

    Flight **temp = NULL;
    Flight *flight = (Flight *) malloc(sizeof(Flight));


    if (pComp->s_type < 0 || pComp->s_type > 3) {
        printf("The airline dont sorted yet");
        return NULL;
    } else {
        if (pComp->s_type == eSortByNameSource) {
            flight->nameSource = getStrExactName("Please enter source name\n");
            temp = &flight;
            pFlight = (Flight *) bsearch(temp, pComp->flightArr, pComp->flightCount, sizeof(Flight *),
                                         compareSourceName);
            return pFlight;
        } else if (pComp->s_type == eSortByNameDest) {
            flight->nameDest = getStrExactName("Please enter destination name\n");
            temp = &flight;
            pFlight = (Flight *) bsearch(temp, pComp->flightArr, pComp->flightCount, sizeof(Flight *),
                                         compareDestName);
            return pFlight;
        } else if (pComp->s_type == eSortByDate) {
            getCorrectDate(&flight->date);
            temp = &flight;
            pFlight = (Flight *) bsearch(temp, pComp->flightArr, pComp->flightCount, sizeof(Flight *), compareDate);
            return pFlight;
        } else if (pComp->s_type == eSortByCode)
            getPlaneCode(flight->thePlane.code);
        temp = &flight;
        pFlight = (Flight *) bsearch(temp, pComp->flightArr, pComp->flightCount, sizeof(Flight *), comparePlaneCode);
        return pFlight;
    }

}

eSortType getSortType() {
    int option;
    printf("\n\n");
    do {
        printf("Please enter one of the following types\n");
        for (int i = 0; i < NotSorted; i++)
            printf("%d for %s\n", i, SortTypeStr[i]);
        scanf("%d", &option);
    } while (option < 0 || option >= NotSorted);
    getchar();
    return (eSortType) option;
}


