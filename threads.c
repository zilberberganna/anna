#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int a=0; //инициализация глобальной статической переменнойЮ доступной из каждого thread'а
//функция, выполняющаяся в рамках второго thread'а
void *mythread(void *dummy) {
	pthread_t mythid;//идентификатор thread'а  - для каждого имеет свое значение
	mythid=pthread_self();
	a=a+1;
	printf("Thread %ld, Результат вычисления a =%d\n", mythid, a); //печать идентификатора текущего thread'а и результата из значения глобальной переменной
	return NULL;
}
int main() {
	pthread_t thid, mythid;
	int result;
	result=pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL);//создание нового thread'а
	if(result !=0) {
		printf("ошибка при создании нового thread\'a, возвращенное значение =%d\n", result);
		exit(-1);
	}
	printf("Thread создан, thid=%ld\n", thid);
	mythid=pthread_self();//сохраняем в переменной mythid идентификатор главного thread'а
	a=a+1;
	printf("Thread %ld, результат вычисления a=%d\n", mythid, a);
	pthread_join(thid, (void **)NULL);//ожидание завершения порожденного thrad'а
	return 0;
}
