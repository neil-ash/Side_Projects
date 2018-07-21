/*
 Goal: convert decimal number to binary, including fractional components
 
 Implementation:
 - first separate decimal number into whole and fractional components
 whole = static_cast<int>(dec);
 frac = dec - whole;
 - for whole number: complete process previously used
 - for fractional number: same setup of filling in array
 - loop multiplying by two each iteration
 - if resulting number is greater than 1, subtract 1 from it
 - put 1 in array
 - else:
 - put 0 in array
 - if resulting number is (number >= .95 && number <= 1), then stop loop
 
 NOTE: some finite numbers in fractional decimal will be infitinitely repeating in binary
 - solution: ask user for precision after decimal place
 */

#include <iostream>
using namespace std;

int main()
{
    long double dec,            // dec: user entry (input)
    frac;                       // frac: fractional part of input
    
    long long int whole;        // whole: whole number part of input
    
    //
    // Ask user for input
    //
    cout<<"Please enter a positive decimal number that you'd like to translate into binary: ";
    cin>> dec;
    
    
    
    
    ////////////////////////////////////////////////////////
    // INPUT VALIDATION
    ////////////////////////////////////////////////////////
    while (dec < 0)
    {
        cout<<"\nYou did not enter a positive decimal number. Please enter a positive decimal number that you'd like to translate into binary: ";
        cin>> dec;
    }
    
    //
    // break input into whole and fractional components
    //
    whole = static_cast<int>(dec);
    
    frac = dec - whole;
    
    //
    // determine if input is actually fractional -- if so, ask for number of outputted decimal places
    //
    int fsize = 0;
    
    if (dec != whole)
    {
        cout<<"\nPlease enter the number of decimal places you'd like in your binary ouput: ";
        cin>>fsize;
    }
    
    //
    // output message (same regardless of whole/fractional input)
    //
    cout<<"\nThe number "<<dec<<" in binary is: ";
    
    
    
    
    ////////////////////////////////////////////////////////
    // WHOLE NUMBER
    ////////////////////////////////////////////////////////
    
    long long int dwhole = whole;       // dummy variable dwhole to find array size
    short int wsize = 0;                // wsize: size of array for whole number
    
    //
    // special case: if whole number input is just 0
    //
    if (whole == 0)
    {
        cout<<"0";
    }
    
    //
    // to find arrary size: keep dividing dwhole by 2 until nothing left, each successful division means number of digits is one larger
    //
    while (dwhole > 0)
    {
        dwhole = dwhole/2;
        wsize ++;
    }
    
    int wbin[wsize];                    // declare array used to hold binary digits of previously determined size, NEED TO DECLARE HERE bc size is set just above
    
    //
    // to fill in binary array: fill in right -> left by starting count at size (furthest right point of array) and moving left (count--), bc MSB on "bottom"
    //
    for (int wcount = wsize; wcount > 0; wcount--)
    {
        wbin [wcount] = (whole % 2);   // whole decimal % 2 produces remainder of 1 or 0: correct binary digits
        whole = whole/2;               // divide whole decimal by 2 each iteration: method to translate to binary
    }
    
    //
    // to display whole part of array
    //
    for (int i = 1; i <= wsize; i++)  // to display array: array filled in 'backwards, display 'forwards' (i from 1 -> increasing up to size)
    {
        cout<<wbin[i];
    }
    
    
    
    ////////////////////////////////////////////////////////
    // FRACTION
    ////////////////////////////////////////////////////////
    
    //
    // array to hold binary digits of fractional component (size determined by user input)
    //
    int fbin[fsize];
    
    //
    // displays "." if there is a decimal component (displays after the whole component)
    //
    if (fsize != 0)
    {
        cout<<".";
    }
    
    //
    // to determine fractional component of binary number
    //
    for (int fcount = 0; fcount < fsize; fcount ++) // can fill in left -> right, since MSB on "top"
    {
        frac = frac * 2;                            // multiply by 2
        fbin[fcount] = static_cast<int>(frac);      // if (1 <= frac) (will always be less than 2) fill in 1, if (1 >= frac) fill in 0
        
        cout<<fbin[fcount];                         // output
        
        if (frac >= 1)
        {
            frac = frac - 1;
        }
    }
    
    cout<<"\n\n";
    
    return 0;
}


