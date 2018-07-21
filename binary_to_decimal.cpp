/*
 Purpose: convert from binary number to decimal number, work with both fractional and whole binary numbers
 
 Procedure:
 - ask user to enter binary number, save as STRING
 - will treat string as array of characters, in this case numbers
 
 - find length of string
 
 - validate input: use for loop (i = 0 to (length - 1))
 - valid if only 1s, 0s, and an optional decimal place (only one period)
 - ask user to re-enter if invalid
 - use bool variable, if statment outside of loop ??
 - otherwise, will ask user to re-enter multiple times ??
 - also find where decimal (dot) is (dotspot variable)
 
 
 - create decimal number using whole number part of binary number first
 - for loop: from j = 0 to (length - 1) or to where decimal is
 - add 2^(necessary power) to decimal
 - if number is entirely whole, just 2^((length - i) - 1)
 - if number has fractional component, 2^(dotspot - i) ??
 
 - add fractional component
 - similar for loop as above
 - OR use one loop for both?
 - add 2^(-(i - dotspot)) to decimal number
 - loop terminates when reaches i == length - 1 (end of number)
 
 - display the value of dec
 
 
 
 QUESTION: use one or two for loops -- whole and fractional part of binary number (to compute decimal number)
 - one loop: use if statments
 - if before or after dotspot
 - two loops: one for whole part only, one for fractional part only
 ANSWER: ONE LOOP
 
 */


#include <iostream>
#include <string>   // save user entered binary number as string
#include <cmath>    // to use power function
using namespace std;

int main()
{
    string bin;     // user-entered binary number
    
    long double dec = 0;     // decimal number, starts at 0
    
    bool valid = false;  // validity check, start at false in order to use loop
    
    long int length;     // length of string array, long to remove warning
    
    int dotspot,        // location of period in array NEED TO INITIALIZE??
    dotcount;       // number of periods
    
    cout << "Please enter the binary number you would like to convert to decimal: ";
    cin >> bin;
    
    length = bin.length();  // length of first entry
    
    ///////////////////////////////////////////////////////////////////////////
    // VALIDITY CHECK
    ///////////////////////////////////////////////////////////////////////////
    
    while (valid == false)  // while number entered is not valid, run the loop
    {
        valid = true;       // start at true, must be proven false
        
        dotcount = 0;
        
        for (int i = 0; i < length; i++)
        {
            if (bin[i] == '.')
            {
                dotspot = i;
                
                dotcount ++;
            }
            if ((bin[i] != '1' && bin[i] != '0' && bin[i] != '.') || dotcount > 1)
            {
                valid = false;
            }
        }
        if (valid == false)
        {
            cout << "Please re-enter a valid binary number: ";
            cin >> bin;
            
            length = bin.length();  // NECESSARY: re-assigns to proper length if re-entry needed
        }
    }
    
    ///////////////////////////////////////////////////////////////////////////
    // TO COMPUTE DECIMAL
    ///////////////////////////////////////////////////////////////////////////
    
    for (int j = 0; j < length; j++)
    {
        if (dotcount == 0)      // if binary number is itself whole
        {
            if (bin[j] == '1')
            {
                dec = dec + pow(2, ((length - 1) - j));
            }
        }
        else if (dotcount == 1)     // if binary number contains a decimal
        {
            if (j < dotspot)        // whole component of binary number
            {
                if (bin[j] == '1')
                {
                    dec = dec + pow(2, ((dotspot - 1) - j));
                }
            }
            else if (j > dotspot)   // fractional component of binary number
            {
                if (bin[j] == '1')
                {
                    dec = dec + pow(2, (-(j - dotspot)));
                }
            }
        }
    }
    
    cout<<"\n"<<bin<<" in decimal is "<<dec<<"\n\n";
    
    return 0;
}


