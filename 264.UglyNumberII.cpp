/* Question:
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.
*/

/*
Hint:
The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/  

//Code 1:
int nthUglyNumber(int n) {
    if(n < 1) return 0;
    
    unsigned int index2 = 0, index3= 0, index5= 0;
    int cur = 0;
    std::vector<int> vec{1};
    
    for(unsigned i = 1; i < n; ++i)
    {
        cur = std::min(std::min(vec[index2] * 2,vec[index3] * 3), vec[index5] * 5);
        vec.push_back(cur);
        if(cur == vec[index2] * 2){
            ++index2;
        }
        if(cur == vec[index3] * 3){
            ++index3;
        }
        if(cur == vec[index5] * 5){
            ++index5;
        }
    }
    
    return vec[n-1];
}

//Code 2:
int nthUglyNumber(int n)
{
    if (n == 1) return 1;
    
    std::vector<int> v{1};
    
    for (int i = 2; i <= n; ++i)
    {
        int val1 = *std::find_if(v.begin(), v.end(), [&](int val){ return val*2 > v.back(); }) * 2;
        int val2 = *std::find_if(v.begin(), v.end(), [&](int val){ return val*3 > v.back(); }) * 3;
        int val3 = *std::find_if(v.begin(), v.end(), [&](int val){ return val*5 > v.back(); }) * 5;
        
        v.emplace_back(std::min(std::min(val1, val2), val3));
    }
    
    return v[n-1];
}
