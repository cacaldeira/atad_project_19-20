#pragma once

typedef struct date {
    unsigned int day, month, year;
} Date;

Date dateCreate(char* stringDate);
int dateDaysBetween(Date date1, Date date2);
Date dateDayBefore(char* inputDate);