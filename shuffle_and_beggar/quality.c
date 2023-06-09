#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "riffle.h"

int main()
{	
	// Set the seed based on time
	srand(time(NULL));
	
	// Calculate the averages
	float averages[15];
	for (int i = 1; i <= 15; i++)
		averages[i-1] = average_quality(50, i, 30);
	
	// File access block
	FILE *f_ptr;
	f_ptr = fopen("shuffle.txt", "w");
	
	if (f_ptr == NULL)
	{
		printf("Error opening file.");
		exit(1);
	}
	
	// Output the averages to file
	for (int i = 1; i <= 15; i++)
		fprintf(f_ptr, "Shuffles = %i => Average Quality = %f\n", i, averages[i-1]);
	
	fclose(f_ptr);
}
