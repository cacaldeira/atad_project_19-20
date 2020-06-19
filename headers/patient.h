#pragma once

#include "date.h"

typedef struct patient {
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

/**
 * @brief creates a patient with the given fields
 * 
 * @param id - patient id
 * @param sex - sexual gender
 * @param birthYear - birth year
 * @param country - country
 * @param region - region
 * @param infectionReason - reason of being infected 
 * @param infectedBy - patient id of patient who infected him
 * @param confirmedDate - confirmed date of being infected
 * @param releasedDate - released date
 * @param deceasedDate - deceased date
 * @param status - status isolated, released, deceased
 * @return Patient - created patient
 */
Patient patientCreate(char* id, char* sex, char* birthYear, char* country, char* region,
    char* infectionReason, char* infectedBy, char* confirmedDate, char* releasedDate, char* deceasedDate, char* status);

/**
 * @brief prints a patient with all it's information
 * 
 * @param patient - patient to print information about
 */
void printPatient(Patient patient);

/**
 * @brief calculates age of a patient
 * 
 * @param patient - patient to calculate age
 * @return int - age of patient or -1 if birthyear is unknown
 */
int patientAge(Patient patient);

/**
 * @brief calculates how many days patients was infected
 * 
 * @param patient - patient to calculate days
 * @return int - amount of days infected or -1 if days can't be calculated
 */
int patientIllnessDays(Patient patient);

/**
 * @brief prints a patient information shorten and in a single line only 
 * 
 * @param patient - patient to print
 */
void printSingleLinePatient(Patient patient);