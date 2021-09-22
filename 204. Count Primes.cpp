// ***
//
// Count the number of prime numbers less than a non-negative number n.
//
// Example:
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
// ***
//
// See image here: http://www.cnblogs.com/grandyang/p/4462810.html
// The idea is, if isPrime[i] is a prime number, then it multiples are non-prime number.
// i.e. isPrime[i] is prime, then we know isPrime[i * i], isPrime[i * i * i] ... are non-prime.

// The question asks for the number of prime numbers between [2, n) (not including n)
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        // Stores whether i is a prime number or not.
        // By default everything is prime, and will be toggled to non-prime.
        vector<bool> isPrime(n, true);

        // Number 0 and 1 is neither prime nor non-prime.
        isPrime[0] = false;
        isPrime[1] = false;

        int numPrimes = 0;
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = 2; i * j < n; ++j) {
                    isPrime[i * j] = false;
                }
            }
        }

        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++numPrimes;
            }
        }

        return numPrimes;
    }
};
