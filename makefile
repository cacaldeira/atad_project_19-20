default:
	gcc	-g	-o	prog	main.c	functions.c	list/listArrayList.c	list/listElem.c	types/date.c	types/patient.c	map/mapArrayList.c	map/mapElem.c	types/region.c	-Iheaders

clean:	
	rm	-f	main