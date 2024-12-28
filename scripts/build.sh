#!/bin/bash
mkdir -p build
g++ src/logger.cpp src/encryptor.cpp -o build/keylogger -lcrypto -lssl
echo "Build completed!"
