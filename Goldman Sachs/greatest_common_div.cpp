#include<bits/stdc++.h>
using namespace std;

// Function that finds gcd of 2 strings
string gcd(string str1, string str2)
{
	if (str1.length() < str2.length())
	{
		return gcd(str2, str1);
	}
	else if(str1.find(str2) != 0)
	{
		return "";
	}
	else if (str2 == "")
	{
		return str1;
	}
	else
	{
		return gcd(str1.substr(str2.length()), str2);
	}
}


string findGCD(string arr[], int n)
{
	string result = arr[0];
	for (int i = 1; i < n; i++)
	{
		result = gcd(result, arr[i]);
	}
	return result;
}


int main()
{
	string arr[]={ "BUBUN","BUBU","BUBUBUBUBUNNNBUNN" };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << findGCD(arr, n);
}




