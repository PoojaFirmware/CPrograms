// Reverse Bit Program
// The basic idea is to iterate through each bit of the integer, shift them into the correct position in the result
// and reverse their order.

// Step-by-step approach:
// 1. Initialize a variable to store the reversed bits.
// 2. Iterate through all the bits of the input integer:
//    1. Shift the bits of the input integer to the right to access each bit.
//    2. Shift the bits of the result to the left to make room for the new bit.
//    3. Use bitwise OR to set the current bit of the result.
// 3. Return the reversed result.

