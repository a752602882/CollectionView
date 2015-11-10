#include "DataSubViewController.h"

DataSubViewController::DataSubViewController()
{
}

DataSubViewController::~DataSubViewController()
{
}
void DataSubViewController::viewDidLoad()
{

	size = this->getView()->getBounds().size;
	//headerRefreshView = CAPullToRefreshView::create(CAPullToRefreshView::CAPullToRefreshTypeHeader);
	//footerRefreshView = CAPullToRefreshView::create(CAPullToRefreshView::CAPullToRefreshTypeFooter);

	p_Conllection = CACollectionView::createWithCenter(CCRect(size.width / 2, size.height / 2, size.width, size.height));
	p_Conllection->setAllowsSelection(false);
	p_Conllection->setBounceVertical(false);
	p_Conllection->setAllowsMultipleSelection(false);
	p_Conllection->setCollectionViewDataSource(this);
	p_Conllection->setCollectionViewDelegate(this);
	p_Conllection->setShowsVerticalScrollIndicator(false);

	//p_Conllection->setHeaderRefreshView(headerRefreshView);
	//p_Conllection->setFooterRefreshView(footerRefreshView);
	//p_Conllection->setHoriInterval(_px(2));
	//p_Conllection->setVertInterval(_px(2));
	this->getView()->addSubview(p_Conllection);
}

void DataSubViewController::viewDidUnload()
{
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}

void DataSubViewController::collectionViewDidSelectCellAtIndexPath(CACollectionView *collectionView, unsigned int section, unsigned int row, unsigned int item)
{
	//CCLog(UTF8("选中"));
}
void DataSubViewController::collectionViewDidDeselectCellAtIndexPath(CACollectionView *collectionView, unsigned int section, unsigned int row, unsigned int item)
{
	///CCLog(UTF8("取消选中"));
}
//获取指定cell
CACollectionViewCell* DataSubViewController::collectionCellAtIndex(CACollectionView *collectionView, \
	const CCSize& cellSize, unsigned int section, unsigned int row, unsigned int item){

	//CCLog("-------------row * 10 + item=%d-------------------", row * 10 + item);


	CACollectionViewCell* cell = collectionView->dequeueReusableCellWithIdentifier("crossApp");
	if (cell == NULL)
	{
		cell = CACollectionViewCell::create("crossApp");


		CAButton* m_Button = CAButton::createWithFrame(CCRect(0, 0, cellSize.width-10, cellSize.height-5), CAButtonTypeSquareRect);
		m_Button->setTag(100);
		cell->addSubview(m_Button);




		CAImageView* m_View = CAImageView::createWithCenter(CCRect(cellSize.width*0.5, cellSize.height*0.5, cellSize.width*0.4, cellSize.height*0.4));
		m_View->setTag(99);
		m_View->setImage(CAImage::create(""));
		m_View->setColor(CAColor_white);
		m_Button->addSubview(m_View);


	}



	//char pos[20] = "";
	//sprintf(pos, "%d", item);
	//CALabel*label = (CALabel*)cell->getSubviewByTag(100)->getSubviewByTag(101);
	//label->setText(pos);

	return cell;
}

//collectionView 个数,设置为1就一个，如果为2，那么会有80个view（160*160）
unsigned int DataSubViewController::numberOfSections(CACollectionView *collectionView)
{
	return 1;
}
//有多少行
unsigned int DataSubViewController::numberOfRowsInSection(CACollectionView *collectionView, unsigned int section)
{
	return 6;
}
//一行有多少个
unsigned int DataSubViewController::numberOfItemsInRowsInSection(CACollectionView *collectionView, unsigned int section, unsigned int row)
{
	return 22;
}
//cell高度
unsigned int DataSubViewController::collectionViewHeightForRowAtIndexPath(CACollectionView* collectionView, unsigned int section, unsigned int row)
{
	return (this->getView()->getBounds().size.height) / 6;
	//return size.width/30;
}
void DataSubViewController::SetSuperView(CAView * pView){
	//	m_pContainer = pView;
	addViewFromSuperview(pView);
}
void DataSubViewController::pushBtn_BLUE(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAImageView* itemImageView = (CAImageView*)p_Cell->getSubviewByTag(100)->getSubviewByTag(99);
	itemImageView->setImage(CAImage::create("colour/blue.png"));

}
void DataSubViewController::pushBtn_RED(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAImageView* itemImageView = (CAImageView*)p_Cell->getSubviewByTag(100)->getSubviewByTag(99);
	itemImageView->setImage(CAImage::create("colour/red.png"));

}
void DataSubViewController::pushBtn_BLUEVIEWTEST(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAImageView* itemImageView = (CAImageView*)p_Cell->getSubviewByTag(100)->getSubviewByTag(99);
	itemImageView->setImage(CAImage::create("colour/green.png"));

}
void DataSubViewController::pushBtn_BLACKVIEWTEST(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAImageView* itemImageView = (CAImageView*)p_Cell->getSubviewByTag(100)->getSubviewByTag(99);
	itemImageView->setImage(CAImage::create("colour/black.png"));;

}
void DataSubViewController::pushBtn_WHITE(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAImageView* itemImageView = (CAImageView*)p_Cell->getSubviewByTag(100)->getSubviewByTag(99);
	itemImageView->setImage(CAImage::create(""));;

}