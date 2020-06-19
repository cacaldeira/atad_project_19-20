#pragma once

#include "list.h"
#include "map.h"

///////////////////////// AUXILIARES /////////////////////////

/**
 * @brief splits a string in an array of strings delimetted by a given symbol
 * 
 * @param string - original string to split
 * @param nFields - number of fields expected out of conversion
 * @param delim - delimitter character
 * 
 * @return char** - array of strings
 */
char** split(char* string, int nFields, const char* delim);

/**
 * @brief removes commas from numeric fields
 * 
 * @param fields - array of strings where numeric fields will be
 */
void cleanFields(char** fields);

/**
 * @brief gets the "object" of a given patient id
 * 
 * @param patientsList - patient list from where to search
 * @param patient - patient of id is passed by reference
 * @param id - id of patient to search for
 * 
 * @return int - 1 if patient was found else 0 
 */
int getPatientByID(PtList patientsList, Patient* patient, char* id);

/**
 * @brief returns the position of a key in an array of keys
 * 
 * @param key - key to search for
 * @param regionKeys - array of keys where to search
 * @param length - length of the array
 * @return int - returns index of key or -1 if not found
 */
int keyToPos(char* key, String* regionKeys, int length);

/**
 * @brief sort map of regions alphabetically 
 * 
 * @param regions - map to sort
 */
void sortRegionsAlphabetical(PtMap regions);

/////////////////////////  FUNCTIONS A /////////////////////////

/**
 * @brief loads a file of patients into memory
 *  the filename is given by asked user input
 * 
 * if the file is not found prints a warning else: 
 * @return PtList - a list containing the file information divided by patients
 */
PtList loadp();

/**
 * @brief loads the file of regions into memory
 * 
 * if the file is not found prints a warning else:
 * @return PtMap - a map containing region information separated by field region (key)
 */
PtMap loadr();

/**
 * @brief clears and frees the memory from list of patients and regions
 * 
 * prints information on how many registers were cleared from each colletion
 * 
 * @param patients - list of patients
 * @param regions - list of regions
 */
void clear(PtList* patients, PtMap* regions);

///////////////////////// FUNCTIONS B /////////////////////////

/**
 * @brief prints information about a given patient
 * receives patient id by user input
 * 
 * prints a warning if patient does not exist or list of patients is empty
 *  
 * @param patients - list of patients to search for id
 */
void show(PtList patients);

/**
 * @brief prints average of age for deceased, released and isolated patients
 * 
 * patients without a known birth year are not accounted for
 * 
 * @param patients - list of patients to calculate averages from
 */
void average(PtList patients);

/**
 * @brief prints percentage of patients from which binary gender and unknown gender patients
 * and total amount of patients
 * 
 * prints a warning if the list is empty
 * 
 * @param patients - list of patients to calculate percentages from
 */
void sex(PtList patients);

/**
 * @brief prints the top 5 patients who took the longest days period to recover from illness
 * prioritizes oldest patients
 * 
 * prints a warning if the list is empty
 * 
 * @param patients - list of patients to calculate top5 from
 */
void topFive(PtList patients);

/**
 * @brief prints the contamination sequence of a patient - who contamited the patient, who contaminated who contaminated the patient...
 * patient id is passed by user input
 * 
 * prints a warning if the list is empty
 * 
 * @param patients - list of patients to check for patient and his sequence
 */
void follow(PtList patients);

/**
 * @brief prints the oldest person or persons if more than one patient has the same "top" age from both binary genders
 * 
 * prints a warning if the list is empty
 * 
 * @param patients - list of patients from where to check for oldest persons
 */
void oldest(PtList patients);

/**
 * @brief prints the growth of deceased and infected patients from a given date and the day before that
 * date is passed by user input - format 1/1/2020 or 01/01/2020
 * 
 * prints a warning if the list is empty
 * 
 * @param patients - list of patients to check for growth in given date
 */
void growth(PtList patients);

/**
 * @brief prints a 7x3 matrix contaning the number of deceased, released and isolated patients by age interval
 * patients with unknow age are also grouped
 * 
 * @param patients - list of patients from where to draw to the matrix
 */
void matrix(PtList patients);

///////////////////////// FUNCTIONS C /////////////////////////

/**
 * @brief prints a report to a file containing rate percentage for mortality, lethality and incidient rate for each region
 * 
 * @param patients - list of patients to calculate rates
 * @param regions  - list of regions to separete information
 */
void report(PtList patients, PtMap regions);

/**
 * @brief prints the regions with active cases
 * 
 * @param patients - patient list to search
 * @param regions  - regions to verify 
 */
void regions(PtList patients, PtMap regions);