
#include "Types.h"
#include "String.h"
#include <stdio.h>


String StringConcat(String str1 ,String str2)
{
	String Result = {};
	Result.count= (str1.count) + (str2.count) ;
	Result.data = (u8*)malloc(sizeof(u8) * (Result.count+1));
	memcpy(Result.data,str1.data,str1.count);
	memcpy(Result.data+str1.count,str2.data,str2.count);
	Result.data[Result.count]= '\0';
	return Result;
}


String StringAlloc(u64 Size)
{
	
	String str = {};
	str.data = (u8*)malloc(sizeof(u8)* (Size+1));
	str.data[Size] = '\0';
	str.count = Size; 
	return str;
	
}

String ReadFileIntoString(const char *filename)
{
	
	String Result={};
	FILE *fp = fopen(filename,"rb");
	if(fp == NULL)
	{
		
		printf("Error LoadingFile ");
		
	}
	
	fseek(fp, 0, SEEK_END);
	u64 FileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	Result = StringAlloc(FileSize);
	
	size_t BytesRead = fread(Result.data, 1, FileSize,fp);
	if(BytesRead != FileSize)
	{
		printf("Could not read entire file ");
		
	}
	
	return Result;
	
}

void StringFree(String* str)
{
	if (str->data)
	{
		free(str->data);
		
	}
	*str = {};
}




