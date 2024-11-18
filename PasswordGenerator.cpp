// PasswordGenerator.cpp

#include "PasswordGenerator.h"

#include <iostream>

#include <cstdlib>

#include <ctime>

#include <fstream>



std::string generatePassword(int length, bool useUppercase, bool useLowercase, bool useDigits, bool useSpecialChars) {

    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";

    std::string digits = "0123456789";

    std::string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";



    std::string characterPool;



    if (useUppercase) {

        characterPool += uppercase;

    }

    if (useLowercase) {

        characterPool += lowercase;

    }

    if (useDigits) {

        characterPool += digits;

    }

    if (useSpecialChars) {

        characterPool += specialChars;

    }



    if (characterPool.empty()) {

        std::cerr << "Error: At least one character type must be selected." << std::endl;

        return "";

    }



    std::string password;

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation



    for (int i = 0; i < length; ++i) {

        int index = rand() % characterPool.size();

        password += characterPool[index];

    }



    return password;

}



std::string passwordStrength(const std::string& password) {

    int length = password.length();

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;



    for (char c : password) {

        if (isupper(c)) hasUpper = true;

        else if (islower(c)) hasLower = true;

        else if (isdigit(c)) hasDigit = true;

        else hasSpecial = true;

    }



    int strength = hasUpper + hasLower + hasDigit + hasSpecial;



    if (length >= 12 && strength == 4) return "Very Strong";

    if (length >= 8 && strength >= 3) return "Strong";

    if (length >= 6 && strength >= 2) return "Moderate";

    return "Weak";

}



void savePasswordsToFile(const std::vector<std::string>& passwords) {

    std::ofstream outFile("generated_passwords.txt");

    if (outFile.is_open()) {

        for (const auto& password : passwords) {

            outFile << password << std::endl;

        }

        outFile.close();

        std::cout << "Passwords saved to generated_passwords.txt" << std::endl;

    } else {

        std::cerr << "Error: Unable to open file for writing." << std::endl;

    }

}



