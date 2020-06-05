#pragma once

typedef struct region {
  char name[40];
  char city[40];
  float area;
  int population;
} Region;

Region regionCreate(char* name, char* city, char* area, char* population);
void regionPrint(Region region);