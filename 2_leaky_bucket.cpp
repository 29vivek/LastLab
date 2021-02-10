#include <iostream>
using namespace std;

int main()
{
    int incoming, outgoing, buck_size, n, store = 0;

    cout << "Enter the details: " << endl;
    cout << "Bucket size : ";
    cin >> buck_size;
    cout << "Outgoing rate : ";
    cin >> outgoing;
    cout << "No of Inputs : ";
    cin >> n;

    while (n--)
    {
        cout << "\nEnter the incoming packet size : ";
        cin >> incoming;
        cout << "Incoming packet size " << incoming << endl;

        if (incoming <= (buck_size - store))
        {
            store += incoming;
            cout << "Bucket buffer size " << store << " out of " << buck_size << endl;
        }
        else
        {
            cout << "Dropped " << incoming - (buck_size - store) << " packets\n";
            store = buck_size;
            cout << "Bucket buffer size " << store << " out of " << buck_size << endl;
        }
        store = store - outgoing;

        if (store < 0)
        {
            store = 0;
        }

        cout << "After outgoing, " << store << " packets left in bucket\n";
    }
    return 0;
}
