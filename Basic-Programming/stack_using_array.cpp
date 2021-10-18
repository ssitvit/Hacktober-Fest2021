#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int nextIndex;
    int capacity;

    public:
        Stack(){
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
        }
        Stack(int cap){
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
        }

        /// return no. of elements
        int size(){
            return nextIndex;
        }

        bool isEmpty(){
            if(nextIndex==0){
                return true;
            }
            else{
                return false;
            }
        }

        void push(int ele){
            if(nextIndex==capacity){
                cout<<"Stack Full"<<endl;
                return;
            }
            arr[nextIndex]=ele;
            nextIndex++;

        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return;
            }
            nextIndex--;
        }

        int top(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[nextIndex-1];
        }
};

int main(){
    Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

    /// another stack with pattern 1 4 9 16..
    Stack s2(10);
    for(int i=1;i<=10;i++){
        s2.push(i);
    }
    while(!s2.isEmpty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }
    cout<<s2.size()<<endl;
    return 0;
}
