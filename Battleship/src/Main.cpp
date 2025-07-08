#include <iostream>

void Fill(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

void Resize(int** arr, int size) {
	if (*arr != nullptr) delete[] *arr;
	*arr = new int[size];
}

int Sum(int* arr, int size);
float Average(int* arr, int size);
template <typename T>
T Output(int* arr, int size, T (*Fn)(int*, int));

int main() {
	int size = 10;
	int* arr = new int[size];
	Fill(arr, size);

	//size = 20;
	//Resize(&arr, size);
	//Fill(arr, size);

	std::cout << "sum: " << Output(arr, size, Sum) << std::endl;
	std::cout << "average: " << Output(arr, size, Average) << std::endl;
}

int Sum(int* arr, int size) {
	int result = 0;
	for (int i = 0; i < size; i++) {
		result += arr[i];
	}
	return result;
}

float Average(int* arr, int size) {
	float sum = Sum(arr, size);
	return sum / size;
}

template <typename T>
T Output(int* arr, int size, T (*Fn)(int*, int)) {
	return Fn(arr, size);
}
