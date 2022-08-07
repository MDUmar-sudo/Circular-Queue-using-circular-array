#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct CircularQueue cq;

struct CircularQueue{
int size;
int front;
int rear;
int *arr;
};

void enqueue();
void dequeue();
void display();
void peek();

int main()
{
    cq *s = (cq *)malloc(sizeof(cq));
    s->size=100;
    s->front=-1;
    s->rear=-1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    int choice;

    printf("-----------------------------------------\n");
    printf("CIRCULAR QUEUEING USING CIRCULAR ARRAY\n");
    printf("-----------------------------------------\n");

  do{
    printf("____________________________");
    printf("\nCHOOSE A QUEUE OPERATION\n\n(1)INSERT\n(2)DELETE\n(3)DISPLAY\n(4)PEEK\n(5)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);
    printf("\n____________________________");

    switch(choice)
    {
    case 1:
            enqueue(s);
             break;

    case 2:
            dequeue(s);
            break;

    case 3:
             display(s);
             break;

    case 4: {
                printf("\n----------------------------");
                printf("\nCHOOSE A PEEK OPERATION\n\n(1)PEEK FRONT\n(2)PEEK REAR\n(3)EXIT\n");
                printf("\n----------------------------");
                int option;
                printf("\nENTER YOUR CHOICE :");
                scanf("%d",&option);
                printf("\n----------------------------");
                switch(option){
                    case 1: peek(s,option);
                            break;

                    case 2: peek(s,option);
                            break;

                    case 3: printf("\nEXIT\n");
                            break;

                    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");
                }

            }
            break;


    case 5: printf("\nEXIT\n");
            break;

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=5);

  getch();
  return 0;

}

//return queue status: Empty or Not

int isEmpty(cq *s){
    if(s->front==-1&&s->rear==-1) return 1;

    return 0;
}

//return queue status: Full or Not

int isFull(cq *s){
    if((s->rear+1)%s->size==s->front) return 1;

    return 0;
}

//enqueue() function add an element at the rear position of the queue

void enqueue(cq *s)
{
    int x;

    if(isFull(s))
    {
        printf("\nQUEUE OVERFLOW!!!\n");
    }
    else if(s->front==-1 && s->rear==-1)
    {

         printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
         scanf("%d",&x);

        s->rear=s->front=0;
        s->arr[s->rear]=x;
        printf("\nINSETRED ELEMENT IN THE QUEUE :%d",s->arr[s->rear]);
        printf("\nrear=%d\n",s->rear);

    }

    else
        {
             printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
             scanf("%d",&x);

          s->rear=(s->rear+1)%s->size;
          s->arr[s->rear]=x;
          printf("\nINSETRED ELEMENT IS THE QUEUE :%d\n",s->arr[s->rear]);
          printf("\nrear=%d\n",s->rear);

        }

}

//dequeue() function deletes the front element from the queue

void dequeue(cq *s)
{


    if(isEmpty(s))
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else if(s->front==s->rear)
    {
       printf("\nDELETED ELEMENT FROM THE QUEUE :%d\n",s->arr[s->front]);
       s->front=-1;
       s->rear=-1;
    }

    else
    {
        printf("\nDELETED ELEMENT FROM THE QUEUE :%d\n",s->arr[s->front]);
        s->front=(s->front+1)%s->size;

    }
}

//display() function print all the elements in the queue

void display(cq *s)
{
    if(isEmpty(s))
   {
     printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else
 {
        printf("\nELEMENTS IN THE QUEUE:");
     for(int i=s->front;i!=s->rear;i=(i+1)%s->size)
    {
        printf("\n%d",s->arr[i]);

    }
    printf("\n%d",s->arr[s->rear]);
    printf("\n");


 }

}

//peek() function returns front or rear elements of the queue

void peek(cq *s,int signal)
{
    if(isEmpty(s))
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else if(signal==1)
    {
        printf("\nFRONT ELEMENT OF THE QUEUE :%d\n",s->arr[s->front]);
    }
    else
    {
        printf("\nREAR ELEMENT OF THE QUEUE :%d\n",s->arr[s->rear]);
    }
}
