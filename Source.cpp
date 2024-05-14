#include <iostream>
#include <fstream>
#include <vector>

void print(std::vector<std::vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			std::cout << matrix[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<std::vector<int>> read()
{
	std::ifstream f("input.txt");
	std::vector<int> input;
	std::vector<std::vector<int>> inputMatrix;
	int x;
	while (f >> x)
	{
		input.push_back(x);
	}
	if (input.size() % 7 != 0)
	{
		std::cout << "Numarul de biti introdusi nu esti divizibil cu 7!";
	}
	std::vector<int> aux;
	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		++count;
		aux.push_back(input[i]);
		if (count==7)
		{
			aux.push_back(0);
			inputMatrix.push_back(aux);
			aux.clear();
			count = 0;
		}
	}
	f.close();
	return inputMatrix;
}

int oneCount(std::vector<int> vector)
{
	int count = 0;
	for (int i=0;i<vector.size()-1;i++)
	{
		if (vector[i] == 1)++count;
	}
	return count;
}

void lastBit(std::vector<std::vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		if (oneCount(matrix[i]) % 2 != 0)
		{
			matrix[i][matrix[i].size() - 1] = 1; //ultimul bit de pe linie devine 1 dc. am nr impar de 1
			//break;
		}

		if (oneCount(matrix[i]) % 2 == 0)
		{
			matrix[i][matrix[i].size() - 1] = 0;
			//break;
		}
	}
	for (int j = 0; j < matrix[0].size(); j++)
	{
		int count = 0;
		for (int i = 0; i < matrix.size()-1; i++)
			if (matrix[i][j] == 1)++count;
		if (count % 2 == 0)matrix[matrix.size() - 1][j] = 0;
		else matrix[matrix.size() - 1][j] = 1;
	}
}

void function(std::vector<std::vector<int>>& matrix)
{
	std::vector<int> aux;
	//adaugare ultima linie
	std::cout << "Matricea initiala:\n";

	for (int j=0;j<8;j++)
	{
		int count = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][j] == 1)++count;
		}
		if (count % 2 != 0)aux.push_back(1);
		else aux.push_back(0);
	}

	matrix.push_back(aux);

	lastBit(matrix);
	print(matrix);

	if (matrix[matrix.size() - 1][matrix[0].size() - 1] == 0)std::cout << "Mesaj corupt!";
	else std::cout << "Mesaj valid!\n";
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[i].size(); j++)
			std::cout << matrix[i][j];
	std::cout << "\n\n";
}

void corruption(std::vector<std::vector<int>> matrix)
{
	//alegem random 2 nr pt pozitia corupta
	std::cout << "Corupem mesajul.\n";
	std::srand(std::time(nullptr));
	int randomNumberColumn = std::rand() % 6 + 0;
	int randomNumberRow = std::rand() % (matrix.size()-1) + 0;

	std::vector<std::vector<int>> auxMatrix;
	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<int> auxVector;
		for (int j = 0; j < matrix[i].size(); j++)
			auxVector.push_back(matrix[i][j]);
		auxMatrix.push_back(auxVector);
		auxVector.clear();
	}

	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[i].size(); j++)
			if (i == randomNumberRow && j == randomNumberColumn)
			{
				if (matrix[i][j] == 0)matrix[i][j] = 1;
				else matrix[i][j] = 0;
			}
	lastBit(matrix);

	print(matrix);

	int row=-1, col = -1;
	for (int i = 0; i < matrix.size(); i++)
		if (matrix[i][matrix[i].size() - 1] != auxMatrix[i][matrix[i].size() - 1] && i!=matrix.size()-1)row = i;
	for (int j = 0; j < 8; j++)
		if (matrix[matrix.size() - 1][j] != auxMatrix[matrix.size() - 1][j]&&j!=matrix[0].size()-1)col = j;

	std::cout << "Bitul gresit se afla pe pozitia (" << row << "," << col << ").";
}

int main()
{
	std::vector<std::vector<int>> matrix = read();
	function(matrix);
	corruption(matrix);
	return 0;
}