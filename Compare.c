#include "Compare.h"
#include "Flight.h"
#include <string.h>


int compareSourceName(const void *a, const void *b) {
    Flight *flightA = *(Flight **) a;
    Flight *flightB = *(Flight **) b;

    return strcmp(flightA->nameSource, flightB->nameSource);
}

int compareDestName(const void *a, const void *b) {
    Flight *flightA = *(Flight **) a;
    Flight *flightB = *(Flight **) b;

    return strcmp(flightA->nameDest, flightB->nameDest);
}

int compareDate(const void *a, const void *b) {
    Flight *flightA = *(Flight **) a;
    Flight *flightB = *(Flight **) b;

    if (flightA->date.year < flightB->date.year)
        return -1;

    else if (flightA->date.year > flightB->date.year)
        return 1;

    if (flightA->date.year == flightB->date.year) {
        if (flightA->date.month < flightB->date.month) {


            return -1;
        } else if (flightA->date.month > flightB->date.month) {
            return 1;
        } else if (flightA->date.day < flightB->date.day) {
            return -1;
        } else if (flightA->date.day > flightB->date.day) {
            return 1;
        }


    }
    return 0;
}

int comparePlaneCode(const void *a, const void *b) {
    Flight *flightA = *(Flight **) a;
    Flight *flightB = *(Flight **) b;

    return strcmp(flightA->thePlane.code, flightB->thePlane.code);
}
