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

/* KMP模式匹配算法 */
/* 计算返回子串T的next数组 */
void get_next(String T,int *next)
{
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;
	while(i < T[0])			/* 此处T[0]表示串T的长度 */
	{
		if(j == 0 || T[i] == T[j])/* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];	/* 若字符不相同，则j值回溯 */
	}
}

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回0 */
int Index_KMP(String S,String T,int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next( T, next);
	while(i <= S[0] && j <= T[0])
	{
		if(j == 0 || S[i] = T[j])
		{
			++i;++j;
		}
		else
		{
			j = next[j];
		}
	}
	if(j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

/* 改进KVM算法 */
void get_nextval(String T,int *nextval)
{
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;
	while(i < T[0])			/* 此处T[0]表示串T的长度 */
	{
		if(j == 0 || T[i] == T[j])/* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
		{
			++i;
			++j;
			if(j == 0 || T[i] == T[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	
	}
}














