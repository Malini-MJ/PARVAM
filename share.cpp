#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int *regno = new int[n];

    cout << "Enter student reg no:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> regno[i];
    }

    int key;
    cout << "Enter the reg no to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (regno[i] == key) {
            cout << "Student " << key << " found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student " << key << " not found in the list" << endl;
    }

    delete[] regno;
    return 0;
}
