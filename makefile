default:
	gcc	-g	-o	main	main.c	functions.c	list/listArrayList.c	list/listElem.c	types/date.c	types/patients.c	map/mapArrayList.c	map/mapElem.c	types/region.c	-Iheaders

clean:	
	rm	-f	main