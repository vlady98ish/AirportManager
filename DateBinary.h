#ifndef HW_3_DATEBINARY_H
#define HW_3_DATEBINARY_H

#include <stdio.h>
#include "Date.h"

int writeDateToBFile(FILE *fp, Date *date);

int readDateFromBFile(FILE *fp, Date *date);


#endif
