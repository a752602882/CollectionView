
#include "ColorSet.h"
void ColorSet::pushBtn_RED(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item){


	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CALabel* lable = (CALabel*)p_Cell->getSubviewByTag(99)->getSubviewByTag(100);
	lable->setText(UTF8("в╞"));
	lable->setColor(CAColor_red);
	lable->setFontSize(10);

	//char pos[20] = "";
	//sprintf(pos, "%d", item);
	//CALabel*label = (CALabel*)cell->getSubviewByTag(100)->getSubviewByTag(101);
	//label->setText(pos);
}
void ColorSet::pushBtn_BLUETEST(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAView* m_View = p_Cell->getSubviewByTag(99);
	m_View->setColor(CAColor_blueTest);
}
void ColorSet::pushBtn_BLUE(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CALabel* lable = (CALabel*)p_Cell->getSubviewByTag(99)->getSubviewByTag(100);
	lable->setText(UTF8("оп"));
	lable->setColor(CAColor_blue);
	lable->setFontSize(10);

}
void ColorSet::pushBtn_WHITE(CACollectionView*p_Conllection, unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CALabel* lable = (CALabel*)p_Cell->getSubviewByTag(99)->getSubviewByTag(100);
	lable->setText(UTF8(" "));
}