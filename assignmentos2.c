#include<stdio.h>
#include<stdlib.h>
 

int mutex=1,full=0,empty=3,x=0;
// mutex :Initialize a mutex to 1
// full :Number of full slots as 0
// empty :Number of empty slots as size of buffer

//create wait function
int wait(int s)
{
    return (--s);
}
//create signal function 
int signal(int s)
{
    return(++s);
}

//create producer function
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=signal(mutex);
}

//create consumer function
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}
 
void main()
{
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:    if((mutex==1)&&(empty!=0))
                        producer();
                    else
                        printf("Buffer is full!!");
                    break;
            case 2:    if((mutex==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty!!");
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }
   
   
}
 
