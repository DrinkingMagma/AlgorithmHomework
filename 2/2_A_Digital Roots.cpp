// #include <stdio.h>
// int main()
// {
// 	char a[2000];
// 	int sum = 0;
// 	while (scanf("%s", &a) != EOF && a[0] != '0')
// 	{
// 		sum = 0;
// 		for (int i = 0; a[i]; i++)
// 		{
// 			sum += a[i] - '0'; // 将数字字符转换成整型数字 sum='2'-'0'=2
// 							   // a[0]='2'  对应的ASCII值为50
// 		}
// 		printf("%d\n", (sum - 1) % 9 + 1);
// 	}

// 	return 0;
// }




#include <iostream>
using namespace std;

int main(){
	string str;
	int result;


	while(cin >> str && str != "0")
	{
		result = 0;
		for(int i = 0; i < str.size(); ++i){
			result += str[i] - '0';
		}
		result = (result - 1) % 9 + 1;

		cout << result << endl;
	}

	return 0;
}
