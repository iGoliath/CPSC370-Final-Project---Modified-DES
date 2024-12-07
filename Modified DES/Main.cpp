#include <iostream>
#include <string>

void HextoBinary(std::string Hex, int binary[]);
void BinarytoHexPrint(int* binary);

int main() {
	std::string Hex = "";
	int binary[16];
	HextoBinary(Hex, binary);
	for (int i = 0; i < 16; i++) std::cout << binary[i];
}

void HextoBinary(std::string Hex, int binary[]) {
	int stringIndex = 0;
	for (int i = 0; i < 64; i+=4) {
		switch (Hex[stringIndex]) {
		case ('0'):
			binary[i] = 0;
			binary[i + 1] = 0;
			binary[i + 2] = 0;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('1'):
			binary[i] = 0;
			binary[i + 1] = 0;
			binary[i + 2] = 0;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('2'):
			binary[i] = 0;
			binary[i + 1] = 0;
			binary[i + 2] = 1;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('3'):
			binary[i] = 0;
			binary[i + 1] = 0;
			binary[i + 2] = 1;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('4'):
			binary[i] = 0;
			binary[i + 1] = 1;
			binary[i + 2] = 0;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('5'):
			binary[i] = 0;
			binary[i + 1] = 1;
			binary[i + 2] = 0;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('6'):
			binary[i] = 0;
			binary[i + 1] = 1;
			binary[i + 2] = 1;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('7'):
			binary[i] = 0;
			binary[i + 1] = 1;
			binary[i + 2] = 1;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('8'):
			binary[i] = 1;
			binary[i + 1] = 0;
			binary[i + 2] = 0;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('9'):
			binary[i] = 1;
			binary[i + 1] = 0;
			binary[i + 2] = 0;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('A'):
			binary[i] = 1;
			binary[i + 1] = 0;
			binary[i + 2] = 1;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('B'):
			binary[i] = 1;
			binary[i + 1] = 0;
			binary[i + 2] = 1;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('C'):
			binary[i] = 1;
			binary[i + 1] = 1;
			binary[i + 2] = 0;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('D'):
			binary[i] = 1;
			binary[i + 1] = 1;
			binary[i + 2] = 0;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		case('E'):
			binary[i] = 1;
			binary[i + 1] = 1;
			binary[i + 2] = 1;
			binary[i + 3] = 0;
			stringIndex++;
			break;
		case('F'):
			binary[i] = 1;
			binary[i + 1] = 1;
			binary[i + 2] = 1;
			binary[i + 3] = 1;
			stringIndex++;
			break;
		}
	}
}

void BinarytoHexPrint(int* binary) {
	for (int i = 0; i < 64; i += 4) {
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 0) std::cout << "0";
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 1) std::cout << "1";
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 0) std::cout << "2";
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 1) std::cout << "3";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 0) std::cout << "4";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 1) std::cout << "5";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 0) std::cout << "6";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 1) std::cout << "7";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 0) std::cout << "8";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 1) std::cout << "9";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 0) std::cout << "A";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 1) std::cout << "B";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 0) std::cout << "C";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 1) std::cout << "D";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 0) std::cout << "E";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 1) std::cout << "F";
	}
}