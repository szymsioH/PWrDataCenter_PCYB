#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include "elzip.hpp"

#define OVERTIME 120

using namespace std;
string crackPassword(const string& zipPath, const string& extractPath);
string dictionaryAttack(const string& zipPath, const string& extractPath);
long long int attempt;
clock_t start_t = clock();
clock_t end_t;

//DICTIONARIES:
const string dictDigits = "-0123456789";
const string dictSmallCase = "-abcdefghijklmnopqrstuvwxyz";
const string dictUppCase = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string dictDigNSmall = "-0123456789abcdefghijklmnopqrstuvwxyz";
const string dictDigNUpp = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string dictSmallNUpp = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string dictFull = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string test;
string alphabet;
string zipPath = "D:/UwU/stud/PCYB/repo/secret.zip";
string extractPath = "D:/UwU/stud/PCYB/repo/";
int digit[8];
int alphabetSet = 1;
int passwordLength = 1;

int main() {


    string dictionaryResult = dictionaryAttack(zipPath,extractPath);

    if (dictionaryResult != "Dictionary attack failed\n") {
        cout << "\n\n>\n>> CRACKED THE PASSWORD! >>\n>\n The password : " << dictionaryResult << "\n";
        cout << "The number of attempts : " << attempt << "\n";
        cout << "The time duration  passed : " << (double)(end_t - start_t) / 1000 << " seconds\n\n";
    } else {
        if((double)(end_t - start_t) / 1000 > OVERTIME ) {
            cout << "Dictionary attack overtime. Starting brute-force attack.\n";
        }else{
        cout << "Dictionary attack failed. Starting brute-force attack.\n";}
        string bruteForceResult = crackPassword(zipPath,extractPath);
        cout <<  "\n\n>\n>> CRACKED THE PASSWORD! >>\n>\n The password : " << bruteForceResult << "\n";
        cout << "The number of attempts : " << attempt << "\n";
        cout << "The time duration  passed : " << (double)(end_t - start_t) / 1000 << " seconds\n\n";
    }
}
bool extractZipSuccessfully(const string& zipPath, const string& extractPath, const string& password) {
    try {
        elz::extractZip(zipPath, extractPath, password);
    } catch (const elz::zip_exception& e) {
        return false;
    }
    return true;
}
void textDisplayFun(int alphabetSet) {
        switch (alphabetSet) {
            case 1 : alphabet = dictDigits;
            cout << "\n\n (Tested password length: " << passwordLength << " )Testing only DIGITS, please wait";  break;
            case 2 : alphabet = dictSmallCase;
            cout << "\n\n Couldn't find the password. \n\n Testing LOWERCASE, please wait";  break;
            case 3 : alphabet = dictUppCase;
            cout << "\n\n Couldn't find the password. \n\n Testing UPPERCASE, please wait";  break;
            case 4 : alphabet = dictDigNSmall;
            cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, please wait";  break;
            case 5 : alphabet = dictDigNUpp;
            cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, UPPERCASE, please wait";  break;
            case 6 : alphabet = dictSmallNUpp;
            cout << "\n\n Couldn't find the password. \n\n Testing LOWERCASE, UPPERCASE, please wait";  break;
            case 7 : alphabet = dictFull;
            cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";
            break;
        }
}
string dictionaryAttack(const string& zipPath, const string& extractPath) {
    cout << "Starting Dictionary Attack" << endl;
    string line;
    vector<string> dictionary;

    ifstream dictionaryFile("dictionary.txt");
    if (dictionaryFile.is_open()) {
        while (getline(dictionaryFile, line)) {
            dictionary.push_back(line);
        }
        dictionaryFile.close();
    } else {
        cout << "Unable to open dictionary file." << endl;
        return "Dictionary attack failed\n";
    }

    for (const string& dictPass : dictionary) {
        attempt++;
        end_t = clock();
        if (attempt % 2500 == 0)
            cout << ".";
        if((double)(end_t - start_t) / 1000 > OVERTIME){
            return "Dictionary attack failed\n";
        }
        if (extractZipSuccessfully(zipPath, extractPath, dictPass)) {
            end_t = clock();
            return dictPass;
        }
    }

    return "Dictionary attack failed\n";
}
string crackPassword(const string& zipPath, const string& extractPath) {
    while (true) {
            switch (passwordLength) {
                case 1:
                    while (alphabetSet < 4) {
                        switch (alphabetSet) {
                            case 1 : alphabet = dictDigits;
                                     cout << "\n\n (Tested password length: " << passwordLength << " )Testing: DIGITS, please wait";  break;
                            case 2 : alphabet = dictSmallCase;
                                     cout << "\n\n Couldn't find the password. \n\n Testing LOWERCASE, please wait";  break;
                            case 3 : alphabet = dictUppCase;
                                     cout << "\n\n Couldn't find the password. \n\n Testing UPPERCASE, please wait";  break;
                            }
                        for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                            attempt++;
                            if (attempt % 2500000 == 0)
                                cout << ".";
                            test = alphabet[digit[0]];
                            for (int i=1; i < passwordLength; i++)
                                if (alphabet[digit[i]] != '-')
                                    test += alphabet[digit[i]];
                            if(extractZipSuccessfully(zipPath, extractPath, test)) {
                                end_t = clock();
                                return test;
                            }
                        }
                        alphabetSet++;
                    }
                    break;
                case 2:
                    alphabetSet = 1;
                    while (alphabetSet < 6) {
                        switch (alphabetSet) {
                            case 1 : alphabet = dictDigits;
                                     cout << "\n\n (Tested password length: " << passwordLength << " )Testing: DIGITS, please wait";  break;
                            case 2 : alphabet = dictSmallCase;
                                     cout << "\n\n Couldn't find the password. \n\n Testing LOWERCASE, please wait";  break;
                            case 3 : alphabet = dictUppCase;
                                     cout << "\n\n Couldn't find the password. \n\n Testing UPPERCASE, please wait";  break;
                            case 4 : alphabet = dictDigNSmall;
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, please wait";  break;
                            case 5 : alphabet = dictDigNUpp;
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, UPPERCASE, please wait";  break;
                        }
                        for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                            for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                attempt++;
                                if (attempt % 2500000 == 0)
                                    cout << ".";
                                    test = alphabet[digit[0]];
                                for (int i = 1; i < passwordLength; i++)
                                    if (alphabet[digit[i]] != '-')
                                        test += alphabet[digit[i]];
                                if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                    end_t = clock();
                                    return test;
                                }
                            }
                        alphabetSet++;
                    }
                    break;
                case 3:
                    alphabetSet = 1;
                    while (alphabetSet < 8) {
                        textDisplayFun(alphabetSet);
                        alphabetSet++;
                        for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                            for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                    attempt++;
                                    if (attempt % 2500000 == 0)
                                        cout << ".";
                                    test = alphabet[digit[0]];
                                    for (int i = 1; i < passwordLength; i++)
                                        if (alphabet[digit[i]] != '-')
                                            test += alphabet[digit[i]];
                                    if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                        end_t = clock();
                                        return test;
                                    }
                                }
                    }
                    break;
                case 4:
                    alphabetSet = 1;
                    while (alphabetSet < 8){
                        textDisplayFun(alphabetSet);
                        for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                            for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                    for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                        attempt++;
                                        if (attempt % 2500000 == 0) cout << ".";
                                        test = alphabet[digit[0]];
                                        for (int i = 1; i < passwordLength; i++)
                                            if (alphabet[digit[i]] != '-')
                                                test += alphabet[digit[i]];
                                        if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                            end_t = clock();
                                            return test;
                                        }
                                    }
                        alphabetSet++;
                    }
                    break;
                case 5:
                    alphabetSet = 1;
                    while (alphabetSet < 8) {
                        textDisplayFun(alphabetSet);
                        for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                            for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                    for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                        for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                            attempt++;
                                            if (attempt % 2500000 == 0)
                                                cout << ".";
                                            test = alphabet[digit[0]];
                                            for (int i = 1; i < passwordLength; i++)
                                                if(alphabet[digit[i]] != '-')
                                                    test += alphabet[digit[i]];
                                            if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                                end_t = clock();
                                                return test;
                                            }
                                        }
                        alphabetSet++;
                    }
                    break;
                case 6:
                    alphabetSet = 1;
                    while (alphabetSet < 8) {
                        textDisplayFun(alphabetSet);
                            for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                                for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                                    for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                        for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                            for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                                for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                                    attempt++;
                                                    if (attempt % 2500000 == 0)
                                                        cout << ".";
                                                    test = alphabet[digit[0]];
                                                    for (int i = 1; i < passwordLength; i++)
                                                        if (alphabet[digit[i]] != '-')
                                                            test += alphabet[digit[i]];
                                                    if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                                        end_t = clock();
                                                        return test;
                                                    }
                                                }
                        alphabetSet++;
                    }
                    break;
                case 7:
                    alphabetSet = 1;
                    while (alphabetSet < 8) {
                        textDisplayFun(alphabetSet);
                        for (digit[6] = 0; digit[6] < alphabet.length(); digit[6]++)
                            for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                                for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                                    for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                        for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                            for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                                for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                                    attempt++;
                                                    if (attempt % 2500000 == 0)
                                                        cout << ".";
                                                    test = alphabet[digit[0]];
                                                    for (int i = 1; i < passwordLength; i++)
                                                        if (alphabet[digit[i]] != '-')
                                                            test += alphabet[digit[i]];
                                                    if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                                        end_t = clock();
                                                        return test;
                                                    }
                                                }
                        alphabetSet++;
                    }
                    break;
                case 8:
                    alphabetSet = 1;
                    while (alphabetSet < 8) {
                        textDisplayFun(alphabetSet);
                        for (digit[7] = 0; digit[7] < alphabet.length(); digit[7]++)
                            for (digit[6] = 0; digit[6] < alphabet.length(); digit[6]++)
                                for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                                    for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                                        for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                            for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                                for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                                    for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                                        attempt++;
                                                        if (attempt % 2500000 == 0)
                                                            cout << ".";
                                                        test = alphabet[digit[0]];
                                                        for (int i = 1; i < passwordLength; i++)
                                                            if (alphabet[digit[i]] != '-')
                                                                test += alphabet[digit[i]];
                                                        if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                                            end_t = clock();
                                                            return test;
                                                        }
                                                    }
                        alphabetSet++;
                    }
                    break;
                case 9:
                    alphabetSet = 1;
                    while (alphabetSet < 8) {
                        textDisplayFun(alphabetSet);
                        for (digit[8] = 0; digit[8] < alphabet.length(); digit[8]++)
                            for (digit[7] = 0; digit[7] < alphabet.length(); digit[7]++)
                                for (digit[6] = 0; digit[6] < alphabet.length(); digit[6]++)
                                    for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                                        for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                                            for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                                for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                                    for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                                        for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                                            attempt++;
                                                            if (attempt % 2500000 == 0)
                                                                cout << ".";
                                                            test = alphabet[digit[0]];
                                                            for (int i = 1; i < passwordLength; i++)
                                                                if (alphabet[digit[i]] != '-')
                                                                    test += alphabet[digit[i]];
                                                            if (extractZipSuccessfully(zipPath, extractPath, test)) {
                                                                end_t = clock();
                                                                return test;
                                                            }
                                                        }
                        alphabetSet++;
                    }
                    break;
            }
        cout  << "\n\n * \n ";
        cout  << "*** Password length is not " << passwordLength <<  ". Increasing password length! ***";
        cout  << "\n * \n\n";
        passwordLength++;
    }
}