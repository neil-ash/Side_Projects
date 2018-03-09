
 // Find the sum of all primes from 1 - user-entered number


#include <iostream>
using namespace std;

int main()
{
    long long int num,
    half,
    endpt,
    sum = 0;
    
    bool prime;
    
    cout<<"This program finds the sum of all primes between 1 and an inputted number. Please input this number: ";
    cin>>endpt;
    
for (num = 1; num <= endpt; num++)
    {
        half = num/2;
        prime = true;
        
        // while loop won't run for num 1, 2, and 3 bc half == 0, 1, 1 for each, but its fine bc they're all prime
        while (half >= 2) // largest possible prime factor: half of number... smallest possible prime factor: 2
        {
            if (num % half == 0)
            {
                prime = false;
                
            }
            
            half --;
        }
        
        if (prime == true)
        {
            sum += num;
            
        }
    }
    
    sum = sum - 1; // to fix -- 1 not prime
    
    cout<<"\nThe sum of all primes between 1 and "<<endpt<<" is "<<sum<<".\n\n";
    
    return 0;
}
