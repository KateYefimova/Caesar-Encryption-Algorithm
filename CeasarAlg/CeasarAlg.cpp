#include <windows.h>
#include <iostream>
#include "Header1.h"
using namespace std;


int main()
{
	/*HINSTANCE handle = LoadLibrary(TEXT("lib.dll"));
	if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		cout << "Lib not found" << endl;
		return 1;
	}
	typedef char*(*encrypt_ptr_t)(char*, int);
	typedef char*(*decrypt_ptr_t)(char*, int);
	encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, TEXT("encrypt"));
	if (encrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}
	decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, TEXT("decrypt"));
	if (decrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}
	int key;
	cout << "Enter the encryption/decryption key (integer): ";
	cin >> key;
	cin.ignore(); 

	cout << "Enter the text to encrypt/decrypt (max 1000 characters): ";
	char rawText[1001];
	cin.getline(rawText, 1001);
	char* encryptedText = encrypt_ptr(rawText, key);
	cout << "Encrypted Text: " << encryptedText << endl;

	// Decrypt the encrypted text
	char* decryptedText = decrypt_ptr(encryptedText, key);
	cout << "Decrypted Text: " << decryptedText << endl;

	// Deallocate memory
	delete[] encryptedText;
	delete[] decryptedText;
	FreeLibrary(handle);*/
	char text[] = "Hello, World!";
	int key = 3;

	char* encryptedText = encrypt(text, key);
	cout << "Encrypted: " << encryptedText << endl;

	char* decryptedText = decrypt(encryptedText, key);
	cout << "Decrypted: " << decryptedText << endl;

	delete[] encryptedText;
	delete[] decryptedText;


	return 0;
}

