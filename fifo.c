#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	int fd;
	size_t size;
	char resstring[13];
//создаем символьный массив где будет храниться имя файла  fifo
	char name[]="fifo.fifo";
//после первого запуска программы необходимо закомментировать процесс создания файла fifo
/*	if (mknod(name, S_IFIFO | 0666, 0) < 0) {
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
*/

//процесс родитель пишет информацию в fifo
       	if((fd = open(name, O_WRONLY)) < 0) {
		printf("Не удалось открыть файл на запись\n");
		exit(-1);
	}
	size = write(fd, "Hello, all!", 11);
	if (size != 11){
		printf("Не получилось записать 11  байт в FIFO\n");
		exit(-1);
	}
	if (close(fd) < 0) {
		printf("Не получилось закрыть FIFO\n");
		exit(-1);
	}
	printf("Процесс записал информацию в FIFO и завершил работу\n");
	return 0;
}
