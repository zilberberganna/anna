#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[])  {
	int result;
	result=execle("/bin/cat","/bin/cat","otchet_16_-4_2024.txt", 0, envp);
	printf("ошибка при выполнении системного вызовва execle()\n");
	exit(-1);
	return 0;
}
