#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str;
    cin >> str;

    string tmpStr = "";
    int minRes = 0;
    bool negFlag = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            tmpStr += str[i];
            if (i == str.size() - 1)
            {
                if (negFlag)
                {
                    minRes += (-1 * stoi(tmpStr));
                }
                else
                {
                    minRes += stoi(tmpStr);
                }
            }
        }
        else
        {
            if (negFlag)
            {
                minRes += (-1 * stoi(tmpStr));
            }
            else
            {
                minRes += stoi(tmpStr);
            }

            if (str[i] == '-')
            {
                negFlag = true;
            }
            tmpStr.clear();
        }
    }

    cout << minRes;

    return 0;
}