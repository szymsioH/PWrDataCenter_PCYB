#include <iostream>
#include <ctime>

using namespace std;
string crackPassword(const string& pass);
long long int attempt;
clock_t start_t;
clock_t end_t;

int main() {
    string password;

    cout << "Enter the password to crack : ";
    cin >> password;
    cout <<  crackPassword(password) << "\n\n>\n>> CRACKED THE PASSWORD! >>\n>\n The password : " << password << "\n";
    cout << "The number of attempts : " << attempt << "\n";
    cout << "The time duration  passed : " << (double)(end_t - start_t)/1000 << " seconds\n\n";
    return 0;
}

string crackPassword(const string& pass) {

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

    int digit[8];
    int alphabetSet = 1;
    int passwordLength = 1;
    start_t = clock();

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
                            if(pass == test) {
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
                                if (pass == test) {
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
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                    if (pass == test) {
                                        end_t = clock();
                                        return test;
                                    }
                                }
                        alphabetSet++;
                    }
                    break;
                case 4:
                    alphabetSet = 1;
                    while (alphabetSet < 8){
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
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                        if (pass == test) {
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
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                            if (pass == test) {
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
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                                    if (pass == test) {
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
                                     cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                                    if (pass == test) {
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
                                cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                                        if (pass == test) {
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
                                cout << "\n\n Couldn't find the password. \n\n Testing DIGITS, LOWERCASE, UPPERCASE, please wait";  break;
                        }
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
                                                            if (pass == test) {
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