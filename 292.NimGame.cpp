/*Question:
ou are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
Hint:
If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
*/

/*Method:
case 1:
Number of stones - 1, 2 or 3
Analysis - Since, I am allowed to remove a maximum of 3 stones, I will win this case.
case 2:
Number of stones - 4
Analysis - If I remove 1, the opposition removes rest 3 and wins the game .
                 If I remove 2, the opposition removes rest 2 and wins the game.
                 If I remove 3, the opposition removes the remaining 1 stone and wins the game.
                 Thus, if the number of initial stones are 4 I will lose the game. We can also conclude that whoever has 4 stones in their turn loses the game.
case 3:
Number of stones - 5
Analysis: If I remove 1, the opposition gets 4 and thus he loses and I win.
case 4:
Number of stones - 6
Analysis: If I remove 2, the opposition gets 4 and thus he loses and I win.
case 5:
Number of stones - 7
Analysis: If I remove 3, the opposition gets 4 and thus he loses and I win.
case 6:
Number of stones - 8
Analysis: If I remove 1, the opposition gets 7 stones and wins the game .
                 If I remove 2, the opposition gets 6 stones and wins the game.
                 If I remove 3, the opposition gets 5 stones and wins the game.
                 Thus, if the number of initial stones are 8 I will lose the game. We can also conclude that whoever has 8 stones in their turn loses the game.
From the above cases we see that if the number of stones during my turn is a multiple of 4 I will lose the game. Thus the code we will write is:
*/

//Code:
class Solution {
public:
    bool canWinNim(int n) {
        if(n < 0) return false;
        return(!(n%4 == 0));
    }
};
