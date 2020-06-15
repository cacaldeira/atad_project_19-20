#include "region.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Region regionCreate(char* name, char* city, char* area, char* population)
{
    Region region;

    strcpy(region.name, name);
    strcpy(region.city, city);
    region.area = atof(area);
    region.population = atoi(population);

    return region;
}

//not needed for the project just to test if stuff was imported initially
void regionPrint(Region region)
{
    printf("\nNAME: %s\n", region.name);
    printf("CITY: %s\n", region.city);
    printf("AREA: %0.3f\n", region.area);
    printf("POPULATION: %d\n", region.population);
}