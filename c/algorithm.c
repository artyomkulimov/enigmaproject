#include<stdlib.h>
#include<stdio.h>



int simple_rand(int n){
    return rand() % n;
}

int advanced_rand(int n){
    return ( rand() > (RAND_MAX / 2) );
}

int main(void){
    int seed = 42;
    int r,n,m;

    srand(seed);
    n = 100;
    m=2;
    

    for(int i=0;i<n;i++){
        printf("%d",simple_rand(m));
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d",advanced_rand(m));
    }

    
    // printf(" %d",RAND_MAX);
    return 0;
}