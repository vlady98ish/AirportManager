#ifndef HW_3_PLANEBINARY_H
#define HW_3_PLANEBINARY_H

#include <stdio.h>
#include "Plane.h"

int writePlaneToBFile(FILE *fp, Plane *plane);

int readPlaneFromBFile(FILE *fp, Plane *plane);

#endif
