#include <iostream>
using namespace std;

int* CreateArray(int size)
{
	int* arr = new int[size];
	return arr;
}

void InitArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}
void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ShowArrayAdress(int* arr)
{
	cout << "Adress of array : " << arr << endl;
}

int* DeleteLastElement(int* arr, int* size)
{
	int* temp = new int[*size - 1];
	for (int i = 0; i < *size - 1; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	(*size)--;
	return temp;
}

int* AddDesireElement(int* arr, int* size)
{
	int des, pos;
	cout << "Enter number to add : ";
	cin >> des;
	cout << endl;
	cout << "Enter number's position : ";
	cin >> pos;
	cout << endl;
	int* temp = new int[*size + 1];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	temp[pos] = des;
	for (int i = pos; i < *size; i++)
	{
		temp[i+1] = arr[i];
	}
	delete[]arr;
	(*size)++;
	return temp;
}

int main()
{
	int* first = new int(5);
	float* second = new float(5.5);
	double* third = new double(5.55);

	cout << "First - " << *first << endl;
	cout << "Second - " << *second << endl;
	cout << "Third - " << *third << endl;

	cout << "Their sum : " << *first + *second + *third << endl;

	delete first;
	delete second;
	delete third;

	cout << "==============================" << endl;

	int size = 5;
	cout << "Enter size : ";
	cin >> size;
	int* arr = CreateArray(size);
	InitArray(arr, size);
	ShowArray(arr, size);
	ShowArrayAdress(arr);
	arr = DeleteLastElement(arr, &size);
	ShowArray(arr, size);
	arr = AddDesireElement(arr, &size);
	ShowArray(arr, size);

	delete[]arr;
}