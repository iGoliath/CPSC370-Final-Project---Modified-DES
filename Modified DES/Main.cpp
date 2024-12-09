#include <iostream>
#include <string>

void HextoBinary(std::string Hex, int binary[]);
void DecimaltoBinary(int decimal, int* binary);
void BinarytoHexPrint(int* binary, int bits);
std::string BinarytoHex(int* binary);
void IP(int* binary, int* R0, int* L0);
void GenerateKeys(std::string Hex, int* k1, int* k2);
void PC1(int* key, int* C0D0);
void LeftShiftBits(int* C0D0);
void PC2(int* C0D0, int* PC2Array);
void ExpandR(int* R0, int* ER0);
void XORKey(int* ER0, int* key, int* results);
void SBoxes(int* XOR, int* reults);
void Permutation(int* SBoxResults, int* PB);
void LXORR(int* L0, int* afterPermutation, int* R1);
void IIP(int* L2R2, int* final);
std::string DESEncrypt(std::string Plaintext, int* key);
std::string DESDecrypt(std::string Ciphertext, int* key);
void DESBruteForce(std::string Ciphertext, std::string plaintext);

const int IPTable[64] = { 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35,
27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15,
7, 56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44,
36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6 };

const int PC2Table[48] = { 13, 16, 10, 23, 0, 4, 2, 27, 
14, 5, 20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12,
1, 40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47, 43, 
48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31};

const int ERTable[48] = { 31, 0, 1, 2, 3, 4, 3, 4,
5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 11, 12, 13, 14, 15,
16, 15, 16, 17, 18, 19, 20, 19, 20, 21, 22, 23, 24, 23,
24, 25, 26, 27, 28, 27, 28, 29, 30, 31, 0 };

const std::string SBox[64] = { "0010", "1100", "0100", "0000", "1000", "1010", "1011", "0111", "0110", "0101",
"0011", "1111", "1110", "0001", "1101", "1001", "1110", "1011", "0011", "1101", "0100", "0110", "1100", "0001",
"1111", "0000", "0101", "1010", "0010", "1001", "1000", "0111", "0101", "0010", "0001", "1011", "1010", "1101",
"0110", "1000", "0100", "1001", "1100", "1110", "0111", "0011", "0000", "1111", "1010", "1001", "1100", "0110",
"0001", "0100", "0010", "1101", "0111", "1111", "0000", "1000", "1011", "1110", "0101", "0011"};

const int PB[32] = { 15, 6, 19, 20, 28, 11, 27,
16, 0, 14, 22, 25, 4, 17, 30, 9, 1, 7, 23, 13, 
31, 26, 2, 8, 18, 12, 29, 5, 21, 10, 3, 24 };

const int IIPTable[64] = { 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62,
30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51,
19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48, 16, 56, 24 };

int main() {
	std::string plaintext;
	std::string key;
	std::cout << "Please enter key: ";
	getline(std::cin, key, '\n');
	std::cout << "Please enter plaintext: ";
	getline(std::cin, plaintext, '\n');
	int K1[56];
	int K2[56];
	GenerateKeys(key, K1, K2);
	
	std::string toReturn = DESEncrypt(plaintext, K1);

	std::string toReturn2 = DESEncrypt(toReturn, K2);

	std::string firstDecrypt = DESDecrypt(toReturn2, K2);

	std::string secondDecrypt = DESDecrypt(firstDecrypt, K1);

	std::cout << "\n\nAn intercepted cipher text was found to be: " << toReturn2
		<< ". Using a brute force attack, the plaintext will be found. Please press enter to continue: ";
	
	std::string empty;
	getline(std::cin, empty, '\n');

	DESBruteForce(toReturn2, "0123456789ABCDEF");

	return 0;

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

void DecimaltoBinary(int decimal, int* binary) {
	for (int i = 63; i >= 0; i--) {
		binary[i] = decimal % 2;
		decimal /= 2;
	}
}

std::string BinarytoHex(int* binary) {
	std::string toReturn = "";
	for (int i = 0; i < 64; i += 4) {
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 0) toReturn += "0";
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 1) toReturn += "1";
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 0) toReturn += "2";
		if (binary[i] == 0 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 1) toReturn += "3";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 0) toReturn += "4";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 1) toReturn += "5";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 0) toReturn += "6";
		if (binary[i] == 0 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 1) toReturn += "7";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 0) toReturn += "8";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 0 && binary[i + 3] == 1) toReturn += "9";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 0) toReturn += "A";
		if (binary[i] == 1 && binary[i + 1] == 0 && binary[i + 2] == 1 && binary[i + 3] == 1) toReturn += "B";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 0) toReturn += "C";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 0 && binary[i + 3] == 1) toReturn += "D";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 0) toReturn += "E";
		if (binary[i] == 1 && binary[i + 1] == 1 && binary[i + 2] == 1 && binary[i + 3] == 1) toReturn += "F";
	}
	return toReturn;
}

void BinarytoHexPrint(int* binary, int bits) {
	for (int i = 0; i < bits; i += 4) {
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

void IP(int* binary, int* L0, int* R0) {
	int startingIndex = 57;
	int holdIndex = 57;
	for (int i = 0; i < 32; i++) {
		L0[i] = binary[startingIndex];
		startingIndex -= 8;
		if (startingIndex < 0) {
			holdIndex += 2;
			startingIndex = holdIndex;
		}
	}
	startingIndex = 56;
	holdIndex = 56;
	for (int i = 0; i < 32; i++) {
		R0[i] = binary[startingIndex];
		startingIndex -= 8;
		if (startingIndex < 0) {
			holdIndex += 2;
			startingIndex = holdIndex;
		}
	}


}

void GenerateKeys(std::string Hex, int* k1, int* k2) {
	int K0[64];
	int C0D0[56];
	int K1[48];
	int K2[48];
	HextoBinary(Hex, K0);
	PC1(K0, C0D0);
	std::cout << "\nResult of Permuted Choice 1: ";
	BinarytoHexPrint(C0D0, 56);
	LeftShiftBits(C0D0);
	std::cout << "\nResult of Left Shift #1: ";
	BinarytoHexPrint(C0D0, 56);
	PC2(C0D0, k1);
	std::cout << "\nResult of Permuted Choice 2 #1 (Key 1): ";
	BinarytoHexPrint(k1, 56);
	LeftShiftBits(C0D0);
	std::cout << "\nResult of Left Shift #2: ";
	BinarytoHexPrint(C0D0, 56);
	PC2(C0D0, k2);
	std::cout << "\nResult of Permuted Choice 2 #2 (Key 2): ";
	BinarytoHexPrint(k2, 56);
	std::cout << "\n\n";
	
}

void PC1(int* key, int* C0D0) {
	int startingIndex = 56;
	int holdIndex = 56;
	for (int i = 0; i < 28; i++) {
		C0D0[i] = key[startingIndex];
		startingIndex -= 8;
		if (startingIndex < 0) {
			holdIndex++;
			startingIndex = holdIndex;
		}
	}

	startingIndex = 62;
	holdIndex = 62;
	for (int i = 28; i < 56; i++) {
		C0D0[i] = key[startingIndex];
		startingIndex -= 8;
		if (startingIndex == -4) {
			startingIndex = 27;
		}
		else if (startingIndex < 0) {
			holdIndex--;
			startingIndex = holdIndex;
		}
	}
}

void LeftShiftBits(int* C0D0) {
	int temp = C0D0[0];
	for (int i = 1; i < 27; i++) {
		C0D0[i - 1] = C0D0[i];
	}
	C0D0[27] = temp;
	temp = C0D0[28];
	for (int i = 29; i < 55; i++) {
		C0D0[i - 1] = C0D0[i];
	}
	C0D0[55] = temp;
}

void PC2(int* C0D0, int* PC2Array) {
	for (int i = 0; i < 48; i++) {
		PC2Array[i] = C0D0[PC2Table[i]];
	}
}

void ExpandR(int* R0, int* ER0) {
	for (int i = 0; i < 48; i++) {
		ER0[i] = R0[ERTable[i]];
	}
}

void XORKey(int* ER0, int* key, int* results) {
	for (int i = 0; i < 48; i++) {
		if (ER0[i] != key[i])
			results[i] = 1;
	}
}

void SBoxes(int* XOR, int* results) {
	int first, last;
	int tot = 0;
	int middle = 0;
	std::string pass = "";
	for (int i = 0; i < 48; i += 6) {
		int first = XOR[i];
		int last = XOR[i + 5];
		if (first == 1) tot += 2;
		if (last == 1) tot += 1;
		if (XOR[i + 1] == 1) middle += 8;
		if (XOR[i + 2] == 1) middle += 4;
		if (XOR[i + 3] == 1) middle += 2;
		if (XOR[i + 4] == 1) middle += 1;
		pass += SBox[middle + (16 * tot)];
		first = 0;
		last = 0;
		middle = 0;
		tot = 0;
	}
	for (int i = 0; i < 32; i++) results[i] = pass[i] - 48;
}

void Permutation(int* SBoxResults, int* PBResults) {
	for (int i = 0; i < 32; i++) {
		PBResults[i] = SBoxResults[PB[i]];
	}
}

void LXORR(int* L0, int* afterPermutation, int* R1) {
	for (int i = 0; i < 32; i++) {
		if (afterPermutation[i] != L0[i]) R1[i] = 1;
	}
}

void IIP(int* L2R2, int* final) {
	for (int i = 0; i < 64; i++) {
		final[i] = L2R2[IIPTable[i]];
	}
}

std::string DESEncrypt(std::string Plaintext, int* key) {
	int binary[64];
	HextoBinary(Plaintext, binary);
	int L0[32];
	int R0[32];
	IP(binary, L0, R0);
	std::cout << "\nL0 as a result of Initial Permutation: ";
	BinarytoHexPrint(L0, 32);
	std::cout << "\nR0 As a result of Initial Permutation: ";
	BinarytoHexPrint(R0, 32);
	int ER0[48];
	ExpandR(R0, ER0);
	std::cout << "\nR0 Expanded: ";
	BinarytoHexPrint(ER0, 48);

	int K1[48];
	int K2[48];

	int XOR[48] = { 0 };
	XORKey(ER0, key, XOR);
	std::cout << "\nResult of Expanded R0 XOR with the round key: ";
	BinarytoHexPrint(XOR, 48);

	int results[32];
	SBoxes(XOR, results);
	std::cout << "\nResult of applying S-Box: ";
	BinarytoHexPrint(results, 32);

	int PBResults[32];
	Permutation(results, PBResults);
	std::cout << "\nResult of Permutation: ";
	BinarytoHexPrint(PBResults, 32);

	int R1[32] = { 0 };
	LXORR(L0, PBResults, R1);
	std::cout << "\nResults of L(i-1) XOR R(i): ";
	BinarytoHexPrint(R1, 32);
	int L2R2[64];
	for (int i = 0; i < 32; i++) {
		L2R2[i] = R0[i];
	}
	for (int i = 0; i < 32; i++) {
		L2R2[i + 32] = R1[i];
	}
	int final[64];
	IIP(L2R2, final);
	std::cout << "\n\nResulting Ciphertext: ";

	BinarytoHexPrint(final, 64);
	std::cout << "\n\n";
	return (BinarytoHex(final));

}

std::string DESDecrypt(std::string Ciphertext, int* key) {
	int binary[64];
	HextoBinary(Ciphertext, binary);
	int L0[32];
	int R0[32];
	IP(binary, R0, L0);
	std::cout << "\nL(i) as a result of Initial Permutation: ";
	BinarytoHexPrint(L0, 32);
	std::cout << "\nR(i) As a result of Initial Permutation: ";
	BinarytoHexPrint(R0, 32);
	int ER0[48];
	ExpandR(R0, ER0);
	std::cout << "\nR(i) Expanded: ";
	BinarytoHexPrint(ER0, 48);

	int K1[48];
	int K2[48];

	int XOR[48] = { 0 };
	XORKey(ER0, key, XOR);
	std::cout << "\nResult of Expanded R(i) XOR with the round key: ";
	BinarytoHexPrint(XOR, 48);

	int results[32];
	SBoxes(XOR, results);
	std::cout << "\nResult of applying S-Box: ";
	BinarytoHexPrint(results, 32);

	int PBResults[32];
	Permutation(results, PBResults);
	std::cout << "\nResult of Permutation: ";
	BinarytoHexPrint(PBResults, 32);

	int R1[32] = { 0 };
	LXORR(L0, PBResults, R1);
	std::cout << "\nResults of L(i-1) XOR R(i): ";
	BinarytoHexPrint(R1, 32);
	int L2R2[64];
	for (int i = 0; i < 32; i++) {
		L2R2[i] = R1[i];
	}
	for (int i = 0; i < 32; i++) {
		L2R2[i + 32] = R0[i];
	}
	int final[64];
	IIP(L2R2, final);
	std::cout << "\n\nResulting Plaintext: ";

	BinarytoHexPrint(final, 64);
	std::cout << "\n\n";
	return (BinarytoHex(final));

}

void DESBruteForce(std::string Ciphertext, std::string plaintext) {
	int decimal = 0;
	int key[64];
	int K1[56];
	int K2[56];
	std::string foundPlaintext1 = "";
	std::string foundPlaintext2 = "";
	DecimaltoBinary(decimal, key);
	std::string keyIn = BinarytoHex(key);
	GenerateKeys(keyIn, K1, K2);

	while (1) {
		foundPlaintext1 = DESDecrypt(Ciphertext, K2);
		foundPlaintext2 = DESDecrypt(foundPlaintext1, K1);
		if (foundPlaintext2 == plaintext) break;
		decimal += 1;
		DecimaltoBinary(decimal, key);
		keyIn = BinarytoHex(key);
		GenerateKeys(keyIn, K1, K2);
	}
	std::cout << "\n\nPlaintext was found to be: ";
	std::cout << foundPlaintext2;
	std::cout << "\nKey was found to be: ";
	BinarytoHexPrint(key, 64);
}



