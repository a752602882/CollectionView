
#ifndef __HelloCpp__ViewController__
#define __HelloCpp__ViewController__

#include <iostream>
#include "CrossApp.h"
#include "DataSubViewController.h"
#include "Road.h"
#include "UTF8ToGBK.h"
USING_NS_CC;


static int RowNum = 10;
static int a[10][22];




class FirstView;
class FirstViewController : public CAViewController{

public:

	FirstViewController();

	virtual ~FirstViewController();

	vector<int> m_vecBigRoadData;
	vector<int> m_BLUE_GRAYRoadData;
	vector<int>  m_MultiRoadData;
protected:

	void lastNextcolor();
	
	void ClearRoadForRow();
	void ClearMultiRoadLastColor();
	void ReashMultiRoad();
	void ReashMultiRoad(int TAG);
	void ReashMultiRoadForRow();
	void ReashBigRoad();
	void ReashBLUE_GRAYRoad();
	
	void BackMultiRoadSpace();
	void Backspace();
	void BackBlue_Blackspace();
	//计算背景
	void CompoundColor(int TAG);
	void CompoundColor();
	void DrawbackgroundColor();

	void CompoundBigRoadColor();
    //计算绿黑路数据
	void CountBLUE_GRAYRoad();
	void CountMultiRoad();
	void CountColorNum();

	void viewDidLoad();
	FirstView * SubDataView1;
	DataSubViewController * SubDataView2;
	DataSubViewController * SubDataView3;
	void viewDidUnload();

	void switchStateChange(CAControl* btn, CCPoint point);
public:
	

private:
	void CLandlordBton(CAControl* btn, CCPoint point);
	void CFarmerBton(CAControl* btn, CCPoint point);
	void CMultiRoadButton(CAControl* btn, CCPoint point);
	void CClear_ONE(CAControl* btn, CCPoint point);
	void CClear_ALL(CAControl* btn, CCPoint point);
	void CCutButton(CAControl* btn, CCPoint point);
	

	void ClearALLViewColor();
	void ClearViewColor();
	CAView* m_pContainer1;
	//CAView* m_pContainer2;
	CAView* m_pContainer2;
	CAView* m_pContainer3;
	
	bool  state;
	DRoad bigRoad;
	DRoad BGRoad;
	int m_nNumRows;

	CASwitch* defaultSwitch;
	
};

class FirstView :public CAViewController, CACollectionViewDelegate, CACollectionViewDataSource
{
public:

	FirstView();

	virtual ~FirstView();



protected:

	
	void viewDidLoad();

	void viewDidUnload();
public:
	//CACollectionView实现了tableView的基本功能,主要是一系列cell的表
	//全部是CACollectionViewDelegate 定义的虚函数
	virtual void collectionViewDidSelectCellAtIndexPath(CACollectionView *collectionView, \
		unsigned int section, unsigned int row, unsigned int item);
	virtual void collectionViewDidDeselectCellAtIndexPath(CACollectionView *collectionView, \
		unsigned int section, unsigned int row, unsigned int item);

	virtual CACollectionViewCell* collectionCellAtIndex(CACollectionView *collectionView, \
		const CCSize& cellSize, unsigned int section, unsigned int row, unsigned int item);
	virtual unsigned int numberOfSections(CACollectionView *collectionView);
	virtual unsigned int numberOfRowsInSection(CACollectionView *collectionView, unsigned int section);
	virtual unsigned int numberOfItemsInRowsInSection(CACollectionView *collectionView, \
		unsigned int section, unsigned int row);
	virtual unsigned int collectionViewHeightForRowAtIndexPath(CACollectionView* collectionView, \
		unsigned int section, unsigned int row);
	
public:
	void SetSuperView(CAView * pView);
	void refreshData();
	void pushBtn_BLUE(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_RED(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_WHITE(unsigned int section, unsigned int row, unsigned int item);

	void pushBtn_BLUETEST(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_GRAYTEST(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_WHITETEST(unsigned int section, unsigned int row, unsigned int item);

	

	//private:
	
	CACollectionView* p_Conllection;
	std::vector<CAColor4B> colorArr;
	CAPullToRefreshView* headerRefreshView;
	CAPullToRefreshView* footerRefreshView;
	CAView *m_pContainer;
	CAView *m_pContainer1;
};

#endif /* defined(__HelloCpp__ViewController__) */
