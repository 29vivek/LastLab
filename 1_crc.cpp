#include <iostream>
#include <cstring>

using namespace std;

int crc(string in, string key, string &sent, int len, int mode)
{
    string out;
    out = in;
    
    //Append 0's at the end of data
    //Mode 1 = Sender side

    if (mode==1) {
        for (int i = 1; i < key.size(); i++)
            out.append("0");
    }
    
    /* Perform XOR on the msg with the selected key */
    for (int i = 0; i < len; i++) {
        //cout << out << endl;
        if (out[i] == '1') {
            for (int j = 0; j < key.size(); j++) {
                if (out[i + j] == key[j])
                    out[i + j] = '0';
                else
                    out[i + j] = '1';
            }
            
        }
    }
    
    //Reminder of XOR operation is appended to data
    if(mode==1) 
        sent = in+out.substr(in.size(),key.size()-1);
        
    //Mode 2 = Receiver side
    if(mode==2)
    {
       // cout << out << endl;
        for (int i = 0; i < out.size(); i++)
            if (out[i] == '1') //Error in transmission
                return 0;
        cout << "Original Message: " << in.substr(0,in.size()-key.size()+1);
    }
    
    return 1;
}

int main()
{
    string data,recv,key,sent;
    int len;

    
    //Sender
    cout << "Enter the input message in binary"<< endl;
    cin >> data;
    len = data.size();
    cout << "Enter the key in binary"<< endl;
    cin>>key;
    crc(data, key, sent, len, 1);
    cout << "The transmitted message is: " << sent << endl;
    
    //Receiver
    cout << "Enter the recevied message in binary" << endl;
    cin >> recv;
    if (crc(recv, key, sent, len, 2))
        cout << "\nNo error in data" << endl;
    else
        cout << "\nError in data transmission has occurred" << endl;

    return 0;
} 
