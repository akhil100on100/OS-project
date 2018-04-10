#include <stdio.h>         
#include <stdlib.h>          
#include <string.h>         
#include <pthread.h>        
#include <semaphore.h>       
#include <unistd.h>

#define wait_chairs 3           

void *student(void *stud_id);     
void *assistant();              

sem_t s_stud;
sem_t s_Tass;

pthread_mutex_t mutex;

int wait_room[3],stud_wait=0,next_seat_pos=0,next_teach_pos=0,ta_flag=0;

void *student(void *stud_id)
{
	int id=*(int*)stud_id;
	printf("\nStudent %d is going to TA office",id);
	while(1)
	{
		int p=rand()%5;
		sleep(p);
		pthread_mutex_lock(&mutex);
		if(stud_wait<wait_chairs)
		{
			wait_room[next_seat_pos]=id;
			stud_wait++;
			printf("\n\t\tStudent %d has taken a seat in the waiting room....Number of students waiting : %d",id,stud_wait);
			printf("\nWaiting students : seat-1 <%d>  ||  seat-2 <%d>  ||  seat-3 <%d>",wait_room[0],wait_room[1],wait_room[2]);
			next_seat_pos=(next_seat_pos+1)%wait_chairs;
			pthread_mutex_unlock(&mutex);
			sem_post(&s_stud);
			sem_wait(&s_Tass);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			printf("\nStudent %d will try later...",id);
		}
	}
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
		printf("\n\t*!*!*!*!*!*!*!*!*!TEACHING FINISH!*!*!*!*!*!*!*!*!*\n");
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
int main()
{
    int i,snum;
    printf("\nenter number of students: ");
    scanf("%d",&snum);
    if(snum==0)
    {
    	printf("\t\tNO STUDENTS...\n");
    	return 0;
    }
    int s_ids[snum];
    pthread_t st[snum],t;
    sem_init(&s_stud,0,0);
    sem_init(&s_Tass,0,1);
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t,NULL,assistant,NULL);
    for(i=0;i<snum;i++)
    {
	s_ids[i]=i+1;
	pthread_create(&st[i],NULL,student,(void*)&s_ids[i] );
    }
    pthread_join(t,NULL);
    for(i=0;i<snum;i++)
    {
	pthread_join(st[i],NULL);
    }
    return 0;
}
