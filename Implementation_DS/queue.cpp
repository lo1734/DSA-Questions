#include <iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int front;
        int rear;
        int count;
        int capacity;
    public:
        Queue(int size){
            capacity=size;
            arr=new int[capacity];
            front=0;
            rear=-1;
            count=0;
        }
        void enqueue(int val){
            if(isFull()){
                return ;
            }
            rear=(rear+1);
            arr[rear]=val;
            count++;
        }
        void dequeue(){
            if(isEmpty()){
                return;
            }
            front=(front+1);
            count--;
        }
        bool isFull(){
            return count==capacity;
        }
        bool isEmpty(){
            return count==0;
        }
        int Front(){
            if(isEmpty()){
                return -1;
            }
            return arr[front];
        }
        int Rear(){
            if(isEmpty()){
                return -1;
            }
            return arr[rear];
        }
        int size(){
            return count;
        }
};

int main()
{
    std::cout<<"Hello World"<<endl;
    Queue q(100);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(10);
    q.enqueue(120);
    q.enqueue(330);
    q.enqueue(440);
    q.enqueue(560);
    q.enqueue(100);
    cout<<"Front Element: "<<q.Front()<<endl;
    cout<<"Rear Element: "<<q.Rear()<<endl;
    cout<<"Total Elements: "<<q.size()<<endl;
    return 0;
}
