#include <iostream>
#include<list>

using namespace std;
class Stack
{
    list<int>ll;

public:
  void push(int val){
    ll.push_front(val);
  }
  void pop(){
    ll.pop_front();
  }
  int top(){
    return ll.front();
}
  bool empty(){
    return ll.size()==0;
  }
    
};

int main()
{
   
    Stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.push(6); //6,5,4,3,2

    while (!st.empty())
    {
       cout<<st.top()<<" ";
       st.pop(); 
    }
    
        return 0;
}