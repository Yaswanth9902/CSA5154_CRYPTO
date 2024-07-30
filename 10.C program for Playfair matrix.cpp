#include <stdio.h>
#include <string.h>

int main() {
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    
    char plaintext[100], prepared_text[100], ciphertext[100];
    int i, j, k, a_row, a_col, b_row, b_col;
    int len, pt_len = 0;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Prepare the plaintext
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] == 'J') plaintext[i] = 'I'; // Replace 'J' with 'I'
        if (plaintext[i] != ' ') {
            prepared_text[pt_len++] = toupper(plaintext[i]);
            if (i > 0 && prepared_text[pt_len - 1] == prepared_text[pt_len - 2]) {
                prepared_text[pt_len++] = 'X'; // Insert 'X' between duplicate letters
            }
        }
    }
    if (pt_len % 2 != 0) prepared_text[pt_len++] = 'X'; // Add 'X' if length is odd
    prepared_text[pt_len] = '\0';

    // Encrypt the plaintext
    for (i = 0; i < pt_len; i += 2) {
        char a = prepared_text[i], b = prepared_text[i + 1];

        // Locate characters in matrix
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

        // Encryption logic
        if (a_row == b_row) {
            ciphertext[i] = matrix[a_row][(a_col + 1) % 5];
            ciphertext[i + 1] = matrix[b_row][(b_col + 1) % 5];
        } else if (a_col == b_col) {
            ciphertext[i] = matrix[(a_row + 1) % 5][a_col];
            ciphertext[i + 1] = matrix[(b_row + 1) % 5][b_col];
        } else {
            ciphertext[i] = matrix[a_row][b_col];
            ciphertext[i + 1] = matrix[b_row][a_col];
        }
    }
    ciphertext[pt_len] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
