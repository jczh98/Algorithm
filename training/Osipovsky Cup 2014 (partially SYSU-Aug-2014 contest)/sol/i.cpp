#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;

string location[20];
map<string,int> mIndex;
int maxIndex , T[20][100000+10];
int getIndex(string s)
{
	if(mIndex.find(s)!=mIndex.end()) return mIndex[s];
	location[maxIndex]=s;
	mIndex[s]=maxIndex++;
	if(maxIndex>15) 
	{
		exit(0);
	}
	return mIndex[s];
}


int main()
{
	int N,M,i,j,index,a,b;
	string str;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&a,&b);
		cin >> str;
		index = getIndex(str);
		T[index][b]++;
	}
	for(i=0;i<maxIndex;i++)
	{
		index = 0;
		for(j=0;j<=M;j++)
			if(T[i][index]<T[i][j]) index=j;
		cout << location[i] << " " << index << endl;
	}
	return 0;
}
