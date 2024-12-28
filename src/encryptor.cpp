#include <openssl/aes.h>
#include <fstream>
#include <cstring>

void encryptLog() {
    AES_KEY encryptKey;
    unsigned char key[16] = "mysecretpassword";
    AES_set_encrypt_key(key, 128, &encryptKey);

    std::ifstream logFile("data/raw_logs/log.txt", std::ios::binary);
    std::ofstream encFile("data/encrypted_logs/log.enc", std::ios::binary);

    unsigned char buffer[16];
    while (logFile.read((char *)buffer, sizeof(buffer))) {
        unsigned char encrypted[16];
        AES_encrypt(buffer, encrypted, &encryptKey);
        encFile.write((char *)encrypted, sizeof(encrypted));
    }

    logFile.close();
    encFile.close();
}
