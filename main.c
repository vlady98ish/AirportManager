#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Airline.h"

#include "Compare.h"
#include "AirportManagerText.h"
#include "AirlineBinary.h"
typedef enum 
{ 
	eAddFlight, eAddAirport, ePrintCompany,eSortFlights,eSearchFlights,  ePrintAirports,
	ePrintNumFlightsOrig, ePrintFlightsPlaneCode, ePrintFlightsPlaneType, eNofOptions
} eMenuOptions;

typedef enum
{
    eNameSource,eNameDestination,eDate,eCodePlane,eNof
}eSortsOptions;

const char* str[eNofOptions] = { "Add Flight", "Add Airport",
								"Print Airline","Sort Flights","Search Flights", "Print all Airports",
								"Print number of flights from origin airport name",
								"Print all flights with plane code",
								"Print all flights with plane type" };

const char* sorts[eNof] = {"Name Source Sort", "Name Destination Sort", "Date Sort", "Plane Code Sort"};
const char* search[eNof] = {"Name Source Search","Name Destination Search","Date Search","Plane Code Search"};




#define EXIT			-1
#define TEXT_FILE "airport_authority.txt"
#define BIN_FILE "airline.bin"
int menu();
int menuSorts();
int menuSearch();

int main()
{
	AirportManager	manager;
	Airline			company;
   if(readAirportManagerFromTextFile(TEXT_FILE,&manager)==1)
   {
       readAirlineFromBFile(BIN_FILE,&company);
    }
    else {
       initManager(&manager);
       initAirline(&company);
   }


	int option;
	int stop = 0;
    int flag =0;
    int choose;
	do
	{
		option = menu();
		switch (option)
		{
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
                choose=menuSorts();
                switch (choose) {
                    case eNameSource:
                        sortFlights(&company,compareSourceName);

                        break;
                    case eNameDestination:
                        sortFlights(&company,compareDestName);
                        break;
                    case eDate:
                        sortFlights(&company,compareDate);
                        break;
                    case eCodePlane:
                        sortFlights(&company,comparePlaneCode);
                        break;
                    default:
                        printf("Wrong number!");
                }
                flag=1;
                break;
         case eSearchFlights:
//                if(flag!=1)
//                    printf("Please sort array Of Flights");
//                else{
//                    choose=menuSorts();
//                    switch (choose) {
//                        case eNameSource:
//                            sortFlights(&company,compareSourceName);
//
//                            break;
//                        case eNameDestination:
//                            sortFlights(&company,compareDestName);
//                            break;
//                        case eDate:
//                            sortFlights(&company,compareDate);
//                            break;
//                        case eCodePlane:
//                            sortFlights(&company,comparePlaneCode);
//                            break;
//                        default:
//                            printf("Wrong number!");
//                }
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
                writeAirportManagerToTextFile("",&manager);
                writeAirlineToBFile("",&company);
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);

	freeManager(&manager);
	//freeCompany(&company);
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for(int i = 0 ; i < eNofOptions ; i++)
		printf("%d - %s\n",i,str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}

int menuSorts()
{
    int option;
    printf("\n\n");
    printf("Please choose one of the following options\n");
    for(int i = 0 ; i < eNof ; i++)
        printf("%d - %s\n",i,sorts[i]);

    scanf("%d", &option);
    //clean buffer
    char tav;
    scanf("%c", &tav);
    return option;
}

int menuSearch()
{
    int option;
    printf("\n\n");
    printf("Please choose one of the following options\n");
    for(int i = 0 ; i < eNof ; i++)
        printf("%d - %s\n",i,sorts[i]);

    scanf("%d", &option);
    //clean buffer
    char tav;
    scanf("%c", &tav);
    return option;
}