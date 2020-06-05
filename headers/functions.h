#pragma once

#include "list.h"
#include "map.h"

char** split(char* string, int nFields, const char* delim);

void cleanificator(char** fields);

// Funções A

PtList loadp();
PtMap loadr();
void clear();
void show(PtList patients);
void average(PtList patients);
void sex(PtList patients);
void topFive(PtList patients);
