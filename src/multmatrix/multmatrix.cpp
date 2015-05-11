// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <cmath> 

using namespace std;

void Print_Matrix(const vector<vector<float>> &matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << fixed << setprecision(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void ReadFileAndFillMatrix(const string &fileName, vector<vector<float>> &matrix)
{
	ifstream inputFile;
	inputFile.open(fileName, ifstream::in);

	if (inputFile.good())
	{
		for (int i = 0; i < 3; ++i)
		{
			vector<float> line;
			for (int j = 0; j < 3; ++j)
			{
				float symbol;
				inputFile >> symbol;
				line.push_back(symbol);
			}
			matrix.push_back(line);
			line.clear();
		}
	}
}

void MultMatrix(const vector<vector<float>> &first, const vector<vector<float>> &second, vector<vector<float>> &result)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float prom_result = 0;
			for (int k = 0; k < 3; k++)
				prom_result += first[i][k] * second[k][j];

			result[i][j] = prom_result;
		}
	}
}

int main(int argc, char* argv[])
{
	string firstMatrixFileName = argv[1];
	string secondMatrixFileName = argv[2];

	vector<vector<float>> firstMatrix, secondMatrix, resultMatrix;

	ReadFileAndFillMatrix(firstMatrixFileName, firstMatrix);
	ReadFileAndFillMatrix(secondMatrixFileName, secondMatrix);

	resultMatrix = firstMatrix;

	MultMatrix(firstMatrix, secondMatrix, resultMatrix);
	Print_Matrix(resultMatrix);
	return 0;
}

