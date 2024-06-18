#pragma once
extern "C" {
    char* encrypt(char* rawText, int key);
    char* decrypt(char* encryptedText, int key);
}