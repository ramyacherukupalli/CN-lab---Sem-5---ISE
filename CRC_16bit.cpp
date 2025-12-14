#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// XOR operation for modulo-2 division
void findxor(string& s, string& divisor, int pos)
{
    for (int i = 0; i < divisor.length(); i++)
    {
        s[pos + i] = (s[pos + i] == divisor[i]) ? '0' : '1';
    }
}

// CRC computation
string crc(string s, string divisor)
{
    int r = divisor.length() - 1;   // CRC length
    string temp = s + string(r, '0');  // append zeros

    for (int i = 0; i <= temp.length() - divisor.length(); i++)
    {
        if (temp[i] == '1')
            findxor(temp, divisor, i);
    }

    return temp.substr(temp.length() - r); // remainder
}

int main()
{
    string dataword, divisor;

    // ---------------- SENDER SIDE ----------------
    cout << "----- SENDER SIDE -----\n";
    cout << "Enter Dataword: ";
    cin >> dataword;

    cout << "Enter Divisor (Generator): ";
    cin >> divisor;

    int crc_len = divisor.length() - 1;

    cout << "\nSender Information:\n";
    cout << "Original Dataword        : " << dataword << endl;
    cout << "Generated Divisor        : " << divisor << endl;
    cout << "CRC Length               : " << crc_len << " bits" << endl;

    string appended_data = dataword + string(crc_len, '0');
    cout << "Appended Dataword        : " << appended_data << endl;

    string remainder = crc(dataword, divisor);
    cout << "CRC Remainder            : " << remainder << endl;

    string codeword = dataword + remainder;
    cout << "Final Codeword Sent      : " << codeword << endl;

    // ---------------- RECEIVER SIDE ----------------
    cout << "\n----- RECEIVER SIDE -----\n";
    string received_codeword;
    cout << "Enter Received Codeword: ";
    cin >> received_codeword;

    cout << "\nReceiver Information:\n";
    cout << "Received Codeword        : " << received_codeword << endl;
    cout << "Using Same Divisor       : " << divisor << endl;

    string check = crc(received_codeword, divisor);
    cout << "Remainder After Division : " << check << endl;

    bool error = false;
    for (char c : check)
    {
        if (c == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Status                   : ERROR DETECTED ❌\n";
    else
        cout << "Status                   : NO ERROR DETECTED ✅\n";

    return 0;
}
