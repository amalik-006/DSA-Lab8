#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    // Dynamic 2d array
    int ** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int [n];
    }

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int row = 0;

        for (int i = 1; i < n; i++)
            if (a[i][mid] > a[row][mid])
                row = i;

        if (mid > 0 && a[row][mid - 1] > a[row][mid])
            right = mid - 1;
        else if (mid < n - 1 && a[row][mid + 1] > a[row][mid])
            left = mid + 1;
        else
        {
            cout << "Peak element: " << a[row][mid] << endl;
            cout << "Position: (" << row << ", " << mid << ")" << endl;

            for (int i = 0;i < n; i++) delete [] a[i];
            delete [] a;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) delete [] a[i];
    delete [] a;
    return 0;
}