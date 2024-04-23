#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//подключение библиотеки для управления файлами
int main() {
	int fd; //файловый дескриптор
	size_t size;//размер строки в байтах
	char string[]="group\n";
	//открытие файла на запись, если файла не существуют,  он будет создан с правами доступа 0666
	if((fd=open("file1.txt", O_WRONLY|O_CREAT, 0666))<0){
		printf("ошибка при открытии файла на запись\n");
		exit(-1);
	}
//чтение из файла в строку стринг 
	size = write(fd, string, 6);
	if (size != 6){
		printf("не удалось записать всю строку в файл\n");
		exit(-1);
	}
//закрытие файла
	 if (close(fd)){ 
                printf("не удалось закрыть файл\n");
                exit(-1);
        }
	return 0;
}
