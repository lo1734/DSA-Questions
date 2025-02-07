#include <iostream>
#include<stack>
using namespace std;
class Queue{
    private:
        stack<int> st1,st2;
    public:
        void enqueue(int x){
            st1.push(x);
        }
        int dequeue(){
            if(st2.empty()){
                if(st1.empty()){
                    return -1;
                }
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            int k=st2.top();
            st2.pop();
            return k;
        }
        int front(){
            if(st2.empty()){
                if(st1.empty()){
                    return -1;
                }
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            return st2.top();
        }
        int rear(){
            if(st1.empty()){
                if(st2.empty()){
                    return -1;
                }
                while(!st1.empty()){
                    st2.push(st1.top());
                    st2.pop();
                }
            }
            return st1.top();
        }
        bool isEmpty(){
            return st1.empty()&&st2.empty();
        }
};
int main()
{
    Queue q;
    q.enqueue(200);
    q.enqueue(202);
    q.enqueue(206);
    q.dequeue();
    cout<<q.front()<<endl;
    q.enqueue(100);
    cout<<q.rear()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}
