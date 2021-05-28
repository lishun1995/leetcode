#include <iostream>
#include<sstream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	string convert(string s, int numRows) {

		if(s.length() == 0)
		{
			return s;
		}

		if(numRows == 1)
			return s;

		string res;

		int n = s.length();
		int p = 0;

		int row_count = numRows * 2 - 2;
		int increase = 2 * numRows;
		int increase_tmp = 0;

		for (int i = 0; i < numRows; i++)
		{
			res += s[i];
			p = i;
			if(increase > 2)
			{
				increase -=  2;
			}
			else if (increase == 2)
			{
				increase = row_count;
			}

			increase_tmp = increase;
			while(p < n)
			{			
				p += increase_tmp;
				if(p < s.length())
				{
					res += s[p];
				}else
				{
					break;
				}
				increase_tmp = row_count - increase_tmp;
				if(increase_tmp == 0)
				{
					increase_tmp = row_count;
				}
			}

		}
		return res;
    }
};



int main1111()
{
	//char * str = "hello";
	//cout << str[2] << endl;  //l
	//cout << *(str + 2) << endl; //l
	//string str2 = "hello";
	//cout << str2[2] << endl;  //l
	//cout << *str2 << endl; 

	//Solution solu;
	//string ret = solu.convert(s, 3);
	//cout << ret << endl;

	string s = "LEETCODEISHIRING";

    

	getchar();
	return 0;
}

//class gis_PropertySet
//{
//public:
//	gis_PropertySet()
//	{
//		cout << "this is gis_PropertySet construct"  << endl;
//	}
//
//	void print()
//	{
//		cout << "this is gis_PropertySet print " << endl;
//	}
//
//};

//#include "gis_commontype.h"
//#include "gis_propertySet.h"

//void mainGis_PropertySet()
//{
//	//gis_PropertySet gisPropertySet;
//	//gis_PropertySet *p_gisPropertySet = &gisPropertySet;
//
//	gis_PropertySet *p_gisPropertySet = GetGlobalPropertySetObject(); //0x0f07a130
//	gis_PropertySet *p_gisPropertySet2 = GetGlobalPropertySetObject();
//	gis_PropertySet *p_gisPropertySet3 = GetGlobalPropertySetObject();
//	gis_PropertySet *p_gisPropertySet4 = GetGlobalPropertySetObject();
//}