#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int LCS[8][8];//LCS array
int main(void) {
	string str1;// string to put the value of X
	string str2;// string to put the value of Y
	string LCS1;// row major LCS
	string LCS2;// column major LCS
	string X;//str1 add '0' 
	string Y;//str2 add '0' 
	int m ;// Variable for X length
	int n ;//Variable for Y length
	while (1) {
		cout << "Input X={A,B,C,D}(1 ≤ m ≤ 7): ";
		cin >> str1;// input the argument of X
		cout << "Input Y={A,B,C,D}(1 ≤ n ≤ 7): ";
		cin >> str2;// input the argument of y
		if (str2.length() > str1.length())// Conditional statement to calculate based on the longest side of the string
		{
			swap(str1, str2);// Swap string if str2 is long
		}
		X = '0' + str1;// Add '0' in front for LCS algorithm.
		Y = '0' + str2;// Add '0' in front for LCS algorithm.
		m = X.size();// length of X
		n = Y.size();// length of Y
		if (m > 8 || n > 8)// If the length of X, length of Y is more than 8
			cout << "ERROR" << endl;
		else
			break;
	}
	// Set up LCS table
	for (int i = 1; i < m; i++)// iterate for the length of X
	{
		for (int j = 1; j < n; j++)// iterate for the length of Y
		{
			if (X[i] == Y[j])// If the current comparison values ​​are equal, lcs is + 1
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else if (LCS[i - 1][j] > LCS[i][j - 1])// If they are different, get the LCS value from the left or top.
				LCS[i][j] = LCS[i - 1][j];
			else
				LCS[i][j] = LCS[i][j - 1];	
		}
	}
	//print table
	cout<<" " << Y<<endl;
	for (int i = 0; i < m; i++)
	{
		cout  <<X[i];
		for (int j = 0; j < n; j++)
		{
			cout << LCS[i][j];
		}
		cout<<endl;
	}

	//print LCS length
	cout <<"LCS length :"<< LCS[m - 1][n - 1] << endl;
	return 0;
}