// main.cpp

#include <iostream>

#include <vector>

#include "PasswordGenerator.h"



int main() {

    int length, numPasswords;

    bool useUppercase, useLowercase, useDigits, useSpecialChars;



    std::cout << "Enter desired password length: ";

    std::cin >> length;



    // Validate length input

    while (length < 6) {

        std::cout << "Length should be at least 6. Please enter again: ";

        std::cin >> length;

    }



    std::cout << "Include uppercase letters? (1 for yes, 0 for no): ";

    std::cin >> useUppercase;



    std::cout << "Include lowercase letters? (1 for yes, 0 for no): ";

    std::cin >> useLowercase;



    std::cout << "Include digits? (1 for yes, 0 for no): ";

    std::cin >> useDigits;



        std::cout << "Include special characters? (1 for yes, 0 for no): ";

    std::cin >> useSpecialChars;



    std::cout << "How many passwords would you like to generate? ";

    std::cin >> numPasswords;
 // std::cin >> numPasswords;


    std::vector<std::string> passwords;



    for (int i = 0; i < numPasswords; ++i) {

        std::string password = generatePassword(length, useUppercase, useLowercase, useDigits, useSpecialChars);

        if (!password.empty()) {

            passwords.push_back(password);

            std::cout << "Generated Password " << (i + 1) << ": " << password 
 // 39
                      << " (Strength: " << passwordStrength(password) << ")" << std::endl;

        }

    }



    // Ask the user if they want to save the passwords to a file

    char saveToFile;

    std::cout << "Would you like to save the generated passwords to a file? (y/n): ";

    std::cin >> saveToFile;



    if (saveToFile == 'y' || saveToFile == 'Y') {

        savePasswordsToFile(passwords);

    }



    return 0;

}





