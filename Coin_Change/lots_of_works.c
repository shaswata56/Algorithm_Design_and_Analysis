#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_OF_CORES 16
#define MAX_PRIME 1000000L

void do_primes()
{
    unsigned long long i, num, primes = 0;
    for (num = 1; num <= MAX_PRIME; ++num) {
        for (i = 2; (i <= num) && (num % i != 0); ++i);
        if (i == num)
            ++primes;
    }
    printf("Calculated %lld primes.\n", primes);
}

int main(int argc, char ** argv)
{
    time_t start, end;
    time_t run_time;
    unsigned long long i;
    pid_t pids[NUM_OF_CORES];

    /* start of test */
    start = time(NULL);
    for (i = 0; i < NUM_OF_CORES; ++i) {
        if (!(pids[i] = fork())) {
            do_primes();
            exit(0);
        }
        if (pids[i] < 0) {
            perror("Fork");
            exit(1);
        }
    }
    for (i = 0; i < NUM_OF_CORES; ++i) {
        waitpid(pids[i], NULL, 0);
    }
    end = time(NULL);
    run_time = (end - start);
    printf("This machine calculated all prime numbers under %d %d times "
           "in %lld seconds\n", MAX_PRIME, NUM_OF_CORES, run_time);
    return 0;
}
