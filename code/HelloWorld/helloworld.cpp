#include <iostream>
#include <vector>
#include <string>

using namespace std;

void convert1(int &a, int b);

int main()
{

    vector<string> msg {"Hello", "C++", "World", "from", "K62 TDH!"};

    for (const string& word : msg)
    {
        cout << word << " "; 
    }
    cout << endl;

    int x = 3, y = 1;
    convert1 (x, y);
    cout << x << y;
    
}

void convert1(int &a, int b)
{
    a = b++;
}