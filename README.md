# Credit Card Validation Program

## Overview

This program validates a credit card (CC) number based on the following criteria:

1. **Length Check**: The credit card number must be between 13 and 16 digits long.
2. **Prefix Check**: The credit card number must start with one of the following:
   - `4` (Visa)
   - `5` (MasterCard)
   - `37` (American Express)
   - `6` (Discover)
3. **Luhn's Algorithm**: The credit card number must pass Luhn's algorithm, a checksum formula used to validate various identification numbers.

## Luhn's Algorithm

Luhn's algorithm verifies the credit card number by following these steps:

1. **Double every second digit** from right to left. If doubling results in a two-digit number, add the digits together (e.g. 15 → 1+5).
2. **Sum all the single-digit results** from the previous step.
3. **Sum all digits** in the odd places from right to left in the credit card number.
4. **Add the sums** from steps 2 and 3.
5. **Check if the total** from step 4 is divisible by 10. If it is, the credit card number is valid; otherwise, it is invalid.

## Code Overview

### Functions

- **`int getDigit(int number)`**: Returns the digit itself if it’s a single digit; otherwise, returns the sum of the digits.
- **`int getSize(unsigned long long d)`**: Returns the number of digits in the credit card number.
- **`unsigned long long getPrefix(unsigned long long number, int k)`**: Returns the first `k` digits of the credit card number.
- **`bool prefixMatched(unsigned long long number, int d)`**: Checks if the credit card number starts with the specified prefix.
- **`int sumOfDoubleEvenPlace(unsigned long long number)`**: Returns the sum of digits in even positions from right to left, doubled according to Luhn’s algorithm.
- **`int sumOfOddPlace(unsigned long long number)`**: Returns the sum of digits in odd positions from right to left.
- **`bool isValid(unsigned long long number)`**: Checks if the credit card number is valid based on the criteria mentioned above.

### Main Function

The main function prompts the user to input a credit card number and then checks its validity using the `isValid` function. The result is printed to the console, indicating whether the number is valid or invalid.

### Example
```
Enter a credit card number: 379354508162306
379354508162306 is valid
```

### Notes
- This project was inspired by yuvraj_chandra.


