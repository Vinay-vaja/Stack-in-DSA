#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// vector<int> nextgreaterEle(vector<int> nums)  //T.C.==O(n^2) ans //S.C.==O(n)
// { // here imagine array is double size hypothetically
//     // also find greater from cirular one
//     int n = nums.size();
//     vector<int> ans(n, -1);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < i + n - 1; j++)
//         {
//             int index = j % n;
//             if (nums[index] > nums[i])
//             {
//                 ans[i] = nums[index];
//                 break;
//             }
//         }
//     }
//     return ans;
// }


//optimal of NGE2
vector<int>nextgreaterEle(vector<int>&arr){
   int n=arr.size();
   vector<int>ans(n,-1);
   stack<int>st;
   for(int i=2*n-1;i>=0;i--){
    while(!st.empty() && st.top()<=arr[i%n]){
    st.pop();
   }
   if(i<n){
    ans[i]=st.empty()?-1:st.top();
   }
   st.push(arr[i%n]);
}
return ans;
}
int main()
{
    // vector<int> arr = {2,10,12,1,11};
    // vector<int> result = nextgreaterEle(arr);

    // cout << "Next Greater Elements: ";
    // for (int val : result)
    // {
    //     cout << val << " ";
    // }
    // cout << endl;  
    
    vector<int>arr={12,13,3,10,4,5,6};
    vector<int>ans=nextgreaterEle(arr);
    cout<<"Next greater elements are:";
    for(auto val:ans){
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}