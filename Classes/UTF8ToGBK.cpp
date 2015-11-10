#include "UTF8ToGBK.h"

UTF8ToGbk::UTF8ToGbk(){

}
UTF8ToGbk::~UTF8ToGbk(){

}
//当在WIN32 平台下，将utf8格式编码转化成gbk，vs2010的默认的编码格式
string UTF8ToGbk::transferGBK(const string text){
	//Wide字符在android下不被支持，使用iconv中转支持android
	//return IconvString::a2u(text.c_str());
	//android 使用utf8 编码格式，解决中文乱码问题,2014年10月8日10:06:35
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

	setlocale(LC_ALL, "chs");
	const char* _Source = text.c_str();
	size_t _Dsize = text.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, "C");

	wstring tes = result;
	int asciSize = WideCharToMultiByte(CP_UTF8, 0, tes.c_str(), tes.size(), NULL, 0, NULL, NULL);
	if (asciSize == ERROR_NO_UNICODE_TRANSLATION || asciSize == 0)
	{
		return string();
	}
	char *resultString = new char[asciSize];
	int conveResult = WideCharToMultiByte(CP_UTF8, 0, tes.c_str(), tes.size(), resultString, asciSize, NULL, NULL);
	if (conveResult != asciSize)
	{
		return string();
	}
	string buffer = "";
	buffer.append(resultString, asciSize);

	delete[] resultString;
	return buffer;
#endif
	return text;

}