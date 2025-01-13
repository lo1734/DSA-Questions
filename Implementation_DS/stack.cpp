
#include <iostream>
using namespace std;

class stack {
    private:
        int *arr;
        int top;
        int capacity;
    public:
        stack(int size){
            capacity=size;
            top=-1;
            arr=new int[capacity];
        }
        void push(int val){
            if(top==capacity-1){
                return ;
            }
            arr[++top]=val;
        }
        void pop(){
            if(top==-1){
                return ;
            }
            top--;
        }
        int Top(){
            if(isEmpty()){
                return -1;
            }
            return arr[top];
        }
        int size(){
            return top+1;
        }
        bool isEmpty(){
            return top==-1;
        }
};
int main()
{
    std::cout<<"Hello World"<<endl;
    stack st(5);
    st.push(25);
    st.push(34);
    // st.pop();
    st.pop();
    cout<<st.Top()<<endl<<st.isEmpty()<<endl;

    return 0;
}
