#include "PlaneBinary.h"
#include <string.h>



int writePlaneToBFile(FILE* fp,Plane* plane )
{
    if(fwrite(&plane->type,sizeof(int),1,fp)!=1)
        return 0;
    int len = (int)strlen(plane->code);
    if(fwrite(plane->code,sizeof(char),len,fp)!=len)
        return 0;
    return 1;
}
int readPlaneFromBFile(FILE* fp,Plane* plane )
{

    if(fread(plane,sizeof(Plane),1,fp)!=1)
        return 0;
    return 1;

}
