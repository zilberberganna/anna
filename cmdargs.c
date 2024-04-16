#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main (int argc, char *argv[], char *envp[] ) {
	int i;
       	printf("Количество аргументов: %d\n\n", argc);		
	 if (argc<1) {
		printf("ошибка\n");
		exit(-1);
 	 }
	 else if (argc ==1) {
		while (envp[i]!=NULL) {
	                printf("%s\n", envp[i]);
	                i++;
                }

         }
	 else{
		for (i=0; i<argc; i++) {
		printf("Аргумент %d: %s\n", i, argv[i]);
		}
       	}

	return 0;
}

