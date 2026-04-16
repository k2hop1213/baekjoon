#include <stdio.h>
#include <string.h>

int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int is_acceptable(char password[]) {
    int length = strlen(password);

    // Rule 1: At least one vowel
    int has_vowel = 0;
    for (int i = 0; i < length; i++) {
        if (is_vowel(password[i])) {
            has_vowel = 1;
            break;
        }
    }

    // Rule 2: No three consecutive vowels or consonants
    for (int i = 0; i < length - 2; i++) {
        if ((is_vowel(password[i]) && is_vowel(password[i + 1]) && is_vowel(password[i + 2])) ||
            (!is_vowel(password[i]) && !is_vowel(password[i + 1]) && !is_vowel(password[i + 2]))) {
            return 0; // Not acceptable
        }
    }

    // Rule 3: No consecutive identical characters except 'ee' and 'oo'
    for (int i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1] && password[i] != 'e' && password[i] != 'o') {
            return 0; // Not acceptable
        }
    }

    return has_vowel; // If it passed all rules, check if it has at least one vowel
}

int main() {
    char password[21];

    while (1) {
        scanf("%s", password);

        if (strcmp(password, "end") == 0) {
            break;
        }

        if (is_acceptable(password)) {
            printf("<%s> is acceptable.\n", password);
        } else {
            printf("<%s> is not acceptable.\n", password);
        }
    }

    return 0;
}
