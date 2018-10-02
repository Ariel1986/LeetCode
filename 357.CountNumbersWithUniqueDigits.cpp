/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
Hint:
A direct way is to use the backtracking approach.
Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10n.
This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
Let f(k) = count of numbers with unique digits with length equals k.
f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
Tags: Dynamic Programming Backtracking Math
*/

/*思路:
Let's call 1..9, group of numbers with 1 digit, 10..99, group of numbers with 2 digits, etc...
If you had the solution for group of numbers of 2 digits, then the solution for the next groups can be built by adding one digit to the numbers that are part of the solution for the group of 2 digits; but only the digits that are not already in the number.
For example:
"10", a solution from group of 2 digits. Let's build the ones for group 3 with prefix "10":
skip 0 (because it is in 10), skip 1 (idem), 102, 103, 104, ....
So for each solution in the group of 2 digits, you can create 10 - 2 new ones (or one new solution per available digit).
Therefore, using induction, you get:
X_0 = 1
X_1 = 9
X_2 = X_1*(10-1)
X_3 = X_2*(10-2)
...
X_n = X_n-1 * (10 - n + 1)
Where n is the number of digits of the number except for the especial case of 0. However, you need to see that for n > 10 you need to make the expression (10 - n + 1) equal 0, because if the number has more than 10 digits there is no way you can get a number with unique digits.
Now, the solution to the problem is just X_0 + X_1 + ... + X_n, which you can calculate as you calculate the Xs also. So you can do everything in one loop, no backtracking, nor array to store stuff necessary.
*/

//Code:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        
        int x = 9;
        int total = x + 1;
        
        for(int i = 2; i <= n && i < 11; ++i)
        {
            x *= 10 - i + 1;
            total += x;
        }
        
        return total;
    }
