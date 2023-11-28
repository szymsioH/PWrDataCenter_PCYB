#include <iostream>
#include <windows.h>

using namespace std;

bool isPasswordCorrect(const string& generatedPassword, const string& clientPassword);

int main() {
    HANDLE pipeHandle;
    pipeHandle = CreateNamedPipe("\\\\.\\pipe\\MyPipe", PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, 1, 0, 0, 0, nullptr);

    if (pipeHandle == INVALID_HANDLE_VALUE) {
        cerr << "Error creating named pipe." << endl;
        return 1;
    }
    if (ConnectNamedPipe(pipeHandle, nullptr)) {
        string generatedPassword = "Sans";
        cout << "Waiting for client to Login" << endl;
        char buffer[256];
        DWORD bytesRead;
        ReadFile(pipeHandle, buffer, sizeof(buffer), &bytesRead, nullptr);
        string clientPassword(buffer);
        bool isCorrect = isPasswordCorrect(generatedPassword, clientPassword);
        do{
            char responseBuffer[1] = { (isCorrect) ? '1' : '0'};
            WriteFile(pipeHandle, responseBuffer, sizeof(responseBuffer), nullptr, nullptr);}while((isPasswordCorrect(generatedPassword, clientPassword)));
        cout << "Login succesful" << endl;
        DisconnectNamedPipe(pipeHandle);
    }
    CloseHandle(pipeHandle);
    return 0;
}
bool isPasswordCorrect(const string& generatedPassword, const string& clientPassword) {
    return (generatedPassword == clientPassword);
}
