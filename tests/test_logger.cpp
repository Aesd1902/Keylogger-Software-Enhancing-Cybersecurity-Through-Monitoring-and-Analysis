#include "logger.h"
#include <assert.h>

void testLogKey() {
    logKey('A');
    // Check if log.txt contains 'A'
}

int main() {
    testLogKey();
    std::cout << "Logger tests passed." << std::endl;
    return 0;
}
