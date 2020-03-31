#include<stdio.h>// For windows based functions
#include<windows.h>// For Unix/Linux based functions
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
pthread_mutex_t lockt=PTHREAD_MUTEX_INITIALIZER;
int s0[3];
int s1[3];
int s2[3];
void exit1()
{
	printf("\n\n\n\t Thank you. Sad to see you go. \n");
	Sleep(2);
	exit(0);
}
int assign(int x,int y)											//prevents students from having same resources
{
	int i=1;
	if(y==0)
	{
		if(s1[x]==1 || s2[x]==1)
		{
			printf("\nTwo students shouldn't have same resource.");
			exit1();
		}
	}
	if(y==1)
	{
		if(s0[x]==1 || s2[x]==1)
		{
			printf("\nTwo students shouldn't have same resource.");
			exit1();
		}
	}
	if(y==2)
	{
		if(s0[x]==1 || s1[x]==1)
		{
			printf("\nTwo students shouldn't have same resource.");
			exit1();
		}
	}
	return i;
}
void *student0()												//input for student 1
{
	printf("\npress 1 for pen, 2 for paper and 3 for question paper\n");
	printf("Enter the item  with 1st student: ");
	int a;
	pthread_mutex_lock(&lockt);
	scanf("%d",&a);
	if(a==1)
	{
		s0[0]=assign(0,0);
	}
	else
    {
        if(a==2)
        {
            s0[1]=assign(1,0);
        }
		else
        {
            if(a==3)
            {
                s0[2]=assign(2,0);
            }
			else
            {
                printf(" A student isn't configured to contain this.\n");
            }
        }
	}
	pthread_mutex_unlock(&lockt);
}
void *student1()												//input for student 2
{
	printf("press the item containing with 2nd student: ");
	int a;
	pthread_mutex_lock(&lockt);
	scanf("%d",&a);
	if(a==1)
	{
		s1[0]=assign(0,1);
	}
	else
    {
        if(a==2)
        {
            s1[1]=assign(1,1);
        }
        else
        {
            if(a==3)
            {
                s1[2]=assign(2,1);
            }
            else
            {
                printf(" A student isn't configured to contain this.\n");
            }
        }
    }
	pthread_mutex_unlock(&lockt);
}
void *student2()													//input for student 3
{
	printf("press the item containing with 3rd student: ");
	int a;
	pthread_mutex_lock(&lockt);
	scanf("%d",&a);
	if(a==1)
	{
		s2[0]=assign(0,2);
	}
	else{ if(a==2)
		{
			s2[1]=assign(1,2);
		}
		else{ if(a==3)
			{
				s2[2]=assign(2,2);
			}
		    else
			{
			printf("A student isn't declared to contain this.\n");
			}
		  }
	}
	pthread_mutex_unlock(&lockt);
}
int checking(int a,int b)										
{   	int c=0;
	if (a==1 && b==2 || a==2 && b==1)
    {
        c=3;
    }
	else
	{
        if (a==1 && b==3 || a==3 && b==1)
		{
            c=2;
		}
		else
		{
            if (a==2 && b==3 || a==3 && b==2)
			{
				c=1;
			}
			else
			{
				printf("\nKindly check your input; The input might be wrong or You have entered the same resources twice which will yield no result\n");
				exit1();
			}
       }
	}
	return c;
}
void checking1(int c)												
{
if(s0[c-1]==1)
{
    printf("******1st Student has the last item, he completes the task and reports to teacher******\n\n");
    Sleep(1.5);
}
else
{
    if(s1[c-1]==1)
    {
        printf("******2nd Student has the last item, he completes the task and reports to teacher******\n");
        Sleep(1.5);
    }
    else
    {
        if(s2[c-1]==1)
        {
            printf("******3rd Student has the last item, he completes the task and reports to teacher******\n");
            Sleep(1.5);
        }
        else
        {
            printf("\nStudent having the corresponding last item has either completed his task\n");}
        }
    }
return;
}
void *table()											
{
	int i,a,b,c,d,e,f;
		pthread_mutex_lock(&lockt);
		a=1,b=2;
		printf("\n______Teacher places Pen and Paper on the table______\n");
		Sleep(2);
		c=checking(a,b);
		checking1(c);
		pthread_mutex_unlock(&lockt);
		pthread_mutex_lock(&lockt);
		a=2,b=3;
		printf("\n______Teacher places Question Paper and Paper on the table______\n");
		Sleep(2);
		c=checking(a,b);
		checking1(c);
		pthread_mutex_unlock(&lockt);
		pthread_mutex_lock(&lockt);
		a=1,b=3;
		printf("\n______Teacher places Pen and Question Paper on the table______\n");
		Sleep(2);
		c=checking(a,b);
		checking1(c);
		pthread_mutex_unlock(&lockt);
}
void main()															
	int a;
	pthread_t Stud0;
	pthread_t Stud1;
	pthread_t Stud2;
	pthread_t Tea1;
	printf("***********************#  OS PROJECT #***************************\n");
    printf("The following contains 2 Frames.\nFrame 1:Found in Examination Hall \nFrame 2:Found in Library\nFrame 3:There is associate optimised answer enforced for the SCENE a pair of that is much ideal..... \n Please proceed consequently by selecting one :-   ");
	scanf("%d",&a);
    switch(a)
    {
        case 1:
            printf("\nFrame clarification: \nThere area unit three student methods and one teacher process. Students area unit presupposed to do their assignments and that they want three things for that- pen,paper and question paper. The teacher has AN infinite offer of all the 3 things. One student should have pen, another one with paper and another with question paper. The teacher places 2 factors on a shared table and also the student having the third complementary thing makes the assignment and tells the teacher on completion. The teacher then places 2 factors out of 3 and once more the scholar having the third thing makes the assignment and tells the teacher on completion.\n\n");
            pthread_create(&Stud0,NULL,student0,NULL);
            pthread_join(Stud0,NULL);
            pthread_create(&Stud1,NULL,student1,NULL);
            pthread_join(Stud1,NULL);
            pthread_create(&Stud2,NULL,student2,NULL);
            pthread_join(Stud2,NULL);
            pthread_create(&Tea1,NULL,table,NULL);
            pthread_join(Tea1,NULL);
            printf("\n\nFrame 1 at Exam Hall finished\n");
            int a;
            printf("\npress 0 to enter other Frame, else any to exit :  ");
            scanf("%d",&a);
            if (a==0)
            {
                system("cls");
                main();
            }
            else {exit1();}
            break;
        case 2:
            {
            printf("\nFrame clarification: \n 2 types of individuals will enter into a library-students and academics. when getting into the library, the traveller searches for the specified books and find them. so as to urge them issued, he goes to the only methoding unit|CPU|C.P.U.|central processor|processor|mainFrame|electronic equipment|hardware|computer hardware} that is there to process the provision of books. two forms of queues square measure there at the counter-1 for college students and one for academics.A student goes and stands at the tail of the queue for college students and equally the teacher goes and stands at the tail of the queue for teaches (FIFO).If a student is being served and a tutor arrives at the counter, he would be following person to urge service (PRIORITY - non preemptive). If 2 academics reach constant time, they'll exchange their queue to urge service (FIFO).\n\n");
            int p[30],pr[30],bt[30],temp,max,wt[30],ta[30],sum=0,i,j,n;
            int c=0,d=0;
            wt[0]=0;
            printf("Enter the number of persons = ");
            scanf("%d",&n);
            printf("Enter 0 for teacher and 1 for student\n");
            for(i=0;i<n;i++)
            {													
                p[i]=i+1;
                bt[i]=1;
                printf("Who arrived %d? =",i+1);
                scanf("%d",&pr[i]);
            }
            for(i=0;i<n;i++)
            {												
                max=i;
                for(j=i+1;j<n;j++)
                {
                    if(pr[j] <pr[max])
                    max=j;
                }
                temp=pr[max];
                pr[max]=pr[i];
                pr[i]=temp;
                temp=bt[max];
                bt[max]=bt[i];
                bt[i]=temp;
                temp=p[max];
                p[max]=p[i];
                p[i]=temp;
            }

            for(i=0;i<n;i++)
            {     												
                wt[i+1]=bt[i]+wt[i];
                ta[i]=bt[i]+wt[i];
                sum+=ta[i];
            }
            for(i=0;i<n;i++)
            {													   
                printf("\nWaiting time(W.T.) for %d person is = %d",p[i],wt[i]);
                printf("\tTurn around time(T.A.T.) for %d person=%d",p[i],ta[i]);
            }
            printf("\n\nAverage turn around = %d\n",sum);
            printf("\n\nFrame 2 at Library completed\n");
            int a;
            printf("\npress 0 to enter other Frame, else any to exit :  ");
            scanf("%d",&a);
            if (a==0)
            {
                system("cls");
                main();
            }
            else {exit1();}
            break;
            }
        case 3:
            {
            printf("\nFrame clarification:\nIf a combine of lecturers hit a similar time, they're going to substitute their queue to induce service (FIFO).n If a lecturer is being served and thru the number once he is being served,while another teacher comes,and then that teacher would get the service next. This methodology may continue leading to increase in waiting time of students and so the program times to cut back this.\n\n");
            int p[30],pr[30],bt[30],temp,max,wt[30],ta[30],sum=0,i,j,n;
            int c=0,d=0;
            wt[0]=0;
            printf("Enter the number of persons = ");
            scanf("%d",&n);
            printf("Enter 0 for teacher and 1 for student\n");
            for(i=0;i<n;i++)
            {
                p[i]=i+1;
                bt[i]=1;
                printf("\t Who arrived %d? =",i+1);
                scanf("%d",&pr[i]);
                if(pr[i]==0)
                {												
                    c=c+1;
                }
                if(pr[i]==0 && d==1)
                {
                    pr[i]=pr[i]+1;
                    d=0;
                }
                if(c==3)
                {
                    c=0;
                    d=1;
                    continue;
                }
            }
            for(i=0;i<n;i++)
            {													
                max=i;
                for(j=i+1;j<n;j++)
                {
                    if(pr[j] <pr[max])
                    max=j;
                }
                temp=pr[max];
                pr[max]=pr[i];
                pr[i]=temp;
                temp=bt[max];
                bt[max]=bt[i];
                bt[i]=temp;
                temp=p[max];
                p[max]=p[i];
                p[i]=temp;
            }
			for(i=0;i<n;i++)
            {     															
                wt[i+1]=bt[i]+wt[i];
                ta[i]=bt[i]+wt[i];
                sum+=ta[i];
            }
            for(i=0;i<n;i++)
            {															    
                printf("\nWaiting time for person %d is =%d",p[i],wt[i]);
                printf("\t Turn around time for p[%d]=%d",p[i],ta[i]);
            }
            printf("\n\n Average turn around time = %d",sum/n);
            printf("\n\nFrame 3 at Library is complete\n");
            int a;
            printf("\npress 0 to enter other Frame, else any:  ");
            scanf("%d",&a);
            if (a==0)
            {
                system("cls");
                main();
            }
            else {exit1();}
            break;
        }
    default:
        printf("Entered Frame does not match any of the listed, Have a decent Day!");exit1();
    }
}
