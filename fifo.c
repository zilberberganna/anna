#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	int fd, result;
	size_t size;
	char resstring[13];
	char name[]="fifo.fifo";
	if (mknod(name, S_IFIFO | 0666, 0) < 0) {
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
	if ((result = fork()) < 0) {
		printf("Не удалось создать дочерний процесс\n");
		exit(-1);
	}
	else if (result > 0) {
		if((fd = open(name, O_WRONLY)) < 0) {
			printf("Не удалось открыть файл назапись\n");
			exit(-1);
		}
		size = write(fd, "Hello, child", 13);
		if (size != 13){
			printf("Не получилось записать 13 байт в FIFO\n");
			exit(-1);
		}
		if (close(fd) < 0) {
			printf("Не получилось закрыть FIFO\n");
			exit(-1);
		}
		printf("Процесс-родитель записал информацию в FIFO и завершил работу\n");
	}
	else {
		if ((fd = open(name, O_RDONLY)) < 0) {
			printf("Не удалось открыть FIFO для чтения\n");
			exit(-1);
		}
		size = read(fd, resstring, 13);
		if (size != 13) {
			printf("Не удалось прочитать информацию из FIFO\n");
			exit(-1);
		}
		printf("Процесс-ребенок прочитал информацию: %s\n", resstring);
		if (close(fd) < 0) {
			printf("Не получилось закрыть FIFO, открытый на чтение\n");
			exit(-1);
		}
	}
	return 0;
}
