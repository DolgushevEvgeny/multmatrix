// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
#include <string>
#include <fstream>

float** Create_Matrix()
{
	float **matrix = new float*[3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new float[3];
	}
	return matrix;
}

void Dispose_Memory(float **matrix)
{
	for (int i = 0; i < 3; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

float** Read_Map(char *Name)
{
	FILE *file_input = fopen(Name, "r");;

	if (file_input == NULL)
	{
		printf("Error: cannot load input file\n");
		system("pause");
		exit(1);
	}

	float **map = Create_Matrix();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float symbol;
			fscanf(file_input, "%f", &symbol);
			map[i][j] = symbol;	
		}
	}
	return map;
}

void Print_Matrix(float **matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%.3f ", matrix[i][j]);
		}
		printf("%s", "\n");
	}
}

float** Mult_Matrix(float **matrix1, float **matrix2)
{
	float **matrix_result = Create_Matrix();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float prom_result = 0;
			for (int k = 0; k < 3; k++)
				prom_result += matrix1[i][k] * matrix2[k][j];
			
			matrix_result[i][j] = prom_result;
		}
	}
	return matrix_result;
}

int main(int argc, char* argv[])
{
	char *file_name_first_matrix = argv[1];
	char *file_name_second_matrix = argv[2];
	
	float **first_matrix = Read_Map(&file_name_first_matrix[0]);
	float **second_matrix = Read_Map(&file_name_second_matrix[0]);
	float **matrix_result = Mult_Matrix(first_matrix, second_matrix);
	Print_Matrix(matrix_result);
	Dispose_Memory(first_matrix);
	Dispose_Memory(second_matrix);
	Dispose_Memory(matrix_result);
	return 0;
}

