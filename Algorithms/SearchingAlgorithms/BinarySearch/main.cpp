#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class BinarySearch
{
public:
    int search(vector<int> vt, int target)
    {
        int start = 0, end = vt.size() - 1, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (vt[mid] < target)
            {
                start = mid + 1;
            }
            else if (vt[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {2, 3, 3, 4, 1};
    int target = 3;
    sort(nums.begin(), nums.end());
    BinarySearch s;
    cout << s.search(nums, target);
}