#include "CrossApp.h"
#include <stdio.h>
#include <iostream>

#include <string>
#include <locale>
using namespace std;

class UTF8ToGbk
{
public:
	UTF8ToGbk();
	~UTF8ToGbk();

	//将UTF8转换为GBK格式编码
	static string  transferGBK(const string text);

protected:
private:
};