// the concept of sumof sub array minumum
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int SumOfSubArrayMin(vector<int> &arr)
{
    int n = arr.size();   //brute force and T.C.==O(n^2) and S.C.==O(n)
    int sum = 0;
    int mini = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = arr[i];
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            sum += mini;
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};

    cout << "The minimum subarray sum is :" << SumOfSubArrayMin(arr) << endl;

    return 0;
}