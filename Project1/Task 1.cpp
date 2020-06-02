#include <iostream>
#include <string>

using namespace std;

string cleanText(string text) {
	string cleanedText;

	// For plaintext, remove numbers, spaces, and make lowercase
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i])) {
			cleanedText.push_back(text[i]);
		}
	}

	for (int i = 0; i < cleanedText.length(); i++) {
		cleanedText[i] = tolower(cleanedText[i]);
	}
	
	return cleanedText;
}

string cleanRepeatedKey(string cleanedText, string key) {
	string alphaKey = cleanText(key);
	string repeatedKey;

	// Generate Key for enciphering the input
	for (int i = 0, j = 0; i < cleanedText.length(); i++, j++) {
		if (j == alphaKey.length()) j = 0;

		repeatedKey.push_back(alphaKey[j]);
	}

	return repeatedKey;
}

string vigenereEncrypt(string plainText, string key) {
	string cleanedPlainText = cleanText(plainText);
	string repeatedKey = cleanRepeatedKey(cleanedPlainText, key);
	string encryptedText = cleanedPlainText;

	cout << "Plain Text: " << cleanedPlainText << endl << endl;

	cout << "Encryption Key: " << repeatedKey << endl << endl;

	// Encrypt input string with repeated key
	for (int i = 0; i < cleanedPlainText.length(); i++) {
		encryptedText[i] = (((cleanedPlainText[i] - 'a') + (repeatedKey[i] - 'a')) % 26) + 'a';
		encryptedText[i] = toupper(encryptedText[i]);
	}

	cout << "Encrypted Text: " << encryptedText << endl << endl;

	return encryptedText;
}

string vigenereDecrypt(string ciphertext, string key) {
	string cleanedCiphertext = cleanText(ciphertext);
	string repeatedKey = cleanRepeatedKey(ciphertext, key);
	string decryptedText = cleanText(ciphertext);

	cout << "Deryption Key: " << repeatedKey << endl << endl;

	// Decrypt ciphertext with repeated key
	for (int i = 0; i < cleanedCiphertext.length(); i++) {
		decryptedText[i] = (((cleanedCiphertext[i] - 'a') - (repeatedKey[i] - 'a') + 26) % 26) + 'a';
	}

	cout << "Decrypted Text: " << decryptedText << endl << endl;
	
	return decryptedText;
}

int main() {
	string plainText;
	string key;
	string vigenereCiphertext;

	cout << "Please enter the text to be encoded with the Vigenere Cipher: ";
	getline(cin, plainText);

	if (plainText.length() < 1) {
		cout << endl << endl << "Text must be atleast 1 character: ";
		getline(cin, plainText);
	}

	cout << endl << "Please enter the key to encrypt the text with: ";
	getline(cin, key);

	if (key.length() < 1) {
		cout << endl << "Key must be atleast one character: ";
		getline(cin, key);
	}

	cout << endl << endl;

	vigenereCiphertext = vigenereEncrypt(plainText, key);

	vigenereDecrypt(vigenereCiphertext, key);

	system("pause");

	return 0;
}