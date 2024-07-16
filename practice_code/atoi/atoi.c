/*The C stdlib library atoi() function is used to convert a numeric string into an integer value.

An integer is a whole number that can be positive or negative, including zero. 
It can't be fraction, decimal, or percentage, For example, numbers like 1, 2, -5, and -10 are integers.

#inlclude <stdlib.h>
int atoi(const char *str)

str = "1509.10E";
val = atoi(str); 
o/p 1509

tutorialspoint India
o/p = 0

*/

/*
1: Whitespace Handling:
The function first skips any leading whitespace characters using isspace. for ex: "   123"

2: Sign Handling:
It then checks for an optional sign (+ or -). If a - sign is found, the sign variable is set to -1 to indicate a negative number.
3:Digit Conversion:
 -The function processes each character of the string as long as it is a digit using isdigit.
 -Each digit character is converted to its corresponding integer value by subtracting '0'.

4:Overflow and Underflow Check:
Before updating the result, the function checks for potential overflow or underflow. If adding the next digit would cause the result to exceed the limits of an integer, the function returns INT_MAX or INT_MIN.

5:Return the Result:
Finally, the function multiplies the result by the sign and returns it.
*/
/*
    ctype.h
    isspace(int ch);
    isdigit(int ch);
*/
#include <stdio.h>
#include <stdbool.h>
int my_isspace(int ch) {
//bool my_isspace(int ch) {
    // Check for various whitespace characters
    return (ch == ' '  ||  // space
            ch == '\t' ||  // horizontal tab
            ch == '\n' ||  // newline
            ch == '\v' ||  // vertical tab
            ch == '\f' ||  // form feed
            ch == '\r');   // carriage return
}
int my_isdigit(int ch) {
//bool my_isdigit(int ch) {
    return (ch >= '0' && ch <= '9');
}

int ATOI(const char *str);

int main()
{
    char *str  = "1509.10E";
    int result = ATOI(str);
    return 0;
}

int ATOI(const char *str)
{
    // check for whitespace
    int i =0;
    int sign = 1;
    int digit = 0;
    int result = 0;

    while(my_isspace(str[i]))
    {
        i++;
    }

    //check for sign
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    //convert character to integer
    while (isdigit(str[i])) {
        digit = str[i] - '0';

        // Check for overflow and underflow
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
    
}

