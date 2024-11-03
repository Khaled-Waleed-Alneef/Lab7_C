#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    unsigned char byte = 0;
    int bit, c = 0;

    fp1 = fopen("bitstream1.bit", "r");
    fp2 = fopen("bitstream1.hex", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File Not Found!\n");
        return 1; 
    }

    while ((bit = fgetc(fp1)) != EOF) {

        if (bit == '0' || bit == '1') {

            byte += (bit - '0') << c;
            c++;
        }

        if (c == 8) {
            fprintf(fp2, "%02X\n", byte);
            c = 0;
            byte = 0;
        }
    }


    if (c > 0) {
        fprintf(fp2, "%02X\n", byte); 
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
