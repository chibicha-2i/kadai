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
   for (i=0;i<=stack->back;i++){
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
    queue->data[(queue->back+1)%MAX_NUM]=input;
    queue->back=(queue->back+1)%MAX_NUM;
}

int dequeue(QUEUE1 *queue){
    int ret=0;
    
    if((queue->back + 1) % MAX_NUM == queue->head){
        printf("キューが空です\n");
        return -1;
    }
    ret = queue->data[queue->head];
    queue->head = (queue->head + 1) % MAX_NUM;

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
  int m,input,output;
  clear(&stack);

    while(1){
        
        printf("1:PUSH\n2:POP\n3:PEEK\n4:SIZE\n");
        scanf("%d", &m);

        
        if(m == 1){
            printf("PUSHする数は？");
            scanf("%d", &input);
            if (input == -1) {
               break;
            }
            printf("%dをPUSHします\n", input);
            push(&stack, input);
            
        }else if(m == 2){
            printf("pop\n");
            output = pop(&stack);
            if(output != -1){
                printf("%dをPOPしました\n", output);
            }
        }  else if(m==4) {
            
            printf("size\n");
            printf("%d\n",size(&stack));
        }else if(m==3) {
            
            printf("peek\n");
            printf("%d\n",peek(&stack));
        }
    }
printstack(&stack);
}

void queue(void){
    int m,input,output,i;
    QUEUE1 queue;

    clear1(&queue);
    while(1){
        
        printf("1:ENQUEUE\n2:DEQUEUE\n3:PEEK\n4:SIZE\n");
        scanf("%d", &m);





    if(m == 1){
                printf("ENQUEUEする数は？");
                scanf("%d", &input);
                if(input==-1){
                    break;
                }
                
                enqueue(&queue, input);
            }else if(m == 2){
                printf("DEQUEUEします\n");
                output = dequeue(&queue);
                if(output != -1){
                    printf("%dをDEQUEUEしました\n", output);
                }else{
                    printf("dequeue不可です\n");
                }
            }
            else if(m == 3){
                printf("peekします\n");
                printf("%d\n",peekqueue(&queue));
                }
            else if(m==4){
                printf("sizeを表示します\n");
                printf("%d\n",sizequeue(&queue));
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
