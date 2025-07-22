#include <iostream>

using namespace std;
class Stack
{
public:
    int val;
    int *arr;
    int top;
    Stack()
    { // intialize the val
        top = -1;
        int size = 1000;
        arr = new int[size];
    }
    void push(int val)
    {
        top++;
        arr[top] = val;
    }
    int pop()
    {
        int temp = arr[top];
        top--;
        return temp;
    }
    int toppest()
    {
        return arr[top];
    }
    int size(){
        return top+1;
    }
   
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.push(4);
    st.pop();
    st.push(5); //5,2,1

    while(st.size()>0){
        cout<<st.toppest()<<" ";
        st.pop();

    }
    
    return 0;
}