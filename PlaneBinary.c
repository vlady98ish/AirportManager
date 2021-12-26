#include "PlaneBinary.h"


int writePlaneToBFile(FILE *fp, Plane *plane) {
    if (fwrite(plane, sizeof(Plane), 1, fp) != 1)
        return 0;
    return 1;
}

int readPlaneFromBFile(FILE *fp, Plane *plane) {

    if (fread(plane, sizeof(Plane), 1, fp) != 1)
        return 0;
    return 1;

}
