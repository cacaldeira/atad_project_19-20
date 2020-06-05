/**
 * @file mapElem.c
 * @brief Implements operations for types MapKey and MapValue.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "mapElem.h"
#include <stdio.h>

void mapKeyPrint(MapKey key) {
	printf("%s \n", key);
}

void mapValuePrint(MapValue value) {
	regionPrint(value);
}

bool mapKeyEquals(MapKey key1, MapKey key2) {
	// in case of integer keys:
	return (key1 == key2); 
}