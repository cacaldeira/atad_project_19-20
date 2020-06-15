#pragma once

#include "list.h"
#include "map.h"

char** split(char* string, int nFields, const char* delim);

void cleanificator(char** fields);

int getPatientByID(PtList patientsList, Patient* patient, char* id);

// Funções A

PtList loadp();
PtMap loadr();
void clear();
void show(PtList patients);
void average(PtList patients);
void sex(PtList patients);
void topFive(PtList patients);
void printSingleLinePatient(Patient patient);
void follow(PtList patients);
void cleanFields(char** fields);
void oldest(PtList patients);
void growth(PtList patients);
void matrix(PtList patients);