// simple fibonacci sequence

#include <iostream>
using namespace std;

int main()
{
    long long int a = 0, b = 1, count = 0, end;
    
    cout<<"Enter the number of terms of the fibonacci sequence you would like display: ";
    cin>>end;
    
    while (count < end)
    {
        a = a + b;      // pattern: a,b,a,b,a,b...
        cout<<endl<<a;
        
        b = b + a;
        cout<<endl<<b;
        
        count ++;
    }
    
    cout<<endl;
    
    return 0;
}
