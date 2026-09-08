#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

int main() {
    sem_t s;
    sem_init(&s, 1, 1);

    if (fork() == 0) {
        sem_wait(&s);
        printf("Producer: Producing\n");
        sem_post(&s);
    } else {
        wait(NULL);
        sem_wait(&s);
        printf("Consumer: Consuming\n");
        sem_post(&s);
    }

    sem_destroy(&s);
    return 0;
}
