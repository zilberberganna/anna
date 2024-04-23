#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//создаем массив из двух элементов для хранений файловых дескрипторов для чтения ии для записи

int main () { 
        int fd[2];
        size_t size;
        char string[]="Hello, world!";
        char resstring[14];
        if(pipe(fd)<0){ 
                printf("Can\'t create pipe\n");
                exit(-1);
        }
        size=write(fd[1], string, 14);
//провверка количества байт записанных  в  строку с помощью write()
        if(size!=14) { 
                printf("Can\'t write all string\n");
                exit(-1);
        }
        size=read(fd[0],resstring, 14);
//провверка количества байт прочитанных  в  строку с помощью read()

	if (size<0){
		printf("Can\'t string\n");
		exit(-1);
	}
	printf("%s\n",resstring);
//закрытие для чтения
	if(close(fd[0])<0) {
		printf("Can\'t close input stream\n");
	}
//закрытие для записи
	if(close(fd[1])<0) { 
                printf("Can\'t close output stream\n");
        }
	return 0;
}
