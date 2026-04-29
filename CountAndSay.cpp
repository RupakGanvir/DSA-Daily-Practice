#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        if (n <= 0)
            return "";
        std::string res = "1";

        for (int i = 1; i < n; i++)
        {
            std::string next_term = "";
            int len = res.length();

            for (int j = 0; j < len; j++)
            {
                int count = 1;
                while (j + 1 < len && res[j] == res[j + 1])
                {
                    count++;
                    j++;
                }
                next_term += std::to_string(count) + res[j];
            }
            res = next_term;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int n = 5;

    std::cout << "Count and Say for n=" << n << " is: " << sol.countAndSay(n) << std::endl;

    return 0;
}