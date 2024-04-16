#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
	char string[]="group";
	if((fd=open("file1.txt", O_WRONLY|O_CREAT, 0666))<0){
		printf("ошибка при открытии файла на запись\n");
		exit(-1);
	}
	size=(fd, string, 17);
	if (size !=17){
		printf("не удалось записатьвсю строку в файл\n");
		exit(-1);
	}
	 if (size !=17){ 
                printf("не удалось записатьвсю строку в файл\n");
                exit(-1);
        }
	return 0;
}
