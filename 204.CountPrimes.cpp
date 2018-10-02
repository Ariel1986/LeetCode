/* Question:
escription:
Count the number of prime numbers less than a non-negative number, n.
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

/* Hints:
1. Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers up to n would be O(n2). Could we do better?
2. As we know the number must not be divisible by any number > n / 2, we can immediately cut the total iterations half by dividing only up to n / 2. Could we still do better?
3. Let's write down all of 12's factors:
2 × 6 = 12
3 × 4 = 12
4 × 3 = 12
6 × 2 = 12
As you can see, calculations of 4 × 3 and 6 × 2 are not necessary. Therefore, we only need to consider factors up to √n because, if n is divisible by some number p, then n = p × q and since p ≤ q, we could derive that p ≤ √n.
Our total runtime has now improved to O(n1.5), which is slightly better. Is there a faster approach?
//该方法在leetcode中提交会产生Time Limit Exceeded错误
public int countPrimes(int n) {
   int count = 0;
   for (int i = 1; i < n; i++) {
      if (isPrime(i)) count++;
   }
   return count;
}
private boolean isPrime(int num) {
   if (num <= 1) return false;
   // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
   // to avoid repeatedly calling an expensive function sqrt().
   for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) return false;
   }
   return true;
}
*/

/* Method:
 the terminating loop condition can be p < √n, as all non-primes ≥ √n must have already been marked off. When the loop terminates, all the numbers in the table that are non-marked are prime.
The Sieve of Eratosthenes uses an extra O(n) memory and its runtime complexity is O(n log log n). 
*/

//Code:
    int countPrimes(int n) {
        auto isPrimes = new bool[n];
        for(int i = 2; i < n; ++i)
            isPrimes[i] = true;
        
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for(int i = 2; i * i < n; ++i)
        {
            if(isPrimes == false) continue;
            for(int j = i * i; j < n; j += i)
            {
                isPrimes[j] = false;
            }
        }
        
        int result = 0;
        for(int i = 2; i < n; ++i)
        {
            if(isPrimes[i])
                ++result;
        }
        
        return result;
    }
