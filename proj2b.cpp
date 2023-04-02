// command to compile: make
// command to run: ./proj2a <input file> <output file>
// command to clean: make clean

// Write a multithreaded program that generates the Fibonacci series using the pthreads library.

#include <pthread.h>
#include<iostream>
#include <stdlib.h>
#include<unistd.h>
using namespace std;


int* Arr, size;

void* childfunc(void*arg){
    if(size>1){
        Arr[0]=0;
    }
    if(size>2){
        Arr[1]=1;
    }
    for(int i=2; i<size; i++){
        Arr[i]= Arr[i-1]+Arr[i-2];
    }
    pthread_exit(0);
}

int main(int argc, char** argv){
    if(argc>1){
        int numOfFibonacci=  atoi(argv[1]);
        size= numOfFibonacci; 
        Arr= new int[size];

        // creating the thread
        pthread_t thId;
        pthread_create(&thId,NULL, &childfunc,NULL);
        pthread_join(thId, NULL);
        cout<<"Fibonacci Numbers ::";
        for(int i=0; i<size; i++){
            cout<<Arr[i]<<"  ";
        }
        cout<<endl;
    }else{
        cout<<"Argument <Number of Fibonacci Number>"<<endl;
        return -1;
    }
    return 0;
}