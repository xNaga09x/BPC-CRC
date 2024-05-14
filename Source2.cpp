#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void print(std::vector<int> message)
{
	for (int i = 0; i < message.size(); i++)
		std::cout << message[i];
}

void read(std::vector<int>& message, std::vector<int>& polynom)
{
	std::ifstream f("input.txt");
	std::string line;

	int count = 0;
	while (std::getline(f, line))
	{
		std::istringstream iss(line);

		int num;
		while (iss >> num)
		{
			if (num != 0 && num != 1)std::cout << "\nNu sunt binare toate valorile!\n";
			if (count == 0)message.push_back(num);
			else polynom.push_back(num);
		}
		++count;
	}
	if (polynom.front() == 0)std::cout << "\nPrima valoare a coeficientului a polinomului este 0!\n";
	if (polynom.size() > message.size())std::cout << "\nLungimea mesajului este mai mica decat numarul de coeficienti ai polinomului!\n";

	std::cout << "Message:\n";
	print(message);
	std::cout << "\nPolynom:";
	print(polynom);
	std::cout << "\nRead succesfully!";
	f.close();
}

void addZero(std::vector<int>& message, const int& rang)
{
	for (int i = 0; i < rang; i++)
		message.push_back(0);
	std::cout << "\nPadded succesfully!";
}

std::vector<int> copyMessage(std::vector<int>& message)
{
	std::vector<int> aux;
	for (int i = 0; i < message.size(); i++)
		aux.push_back(message[i]);
	//std::cout << "\nCopied message succesfully!";
	return aux;
}

std::vector<int> XOR(std::vector<int> message, const std::vector<int>& polynom)
{
	std::vector<int> aux = copyMessage(message);
	while (!aux.empty() && aux.front() == 0)
	{
		aux.erase(aux.begin());
	}
	if (aux.empty())
	{
		// Dacă aux este gol, returnăm un vector gol.
		return std::vector<int>();
	}
	else if (aux.size() < polynom.size())
	{
		std::cout << "\nMessage after final XOR:";
		print(aux);
		std::vector<int> aux2 = copyMessage(aux);
		return aux2;
	}
	else
	{
		std::cout << "\n";
		print(polynom);
		std::cout << "\n";
		print(aux);
		std::cout << "\n";
		int count = 0;
		while (count < polynom.size())
		{
			if (polynom[count] == 1 && aux[count] == 1)
			{
				aux[count] = 0;
			}
			else if (polynom[count] == 1 && aux[count] == 0)
			{
				aux[count] = 1;
			}
			++count;
		}
		print(aux);
		std::cout << "\n";

		// Verificăm dacă aux este gol după operația XOR.
		if (aux.empty())
		{
			return std::vector<int>();
		}
		else
		{
			return XOR(aux, polynom);
		}
	}
}


void adjustMessage(std::vector<int>& message, const std::vector<int>& r, const int& rang)
{
	int count = 0;
	int addZero = rang - r.size();
	while (count < addZero)
	{
		message.push_back(0);
		++count;
	}
	count = 0;
	while (count < r.size())
	{
		message.push_back(r[count]);
		++count;
	}
	std::cout << "\nAdjusted message succesfully!";
}

int main()
{
	std::vector<int> message;
	std::vector<int> polynom;
	int rang;

	read(message, polynom);
	rang = polynom.size() - 1;
	std::vector<int> messageCopy = copyMessage(message);
	std::cout << "\nRang:" << rang << "\n";

	addZero(message, rang);
	std::cout << "\nMessage after padding:";
	print(message);

	message = XOR(message, polynom);
	std::cout << "\nR(X) after XOR:";
	print(message);

	std::cout << "\nInitial message:";
	print(messageCopy);
	adjustMessage(messageCopy,message, rang);
	std::cout << "\nMessage after adding R(x):\n";
	print(messageCopy);

	messageCopy = XOR(messageCopy, polynom);

	if (messageCopy.empty())std::cout << "\nMesaj fara erori.";
	else std::cout << "\nMesaj cu erori.";
	return 0;
}