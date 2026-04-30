#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    int compareVersion(std::string version1, std::string version2)
    {
        int i = 0, j = 0;
        int n1 = version1.length();
        int n2 = version2.length();

        while (i < n1 || j < n2)
        {
            long long v1 = 0;
            long long v2 = 0;

            while (i < n1 && version1[i] != '.')
            {
                v1 = v1 * 10 + (version1[i] - '0');
                i++;
            }

            while (j < n2 && version2[j] != '.')
            {
                v2 = v2 * 10 + (version2[j] - '0');
                j++;
            }

            if (v1 < v2)
                return -1;
            if (v1 > v2)
                return 1;

            i++;
            j++;
        }

        return 0;
    }
};

int main()
{
    Solution sol;

    std::string v1 = "1.01";
    std::string v2 = "1.001";

    std::cout << "Comparing '1.01' and '1.001': " << sol.compareVersion("1.01", "1.001") << std::endl;
    std::cout << "Comparing '1.0' and '1.1': " << sol.compareVersion("1.0", "1.1") << std::endl;
    std::cout << "Comparing '0.1' and '1.1': " << sol.compareVersion("0.1", "1.1") << std::endl;
    std::cout << "Comparing '1.0.0' and '1.0': " << sol.compareVersion("1.0.0", "1.0") << std::endl;

    return 0;
}