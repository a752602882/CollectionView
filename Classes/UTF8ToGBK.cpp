#include "UTF8ToGBK.h"

UTF8ToGbk::UTF8ToGbk(){

}
UTF8ToGbk::~UTF8ToGbk(){

}
//����WIN32 ƽ̨�£���utf8��ʽ����ת����gbk��vs2010��Ĭ�ϵı����ʽ
string UTF8ToGbk::transferGBK(const string text){
	//Wide�ַ���android�²���֧�֣�ʹ��iconv��ת֧��android
	//return IconvString::a2u(text.c_str());
	//android ʹ��utf8 �����ʽ�����������������,2014��10��8��10:06:35
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