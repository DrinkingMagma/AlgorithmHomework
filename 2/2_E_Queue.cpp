// #include<iostream>
// #include<cstring>
// using namespace std;

// int main()
// {
//     string s;
//     int ans=0,m=0;
//     cin>>s;
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i] == 'M') m++;
//         if(s[i] == 'F' && m>0)
//         {
//             ans = max(ans+1,m);
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int result = 0, m_num = 0;

    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 'M')
            ++m_num;
        else if(str[i] == 'F' && m_num != 0)
            result = max(result+1, m_num);
    }

    cout << result;

   return 0;
}
