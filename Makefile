#Makefile - for knight tour

tour:    tour.c
		gcc knightTour.c -o tour

clean: rm -rf tour