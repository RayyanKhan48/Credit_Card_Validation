// For a credit card (CC) number to be valid it needs to fulfill 3 cases
// 1. The credit card number must be between 13 and 16 digits long
// 2. The CC number must start with either 4 (Visa), 5 (Master Card), 37 (American Express) or 6 (Discover)
// 3. The CC number must pass Luhn's algorithm

// Luhn's Algorithm:
// 1. Double every second digit from right to left. If doubling of a digit results in a 
// two-digit number, add up the two digits to get a single-digit number (e.g 15:1+5, 11:1+1)
// 2. Now add all single-digit numbers from Step 1
// 3. Add all digits in the odd places from right to left in the card number
// 4. Sum the results from Step 2 and Step 3
// 5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise, it is invalid


#include <iostream>
using namespace std;

// Return this number if it is a single digit, else, return the sum of the two digits
int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return ((number / 10) + (number % 10));
}

// Return the number of digits (coverts to string first)
int getSize(unsigned long long d)
{
    string num = to_string(d);
    return num.length();
}

// Return the first k number of digits. 
// If the number of digits in number is less than k, return number.
unsigned long long getPrefix(unsigned long long number, int k)
{
    if (getSize(number) > k)
    {
        string num = to_string(number);
        // stoll is used to convert a substring of num into a long long int
        return stoll(num.substr(0, k));
    }
    return number;
}

// Return true if the CC number starts with any of the set prefixes
bool prefixMatched(unsigned long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

// Return the sum of even-placed digits
int sumOfDoubleEvenPlace(unsigned long long number)
{
    int sum = 0;
    string num = to_string(number);
    for (int i = getSize(number) - 2; i >= 0; i -= 2)
        // Converts the character at index i of the string num to its integer value
        // The - '0' is required to convert the character to its integer value
        // 0 has an ASCII value of 48
        sum += getDigit(int(num[i] - '0') * 2);
    return sum;
}

// Return the sum of odd-place digits in number
int sumOfOddPlace(unsigned long long number)
{
    int sum = 0;
    string num = to_string(number);
    for (int i = getSize(number) - 1; i >= 0; i -= 2)
        sum += num[i] - '0';
    return sum;
}

// Return true if the card number is valid (checks for the 3 cases)
bool isValid(unsigned long long number)
{
    if ((getSize(number) >= 13 && getSize(number) <= 16) &&
        (prefixMatched(number, 4) || prefixMatched(number, 5) || 
         prefixMatched(number, 37) || prefixMatched(number, 6)) &&
        ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Main function that asks user to enter a CC number to verify
int main()
{
    unsigned long long number;
    cout << "Enter a credit card number: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid";
    else
        cout << number << " is invalid";

    return 0;
}
