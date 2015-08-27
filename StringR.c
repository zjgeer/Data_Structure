#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define String (char *)


/* 主串中查找字串返回位置信息 */
int Index(String S,String T,int pos)
{
	int n, m, i;
	String sub;
	
	if(pos > 0)
	{
		n = StrLength( S );
		m = StrLength( T );
		i = pos;
		
		while(i <= n - m + i)
		{
			SubString( sbu, S, i, m);
			if(StrCompare( sub, T) != 0)
			{
				++i;
			}
			else
			{
				return i;
			}
		}
	}
	return 0;
}