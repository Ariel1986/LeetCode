/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
*/

/*思路：
处理1 - 1.0 或1.0 - 1这种最后是0的情况，需要返回0
*/

//Code:
int compareVersion(string version1, string version2) {
    auto split = [](const string& version, std::vector<int>& nums)
    {
        std::stringstream s(version);
        std::string str;
        while (std::getline(s, str, '.'))
        {
            nums.emplace_back(std::stoi(str));
        }
    };

    std::vector<int> nums1;
    std::vector<int> nums2;
    split(version1, nums1);
    split(version2, nums2);
    int sz1 = nums1.size(), sz2 = nums2.size();
    int index = 0, iEnd = std::min(sz1, sz2);
    for (; index < iEnd; ++index)
    {
        if (nums1[index] > nums2[index]) return 1;
        if (nums1[index] < nums2[index]) return -1;
    }
    if (sz1 < sz2)
    {
        while (index < sz2 && nums2[index] == 0) ++index;  //处理包含0的情况
        if (index < sz2) return -1;
    }

    if (sz1 > sz2)
    {
        while (index < sz1 && nums1[index] == 0) ++index;  //处理包含0的情况
        if (index < sz1) return 1;
    }
    return 0;
}
