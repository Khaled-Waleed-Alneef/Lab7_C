#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY 3

void enc(char *str, int key);
void dec(char *str, int key);

int main() {
    char str1[100], buffer[100], ch, ch1;

    printf("\nDo you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &ch);

    printf("\nDo you want to encrypt data from a (F)ile or enter a (S)tring? ");
    scanf(" %c", &ch1);

    if (ch1 == 'F') {
        char file[100];
        printf("\nPlease enter the filename to read: ");
        scanf("%s", file);
        
        FILE *fp = fopen(file, "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }

        while (fgets(buffer, sizeof(buffer), fp)) {

            strcpy(str1, buffer);
            if (ch == 'E') {
                enc(str1, KEY);
                printf("\nEncrypted Text: %s", str1);
            } else if (ch == 'D') {
                dec(str1, KEY);
                printf("\nDecrypted Text: %s", str1);
            }
        }
        fclose(fp);
    } else {
        printf("\nEnter Text: ");
        scanf("%s", str1);

        if (ch == 'E') {
            enc(str1, KEY);
            printf("\nEncrypted Text: %s\n", str1);
        } else if (ch == 'D') {
            dec(str1, KEY);
            printf("\nDecrypted Text: %s\n", str1);
        }
    }
    return 0;
}

void enc(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A'; 
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';  
        }
    }
}

void dec(char *str, int key) {
    enc(str, -key); 
}
