#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	char rom[13][3] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int dec[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}, i, num;
	printf_s(dec[1]);
//	for(i = 0; i < 13; i++)
//	{
//		while(num >= dec[i])
//		{
//            printf("%s",rom[i]);
//			num -= dec[i];
//		}
//	}
	return 0;
}
