// Can you create a string using array of substrings {Dynamic programming approach}
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include <chrono>

using namespace std;
using namespace std::chrono;

unordered_map<string, bool> Map;

bool checker(string substring, string S)
{
	int flag = true; 
	for (int i = 0; i < substring.length(); i++)
	{
		if (substring[i] != S[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

string Trim(string Sub, string S)
{
	string Trimmed_S = "";
	Trimmed_S = S.substr(Sub.length(), S.length() - Sub.length());
	return Trimmed_S;

}

bool String_Builder(string S , string A[],int size)
{
	bool Flag = false;
	if (Map.find(S)!=Map.end())
	{
		return Map[S]; 
	}
	if (S == "")
	{
		return true; 
	}
	for (int i = 0; i < size; i++)
	{
		//Check if a prefix exists 
		
		bool is_prefix = checker(A[i], S);
		if (is_prefix)
		{
			string Trimmed_S = Trim(A[i], S);
			bool ans = String_Builder(Trimmed_S, A, size);
			if(ans)
			{   
				Map[Trimmed_S] = true; 
				return true;
			}
		}

		//  If yes call the function; 
		//  If no return flag;
	}
	Map[S] = false; 
	return false;
}



int main()
{
	auto start = high_resolution_clock::now();
	
	// DECLARATION OF VARIABLE 
	
	string S = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
	string A[] = { "ee","eeeeeeee", "eeeee","eeeeeeeeeee","e"};
	int size = sizeof(A) / sizeof(A[0]);

	// FUNCTION CALL
	
	bool t = String_Builder(S, A, size);
	string ans = t > 0 ? "YES" : "NO"; 
	cout << ans;
	cout << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function: "
		<< duration.count() << " microseconds" << endl;


	return 0;

}
