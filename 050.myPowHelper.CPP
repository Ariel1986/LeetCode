/* Question:
Implement pow(x, n).
*/

/* Method:
注意n为负数的情况，当n为负数时，结果为1.0/result
*/

//Code:
double myPow(double x, int n) {
    if( n == 0) return 1.0;
    
    std::function<double(double, unsigned int)> myPowHelper
    = [&](double x, unsigned int n) ->double
    {
        if ( n == 1) return x;
        double res = myPowHelper(x, n / 2);
        res *= res;
        if(n %2 != 0)
            res *= x;
        return res;
    };
    
    double result = myPowHelper(x, (n > 0)? n: -n);
    
    if(n < 0)
        result = 1.0/result;
    
    
    return  result;
}
