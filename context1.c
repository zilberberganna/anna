//подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//главная функция программы
int main(int argc, char *argv[], char *envp[])  {
	int result;
	//запуск программы cat с аргументом "otchet_16_-4_2024.txt"
	result=execle("/bin/cat","/bin/cat","otchet_16_-4_2024.txt", 0, envp);
	//printf() выполняется только в случае ошибки вызова execle()
	printf("ошибка при выполнении системного вызовва execle()\n");
	exit(-1);
	return 0;//никогда не выполняется
}
