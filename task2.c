#include <stdio.h>

int main(){

char buffer[100],ch;
FILE *fp;
int c = 0;

fp = fopen("task2test.txt", "r");

	if (fp == NULL) {
    		printf("File not found\n");
    	  return 1;
	}

	printf("\nFile Content: \n\n");
	
	while (fgets(buffer, 100, fp)) {
    		printf("%s", buffer);
		c ++;

	}	
	printf("\nNumber of Lines: %d\n",c);
	
	
	
	fclose(fp);
	fp = fopen("task2test.txt", "r");
	c = 0;
	char LastCh = 'A';
	int cw = 0;

	while ((ch = fgetc(fp)) != EOF) {
		c += 1;
		if (ch == ' ' || ch == '\n' || ch == '\t') {

            		if (LastCh != ' ' && LastCh != '\n' && LastCh != '\t') {
                	cw++;
            		}
        	}
        LastCh = ch; 
    }


    if (LastCh != ' ' && LastCh != '\n' && LastCh != '\t') {
        cw++;
    }

	
	printf("\nNumber of Words: %d\n",cw);
	printf("\nNumber of Characters: %d\n",c);
	fclose(fp);
  return 0;
}
