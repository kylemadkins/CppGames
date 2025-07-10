#include <iostream>

int Index(int* arr, int row, int col, int rowLen) {
	return arr[row * rowLen + col];
}

void Fill(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
		//std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
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

typedef int (*ArithmeticFn)(int x, int y);
int Add(int x, int y);
int Sub(int x, int y);
ArithmeticFn GetArithmeticFn(char op);

int main() {
	int size = 10;
	int* arr = new int[size];
	Fill(arr, size);

	//size = 20;
	//Resize(&arr, size);
	//Fill(arr, size);

	//std::cout << "sum: " << Output(arr, size, Sum) << std::endl;
	//std::cout << "average: " << Output(arr, size, Average) << std::endl;

	int* arr2d = new int[size * size];
	Fill(arr2d, size * size);
	//std::cout << "row 8, col 4 = " << arr2d[84] << std::endl;

	int x;
	int y;
	char op;
	std::cout << "Enter first number: ";
	std::cin >> x;
	std::cout << "Enter second number: ";
	std::cin >> y;
	std::cout << "Enter operation (+, -): ";
	std::cin >> op;

	ArithmeticFn fn = GetArithmeticFn(op);
	std::cout << "Result: " << fn(x, y) << std::endl;

	delete[] arr;
	delete[] arr2d;
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

int Add(int x, int y) {
	return x + y;
}

int Sub(int x, int y) {
	return x - y;
}

ArithmeticFn GetArithmeticFn(char op) {
	switch (op) {
	case '+':
		return Add;
	case '-':
		return Sub;
	default:
		break;
	}
}
