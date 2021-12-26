#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "Airline.h"


#include "AirportManagerText.h"
#include "AirlineBinary.h"

typedef enum {
    eAddFlight, eAddAirport, ePrintCompany, eSortFlights, eSearchFlights, ePrintAirports,
    ePrintNumFlightsOrig, ePrintFlightsPlaneCode, ePrintFlightsPlaneType, eNofOptions
} eMenuOptions;


const char *str[eNofOptions] = {"Add Flight", "Add Airport",
                                "Print Airline", "Sort Flights", "Search Flights", "Print all Airports",
                                "Print number of flights from origin airport name",
                                "Print all flights with plane code",
                                "Print all flights with plane type"};


#define EXIT            -1
#define TEXT_FILE "airport_authority.txt"
#define BIN_FILE "airline.bin"

int menu();


int main() {
    AirportManager manager;
    Airline company;
    if (readAirportManagerFromTextFile(TEXT_FILE, &manager) == 1) {
        readAirlineFromBFile(BIN_FILE, &company);

        updaterAfterReadingBFile(&company);

    } else {
        initManager(&manager);
        initAirline(&company);
    }


    int option;
    int stop = 0;


    do {
        option = menu();
        switch (option) {
            case eAddFlight:
                if (!addFlight(&company, &manager))
                    printf("Error adding flight\n");
                break;


            case eAddAirport:
                if (!addAirport(&manager))
                    printf("Error adding airport\n");
                break;

            case ePrintCompany:
                printCompany(&company);

                break;

            case eSortFlights:
                sortFlights(&company);

                break;
            case eSearchFlights:
                printFlight(searchFlights(&company));
                break;
            case ePrintAirports:
                printAirportManager(&manager);

                break;


            case ePrintNumFlightsOrig:
                doCountFlightsFromName(&company);
                break;

            case ePrintFlightsPlaneCode:
                doPrintFlightsWithPlaneCode(&company);
                break;

            case ePrintFlightsPlaneType:
                doPrintFlightsWithPlaneType(&company);
                break;

            case EXIT:
                printf("Bye bye\n");
                writeAirportManagerToTextFile(TEXT_FILE, &manager);
                writeAirlineToBFile(BIN_FILE, &company);
                freeManager(&manager);
                freeCompany(&company);
                stop = 1;
                break;

            default:
                printf("Wrong option\n");
                break;
        }
    } while (!stop);


    return 1;
}

int menu() {
    int option;
    printf("\n\n");
    printf("Please choose one of the following options\n");
    for (int i = 0; i < eNofOptions; i++)
        printf("%d - %s\n", i, str[i]);
    printf("%d - Quit\n", EXIT);
    scanf("%d", &option);
    //clean buffer
    char tav;
    scanf("%c", &tav);
    return option;
}



