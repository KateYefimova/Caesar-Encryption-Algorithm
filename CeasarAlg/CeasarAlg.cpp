#include <windows.h>
#include <iostream>
using namespace std;


int main()
{
	HINSTANCE handle = LoadLibrary(TEXT("lib.dll"));
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
	char rawText[] = "Roses are red, violets are blue";
	int key = 1;
	char* encryptedText = encrypt_ptr(rawText, key);
	cout << "Encrypted Text: " << encryptedText << endl;

	// Decrypt the encrypted text
	char* decryptedText = decrypt_ptr(encryptedText, key);
	cout << "Decrypted Text: " << decryptedText << endl;

	// Deallocate memory
	delete[] encryptedText;
	delete[] decryptedText;
	FreeLibrary(handle);
	return 0;
}

