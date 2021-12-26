#ifndef __COMP__
#define __COMP__

#include "Flight.h"
#include "AirportManager.h"
#include "list.h"

typedef enum {
    eSortByNameSource, eSortByNameDest, eSortByDate, eSortByCode, NotSorted
} eSortType;


static const char *SortTypeStr[NotSorted] = {"Name Source Sort", "Name Destination Sort", "Date Sort",
                                             "Plane Code Sort"};;
typedef struct {
    char *name;
    int flightCount;
    eSortType s_type;
    Flight **flightArr;
    LIST datesList;
} Airline;

void initAirline(Airline *pComp);

int addFlight(Airline *pComp, const AirportManager *pManager);

void printCompany(const Airline *pComp);



void doCountFlightsFromName(const Airline *pComp);

void doPrintFlightsWithPlaneCode(const Airline *pComp);

void doPrintFlightsWithPlaneType(const Airline *pComp);

void freeFlightArr(Flight **arr, int size);

void freeCompany(Airline *pComp);

void sortFlights(Airline *pComp);

Flight *searchFlights(Airline *pComp);

eSortType getSortType();

int     addDateToList(LIST* list, Date* date);

void updaterAfterReadingBFile(Airline* airline);
#endif

