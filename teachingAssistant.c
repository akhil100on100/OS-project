#include<stdio.h>           //input output
#include<stdlib.h>
#include<pthread.h>         //create POSIX threads
#include<semaphore.h>       //creation of semaphores

#define wait_chairs 3             //no. of waiting chairs
#define default_students 5        //default no. of students

void *student(void *stud_id);     //Student's activity
void *assistant();                //teaching assistant's activity

//semaphores
sem_t s_stud;
sem_t s_Tass;

//mutex
pthread_mutex_t mutex;

int main(int argc,char *argv[])
{
        //work in progress
}
void *student(void *stud_id)
{
        //work in progress
}
void *assistant()
{
        //work in progress
}
