#ifndef _ColorSet_H_
#define _ColorSet_H_
#include "CrossApp.h"
#include <iostream>
/////-------------------------·ÏÎÄ¼þ----------------------------------//
static const CAColor4B CAColor_blueTest = { 0, 255, 0, 255 };
class ColorSet
{
public:
	ColorSet();
	~ColorSet();
public:
	void pushBtn_BLUE(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_BLUETEST(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_RED(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_WHITE(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item);
private:

};



#endif //ColorSet