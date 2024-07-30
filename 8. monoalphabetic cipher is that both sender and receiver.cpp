#include <stdio.h>
#include <string.h>

int main() {
    char keyword[26], plaintext[100], ciphertext[100];
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char cipher[26];
    int used[26] = {0}, i, j, k = 0;

    printf("Enter the keyword: ");
    scanf("%s", keyword);

    for (i = 0; i < strlen(keyword); i++) {
        keyword[i] = tolower(keyword[i]);
        if (!used[keyword[i] - 'a']) {
            cipher[k++] = keyword[i];
            used[keyword[i] - 'a'] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[alphabet[i] - 'a']) {
            cipher[k++] = alphabet[i];
        }
    }

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            j = plaintext[i] - 'a';
            ciphertext[i] = cipher[j];
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            j = plaintext[i] - 'A';
            ciphertext[i] = cipher[j] - 32;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
