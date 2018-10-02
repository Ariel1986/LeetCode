/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
Example:
n = 15,
Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

//Code:
    vector<string> fizzBuzz(int n) {
        if(n <= 0) return {};
        std::vector<std::string> result;
        
        const std::string three = "Fizz";
        const std::string five = "Buzz";
        const std::string threeFive = "FizzBuzz";
        
        for(int i = 1; i <= n; ++i)
        {
            if(i % 15 == 0)
                result.emplace_back(threeFive);
            else if(i % 3 == 0)
                result.emplace_back(three);
            else if(i % 5 == 0)
                result.emplace_back(five);
            else
                result.emplace_back(std::to_string(i));
        }
        
        return result;
    }
