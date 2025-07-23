#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    vector<int> prevSmaller(n), nextSmaller(n);
    vector<int> prevGreater(n), nextGreater(n);

    stack<int> st;

    // Previous smaller
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
        prevSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next smaller
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        nextSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Previous greater
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
        prevGreater[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next greater
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        nextGreater[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long sumMax = 0, sumMin = 0;

    for (int i = 0; i < n; ++i) {
        long long maxCount = (i - prevGreater[i]) * (nextGreater[i] - i);
        long long minCount = (i - prevSmaller[i]) * (nextSmaller[i] - i);
        sumMax += maxCount * nums[i];
        sumMin += minCount * nums[i];
    }

    return sumMax - sumMin;
}

int main() {
    vector<int> nums = { 1,4,3,2};
    cout << "Sum of Subarray Ranges: " << subArrayRanges(nums) << endl;
    return 0;
}
