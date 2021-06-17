/*Challenge 1 Add unit tests to demonstrate that the decoder works

Added few unit tests assuming the code is suppose to reverse a string - no testing framework, just simple method with a few example calls. I didn't add a test 

Challenge 2 : Make sure that the code can compile successfully using

gcc - std = c89 - pedantic - Werror - Wall - Wextra quiz.c
or another compiler with similar ANSI - 89 and strictest warnings as errors.​​​​​​​

Note​​​​​​​ : take care on MacOS that you are using real gcc(not gcc mapped to clang).

I used Visual Studio 2019, with the following options:
Compile as C code (/TC)
Disable language extension: Yes (/Za)


Challenge 3 : Remove all loop statements(tip : recursion)
Added two recursions: one to find the string length and another to reverse the string
​​​​​​​

Challenge 4 : There is a defect in this code which makes the solution sometimes print additional characters.What is the cause ? What is the fix ? (tip : use a memory debugger and /or read C compiler standards and /or use static analysis)
The original reversed string is statically allocated 1000 chars and the code doesn't add NULL terminator ('\0')
I've fixed that by dynamically allocating the memory and adding a NULL terminator. The caller is responsibly for freeing 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int FindStringEndIndexRecurs(char* str, int currentIndex)
{
	if (str[currentIndex] == '\0')
	{
		return currentIndex - 1;
	}
	return FindStringEndIndexRecurs(str, currentIndex + 1);
}

void ReverseStringRecurs(char* originalString, char* reversedString, int originalStringPosition, int reversedStringPosition)
{
	if (originalStringPosition < 0)
	{
		return;
	}
	reversedString[reversedStringPosition] = originalString[originalStringPosition];
	ReverseStringRecurs(originalString, reversedString, --originalStringPosition, ++reversedStringPosition);
}

char* Decode(char* stringToReverse)
{
	int stringEndIndex = FindStringEndIndexRecurs(stringToReverse, 0);
	char* ans =  (char*)malloc(stringEndIndex + sizeof('\0'));
	if (ans == NULL)
	{
		return NULL;
	}
	ReverseStringRecurs(stringToReverse, ans, stringEndIndex, 0);
	ans[stringEndIndex+1] = '\0';
	return ans;
}


int UnitTest(char* originalString, char* reversedString)
{
	char* ans = Decode(originalString);
	int testResult = strcmp(ans, reversedString);
	free(ans);
	return testResult;
}

void UnitTestSuite()
{
	int result;
	result = UnitTest("abc", "cba");
	result |= UnitTest("a", "a");
	result |= UnitTest("", "");
	if (result != 0) 
	{
		printf("Test Failed!\n");
	}
	else
	{
		printf("Test succeeded\n");
	}
}

int main() {
	UnitTestSuite();
	char* str = "12[1]2 ECNE[2]EF[3]OC [4]CNE[5]LECXE W[6] EH[7] N[8][9]J";
	char* ans = Decode(str);
	printf("Quiz answer: %s\n", ans);
	free(ans);
	return 0;
}



