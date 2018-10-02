/*Question:
Determine whether an integer is a palindrome. Do this without extra space.
click to show spoilers.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
Tags: Math
Similar Problems: Palindrome Linked list
*/

/*思路：
方法一：
将数据分成左右两半，然后反正左侧数据，对数据进行比较
方法二：
依次比较左右两边的数据，然后对数据减掉左右两边的数字继续进行比较，直至数字<10。注意处理左边数字为0的情况，如100021此类情况。
方法三（代码最简洁）：
利用题目中提到的反转数字，但是这样会有可能产生溢出。
*/

//Code:
//Code 1:
class Solution {
public:
    bool isPalindrome(int x) {
	    if (x < 0) 
	        return false;
	    
	    int digit = 0;
	    int xCopy = x;
	    while (xCopy > 0)
	    {
		    ++digit;
		    xCopy /= 10;
	    }

	    int dividNum = std::pow(10, digit / 2);
	    int leftNum = (digit % 2 == 0) ? x / dividNum : x / (dividNum * 10);
	    int rightNum = x % dividNum;

	    auto reverseInt = [&leftNum]()->int
	    {
		    int result = 0;
		    while (leftNum > 0)
		    {
			    result = result * 10 + (leftNum % 10);
			    leftNum /= 10;
		    }
	    	return result;
	    };
	    
	    int reverseLeftNum = reverseInt();
	    
	    return reverseLeftNum == rightNum;
    }
};

//Code2:
class Solution {
public:
    bool isPalindrome(int x) {
	    if (x < 0)
		    return false;

	
	    int xCopy = x;
	    auto getDigit = [](int xCopy)->int
	    {
		    int digit = 0;
		    while (xCopy > 0)
		    {
			    ++digit;
			    xCopy /= 10;
		    }
		    return digit;
	    };
	
	    int digit = getDigit(x);
	    int num = std::pow(10, digit-1);
	    auto judgeZero = [](int x, int digit)
	    {
		    while(digit)
		    {
			    int val1 = x % 10;
			    if (val1 != 0)
				    return false;
			    --digit;
			    x /= 10;
		    }
		    return true;
	    };
	    while (x > 9)
	    {
		    int leftNum = x / num;
		    int rightNum = x % 10;
		    if (leftNum != rightNum)
			    return false;

		    x -= num * leftNum;
		    x /= 10;
		    digit -= 2;

		    int digitTemp = getDigit(x);
		    if (digitTemp != digit && !judgeZero(x, digit - digitTemp))
			    return false;
		    num /= 100;
	    }

	    return true;
    }
};

//Code 3:
class Solution {
public:
    bool isPalindrome(int x) {
	    if (x < 0)
		    return false;
		    
        int mirror = 0;
        int xCopy = x;
        while(x)
        {
            mirror = mirror*10 + x%10;
            x /= 10;
        }
        
        return mirror == xCopy;
    }
};
