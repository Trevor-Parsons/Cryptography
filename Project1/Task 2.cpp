#include <iostream>
#include <string>

using namespace std;

string cleanText(string text) {
	string cleanedText;

	// Remove numbers, spaces, and make lowercase
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

string cleanRepeatedKey(string cleanedPlainText, string key) {
	string alphaKey = cleanText(key);
	string repeatedKey;

	// Generate Key for enciphering the input
	for (int i = 0, j = 0; i < cleanedPlainText.length(); i++, j++) {
		if (j == alphaKey.length()) j = 0;

		repeatedKey.push_back(alphaKey[j]);
	}

	return repeatedKey;
}

string vigenereDecrypt(string ciphertext, string key) {
	string repeatedKey = cleanRepeatedKey(ciphertext, key);
	string decryptedText = ciphertext;

	for (int i = 0; i < ciphertext.length(); i++) {
		decryptedText[i] = (((ciphertext[i] - 'a') - (repeatedKey[i] - 'a') + 26) % 26) + 'a';
		toupper(decryptedText[i]);
	}

	return decryptedText;
}

string bruteForceVignere(string ciphertext, string substring, int maxKeySize) {
	char choice;
	string possiblePlainText;
	string possibleKey;
	string cleanedCipertext = cleanText(ciphertext);
	string cleanedRepeatedKey;
	string cleanedSubstring = cleanText(substring);

	for (int keyLength = 1; keyLength <= maxKeySize; keyLength++) {
		switch (keyLength) {
			case 1: {
				string possibleKey = "a";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
					possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

					if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
						cout << "Possible Key found: " << possibleKey << endl;
						cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
						cout << "Would you like to stop the program? y/n: ";
						cin >> choice;

						cout << endl << endl;

						if (choice == 'y') {
							return possibleKey;
						}
					}

					possibleKey[0]++;
				}

				break;
			}

			case 2: {
				possibleKey = "aa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
						possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

						if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
							cout << "Possible Key found: " << possibleKey << endl;
							cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
							cout << "Would you like to stop the program? y/n: ";
							cin >> choice;

							cout << endl << endl;

							if (choice == 'y') {
								return possibleKey;
							}
						}
						possibleKey[1]++;
					}
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 3: {
				possibleKey =  "aaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
							possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

							if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
								cout << "Possible Key found: " << possibleKey << endl;
								cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
								cout << "Would you like to stop the program? y/n: ";
								cin >> choice;

								cout << endl << endl;

								if (choice == 'y') {
									return possibleKey;
								}
							}
							possibleKey[2]++;
						}
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 4: {
				possibleKey = "aaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
								possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

								if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
									cout << "Possible Key found: " << possibleKey << endl;
									cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
									cout << "Would you like to stop the program? y/n: ";
									cin >> choice;

									cout << endl << endl;

									if (choice == 'y') {
										return possibleKey;
									}
								}
								possibleKey[3]++;
							}
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 5: {
				possibleKey = "aaaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								for (int m = 0; m < 26; m++) {
									cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
									possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

									if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
										cout << "Possible Key found: " << possibleKey << endl;
										cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
										cout << "Would you like to stop the program? y/n: ";
										cin >> choice;

										cout << endl << endl;

										if (choice == 'y') {
											return possibleKey;
										}
									}
									possibleKey[4]++;
								}
								possibleKey[4] = 'a';
								possibleKey[3]++;
							}
							possibleKey[4] = 'a';
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[4] = 'a';
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[4] = 'a';
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 6: {
				possibleKey = "aaaaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								for (int m = 0; m < 26; m++) {
									for (int n = 0; n < 26; n++) {
										cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
										possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

										if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
											cout << "Possible Key found: " << possibleKey << endl;
											cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
											cout << "Would you like to stop the program? y/n: ";
											cin >> choice;

											cout << endl << endl;

											if (choice == 'y') {
												return possibleKey;
											}
										}
										possibleKey[5]++;
									}
									possibleKey[5] = 'a';
									possibleKey[4]++;
								}
								possibleKey[5] = 'a';
								possibleKey[4] = 'a';
								possibleKey[3]++;
							}
							possibleKey[5] = 'a';
							possibleKey[4] = 'a';
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[5] = 'a';
						possibleKey[4] = 'a';
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[5] = 'a';
					possibleKey[4] = 'a';
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 7: {
				possibleKey = "aaaaaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								for (int m = 0; m < 26; m++) {
									for (int n = 0; n < 26; n++) {
										for (int o = 0; o < 26; o++) {
											cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
											possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

											if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
												cout << "Possible Key found: " << possibleKey << endl;
												cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
												cout << "Would you like to stop the program? y/n: ";
												cin >> choice;

												cout << endl << endl;

												if (choice == 'y') {
													return possibleKey;
												}
											}
											possibleKey[6]++;
										}
										possibleKey[6] = 'a';
										possibleKey[5]++;
									}
									possibleKey[6] = 'a';
									possibleKey[5] = 'a';
									possibleKey[4]++;
								}
								possibleKey[6] = 'a';
								possibleKey[5] = 'a';
								possibleKey[4] = 'a';
								possibleKey[3]++;
							}
							possibleKey[6] = 'a';
							possibleKey[5] = 'a';
							possibleKey[4] = 'a';
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[6] = 'a';
						possibleKey[5] = 'a';
						possibleKey[4] = 'a';
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[6] = 'a';
					possibleKey[5] = 'a';
					possibleKey[4] = 'a';
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 8: {
				possibleKey = "aaaaaaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								for (int m = 0; m < 26; m++) {
									for (int n = 0; n < 26; n++) {
										for (int o = 0; o < 26; o++) {
											for (int p = 0; p < 26; p++) {
												cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
												possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

												if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
													cout << "Possible Key found: " << possibleKey << endl;
													cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
													cout << "Would you like to stop the program? y/n: ";
													cin >> choice;

													cout << endl << endl;

													if (choice == 'y') {
														return possibleKey;
													}
												}
												possibleKey[7]++;
											}
											possibleKey[7] = 'a';
											possibleKey[6]++;
										}
										possibleKey[7] = 'a';
										possibleKey[6] = 'a';
										possibleKey[5]++;
									}
									possibleKey[7] = 'a';
									possibleKey[6] = 'a';
									possibleKey[5] = 'a';
									possibleKey[4]++;
								}
								possibleKey[7] = 'a';
								possibleKey[6] = 'a';
								possibleKey[5] = 'a';
								possibleKey[4] = 'a';
								possibleKey[3]++;
							}
							possibleKey[7] = 'a';
							possibleKey[6] = 'a';
							possibleKey[5] = 'a';
							possibleKey[4] = 'a';
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[7] = 'a';
						possibleKey[6] = 'a';
						possibleKey[5] = 'a';
						possibleKey[4] = 'a';
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[7] = 'a';
					possibleKey[6] = 'a';
					possibleKey[5] = 'a';
					possibleKey[4] = 'a';
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 9: {
				possibleKey = "aaaaaaaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								for (int m = 0; m < 26; m++) {
									for (int n = 0; n < 26; n++) {
										for (int o = 0; o < 26; o++) {
											for (int p = 0; p < 26; p++) {
												for (int q = 0; q < 26; q++) {
													cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
													possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

													if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
														cout << "Possible Key found: " << possibleKey << endl;
														cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
														cout << "Would you like to stop the program? y/n: ";
														cin >> choice;

														cout << endl << endl;

														if (choice == 'y') {
															return possibleKey;
														}
													}
													possibleKey[8]++;
												}
												possibleKey[8] = 'a';
												possibleKey[7]++;
											}
											possibleKey[8] = 'a';
											possibleKey[7] = 'a';
											possibleKey[6]++;
										}
										possibleKey[8] = 'a';
										possibleKey[7] = 'a';
										possibleKey[6] = 'a';
										possibleKey[5]++;
									}
									possibleKey[8] = 'a';
									possibleKey[7] = 'a';
									possibleKey[6] = 'a';
									possibleKey[5] = 'a';
									possibleKey[4]++;
								}
								possibleKey[8] = 'a';
								possibleKey[7] = 'a';
								possibleKey[6] = 'a';
								possibleKey[5] = 'a';
								possibleKey[4] = 'a';
								possibleKey[3]++;
							}
							possibleKey[8] = 'a';
							possibleKey[7] = 'a';
							possibleKey[6] = 'a';
							possibleKey[5] = 'a';
							possibleKey[4] = 'a';
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[8] = 'a';
						possibleKey[7] = 'a';
						possibleKey[6] = 'a';
						possibleKey[5] = 'a';
						possibleKey[4] = 'a';
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[8] = 'a';
					possibleKey[7] = 'a';
					possibleKey[6] = 'a';
					possibleKey[5] = 'a';
					possibleKey[4] = 'a';
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}

			case 10: {
				possibleKey = "aaaaaaaaaa";

				cout << "Searching keys of length " << keyLength << "..." << endl << endl;

				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < 26; j++) {
						for (int k = 0; k < 26; k++) {
							for (int l = 0; l < 26; l++) {
								for (int m = 0; m < 26; m++) {
									for (int n = 0; n < 26; n++) {
										for (int o = 0; o < 26; o++) {
											for (int p = 0; p < 26; p++) {
												for (int q = 0; q < 26; q++) {
													for (int r = 0; r < 26; r++) {
														cleanedRepeatedKey = cleanRepeatedKey(cleanedCipertext, possibleKey);
														possiblePlainText = vigenereDecrypt(cleanedCipertext, cleanedRepeatedKey);

														if (possiblePlainText.find(cleanedSubstring) != std::string::npos) {
															cout << "Possible Key found: " << possibleKey << endl;
															cout << "Using possible key, decoded plaintext: " << possiblePlainText << endl << endl;
															cout << "Would you like to stop the program? y/n: ";
															cin >> choice;

															cout << endl << endl;

															if (choice == 'y') {
																return possibleKey;
															}
														}
														possibleKey[9]++;
													}
													possibleKey[9] = 'a';
													possibleKey[8]++;
												}
												possibleKey[9] = 'a';
												possibleKey[8] = 'a';
												possibleKey[7]++;
											}
											possibleKey[9] = 'a';
											possibleKey[8] = 'a';
											possibleKey[7] = 'a';
											possibleKey[6]++;
										}
										possibleKey[9] = 'a';
										possibleKey[8] = 'a';
										possibleKey[7] = 'a';
										possibleKey[6] = 'a';
										possibleKey[5]++;
									}
									possibleKey[9] = 'a';
									possibleKey[8] = 'a';
									possibleKey[7] = 'a';
									possibleKey[6] = 'a';
									possibleKey[5] = 'a';
									possibleKey[4]++;
								}
								possibleKey[9] = 'a';
								possibleKey[8] = 'a';
								possibleKey[7] = 'a';
								possibleKey[6] = 'a';
								possibleKey[5] = 'a';
								possibleKey[4] = 'a';
								possibleKey[3]++;
							}
							possibleKey[9] = 'a';
							possibleKey[8] = 'a';
							possibleKey[7] = 'a';
							possibleKey[6] = 'a';
							possibleKey[5] = 'a';
							possibleKey[4] = 'a';
							possibleKey[3] = 'a';
							possibleKey[2]++;
						}
						possibleKey[9] = 'a';
						possibleKey[8] = 'a';
						possibleKey[7] = 'a';
						possibleKey[6] = 'a';
						possibleKey[5] = 'a';
						possibleKey[4] = 'a';
						possibleKey[3] = 'a';
						possibleKey[2] = 'a';
						possibleKey[1]++;
					}
					possibleKey[9] = 'a';
					possibleKey[8] = 'a';
					possibleKey[7] = 'a';
					possibleKey[6] = 'a';
					possibleKey[5] = 'a';
					possibleKey[4] = 'a';
					possibleKey[3] = 'a';
					possibleKey[2] = 'a';
					possibleKey[1] = 'a';
					possibleKey[0]++;
				}

				break;
			}
		}

		cout << "Tried all keys of length " << keyLength
			<< ", would you like to try keys of length " << keyLength + 1 << "? y/n: ";
		cin >> choice; 

		cout << endl << endl;

		if (choice == 'n') {
			return "Key not found.";
		}
	}
}

int main() {
	string ciphertext;
	string substring;
	string foundKey;
	int maxKeySize;

	cout << "Please enter the ciphertext: ";
	getline(cin, ciphertext);

	if (ciphertext.length() < 1) {
		cout << endl << endl << "Text must be atleast 1 character: ";
		getline(cin, ciphertext);
	}

	cout << endl << "Please enter the known substring: ";
	getline(cin, substring);

	if (substring.length() < 1) {
		cout << endl << endl << "Substring must be atleast one character: ";
		getline(cin, substring);
	}

	cout << endl << "Please enter the max key length: ";
	cin >> maxKeySize;
	cout << endl << endl;

	foundKey = bruteForceVignere(ciphertext, substring, maxKeySize);

	cout << endl << endl << "Final key: " << foundKey << endl << endl;


	system("pause");
	return 0;
}