#include <iostream>
#include <vector>
using namespace std;
class LinearSearch
{
public:
    int search(vector<int> vt, int target)
    {
        for (int i = 0; i < vt.size(); i++)
        {
            if (vt[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {2, 3, 3, 4, 1};
    int target = 3;
    LinearSearch s;
    cout << s.search(nums, target);
}