#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
double* randmassiv(int n, double* ptr_array);
double* pereborka(int n, double* ptr_array);
double* delete(double* ptr_arr, int size);
int* insert(int* ptr_arr, int* size, int index, int num);
int* randmassiv2(int n, int* ptr_array2);
int find_element(int* ptr_array2, int size, int element);
void main()
{
	setlocale(LC_ALL, "RUS");
	double* ptr_array;
	int* ptr_array2;
	int size;
	printf("¬ведите размер массива: ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}
	randmassiv(size, ptr_array);
	puts("\n\n");
	pereborka(size, ptr_array);
	puts("\n\n");
	delete(ptr_array, size);
	ptr_array2 = (int*)malloc(size * sizeof(int));
	if (ptr_array2 == NULL)
	{
		puts("error");
		return -1;
	}
	puts("\n\n");
	randmassiv2(size,ptr_array2);
	int i = 0;
	int max = ptr_array2[i];
	for (i; i <= size; i++)
	{
		if (ptr_array2[i] > max)
			max = ptr_array2[i];
	}
	printf("\nmax = %d",max);
	puts("\n\n");
	ptr_array2 = insert(ptr_array2, &size, find_element(ptr_array2, size, max), -999);
	for (int i = 0; i < size; i++) 
	{
		printf("ptr_array2[%d] = %d\n", i, ptr_array2[i]);
	}
}
double* randmassiv(int n, double *ptr_array)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = -1 + 1.f * (1 - (-1)) * rand() / RAND_MAX;;
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nptr_array[%d] = %lf", i, ptr_array[i]);
	}
	return ptr_array;
}
double* pereborka(int n, double *ptr_array)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			ptr_array[i] = ptr_array[i] + 1;
		}
		printf("\nptr_array[%d] = %lf", i, ptr_array[i]);
	}
	return ptr_array;
}
double* delete(double* ptr_arr, int size) 
{
	for (int i = 0; i < size ; i++)
	{
		if (ptr_arr[i] < 0)
		{
			for (int j = i; j < size - 1; j++)
				ptr_arr[j] = ptr_arr[j+1];
			size--;
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("\nptr_array[%d] = %lf", i, ptr_arr[i]);
	}
	return ptr_arr;
}
int* randmassiv2(int n, int* ptr_array2)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array2[i] = -100 + rand() % (100 - (-100));
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nptr_array2[%d] = %d", i, ptr_array2[i]);
	}
	return ptr_array2;
}
int* insert(int* ptr_arr, int* size, int index, int num)
{
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	int* ptr_arr_n = (int*)realloc(ptr_arr, size_n * sizeof(int));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
	{
		ptr_arr[i] = ptr_arr[i - 1];
	}
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
}
int find_element(int* ptr_array2, int size, int element) 
{
	int position =-1;
	for (int i = 0; i < size; i++)
	{
		if (ptr_array2[i] == element) {
			position = i;
		}
	}
	return position;
}

