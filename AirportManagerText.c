
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "AirportManagerText.h"
#include "AirportText.h"
int writeAirportManagerToTextFile(const char* fileName,AirportManager* airportManager )
{
    FILE* fp;
    fp = fopen("C:\\Users\\joker\\CLionProjects\\HW_3\\airport_authority.txt", "w");
    if (!fp){

        return 0;
    }

    fprintf(fp,"%d\n",airportManager->airportsCount);
    writeAirportArrToTextFile(fp,airportManager->airportsArr,airportManager->airportsCount);
    fclose(fp);
    return 1;

}
int readAirportManagerFromTextFile(const char* fileName,AirportManager * airportManager )
{
    FILE* fp;
    fopen_s(&fp,"C:\\Users\\joker\\CLionProjects\\HW_3\\airport_authority.txt", "r");
    if (!fp) {

        return 0;
    }
    if(fscanf_s(fp,"%d\n",&airportManager->airportsCount)!=1)
    {
        fclose(fp);
        return 0;
    }
    airportManager->airportsArr=readAirportArrFromTextFile(fp,airportManager->airportsCount);
    if(airportManager->airportsArr==NULL)
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}