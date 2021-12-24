#include <stdlib.h>
#include "DateBinary.h"


int writeDateToBFile(FILE *fp, Date *date) {
    if (fwrite(date, sizeof(Date), 1, fp) != 1)
        return 0;


    return 1;
}

int readDateFromBFile(FILE *fp, Date *date) {


    if (fread(date, sizeof(Date), 1, fp) != 1)
        return 0;
    return 1;

}
