#include <iostream>
using namespace std;

class SelectionSort
{
private:
    void swp(int &val_1, int &val_2)
    {
        int tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
    void validIdx(int &start, int &end, int size)
    {
        if (start < 0)
            start = 0;
        else if (start > size)
            start = size;
        if (end < 0)
            end = 0;
        else if (end > size)
            end = size;
    }

public:
    void sort(int *arr, int size, int startidx, int endidx)
    {
        validIdx(startidx, endidx, size);

        bool sorted;
        for (int i = startidx; i < endidx - 1; i++)
        {
            sorted = 1;
            for (int j = startidx; j < endidx - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    swp(arr[j], arr[j + 1]), sorted = 0;
            }
            if (sorted)
                break;
        }
    }
};
int main()
{
    int size, start, end;
    int arr[] = {5, 2, 4, 3, 1};
    start = 0, size = 5, end = size;
    SelectionSort srt;
    srt.sort(arr, 5, 0, 5);
    for (auto it : arr)
        cout << it << ' ';
}