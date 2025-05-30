#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int *regno = new int[n];
    string *names = new string[n];
    string *mails = new string[n];

    cout << "Enter student reg no:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> regno[i];
    }
    cout << "Enter student names:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> names[i];
    }
cout << "Enter student mails:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> mails[i];
    }




    
    char choice;
    do{

    int key;
    cout << "Enter the reg no to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (regno[i] == key) {
            cout << "Student " << key << " found at position " << i + 1 << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student " << key << " not found in the list" << endl;
    }
    cout<<"do you want to continue y/n"<< endl;
    cin>>choice;
}
while (choice == 'y' | choice == 'Y' );



    delete[] regno;
    return 0;
}
