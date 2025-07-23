#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> FindNse(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> FindPse(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

int SumOfSubArrayMin(vector<int> &arr)
{
    int n = arr.size();
    int total = 0;
    vector<int> nse = FindNse(arr);
    vector<int> pse = FindPse(arr);

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = total + (left * right * arr[i]);
    }
    return total;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int result = SumOfSubArrayMin(arr);
    cout << "Sum of Subarray Minimums = " << result << endl;

    return 0;
}
