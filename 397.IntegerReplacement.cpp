/*
Given a positive integer n and you can do operations as follow:
If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?
Example 1:
Input:
8
Output:
3
Explanation:
8 -> 4 -> 2 -> 1
Example 2:
Input:
7
Output:
4
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

//Code 1:
int integerReplacement(int n) {
    std::function<int(long long)> helper = [&](long long n)->int{
        if(n == 1) return 0;
        
        if(n % 2 == 0){
            return helper(n/2) + 1;
        }
        else {
            return std::min(helper(n + 1), helper(n - 1)) + 1;
        }
    };
    
    return helper(n);
}

//Code 2:
    int res = 0;
    int integerReplacement(int n) 
    {
        if (n == 1)
            return res;
        if (n == 3)
        {
            res += 2;
            return res;
        }
        if (n == INT_MAX)
            return 32;
        
        res ++;
        if (n & 1){
            if ((n + 1) % 4 == 0)
                integerReplacement(n + 1);
            else
                integerReplacement(n - 1);
        }
        else
            integerReplacement(n / 2);
            
        return res;
    }
    
//Code 3:
int integerReplacement(int n)
{
    int res = 0;
    if (n == 1)
        return res;
    if (n == INT_MAX)
        return 32;
    
    while(n != 1)
    {
        if (n == 3){
            res += 2;
            return res;
        }
        else{
            if (n & 1){
                if ((n + 1) % 4 == 0)
                    ++n;
                else
                    --n;
            }
            else{
                n /= 2;
            }
            ++res;
        }
    }
 
    return res;
}
