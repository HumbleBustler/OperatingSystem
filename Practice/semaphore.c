#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
void func1 (void *ptr);
void func2 (void *ptr);
char buf[24];
sem_t mutex;
int main(int argc, char *argv[])
{
 pthread_t thread1;   //initialized thread
 pthread_t thread2;
  char *m1= "Thread 1";
  char *m2= "Thread 2";
  sem_init(&mutex, 0, 1); //sem_init - initialize an unnamed semaphore (int sem_init(sem_t *sem, int pshared, unsigned int value);)
    	pthread_create(&thread1, NULL, (void*) &func1, (void*) m1);   // create thread
    pthread_create (&thread2, NULL, (void*) &func2, (void*) m2);
 
    pthread_join(thread1, NULL);    //join with a terminated thread.
    pthread_join(thread2, NULL);
  	sem_destroy(&mutex);
return 0;
}

void func1 (void *ptr)
{
char *m=(char *)ptr;
printf("%s\n", m);
sem_wait(&mutex);
sprintf(buf, "%s", "Hello World!");
sem_post(&mutex);
pthread_exit(0);

}

void func2 (void *ptr)
{
char *m=(char *)ptr;
printf("%s\n", m);
sem_wait(&mutex);
printf("%s\n", buf);
sem_post(&mutex);
pthread_exit(0);
}