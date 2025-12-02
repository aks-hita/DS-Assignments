#include<iostream>
using namespace std;
#define MAXLEN 10
class queue {
    int q[MAXLEN];
    int front,rear;
    public:
    void init(){
        front=rear=-1;
    }
    int isEmpty(){
        if(front==-1||front>rear)
            return 1;
        else
            return 0;
        }
    int isFull(){
        if(rear==MAXLEN-1)
            return 1;
        else
            return 0;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Empty Queue."<<endl;
            return -1;
        }
        else
            return q[front];
    }
    void enqueue(int n){
        if(isFull()){
           cout<<"Error: Overflow."<<endl;
     }
        else if(isEmpty()){
            front=rear=0;
            q[front]=n;
        }
        else{
            rear++;
            q[rear]=n;
        }
    }
    int dequeue(){
        int val=-1;
        if(isEmpty()){
            cout<<"Error: Underflow.";
        }
        else{
            val=peek();
            front++;
        }
        return val;
    }
    void display(){
        cout<<"The Queue: ";
        for(int i=front;i<rear+1;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int a,opt;
    queue q1;
    q1.init();
    do{
        cout<<endl<<"Choose an option: "<<endl<<"1. enqueue\n2. dequeue\n3. isEmpty\n4. isFull\n5. display\n6. peek\n7. exit ";
        cin>>opt;
        switch (opt){
        case 1:{
            cout<<"Enter a number ";
            int num;
            cin>>num;
            q1.enqueue(num);
            break; }
        case 2:{
            int val=q1.dequeue();
            if(val!=-1){
                cout<<"The dequeued value is "<<val<<endl;
            }
            break;}
        case 3:{
            if(q1.isEmpty()){
                cout<<"The queue is empty.";
            }
            else{
                cout<<"The queue is not empty.";
            }
            break;}
        case 4:{
        if(q1.isFull()){
                cout<<"The queue is full.";
            }
            else{
                cout<<"The queue is not full.";
            }
            break;}
        case 5:{
            q1.display();
            break;}
        case 6:{
            int val1=q1.peek();
            if(val1!=-1){
                cout<<"The front value is "<<val1<<endl;
                }
            break;}
        case 7:{
            cout<<"Thankyou!";
            break;}
        }
    }
    while(opt!=7);
    return 0;
}
