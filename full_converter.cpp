/*
 
 */

#include <iostream>
#include <stdio.h>
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
    dotcount,       // number of periods
    x;              // base of number
    
    cout << "Please enter the number you would like to convert to decimal: ";
    cin >> bin;
    
    cout << "\nPlease enter the base of this number: ";
    cin >> x;
    
    length = bin.length();  // length of first entry
    
    ///////////////////////////////////////////////////////////////////////////
    // VALIDITY CHECK
    ///////////////////////////////////////////////////////////////////////////
    /*
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
    */
    ///////////////////////////////////////////////////////////////////////////
    // TO COMPUTE DECIMAL
    ///////////////////////////////////////////////////////////////////////////
    int y;
    
    for (int j = 0; j < length; j++)
    {
        y = int(bin[j]) - 48;  // ascii numbers start at 48
        
        // cout << y << endl; // to make sure numbers are correct
        
        dec = dec + y * pow(x, ((length - 1) - j));
        
        /*
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
         */
    }
    
    cout << "\n" << bin << " in base " << x << " is " << dec << " in decimal!\n\n";
    
    return 0;
}


