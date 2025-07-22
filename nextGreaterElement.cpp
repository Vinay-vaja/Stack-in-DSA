#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

// int nge(vector<int>&arr){
//      int n=arr.size();
//      vector<int>NGE(n,0);
//      for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>arr[i]){
//                 NGE[i]=arr[j];
//                 break;
//             }
//             // else{
//             //     NGE[i]=-1;
//             // }
//         }
//      }
//      return -1;
// }

// optimal and better soln

vector<int> nextGreaterEle(vector<int> &arr)
{
    // answer storing
    int n = arr.size();
    vector<int> ans(n, -1);
    //
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
       st.push(arr[i]);
        //  ans[i] = st.empty()?-1:arr[i];
    }
    return ans;
}

int main()
{

    // s.push(15);
    // s.push(12);
    // s.push(8);
    // s.push(20);
    // s.push(-1);
    // s.pop();
    vector<int> arr = {6, 0, 8, 1, 3};
    vector<int> result = nextGreaterEle(arr);

    cout << "Next Greater Elements: ";
    for (auto val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}