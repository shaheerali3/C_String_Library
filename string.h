/* date = November 25th 2024 8:50 pm */

#ifndef _STRING_H
#define _STRING_H

struct String
{
	
	u8* data;
	u64 count;
	
};

String StringConcat(String str1 ,String str2);
String StringAlloc(u64 Size);
String ReadFileIntoString(char *filename);
void StringFree(String* str);




#endif //_STRING_H
