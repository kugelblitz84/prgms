#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    char process_name;
    int arrival_time;
    int priority;
    int cpu1,io,cpu2;
    int completion_time = -1;
    bool qued = false;
} process;

process *process_q[100];
int q_iterator = -1;

void init(){
    for(int i = 0;i<100;i++){
        process_q[i] = (process *)malloc(sizeof(process));
    }
}
void clr(){
    for(int i = 0;i < 100; i++){
        free(process_q[i]);
    }
}
void heapify_process_que(int root){
    if(root == q_iterator) return ;
    int smallest_node = root;
    int left_child = root*2 + 1;
    int right_child = root*2 + 2;
    int root_arrival_time = process_q[root]->arrival_time;
    if(left_child < size && process_q[root*2 + 1]->priority < process_q[root]->priority){
        smallest_node = left_child;
    }

    if(right_child < size  && process_q[root*2 + 2]->priority < process_q[root]->priority){
        smallest_node = right_child;
    }
    if(smallest_node != root){
        process *temp = process_q[root];
        process_q[root] = process_q[smallest_node];
        process_q[smallest_node] = temp;
        heapify_process_que(smallest_node);
    }
}

void heapify_process_que_bottom_up(int child){
    if(child == 0) return;
    int root = (child-1) >> 1;
    if((process_q[child]->arrival_time < process_q[root]->arrival_time || (process_q[child]->arrival_time == process_q[root]->arrival_time && process_q[child]->priority < process_q[root]->priority))
    {
        process* temp = process_q[root];
        process_q[root] = process_q[child];
        process_q[child] = temp;
        heapify_process_que_bottom_up(root);
    }
}

void pop_q(){
    process_q[0]->qued = false;
    process_q[0] = process_q[q_iterator--];
    heapify_process_que(0);
}
void insert_process(process *n){
    n->qued = true;
    process_q[++q_iterator] = n;
    heapify_process_que_bottom_up(q_iterator);
}

int main(){
    init();
    int n;
    printf("Enter the number of precess: ");
    scanf("%d",&n);
    process process_no[100];
    system("cls");
    printf("Enter %d process(es):\n",n);
    for(int i = 0;i < n;i++){
        printf("Enter process %d\n",i+1);
        printf("Process name: ");
        scanf(" %s",&process_no[i].process_name);
        printf("arrival_time : ");
        scanf("%d",&process_no[i].arrival_time);
        printf("set priority: ");
        scanf("%d",&process_no[i].priority);
        printf("Enter cpu1,I/O and cpu2 : ");
        scanf("%d %d %d",&process_no[i].cpu1,&process_no[i].io,&process_no[i].cpu2);
    }
    for(int time = 0;time < 1000;time++){
        for(int i = 0;i < n;i++){
            if(time == process_no[i].arrival_time) insert_process(&process_no[i]);
            else if(time > process_no[i].arrival_time){
                if(!process_no[i].qued) {
                    if(process_no[i].io != 0) process_no[i].io--;
                    else if(process_no[i].completion_time != -1) insert_process(&process_no[i]);
                }
            }      
        }
        if(q_iterator > 0)
            if(process_q[0] -> cpu1 != 0) process_q[0] -> cpu1--;
            else if(process_q[0] -> io != 0){
                process_q[0] -> io--;
                pop_q();
            }else if(process_q[0] -> cpu2 != 0){
                process_q[0] -> cpu2--;
            }else process_q[0] -> completion_time = time,pop_q();
    }
    printf("Process_name\tCompletion_time\n");
    for(int i = 0;i < n;i++) {
        printf("%s\t%d\n",process_no[i].process_name,process_no[i].completion_time);
    }
    
return 0;
}
