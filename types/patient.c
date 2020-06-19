#include "date.h"
#include "patient.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Patient patientCreate(char* id, char* sex, char* birthYear, char* country, char* region,
    char* infectionReason, char* infectedBy, char* confirmedDate, char* releasedDate, char* deceasedDate, char* status)
{
    Patient patient;
    patient.id = atol(id);
    strcpy(patient.sex, sex);

    //No caso da birth_year ou infectedBy vir a branco devem ser inicializados a -1
    patient.birthYear = birthYear[0] == '\0' ? -1 : atoi(birthYear);
    patient.infectedBy = infectedBy[0] == '\0' ? -1 : atol(infectedBy);

    strcpy(patient.country, country);
    strcpy(patient.region, region);
    strcpy(patient.infectionReason, infectionReason);

    // dateCreate handles the verifications to dates
    patient.confirmedDate = dateCreate(confirmedDate);
    patient.releasedDate = dateCreate(releasedDate);
    patient.deceasedDate = dateCreate(deceasedDate);

    status[strlen(status) - 2] = '\0'; //cut out the \r\n that comes from the file
    strcpy(patient.status, status);

    return patient;
}

void printPatient(Patient patient)
{
    puts("\n||||| PATIENT |||||");
    printf("ID: %ld\n", patient.id);
    printf("SEX: %s\n", patient.sex);

    printf("AGE: ");
    int age = patientAge(patient);
    if (age != -1)
        printf("%d\n", age);
    else
        puts("unknow");

    printf("COUNTRY/REGION: %s / %s\n", patient.country, patient.region);

    printf("INFECTION REASON: ");
    if (patient.infectionReason[0] != '\0')
        printf("%s\n", patient.infectionReason);
    else
        puts("unknow");

    printf("STATE: %s\n", patient.status);

    int days = patientIllnessDays(patient);
    printf("NUMBER OF DAYS WITH ILLNESS: ");
    if (days != -1)
        printf("%d\n", days);
    else
        puts("unknow");
}

int patientAge(Patient patient)
{
    if (patient.birthYear == -1)
        return -1;

    time_t rawtime;
    struct tm* timeInfo;

    time(&rawtime);
    timeInfo = localtime(&rawtime);

    return (timeInfo->tm_year + 1900) - patient.birthYear;
}

int patientIllnessDays(Patient patient)
{
    if (patient.confirmedDate.day == 0
        || (patient.deceasedDate.day == 0 && patient.releasedDate.day == 0 && patient.status[0] != 'i'))
        return -1;

    switch (patient.status[0]) {
    case 'd':
        return dateDaysBetween(patient.confirmedDate, patient.deceasedDate);

    case 'r':
        return dateDaysBetween(patient.confirmedDate, patient.releasedDate);

    case 'i':; //a label can only be part of a statement and a declaration is not a statement
        time_t rawtime;
        struct tm* timeInfo;

        time(&rawtime);
        timeInfo = localtime(&rawtime);

        char currDateString[255];

        strftime(currDateString, 255, "%d/%m/%Y", timeInfo);

        Date currDate = dateCreate(currDateString);

        return dateDaysBetween(patient.confirmedDate, currDate);
    }
}

void printSingleLinePatient(Patient patient)
{
    printf("Patient: ID: %ld, ", patient.id);
    printf("SEX: %s, ", patient.sex);
    printf("AGE: ");
    int age = patientAge(patient);
    if (age != -1)
        printf("%d, ", age);
    else
        puts("unknow, ");

    printf("COUNTRY/REGION: %s / %s, ", patient.country, patient.region);
    printf("STATE: %s\n", patient.status);
}