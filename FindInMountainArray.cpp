#include <iostream>
#include <vector>

using namespace std;

class MountainArray
{
private:
    vector<int> arrayData;

public:
    MountainArray(vector<int> data)
    {
        arrayData = data;
    }

    int get(int index)
    {
        return arrayData[index];
    }

    int length()
    {
        return arrayData.size();
    }
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int arrayLength = mountainArr.length();
        int peakIndex = findPeak(mountainArr, arrayLength);

        int leftSearchResult = binarySearchAscending(mountainArr, target, 0, peakIndex);
        if (leftSearchResult != -1)
        {
            return leftSearchResult;
        }

        return binarySearchDescending(mountainArr, target, peakIndex + 1, arrayLength - 1);
    }

private:
    int findPeak(MountainArray &mountainArr, int arrayLength)
    {
        int leftBoundary = 0;
        int rightBoundary = arrayLength - 1;

        while (leftBoundary < rightBoundary)
        {
            int midpoint = leftBoundary + (rightBoundary - leftBoundary) / 2;
            if (mountainArr.get(midpoint) < mountainArr.get(midpoint + 1))
            {
                leftBoundary = midpoint + 1;
            }
            else
            {
                rightBoundary = midpoint;
            }
        }

        return leftBoundary;
    }

    int binarySearchAscending(MountainArray &mountainArr, int target, int leftBoundary, int rightBoundary)
    {
        while (leftBoundary <= rightBoundary)
        {
            int midpoint = leftBoundary + (rightBoundary - leftBoundary) / 2;
            int midpointValue = mountainArr.get(midpoint);

            if (midpointValue == target)
            {
                return midpoint;
            }
            else if (midpointValue < target)
            {
                leftBoundary = midpoint + 1;
            }
            else
            {
                rightBoundary = midpoint - 1;
            }
        }
        return -1;
    }

    int binarySearchDescending(MountainArray &mountainArr, int target, int leftBoundary, int rightBoundary)
    {
        while (leftBoundary <= rightBoundary)
        {
            int midpoint = leftBoundary + (rightBoundary - leftBoundary) / 2;
            int midpointValue = mountainArr.get(midpoint);

            if (midpointValue == target)
            {
                return midpoint;
            }
            else if (midpointValue > target)
            {
                leftBoundary = midpoint + 1;
            }
            else
            {
                rightBoundary = midpoint - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solver;

    vector<int> data1 = {1, 2, 3, 4, 5, 3, 1};
    MountainArray mountain1(data1);
    cout << solver.findInMountainArray(3, mountain1) << "\n";

    vector<int> data2 = {0, 1, 2, 4, 2, 1};
    MountainArray mountain2(data2);
    cout << solver.findInMountainArray(3, mountain2) << "\n";

    vector<int> data3 = {1, 5, 2};
    MountainArray mountain3(data3);
    cout << solver.findInMountainArray(2, mountain3) << "\n";

    vector<int> data4 = {0, 5, 3, 1};
    MountainArray mountain4(data4);
    cout << solver.findInMountainArray(1, mountain4) << "\n";

    vector<int> data5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    MountainArray mountain5(data5);
    cout << solver.findInMountainArray(10, mountain5) << "\n";

    return 0;
}