#include "sort_lib.h"

#include <pthread.h>
#include <unistd.h>

void *sleeping(void *);

int main()
{
    printf("sleep sort\n");
    int length = 10;
    int array[length];

    get_array(array, length);
    print_array(array, length);

    
    pthread_t thread_id[length];
    for (int i = 0; i < length; i++) 
    {
        pthread_create( &thread_id[i], NULL, sleeping, (void*) &array[i]);
    }

    for (int i = 0; i < length; i++) 
    {
        pthread_join( thread_id[i], NULL);
    }
 

    return 0;
}

void *sleeping(void *ptr)
{
    int *how_long;
    how_long = (int*) ptr;
    usleep(*how_long * 1000); 
    printf("%d \n", *how_long);
}
