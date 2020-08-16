#include <stdio.h>
#include <limits.h>

double GetArrayAvarageValue(int* arr, int arrSize) //calculates avarage value of an array
{
	double res=0;
	for (int i=0; i<arrSize; ++i)
		res+=arr[i];
	return (res/(double)arrSize);
}

int GetArrayMaxValue(int* arr, int arrSize) //calculates max value of an array
{
	int res = INT_MIN;
	for (int i=0; i<arrSize; ++i)
		if (res<arr[i])
			res = arr[i];
	return res;	
}

int main()
{
	FILE *inpFptr;
	inpFptr = fopen("inputFile", "r");

	if (inpFptr == NULL) //checking if input file is opened
	{
		printf("Unable to open input file");
		return -1;
	}
	
	int arrSize;
	fscanf(inpFptr, "%d", &arrSize); //reading count of elements of array
	
	int arr[arrSize];
	
	for (int i=0; i<arrSize; ++i)
	{
		if (fscanf(inpFptr, "%d", &(arr[i])) == -1) //reading each elemet and check if not an end of file
		{
			printf("Unvalid array size");
			return -1;
		}
	}
	
	fclose(inpFptr); //closing input file
	
	double avarage = GetArrayAvarageValue(arr, arrSize); //getting needed values
	int max = GetArrayMaxValue (arr, arrSize);
	
	FILE *outpFptr;
	outpFptr = fopen("answer-hw-3", "w");
	
	if (inpFptr == NULL) //checking if output file is opened
	{
		printf("Unable to open output file");
		return -1;
	}
	
	printf("avarage=%f  max=%d", avarage, max); //printing got values to terminal
	fprintf(outpFptr, "avarage=%f  max=%d", avarage, max); //writing got values to file
	
	fclose(outpFptr); //closing file
	
    return 0;
}