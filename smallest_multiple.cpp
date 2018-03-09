// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to x?

#include <iostream>
using namespace std;

int main()
{
    long long int num;      // num is the resultant number that is evenly divisible by 1 --> entry
    int entry,              // user entry, 1 --> entry
    count = 0;              // count counts each success (if num is divisble by 1, 2, 3..., add 1 to count each time)
    
    cout<<"This program finds the smallest positive number that is evenly divisible by all of the numbers from 1 to: ";
    cin>>entry;
    
    //
    // resultant num will never be less than (entry * (entry - 1)) since num must be divisible by (entry - 1)
    //
    num = entry * (entry - 1);
    
    //
    // count counts each success, loop ends when count == entry (meaning the first time a number is found that is divisible by 1 --> entry)
    //
    while (count != entry)
    {
        count = 0;          // reset to 0 each iteration since each iteration is a new test
        
        //
        // check is num is divisible by i (1 --> entry), if not, return that end is true
        //
        bool end = false;
        for (int i = 1; i <= entry && end == false; i++)
        {
            //
            // if num is divisible, add one to count
            //
            if (num % i == 0)
            {
                count++;
            }
            else
            {
                end = true;
            }
        }
        num++;              // check next number (1 above previous)
    }
    
    //
    // to account for final n++: num is correct before adding 1 the last time
    //
    cout<<endl<<(num - 1)<<endl<<endl;
    
    return 0;
}
