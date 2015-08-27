# Data_Structure
PLAY WITH DATA STRUCTURE

2015-8-27 16:30:37

ADT串(string)

Data 
	串元素仅由一个字符自称， 相邻元素具有前缀和后继关系。
Operation
	StrAssign(T, *chars):生成一个其值等于字符串常量chars的串T.
	StrCopy(T, S):串S存在，由串S复制得串T.
	ClearString(S):串S存在，将串清空.
	StringEmpty(S)L:判断串是否为空，若为空则返回true，否则返回false.
	StrLength(S):返回串S的元素个数.
	StrCompare(S,T):若S > T，返回值 > 0,若S = T,返回0，若S < T,返回 <0.
	Concat(T,S1,S2):用T返回由S1和S2连接而成的新串.
	SubString(Sub,S,pos,len):串S存在，1 ≤ pos ≤StringLength(S),
		且0 ≤ len ≤ StrLength(S) - pos + 1，用Sub返回串S的第pos个字符起长度为len的子串.
	Index(S,T,pos):S,T存在非空串，主串S返回T第一次出现的位置
	Replace(S,T,V):V替换T字串
	StrInsert(S,pos,T):在pos位置插入串T
	StrDelete(S,pos,len):在S中从pos开始删除长度为len的串
endADT
	