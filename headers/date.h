#pragma once

typedef struct date {
    unsigned int day, month, year;
} Date;

/**
 * @brief create date from given date string
 * 
 * @param stringDate - string date with format dd/mm/yyyy
 * @return Date - returns date
 */
Date dateCreate(char* stringDate);

/**
 * @brief calculate days between to given dates
 * 
 * @param date1 - from date
 * @param date2 - to date
 * @return int - return amount of days
 */
int dateDaysBetween(Date date1, Date date2);

/**
 * @brief returns the date of the day before given date
 * 
 * @param inputDate - date to calculate yesterday from
 * @return Date - return yesterday date
 */
Date dateDayBefore(char* inputDate);

/**
 * @brief verifies if two dates are the same
 * 
 * @param date1 
 * @param date2 
 * @return int - 1 if true or 0 zero if false and dates are different
 */
int dateIsEqual(Date date1, Date date2);

/**
 * @brief prints a date in format dd/mm/yyyy
 * 
 * @param date - date to print
 */
void datePrint(Date date);