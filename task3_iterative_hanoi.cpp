#include <iostream>
using namespace std;

const int MAX = 100;

struct Rod
{
    int disks[MAX];
    int top;

    Rod() : top(-1) {}

    bool isEmpty() { return top == -1; }

    void push(int disk) { disks[++top] = disk;}

    int pop() { return disks[top--]; }

    int peek() { return disks[top]; }
};

void moveDisk(Rod &source, Rod &destination,
              char sourceName, char destinationName)
{
    if (source.isEmpty())
    {
        int disk = destination.pop();
        source.push(disk);

        cout << "Move disk " << disk << " from "
             << destinationName << " to " << sourceName << '\n';
    }
    else if (destination.isEmpty() ||
             source.peek() < destination.peek())
    {
        int disk = source.pop();
        destination.push(disk);

        cout << "Move disk " << disk << " from "
             << sourceName << " to " << destinationName << '\n';
    }
    else
    {
        int disk = destination.pop();
        source.push(disk);

        cout << "Move disk " << disk << " from "
             << destinationName << " to " << sourceName << '\n';
    }
}

int main()
{
    int n;

    cout << "Enter number of disks (1-" << MAX << "): ";
    cin >> n;

    if (n < 1 || n > MAX)
    {
        cout << "Invalid number of disks\n";
        return 0;
    }

    Rod rods[3];
    Rod &source = rods[0];

    for (int disk = n; disk >= 1; disk--)
        source.push(disk);

    unsigned long long totalMoves = (1ULL << n) - 1;

    cout << "\nMinimum number of moves: " << totalMoves << '\n';

    // For even disk counts, interchange the auxiliary and destination roles
    int auxiliaryIndex = (n % 2 == 0) ? 2 : 1;
    int destinationIndex = (n % 2 == 0) ? 1 : 2;

    Rod &aux = rods[auxiliaryIndex];
    Rod &dest = rods[destinationIndex];

    char auxName = (n % 2 == 0) ? 'C' : 'B';
    char destName = (n % 2 == 0) ? 'B' : 'C';

    for (unsigned long long i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
            moveDisk(source, dest, 'A', destName);
        else if (i % 3 == 2)
            moveDisk(source, aux, 'A', auxName);
        else
            moveDisk(aux, dest, auxName, destName);
    }

    return 0;
}