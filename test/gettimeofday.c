#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// struct timeval {
//     time_t      tv_sec;
//     suseconds_t tv_usec;
// }

int main()
{
    struct timeval startTime, endTime;
    double diffTime;

    gettimeofday(&startTime, NULL);
    // 특정 작업 수행
    sleep(1);
    gettimeofday(&endTime, NULL);
	printf("test1: %ld\n", endTime.tv_sec);
	printf("test2: %d\n", endTime.tv_usec);
    diffTime = ( endTime.tv_sec - startTime.tv_sec ) + (( endTime.tv_usec - startTime.tv_usec ) / 1000000);
    printf("%f s\n", diffTime);
    return 0;
}
