#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int cntMaxiWater(vector<int> &arr)
{
    int n = arr.size();
    int Mwater = 0;
    int height = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int width = j - i;
            height = min(arr[i], arr[j]);
            int area = width * height;
            Mwater = max(Mwater, area);
        }
    }
    return Mwater;
}
int main()
{
      vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Water: " << cntMaxiWater(heights) << endl;
    return 0;
    return 0;
}