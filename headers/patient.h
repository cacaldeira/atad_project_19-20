#pragma once

#include "date.h"

typedef struct patient
{
    long int id;
    char sex[6]; // {“male”,“female”}
    int birthYear;
    char country[40]; //birth country
    char region[40];
    char infectionReason[100];
    long int infectedBy; // id of the infected patient
    Date confirmedDate;
    Date releasedDate;
    Date deceasedDate;
    char status[10]; //{“isolated,“released”,“deceased”}
} Patient; 

Patient patientCreate(char *id, char *sex, char *birthYear, char *country, char *region,
                      char *infectionReason, char *infectedBy, char *confirmedDate, char *releasedDate, char *deceasedDate, char *status);

void printPatient(Patient patient);

int patientAge(Patient patient);

int patientIllnessDays(Patient patient);