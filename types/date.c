#include "date.h"
#include "functions.h"

#include <stdlib.h>

Date dateCreate(char* stringDate)
{
    Date date;
    char** fields = split(stringDate, 3, "/");

    // No caso de um campo tipo data vir em branco, a data deve ser inicializada a 0/0/0
    if (fields[0][0] == '\0') {
        date.day = 0;
        date.month = 0;
        date.year = 0;
    } else {
        date.day = atoi(fields[0]);
        date.month = atoi(fields[1]);
        date.year = atoi(fields[2]);
    }

    free(fields);

    return date;
}

//https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/
int dateDaysBetween(Date date1, Date date2)
{
    int d1Days = (date1.year * 365) + date1.day;
    int d2Days = (date2.year * 365) + date2.day;
    int auxYear;

    // Leap days to account date1
    auxYear = date1.year;
    if (date1.month <= 2)
        auxYear--;

    d1Days += auxYear / 4 - auxYear / 100 + auxYear / 400;

    // Leap days to account date2
    auxYear = date2.year;
    if (date2.month <= 2)
        auxYear--;

    d2Days += auxYear / 4 - auxYear / 100 + auxYear / 400;

    int monthDays[12] = { 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < date1.month - 1; i++)
        d1Days += monthDays[i];

    for (int i = 0; i < date2.month - 1; i++)
        d2Days += monthDays[i];

    return d2Days - d1Days;
}