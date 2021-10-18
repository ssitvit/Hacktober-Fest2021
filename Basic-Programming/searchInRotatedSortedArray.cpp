#include <bits/stdc++.h>
using namespace std;

int search(vector<int> v, int target)
{
    int s = v[0];
    int e = v.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (v[mid] == target)
        {
            return mid;
        }

        if (v[mid] >= v[s]) // case 1
        {
            if (target >= v[s] && target <= v[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else // case 2
        {
            if (target >= v[mid] && target <= v[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    // if elemet not found
    return -1;
}
int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    int target = 0;

    cout << search(v, target);

    return 0;
}