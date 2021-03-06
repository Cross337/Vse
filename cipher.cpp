#include "pch.h"
#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

const char alphabet[] = "АБВГДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
const int alphabetSize = strlen(alphabet);

short getCode(char givenChar) {
	for (int currentIdx = 0; currentIdx < alphabetSize; currentIdx++) {
		if (alphabet[currentIdx] == givenChar) {
			return currentIdx;
		}
	}
	return -1;
}

char getChar(short givenCode) {
	if ((givenCode % alphabetSize != 0) && (givenCode < 0)) {
		return alphabet[alphabetSize - (abs(givenCode) % alphabetSize)];
	}
	return alphabet[givenCode % alphabetSize];
}

string encrypt(string givenString, long long int givenKey) {
	string encryptedString;
	short receivedCode;
	for (int currentIdx = 0; currentIdx < givenString.size(); currentIdx++) {
		receivedCode = getCode(givenString[currentIdx]);
		if (receivedCode != -1) {
			encryptedString += getChar(getCode(tolower(givenString[currentIdx])) + givenKey);
		}
		else {
			encryptedString += tolower(givenString[currentIdx]);
		}
	}
	return encryptedString;
}

string decrypt(string givenString, long long int givenKey) {
	string decryptedString;
	short receivedCode;
	for (int currentIdx = 0; currentIdx < givenString.size(); currentIdx++) {
		receivedCode = getCode(givenString[currentIdx]);
		if (receivedCode != -1) {
			decryptedString += getChar(getCode(givenString[currentIdx]) - givenKey);
		}
		else {
			decryptedString += tolower(givenString[currentIdx]);
		}
	}
	return decryptedString;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введіть 1 для шифрування, 2 для дешифрування: ";
	char userChoice = getchar();
	
	cout << "Введіть рядок, який будемо використовувати: ";
	string userString;
	getline(cin.ignore(), userString);

	cout << "Введіть ключ: ";
	long long int userKey;
	cin >> userKey;

	if (userChoice == '1') {
		cout << "Зашифроване повідомлення:\n" << encrypt(userString, userKey) << endl;
	}
	else if (userChoice == '2') {
		cout << "Дешифроване повідомлення:\n" << decrypt(userString, userKey) << endl;
	}

	system("pause");
	return 0;
}
