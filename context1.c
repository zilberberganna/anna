//подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//главная функция программы
int main(int argc, char *argv[], char *envp[])  {
	int result1
;
	//запуск программы cat с аргументом "otchet_16_-4_2024.txt"
	//объявлене переменных
	pid_t procid, parentid;//идентификаторы процессов
	pid_t result;//рез-т системного вызова
	int a=0;//переменная для проверки работы процесса-родителя и процесса-ребенка
	result =fork();
	if (result<0) {
		printf("ОШИБКА ПРИ ВЫПОЛНЕНИИ fork1()\n");
		exit(-1);
	}
	else if (result==0) {


		a = a+1;
		procid =getpid();//получение идетификатора теущего процесса
		parentid = getppid();//получение  идентификаторы родит.процесса
		printf("Ид. процесса: %d, ид.родителя: %d, значение переменной a: %d\n", procid, parentid, a);
		result1=execle("/bin/cat","/bin/cat","otchet_16_-4_2024.txt", 0, envp);
		printf("ошибка при выполнении системного вызовва execle()\n");
	        exit(-1);

	}
	else {
		a= a+555;

		procid =getpid();//получение идетификатора теущего процесса
	        parentid = getppid();//получение  идентификаторы родит.процесса
	        printf("Ид. процесса: %d, ид.родителя: %d, значение переменной a: %d\n", procid, parentid, a);

	}

	//printf() выполняется только в случае ошибки вызова execle()

	return 0;//никогда не выполняется
}
