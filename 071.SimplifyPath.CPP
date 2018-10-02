/*
Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.
Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
Subscribe to see which companies asked this question
Tags: Stack String
*/

/*思路
如果单纯的单个字符处理，会出现很多情况，如：
/.. => /
/. => /
/...  => /...
/.../ => /...
/home/ => /home
/home//foo => /home/foo
/a/./b/../../c/ => /c
/abc/... => /abc/...
所以借助getline，去处理每一个由“／”分开的字符串
*/

//Code:string simplifyPath(string path) {
    std::vector<std::string> sVec;
    stringstream ss(path);
    string temp;
    while(getline(ss, temp, '/'))
    {
        if(temp == "" || temp == ".")
            continue;
        else if(temp == "..")
        {
            if(!sVec.empty())
            sVec.pop_back();
        }
        else 
            sVec.emplace_back(temp);
    }
    
    temp = "";
    for(auto&& str : sVec)
        temp += "/" + str;
        
    if(temp == "")
        temp = "/";
    return temp;
}

