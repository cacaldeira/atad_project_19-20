#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "map.h"
#include "patient.h"
#include "region.h"

char** split(char* string, int nFields, const char* delim)
{
    char** tokens = (char**)malloc(sizeof(char*) * nFields);

    int index = 0;

    int len = strlen(string);

    tokens[index++] = &string[0];

    for (int i = 0; i < len; i++) {
        if (string[i] == delim[0]) {
            string[i] = '\0';

            if (i < len - 1) {
                tokens[index++] = &string[i] + 1;
            }
        }
    }

    return tokens;
}

PtList loadp()
{
    // Pede o nome dum ficheiro de pacientes
    printf("file> ");
    char filename[255];
    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename) - 1] = '\0'; // remove trailing \n

    char path[] = "files/";
    strcat(path, filename);

    // Abre o ficheiro
    FILE* file;
    file = fopen(path, "r");

    // Se  o  ficheiro  não  puder  ser aberto, escreve File not found e a coleção fica vazia
    if (file == NULL) {
        puts("File not found\n");
        return NULL;
    }

    // Carrega-o em memória,  mostrando  o  número  de  doentes  importados
    PtList patients = listCreate(100);
    char line[255];
    int count = -2;

    while (fgets(line, 255, file) != NULL) {
        count++;

        // A primeira linha dos ficheiros é uma linha com os cabeçalhos e não contem dados
        if (count == -1)
            continue;

        char** fields = split(line, 11, ";");

        Patient patient = patientCreate(fields[0], fields[1], fields[2], fields[3],
            fields[4], fields[5], fields[6], fields[7],
            fields[8], fields[9], fields[10]);

        free(fields);

        listAdd(patients, count, patient);
    }

    fclose(file);

    printf("Imported %d lines\n", count + 1);
    return patients;
}

PtMap loadr()
{
    /* 
    because setLocale does not work well with my Linux configurations 
    (even if change my own computer locale) I needed to replace commas 
    so atof() parses the number correctly from area with decimal places
    and at the same time remove commas from population because atoi() won't parse them    

    set 'cleanify = 0' to work with the raw data input
    */
    int cleanify = 1;

    // Abre o ficheiro “regions.csv”
    FILE* file;
    file = fopen("files/regions.csv", "r");

    // Se o ficheiro não puder ser aberto, escreve File not found e a coleção respetiva fica vazia.
    if (file == NULL) {
        puts("File not found");
        return NULL;
    }

    // Carrega-o em memória, mostrando o número de regiões importadas
    PtMap regions = mapCreate(100);
    char line[255];
    int count = -2;

    while (fgets(line, 255, file) != NULL) {
        count++;

        // A primeira linha dos ficheiros é uma linha com os cabeçalhos e não contem dados
        if (count == -1)
            continue;

        char** fields = split(line, 4, ";");

        if (cleanify)
            cleanificator(fields);

        Region region = regionCreate(fields[0], fields[1], fields[2], fields[3]);

        mapPut(regions, region.name, region);

        regionPrint(region);

        free(fields);
    }

    fclose(file);

    printf("Imported %d lines", count);
    return regions;
}

//special function so I can test stuff on my linux box _ César
void cleanificator(char** fields)
{
    for (int i = 0; i < strlen(fields[2]); i++)
        if (fields[2][i] == ',')
            fields[2][i] == '.';

    char cleanPopulation[strlen(fields[3])];
    int tracker = 0;
    for (int i = 0; i < strlen(fields[3]); i++)
        if (fields[3][i] != ',')
            cleanPopulation[tracker++] = fields[3][i];

    strcpy(fields[3], cleanPopulation);
}

void clear(PtList* patients, PtMap* regions)
{
    int nPatients = 0, nRegions = 0;

    if (patients != NULL)
        listSize(*patients, &nPatients);

    if (regions != NULL)
        mapSize(*regions, &nRegions);

    listDestroy(patients);
    mapDestroy(regions);

    *patients = NULL;
    *regions = NULL;

    printf("%d records deleted from Patients\n", nPatients);
    printf("%d records deleted from Regions\n", nRegions);
}

void show(PtList patients)
{
    if (patients == NULL) {
        puts("Empty patient list!\n");
        return;
    }

    printf("id> ");
    char patientID[255];
    fgets(patientID, sizeof(patientID), stdin);

    int size;
    listSize(patients, &size);

    Patient patient;

    for (int i = 0; i < size - 1; i++) {
        listGet(patients, i, &patient);
        if (patient.id == atol(patientID)) {
            printPatient(patient);
            break;
        }
    }
}

void average(PtList patients)
{
    if (patients == NULL) {
        puts("Empty patient list!\n");
        return;
    }

    int avgDeceased = 0, avgReleased = 0, avgIsolated = 0;
    int countDeceased = 0, countReleased = 0, countIsolated = 0;

    int size;
    listSize(patients, &size);

    Patient patient;

    for (int i = 0; i < size; i++) {
        listGet(patients, i, &patient);

        if (patient.birthYear != -1)
            switch (patient.status[0]) {

            case 'd':
                avgDeceased += patientAge(patient);
                countDeceased++;
                break;

            case 'r':
                avgReleased += patientAge(patient);
                countReleased++;
                break;

            case 'i':
                avgIsolated += patientAge(patient);
                countIsolated++;
                break;

            default:
                break;
            }
    }

    avgDeceased /= countDeceased;
    avgReleased /= countReleased;
    avgIsolated /= countIsolated;

    puts("Average age of patients:");
    printf("\tdeceased: %d y.o.\n", avgDeceased);
    printf("\treleased: %d y.o.\n", avgReleased);
    printf("\tisolated: %d y.o.\n", avgIsolated);
}

void sex(PtList patients)
{
    if (patients == NULL) {
        puts("Empty patient list!\n");
        return;
    }

    int countMale = 0, countFemale = 0, countUnknow = 0;

    int size;
    listSize(patients, &size);

    Patient patient;

    for (int i = 0; i < size; i++) {
        listGet(patients, i, &patient);
        switch (patient.sex[0]) {

        case 'm':
            countMale++;
            break;

        case 'f':
            countFemale++;
            break;

        case '\0':
            countUnknow++;
            break;

        default:
            break;
        }
    }

    countMale *= 100;
    countMale /= size;

    countFemale *= 100;
    countFemale /= size;

    countUnknow *= 100;
    countUnknow /= size;

    puts("Percentage gender of patients:");
    printf("\tmale: %d%%\n", countMale);
    printf("\tfemale: %d%%\n", countFemale);
    printf("\tunknow: %d%%\n", countUnknow);
}

void topFive(PtList patients)
{
    if (patients == NULL) {
        puts("Empty patient list!\n");
        return;
    }

    int size;
    listSize(patients, &size);

    Patient currPatient;
    Patient topPatient;

    PtList topList = listCreate(5);
    int counter = 0;

    for (int i = 0; i < size; i++) { //run all

        //pick one
        listGet(patients, i, &topPatient);
        int topDays = patientIllnessDays(topPatient);

        // check if is valid
        // there's isolated patients with recovered dates and theres recovered patients with no recovered date
        if (topPatient.releasedDate.day == 0 || topPatient.status[0] != 'r')
            continue;

        // check if there's any bigger
        for (int z = i + 1; z < size; z++) {
            //pick one
            listGet(patients, z, &currPatient);
            int currDays = patientIllnessDays(currPatient);

            // check if is valid
            // there's isolated patients with recovered dates and theres recovered patients with no recovered date
            if (currPatient.releasedDate.day == 0 || currPatient.status[0] != 'r')
                continue;

            // check if current patient is already in top list
            Patient auxPatient;
            int auxSize;
            listSize(topList, &auxSize);
            int repeated = 0;
            for (int k = 0; k < auxSize; k++) {
                listGet(topList, k, &auxPatient);
                if (currPatient.id == auxPatient.id) {
                    repeated = 1;
                    break;
                }
            }

            // if existed ignore
            if (repeated)
                continue;

            // check if it's bigger
            if (currDays > topDays) {
                topPatient = currPatient;
                topDays = currDays;
            }

            // check if its the same and keeps the oldest patient
            if (currDays == topDays)
                if (currPatient.birthYear < topPatient.birthYear) {
                    topPatient = currPatient;
                    topDays = currDays;
                }
        }
        if (counter < 5) {
            listAdd(topList, counter, topPatient);
            counter++;
        } else
            break;
    }

    listPrint(topList);
}