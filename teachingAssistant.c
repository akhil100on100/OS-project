#include<stdio.h>           //input output
#include<stdlib.h>          //standard library
#include<string.h>          //string library
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

int wait_room[3],stud_wait=0,next_seat_pos=0,next_teach_pos=0,ta_flag=0;

void *student(void *stud_id)
{
        //work in progress
}
void *assistant()
{
       //work in progress
}
int isnum(char num[])
{
        int i;
        for(i=0;num[i]!=0;i++)
        {
                if(!isdigit(num[i])
                {
                        return 0;
                }
        }
        return 1;
}
int iswait(int stud_id)
{
        int i;
        for(i=0;i<3;i++)
        {
                if(wait_room[i]==stud_id)
                {
                        return 1;
                }
        }
        return 0;
}

int main(int argc,char *argv[])
{
        int i,snum;
        if(argc>1)
        {
                if(isnum(argv[1]==1)
                {
                        snum=atoi(argv[1]);
                }
                else
                {
                        printf("\n*!*!*!*!*!*!*!*INVALID INPUT.....BYE BYE*!*!*!*!*!*!*!*\n");
                        return 0;
                }
        }
        else
        {
                snum=default_students;
        }
        //work in progress
}
