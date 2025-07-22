#include <iostream>
#include <stack>
#include <vector>
// the concept of prevsmaller element
//  nearest smaller element same que
using namespace std;

// brute force using 2 loop and simple traversal
vector<int> prevSele(vector<int> &arr)
{ // brute force approch T.C.==O(n^2)  && S.C.==O(n)
    int n = arr.size();
    vector<int> nse(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                nse[i] = arr[j];
                break;
            }
        }
    }
    return nse;
}
vector<int> PSE(vector<int> &nums)  //better approch for PSE
{
    int n = nums.size();
    // left to right traversal using stack
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = prevSele(arr);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}