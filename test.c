#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerableFunction(char *userInput) {
    char buffer[8];  // Small buffer for demonstration
    strcpy(buffer, userInput);  // Potential buffer overflow
    printf("User Input: %s\n", buffer);
}

void secureFunction(char *userInput) {
    char buffer[8];
    strncpy(buffer, userInput, sizeof(buffer) - 1);  // Safer usage
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
    printf("Secure Input: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an input.\n");
        return 1;
    }

    printf("Running vulnerable function...\n");
    vulnerableFunction(argv[1]);  // Running vulnerable function

    printf("\nRunning secure function...\n");
    secureFunction(argv[1]);  // Running secure function
    return 0;
}
