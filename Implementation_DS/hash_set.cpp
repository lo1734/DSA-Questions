#include <iostream>
#include <list>
using namespace std;

class hashset{
    private:
        int capacity;
        list<int>* table;
        
        int hFun(int key){
            return key%capacity;
        }
    public:
        hashset(int size){
            capacity=size;
            table=new list<int>[capacity];
        }
        void insert(int key){
            int idx=hFun(key);
            for(int val:table[idx]){
                if(val==key) return ;
            }
            table[idx].push_back(key);
        }
        void removeItem(int key){
            int idx=hFun(key);
            table[idx].remove(key);
        }
        bool cointains(int key){
            int idx=hFun(key);
            for(int val:table[idx]){
                if(val==key) return 1;
            }
            return 0;
        }
        void display(){
            for(int i=0;i<capacity;i++){
                for(auto it:table[i]){
                    cout<< it<<endl;
                }
            }
            cout<<endl;
        }
};
int main()
{
    std::cout<<"Hello World"<<endl;
    hashset hst(100);
    hst.insert(10);
    hst.insert(20);
    hst.insert(19);
    hst.insert(34);
    hst.insert(21);
    cout<<hst.cointains(21)<<endl;
    hst.removeItem(10);
    hst.display();
    return 0;
}
