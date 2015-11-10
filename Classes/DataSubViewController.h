#ifndef _DataSubViewController_H_
#define _DataSubViewController_H_

#include <iostream>
#include "CrossApp.h"

USING_NS_CC;
class DataSubViewController:public CAViewController, CACollectionViewDelegate, CACollectionViewDataSource
{
public:
	DataSubViewController();
	~DataSubViewController();

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
	void pushBtn_BLUE(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_RED(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_WHITE(unsigned int section, unsigned int row, unsigned int item);

	void pushBtn_BLUEVIEWTEST(unsigned int section, unsigned int row, unsigned int item);
	void pushBtn_BLACKVIEWTEST(unsigned int section, unsigned int row, unsigned int item);

protected:
	void viewDidLoad();

	void viewDidUnload();
private:
	CCSize size;
	CACollectionView* p_Conllection;
	std::vector<CAColor4B> colorArr;
	CAPullToRefreshView* headerRefreshView;
	CAPullToRefreshView* footerRefreshView;
	CAView *m_pContainer;
	CAView *m_pContainer1;
};


#endif // !_DataSubView_H_
