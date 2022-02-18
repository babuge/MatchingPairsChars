#include <iostream>
#include <vector>
#include <map>

// 匹配字符数组（）{}[]， 示例 输入 [()] 或者 []() 或者 {()}[]，返回 true，输入[{]] 或者 )( 返回false
typedef enum class CharsType_ {
    SLeft = 1,
    SRight,
    MLeft,
    MRight,
    LLeft,
    LRight
} CahrsType;

using namespace std;

void eatChar(const map<char, CahrsType> &mp,vector<char> &tmp, char next)
{
    if(tmp.size() == 0){
        return;
    }
    int len = tmp.size();
    char last = tmp[len -1];

    int nextInt = static_cast<int>(mp.at(next));
    int lastInt = static_cast<int>(mp.at(last));
    if(nextInt%2 == 0 && lastInt == nextInt - 1)
    {
        tmp.pop_back();
        len = tmp.size();
        if(len == 0)
        {
            return;
        }
        last = tmp[len -1];
        tmp.pop_back();

        eatChar(mp, tmp, last);
    } else {
        tmp.push_back(next);
    }

}

void inputTips()
{
    cout << " \n输入0退出，";
    cout << " 请输入需要匹配的字符数（偶数）: ";
}

int main()
{
    map<char, CahrsType> typeMap;
    typeMap.insert(pair<char,CahrsType>('(', CahrsType::SLeft));
    typeMap.insert(pair<char,CahrsType>(')',CahrsType::SRight));
    typeMap.insert(pair<char,CahrsType>('[',CahrsType::MLeft));
    typeMap.insert(pair<char,CahrsType>(']',CahrsType::MRight));
    typeMap.insert(pair<char,CahrsType>('{',CahrsType::LLeft));
    typeMap.insert(pair<char,CahrsType>('}',CahrsType::LRight));

    vector<char> vct;
    int n;
    inputTips();
    while(cin >> n)
    {
        if(n == 0)
        {
            cout <<endl;
            cout << "输入0，已退出！" << endl;
            break;
        }
        vct.clear();
        if(n%2 != 0)
        {
            cout << "匹配结果：false" << endl;
            inputTips();
            continue;
        }
        vct.reserve(n);
        cout << "请输入要匹配的字符: ";
        while(n--)
        {
            char tmp;
            cin >> tmp;
            vct.push_back(tmp);
        }
        cout << "print: " << endl;
        int len = vct.size();
        for(int i = 0; i < len; ++i)
        {
            cout << vct.at(i) <<" ";
        }
        cout << endl;

        vector<char> tmp;
        for(int i = 0; i < len; ++i)
        {
            if(i==0)
            {
                tmp.push_back(vct.at(i));
            }
            else{
                 eatChar(typeMap, tmp, vct.at(i));
            }
        }

        if(tmp.size())
        {

            cout << "结果：false"<< endl;
        }
        else {
            cout << "结果：true" << endl;
        }

        inputTips();
    }

    return 0;
}
