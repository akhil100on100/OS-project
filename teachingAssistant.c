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


void *student(void *stud_id)
{
        //work in progress
}
void *assistant()
{
    printf("Checking for students.\n");
    while(1)
    {
	 	if(stud_wait>0)
    	{
       		ta_flag=0;
       		sem_wait(&s_stud);
       		pthread_mutex_lock(&mutex);
       		int ht=rand()%5;
		printf("\nTeacher is teaching student %d ",wait_room[next_teach_pos]);
		wait_room[next_teach_pos]=0;
		stud_wait--;
		printf("\nWaiting students : seat-1 <%d>  ||  seat-2 <%d>  ||  seat-3 <%d>",wait_room[0],wait_room[1],wait_room[2]);
		next_teach_pos=(next_teach_pos+1)%wait_chairs;
		sleep(ht);
		printf("\n\t*!*!*!*!*!*!*!*!*!TEACHING FINISH!*!*!*!*!*!*!*!*!*");
		//printf("\nNumber of students waiting : %d",stud_wait);
		pthread_mutex_unlock(&mutex);
	        sem_post(&s_Tass);
		}
		else
		{
			if(ta_flag==0)
			{
				printf("\n\n\t#-#-#-#-#-#-#-#-#-NO STUDENTS WAITING....TEACHER IS SLEEPING-#-#-#-#-#-#-#-#-#");
				ta_flag=1;
			}
		}
	}
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
