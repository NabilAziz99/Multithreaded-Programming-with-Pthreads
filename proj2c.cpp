#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

using namespace std;

int count=1,size;

void* vowel(void* argv){
    const char vowel[]={ 'a','A', 'e','E', 'i','I', 'o','O', 'u','U'};
    char** arg= (char**)argv;
    while(count<size){
        bool con= false;
        for(int j=0; j<10; j++){
            if(arg[count][0]==vowel[j]){
                con=true;
                break;
            }
        }
        if(con){
            cout<<"vols :"<<arg[count]<<endl;
            count++;
        }
        else{
            int x= sched_yield();
            if(x<0){
                cout<<"Error in sched_yield()"<<endl;
            }
        }
    }
    pthread_exit(0);
}


void* consonant(void* argc){
    const char vowel[]={ 'a','A', 'e','E', 'i','I', 'o','O', 'u','U'};
    char** arg= (char**)argc;
    while(count<size){
        bool con= true;
        for(int j=0; j<10; j++){
            if(arg[count][0]==vowel[j]){
                con=false;
                break;
            }
        }
        if(con){
            cout<<"cons :"<<arg[count]<<endl;
            count++;
        }
        else{
            int x= sched_yield();
            if(x<0){
                cout<<"Error in sched_yield()"<<endl;
            }
        }
    }
    pthread_exit(0);
}


int main(int argc, char** argv){
    if(argc>2){   
        size=argc;
        // create the thread
        pthread_t thId1, thId2;
        pthread_create(&thId1, NULL, &vowel, (void*)argv);
        pthread_create(&thId2, NULL, &consonant, (void*)argv);
        pthread_join(thId1, NULL);
        pthread_join(thId2, NULL);
    }else{
        cout<<"Argument::<Prompt String>"<<endl;
        return -1;
    }
    

    return 0;
}