/*Question:
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
Subscribe to see which companies asked this question
Tags: Dynamic Programming String
*/

/*思路:
动态规划
用一个二维数组dist[m][n]存储结果，先将第一行第一列分别保存为如果不等需要进行的操作数。
然后遍历两个字符串，如果字符相等，则dist[i+1][j+1] = dist[i][j]；
否则，dist[i+1][j+1] = std::min(dist[i][j] + 1, std::min(dist[i+1][j] + 1, dist[i][j+1] + 1));
*/

//Code:
class Solution {
public:
    int minDistance(string word1, string word2) {
         if (word1.empty() || word2.empty()) 
            return (int)word2.size() + (int)word1.size();
    
        std::vector<int> temp(word2.size()+1, 0);
        std::vector<std::vector<int>> dist(word1.size()+1, temp);
    
        for (int i = 1, iEnd = (int)word1.size()+1; i < iEnd; ++i)
            dist[i][0] = i;
        for (int i = 1, iEnd = (int)word2.size()+1; i < iEnd; ++i)
            dist[0][i] = i;
             
        for(int i = 0, iEnd = word1.size(); i < iEnd; ++i)
            for(int j = 0, jEnd = word2.size(); j < jEnd; ++j)
                {
                    if(word1[i] == word2[j])
                        dist[i+1][j+1] = dist[i][j];
                    else
                    {
                        int dist1 = dist[i][j] + 1;   // replace
                        int dist2 = dist[i+1][j] + 1; // insert
                        int dist3 = dist[i][j+1] + 1; // delete
                        dist[i+1][j+1] = std::min(dist1, std::min(dist2, dist3));
                    }
                }
                
        return dist[word1.size()][word2.size()];
    }
};
