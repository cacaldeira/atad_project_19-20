#pragma once

typedef struct region {
    char name[40];
    char city[40];
    float area;
    int population;
} Region;

/**
 * @brief creates a region with given fields
 * 
 * @param name - name of region
 * @param city - city in region
 * @param area - area of region
 * @param population - total population of region
 * @return Region* - returns pointer to memory of created region
 */
Region* regionCreate(char* name, char* city, char* area, char* population);

/**
 * @brief prints information of a region
 * //not in use
 * 
 * @param region - region to print
 */
void regionPrint(Region region);