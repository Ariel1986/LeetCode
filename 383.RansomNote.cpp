/*Quesstion:
 Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   
Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.
Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/*Method:
此题类似yu此题类似于389。
*/

//Code 1:
bool canConstruct(string ransomNote, string magazine) {
    if(magazine.length() < ransomNote.length())
        return false;
    
    for(auto&& ch : ransomNote)
    {
        auto pos = magazine.find(ch);
        if(pos == std::string::npos)
        {
            return false;
        }
        else
        {
            magazine.erase(pos, 1);
        }
    }
    
    return true;
}

//Code 2:
bool canConstruct(string ransomNote, string magazine) {
    if(magazine.length() < ransomNote.length())
        return false;
    
    int letterCount[128] = {0};
    
    for(int i = 0, iEnd = magazine.size(); i < iEnd; ++i)
    {
        ++letterCount[magazine[i]];
    }
    
    for(auto&& ch : ransomNote)
    {
        if(letterCount[ch] == 0)
            return false;
        else
            --letterCount[ch];
    }
    
    return true;
}
