// ***
//
// Given an integer, write a function to determine if it is a power of three.
//
// ***

bool isPowerOfThree(int num) {
    while ((num > 0) && (num % 3 == 0)) {
        num /= 3;
    }

    return num == 1;
}
