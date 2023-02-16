// Codechef - CONCATPAL
#include <iostream>
#include<map>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int x, k, flag = 1;
		cin >> x >> k;
		string s1, s2;
		cin >> s1 >> s2;

		// Ensuring larger string is in S1 
		if (s1.length() < s2.length())
		{
			string temp = s1;
			s1 = s2;
			s2 = temp;
		}
		int ch_1[26] = { 0 };
		int ch_2[26] = { 0 };

		// CHECKING IF SMALLER SUBSTRING EXISTS IN LARGER ONE 
		for (int i = 0; i < s1.length(); i++)
		{
			ch_1[(int)s1[i] - 97]++;
		}
		for (int i = 0; i < s2.length(); i++)
		{
			ch_2[(int)s2[i] - 97]++;
		}
		for (int i = 0; i < 26; i++)
		{

			ch_1[i] = ch_1[i] - ch_2[i]; 

			if (ch_1[i] < 0)
			{
				flag = -1;
				break;
			}
		}

		if (flag == -1) { cout << "NO\n";}

		else
		{
			int odd = 0; 
			for (int i = 0; i < 26; i++)
			{
				if (ch_1[i] % 2 != 0)
				{
					odd++;
				}

			}
			if (odd > 1)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
			}
		}

	}
		return 0; 
}
