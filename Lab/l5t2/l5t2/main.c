#include <stdio.h>

int main(void)
{
	FILE *infile = NULL;
	FILE *outfile = NULL;
	int count = 0;
	double nums = 0.0,total=0.0;

	infile = fopen("data.txt", "r");
	outfile = fopen("outdata.txt", "w");
	/* Fill in the code to open a file. Make sure you check that the file was open successfully. */

	while (!feof(infile))
	{
		fscanf(infile, "%lf", &nums);
		total += nums;
		count += 1;
		/* Read in the real values. */
		/* Keep track of the number of values read and the sum of the values. */
	}

	total = total / count;
	fprintf(outfile, "%lf\n", total);

	/* Output average to a file named "output.txt". */
	/* Close your files. */
	fclose(infile);
	fclose(outfile);
	return 0;
}