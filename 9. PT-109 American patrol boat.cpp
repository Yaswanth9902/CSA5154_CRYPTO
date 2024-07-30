#include <stdio.h>
#include <string.h>

int main() {
    char key[25] = "PLAYFIR";
    char matrix[5][5];
    char ciphertext[100], plaintext[100];
    int i, j, a_row, a_col, b_row, b_col;
    int len, k = 0;

    int used[26] = {0};
    int index = 0;

    for (i = 0; key[i] != '\0'; i++) {
        if (key[i] == 'J') key[i] = 'I'; 
        key[i] = tolower(key[i]);
        if (!used[key[i] - 'a']) {
            matrix[index / 5][index % 5] = key[i];
            used[key[i] - 'a'] = 1;
            index++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i + 'a' == 'j') continue;
        if (!used[i]) {
            matrix[index / 5][index % 5] = i + 'a';
            index++;
        }
    }

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';

    len = strlen(ciphertext);
    for (i = 0; i < len; i += 2) {
        char a = ciphertext[i], b = ciphertext[i + 1];

        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (matrix[j][k] == a) {
                    a_row = j;
                    a_col = k;
                }
                if (matrix[j][k] == b) {
                    b_row = j;
                    b_col = k;
                }
            }
        }
        if (a_row == b_row) {
            plaintext[i] = matrix[a_row][(a_col - 1 + 5) % 5];
            plaintext[i + 1] = matrix[b_row][(b_col - 1 + 5) % 5];
        } else if (a_col == b_col) {
            plaintext[i] = matrix[(a_row - 1 + 5) % 5][a_col];
            plaintext[i + 1] = matrix[(b_row - 1 + 5) % 5][b_col];
        } else {
            plaintext[i] = matrix[a_row][b_col];
            plaintext[i + 1] = matrix[b_row][a_col];
        }
    }
    plaintext[len] = '\0';

    printf("Plaintext: %s\n", plaintext);

    return 0;
}
