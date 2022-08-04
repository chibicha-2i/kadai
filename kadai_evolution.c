#include <stdio.h>
#define MAX_NUM 10000
//構造体
typedef struct stack{
    int back;
    int data[MAX_NUM];

}STACK1;

typedef struct queue{
    int back;
    int head;
    int data[MAX_NUM];
    
}QUEUE1;

//stack
void clear(STACK1*);
void printstack(STACK1*);
void push(STACK1*,int);
int pop(STACK1*);
int sizestack(STACK1*);
int peek(STACK1*);
//queue
void clear1(QUEUE1*);
void printqueue(QUEUE1*);
void enqueue(QUEUE1*,int);
int dequeue(QUEUE1*);
int sizequeue(QUEUE1*);






//スタックの関数
void clear(STACK1 *stack){
    stack->back=-1;
}

void push(STACK1 *stack, int input){
    stack->data[stack->back+1]=input;
    stack->back=stack->back+1;
}

void printstack(STACK1 *stack){
   int i;
   for(i=0;i<=stack->back;i++){
     printf("%d\n",stack->data[i]);
   }
   printf("\n");
}

int pop(STACK1 *stack){
    int r;
    r=stack->data[stack->back];
    stack->back=stack->back-1;
    return r;    
}

int size(STACK1 *stack){
    return stack->back+1;
}

int peek(STACK1 *stack){   
    if (stack->data[0]==-1){
        return 0;
    }
     return stack->data[0];
} 
//キューの関数
void clear1(QUEUE1 *queue){
    queue->back=-1;
    queue->head=0;

}

void enqueue(QUEUE1 *queue, int input){
    if((queue->back+2)%MAX_NUM==queue->head){
        printf("キューが満杯でENQUEUEできません\n");
        printf("%d\n",queue->back);
        return;
    }
    if (queue->back+1>=MAX_NUM-1){
        clear1(queue);  //初期化
    }
    queue->data[(queue->back+1)%MAX_NUM]=input;
    queue->back=(queue->back+1)%MAX_NUM;
    
}

int dequeue(QUEUE1 *queue){
    int ret=0;
    
    if((queue->back + 1) % MAX_NUM == queue->head){
        printf("キューが空です\n");
        printf("%d\n",queue->head);
        return -1;
    }
    
    ret = queue->data[queue->head];
    queue->head = (queue->head + 1) % MAX_NUM;
    printf("%d\n",queue->head);
    return ret;
    
}

int peekqueue(QUEUE1 *queue){
    int ret=0;
    ret = queue->data[queue->head];
    
    return ret;
    

    
}
int sizequeue(QUEUE1 *queue){
    int size;
    
    size=queue->back-queue->head+1;
    return size;
}

void printqueue(QUEUE1 *queue){
    int i;
    i=queue->back;
    while(i>=queue->head){
        
        printf("%d\n",queue->data[i]);
        i--;
    }

}

//それぞれの処理
void stack(void){
  STACK1 stack;
  int m,input,output,n;
  clear(&stack);
  n=10000;

    while(n!=0){
        
        printf("1:PUSH\n2:POP\n3:PEEK\n4:SIZE\n");
        scanf("%d", &m);

        switch(m){
            case 1:
                printf("PUSHする数は？");
                scanf("%d", &input);
                if (input == -1) {
                    n=0;
                    break;
                }
                printf("%dをPUSHします\n", input);
                push(&stack, input);
                break;
            case 2:
                printf("pop\n");
                output = pop(&stack);
                if(output != -1){
                    printf("%dをPOPしました\n", output);
                }
                break;
            case 4:
                
                printf("size\n");
                printf("%d\n",size(&stack));
                break;
            case 3:
                
                printf("peek\n");
                printf("%d\n",peek(&stack));
                break;
        }
    }
        
    
    printstack(&stack);
}

void queue(void){
    int m,input,output,i,n;
    QUEUE1 queue;
    n=10000;
    clear1(&queue);
    while(n!=0){
        
        printf("1:ENQUEUE\n2:DEQUEUE\n3:PEEK\n4:SIZE\n");
        scanf("%d", &m);
            switch(m){
                case 1:
                    printf("ENQUEUEする数は？");
                    scanf("%d", &input);
                    if(input==-1){
                        n=0;
                        break;
                    }
                    enqueue(&queue, input);
                    break;
                case 2:
                    printf("DEQUEUEします\n");
                    output = dequeue(&queue);
                    if(output != -1){
                        printf("%dをDEQUEUEしました\n", output);
                    }else{
                        printf("dequeue不可です\n");
                    }
                    break;
                case 3:
                    printf("peekします\n");
                    printf("%d\n",peekqueue(&queue));
                    break;
                case 4:
                    printf("sizeを表示します\n");
                    printf("%d\n",sizequeue(&queue));
                    break;
            }
            
           
        }
    printqueue(&queue);
}

int main(void){
    int a;
    printf("stackモード:0 queueモード:1\n");
    scanf("%d",&a);
    if (a==0){
        stack();
    }else if (a==1){
        queue();
    }else{
        printf("終了します\n");
        return 0;
    }
    
    return 0;     
}
