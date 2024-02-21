#Makefile - for knight tour

tour:    knightTour.c
		gcc knightTour.c -o ktour

clean: 
	rm -f tour