
#include "FirstViewController.h"
#include "UtilManager.h"
static const CAColor4B CAColor_blueTest = { 0, 255, 0, 255 };
static const CAColor4B CAColor_grayTest = { 144, 144,144, 144};
enum BLUE_RED{
	
	WHITE=0,
	RED,
	BLUE,
	
	//BLUETEST,
	//BLACK,
};
enum TAG{

	ADD_BLUE_TAG = 1,
	ADD_RED_TAG,
	CLEAR_ONE_TAG,
	CLEAR_ALL_TAG
};
enum GRID_MARKS
{
	MARK_NULL = 0,
	MARK_BANKER,
	MARK_PLAYER
};
//----------------------------FirstView-----------------------------------------
FirstView::FirstView()
{

}

FirstView::~FirstView()
{

}
void FirstView::pushBtn_RED(unsigned int section, unsigned int row, unsigned int item){
	
	
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CALabel* lable = (CALabel*)p_Cell->getSubviewByTag(99)->getSubviewByTag(100);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	lable->setText(UTF8("庄"));
#else
	lable->setText("庄");
#endif	
	lable->setColor(CAColor_red);
	
	
	//char pos[20] = "";
	//sprintf(pos, "%d", item);
	//CALabel*label = (CALabel*)cell->getSubviewByTag(100)->getSubviewByTag(101);
	//label->setText(pos);
}
void FirstView::pushBtn_BLUETEST(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAView* m_View = p_Cell->getSubviewByTag(99);
	m_View->setColor(CAColor_blueTest);
}
void FirstView::pushBtn_GRAYTEST(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAView* m_View = p_Cell->getSubviewByTag(99);
	m_View->setColor(CAColor_grayTest);
}
void FirstView::pushBtn_WHITETEST(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CAView* m_View = p_Cell->getSubviewByTag(99);
	m_View->setColor(CAColor_white);
}
void FirstView::pushBtn_BLUE(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CALabel* lable = (CALabel*)p_Cell->getSubviewByTag(99)->getSubviewByTag(100);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	lable->setText(UTF8("闲"));
#else
	lable->setText("闲");
#endif	

	lable->setColor(CAColor_blue);
	

}
void FirstView::pushBtn_WHITE(unsigned int section, unsigned int row, unsigned int item){
	CACollectionViewCell* p_Cell = p_Conllection->GetViewCell(section, row, item);
	if (!p_Cell) return;
	CALabel* lable = (CALabel*)p_Cell->getSubviewByTag(99)->getSubviewByTag(100);
	//lable->setText(UTF8(" "));
	lable->setText(" ");
}

void FirstView::refreshData()
{
	p_Conllection->reloadData();
}
void FirstView::viewDidLoad()
{
	vector<std::string> LableData;

	CCSize size = this->getView()->getBounds().size;
	//headerRefreshView = CAPullToRefreshView::create(CAPullToRefreshView::CAPullToRefreshTypeHeader);
	//footerRefreshView = CAPullToRefreshView::create(CAPullToRefreshView::CAPullToRefreshTypeFooter);

	p_Conllection = CACollectionView::createWithCenter(CCRect(size.width/2,size.height/2,size.width,size.height));
	p_Conllection->setAllowsSelection(false);
	p_Conllection->setBounceVertical(false);
	p_Conllection->setAllowsMultipleSelection(false);
	p_Conllection->setCollectionViewDataSource(this);
	p_Conllection->setCollectionViewDelegate(this);
	p_Conllection->setShowsVerticalScrollIndicator(false);

	//p_Conllection->setHeaderRefreshView(headerRefreshView);
	//p_Conllection->setFooterRefreshView(footerRefreshView);
	//p_Conllection->setHoriInterval(_px(1));
	//p_Conllection->setVertInterval(_px(1));
    this->getView()->addSubview(p_Conllection);
}

void FirstView::viewDidUnload()
{
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}

void FirstView::collectionViewDidSelectCellAtIndexPath(CACollectionView *collectionView, unsigned int section, unsigned int row, unsigned int item)
{
	//CCLog(UTF8("选中"));
}
void FirstView::collectionViewDidDeselectCellAtIndexPath(CACollectionView *collectionView, unsigned int section, unsigned int row, unsigned int item)
{
	
	
}

//获取指定cell
CACollectionViewCell* FirstView::collectionCellAtIndex(CACollectionView *collectionView, \
	const CCSize& cellSize, unsigned int section, unsigned int row, unsigned int item){

 //	CCLog("-------------row * 10 + item=%d-------------------", row * 10 + item);

	
	    CACollectionViewCell* cell = collectionView->dequeueReusableCellWithIdentifier("crossApp");
		if (cell == NULL)
		{
			cell = CACollectionViewCell::create("crossApp");
		
			
	
			CAView* m_View = CAView::createWithFrame(CCRect(0, 0, cellSize.width, cellSize.height));
			m_View->setTag(99);
			m_View->setColor(CAColor_white);
			cell->addSubview(m_View);

			CALabel* m_Label = CALabel::createWithCenter(CCRect(cellSize.width*0.5, cellSize.height*0.5, cellSize.width, cellSize.height));
		    m_Label->setTag(100);
			m_Label->setTextAlignment(CATextAlignmentCenter);
			m_Label->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
			CCLog("-------------------cellSize.width=%f-----------------", cellSize.width);
			CCLog("-------------------cellSize.height=%f-----------------", cellSize.height);
			m_Label->setFontSize(cellSize.height-_px(3));
			m_View->addSubview(m_Label);
			
			
		}
		
 		return cell;
	}

//collectionView 个数,设置为1就一个，如果为2，那么会有80个view（160*160）
unsigned int FirstView::numberOfSections(CACollectionView *collectionView)
{
	return 1;
}
//有多少行
unsigned int FirstView::numberOfRowsInSection(CACollectionView *collectionView, unsigned int section)
{
	return 10;
}
//一行有多少个
unsigned int FirstView::numberOfItemsInRowsInSection(CACollectionView *collectionView, unsigned int section, unsigned int row)
{
	//return 22;
	return 22;
}
//cell高度
unsigned int FirstView::collectionViewHeightForRowAtIndexPath(CACollectionView* collectionView, unsigned int section, unsigned int row)
{
	return (this->getView()->getBounds().size.height)/10;
}
void FirstView::SetSuperView(CAView * pView){
//	m_pContainer = pView;
	addViewFromSuperview(pView);
}
//------------------------------FirstViewController.h-----------------------------------------
FirstViewController::FirstViewController() :state(false)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 22; j++)
		{

			a[i][j] = WHITE;

		}
	}

}
FirstViewController::~FirstViewController()
{

}
void FirstViewController::viewDidLoad(){

	

	float lineHight = _px(50);
	CCRect winRect = this->getView()->getBounds();

	float INTERVAL_PX = winRect.size.width / 20;
	float TEXTFIELD_LONG = (winRect.size.width - INTERVAL_PX * 5 - INTERVAL_PX*4) / 3;
	//----------------------------------TextField-----------------------------------------
	

	CATextField* textField1 = CATextField::createWithFrame(CCRect(INTERVAL_PX, _px(20), TEXTFIELD_LONG, _px(50)));
	textField1->setTag(1006);
	textField1->setSpaceHolderColor(CAColor_orange);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	textField1->setPlaceHolder(UTF8("3-10有效"));

#else
		textField1->setPlaceHolder("3-10有效");
#endif	
	getView()->addSubview(textField1);

	CALabel*message = CALabel::createWithFrame(CCRect(INTERVAL_PX, _px(20 + 50 + 5), TEXTFIELD_LONG, _px(50)));
	message->setColor(CAColor_red);
	message->setTag(11);
	message->setFontSize(_px(15));
	message->setText(" ");
	//message->setText(UTF8("1111").c_str());
	getView()->addSubview(message);

	CAButton* MultiRoadButton = CAButton::createWithFrame(CCRect(TEXTFIELD_LONG + INTERVAL_PX * 2, _px(16),INTERVAL_PX * 2, _px(50)), CAButtonTypeRoundedRect);
	MultiRoadButton->setTag(1007);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	MultiRoadButton->setTitleForState(CAControlStateAll, UTF8("换珠"));
#else
	MultiRoadButton->setTitleForState(CAControlStateAll, "换珠");
#endif	
	MultiRoadButton->addTarget(this, CAControl_selector(FirstViewController::CMultiRoadButton), CAControlEventTouchUpInSide);
	getView()->addSubview(MultiRoadButton);

	
	CATextField* textField2 = CATextField::createWithFrame(CCRect(TEXTFIELD_LONG + INTERVAL_PX * 5, _px(20), TEXTFIELD_LONG, _px(50)));
	textField2->setSpaceHolderColor(CAColor_orange);
	textField2->setTag(1008);
	textField2->setPlaceHolder("");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	textField2->setPlaceHolder( UTF8("输入切数"));
#else
	textField2->setPlaceHolder("输入切数");
#endif	
	getView()->addSubview(textField2);
	CALabel*cutMessage = CALabel::createWithFrame(CCRect(TEXTFIELD_LONG + INTERVAL_PX * 5, _px(20 + 50 + 5), TEXTFIELD_LONG, _px(50)));
	cutMessage->setColor(CAColor_red);
	cutMessage->setTag(12);
	cutMessage->setFontSize(_px(15));
	//message->setText(UTF8("1111").c_str());
	getView()->addSubview(cutMessage);
//-------------------------------------绿灰统计----------------------------------------------------//
	CAView* greenView = CAView::createWithFrame(CCRect(TEXTFIELD_LONG*2 + INTERVAL_PX * 6, _px(20), INTERVAL_PX , _px(50)));
	greenView->setColor(CAColor_green);
	getView()->addSubview(greenView);
	CALabel* countGreenSize = CALabel::createWithFrame(CCRect(TEXTFIELD_LONG * 2 + INTERVAL_PX * 7 , _px(12), INTERVAL_PX*2 , _px(50)));
	countGreenSize->setText("");
	countGreenSize->setTag(777);
	countGreenSize->setFontSize(_px(25));
	countGreenSize->setTextAlignment(CATextAlignmentCenter);
	getView()->addSubview(countGreenSize);
	CALabel* countGreenColor = CALabel::createWithFrame(CCRect(TEXTFIELD_LONG * 2 + INTERVAL_PX * 7, _px(12 + 22), INTERVAL_PX*2, _px(50)));
	countGreenColor->setText(UTF8(""));
	countGreenColor->setTag(778);
	countGreenColor->setFontSize(_px(25));
	countGreenColor->setTextAlignment(CATextAlignmentCenter);
	getView()->addSubview(countGreenColor);
	
	CAView* gray = CAView::createWithFrame(CCRect(TEXTFIELD_LONG * 2 + INTERVAL_PX * 9, _px(20), INTERVAL_PX, _px(50)));
	gray->setColor(CAColor_gray);
	getView()->addSubview(gray);
	CALabel* countGraySize = CALabel::createWithFrame(CCRect(TEXTFIELD_LONG * 2 + INTERVAL_PX * 10 , _px(12), INTERVAL_PX*2 , _px(50)));
	countGraySize->setText("");
	countGraySize->setTag(888);
	countGraySize->setFontSize(_px(25));
	countGraySize->setTextAlignment(CATextAlignmentCenter);
	getView()->addSubview(countGraySize);
	CALabel* countGrayColor = CALabel::createWithFrame(CCRect(TEXTFIELD_LONG * 2 + INTERVAL_PX * 10 , _px(12 + 22), INTERVAL_PX*2 , _px(50)));
	countGrayColor->setText(UTF8(""));
	countGrayColor->setTag(889);
	countGrayColor->setFontSize(_px(25));
	countGrayColor->setTextAlignment(CATextAlignmentCenter);
	getView()->addSubview(countGrayColor);
	
	//-------------------------------SubView------------------------------------------
	float viewHight = (winRect.size.height - _px(10) - _px(50) - 3 * lineHight-_px(200))/3;
	m_pContainer1 = new CAView();
	//第一个视图多加20的高度
	m_pContainer1->setFrame(CCRect(0, _px(60) + lineHight, winRect.size.width, viewHight+_px(50)));
	this->getView()->addSubview(m_pContainer1);

	float secondViewY = m_pContainer1->getFrameOrigin().y + viewHight + lineHight+_px(50);

	//bkgView = CAScale9ImageView::createWithImage(CAImage::create("source_material/round2.png"));
	//bkgView->setFrame(CADipRect(1, size.height / 3, size.width - 1, size.height / 3));
	//this->getView()->addSubview(bkgView);
	


	CALabel* label = CALabel::createWithFrame(CCRect(5, secondViewY - _px(50), 20, 10));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	textField2->setPlaceHolder(UTF8("开启gaib"));
#else
	textField2->setPlaceHolder("输入切数");
#endif	
	
	CAScale9ImageView* m_pContainer2Image = CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_square_normal.png"));
	m_pContainer2Image->setFrame(CCRect(_px(1), secondViewY, winRect.size.width, winRect.size.width / 22 * 6 + _px(1)));
	this->getView()->addSubview(m_pContainer2Image);



	m_pContainer2 = CAScale9ImageView::createWithImage(CAImage::create("source_material/round1.png"));
	m_pContainer2->setFrame(CCRect(_px(1), secondViewY, winRect.size.width, winRect.size.width / 22 * 6));
	this->getView()->addSubview(m_pContainer2);



	float secondViewY2 = m_pContainer2->getFrame().origin.y+m_pContainer2->getFrame().size.height + _px(60);
	
	CAScale9ImageView* m_pContainer3Image = CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_square_normal.png"));
	m_pContainer3Image->setFrame(CCRect(_px(1), secondViewY2, winRect.size.width, winRect.size.width / 22 * 6 + _px(1)));
	this->getView()->addSubview(m_pContainer3Image);

	m_pContainer3 = new CAView();
	m_pContainer3->setFrame(CCRect(_px(1), secondViewY2, winRect.size.width, winRect.size.width / 22 * 6));
	this->getView()->addSubview(m_pContainer3);

	SubDataView1 = new FirstView();
	SubDataView1->init();
	//FristView的父类视图是有一个view(m_pContainer)
	SubDataView1->SetSuperView(m_pContainer1);

	

	SubDataView2 = new DataSubViewController();
	SubDataView2->init();
	//FristView的父类视图是有一个view(m_pContainer)
	SubDataView2->SetSuperView(m_pContainer2);

	SubDataView3 = new DataSubViewController();
	SubDataView3->init();
	//FristView的父类视图是有一个view(m_pContainer)
	SubDataView3->SetSuperView(m_pContainer3);

	/// ------------------------------

	//添加一个不切的按钮
	defaultSwitch = CASwitch::createWithFrame(CCRect(5, secondViewY2 - _px(60), 50, 50));
	defaultSwitch->setTag(100);
	defaultSwitch->addTarget(this, CAControl_selector(FirstViewController::switchStateChange));
	this->getView()->addSubview(defaultSwitch);

	//------------------------------------------------button----------------------------------------------
	float BUTTON_LONG = (winRect.size.width - _px(60)) / 4;

	float buttonY = secondViewY2  + winRect.size.width / 22 * 6 + _px(10);

	
	CAButton* m_button = CAButton::createWithFrame(CCRect(_px(10), buttonY, BUTTON_LONG, _px(90)), CAButtonTypeSquareRect);
	m_button->addTarget(this, CAControl_selector(FirstViewController::CLandlordBton),CAControlEventTouchUpInSide);
	//m_button->setTitleForState(CAControlStateAll, UTF8("庄"));
	m_button->setBackGroundViewForState(CAControlStateNormal, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_normal.png")));
	m_button->setBackGroundViewForState(CAControlStateHighlighted, CAScale9ImageView::createWithImage(CAImage::create("source_material/ex4.png")));
	m_button->setBackGroundViewForState(CAControlStateSelected, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_selected.png")));
	m_button->setTitleColorForState(CAControlStateNormal, CAColor_white);
	m_button->setTitleColorForState(CAControlStateHighlighted, CAColor_red);
	//m_button->setTitleColorForState(CAControlStateSelected, CAColor_red);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_button->setTitleForState(CAControlStateAll, UTF8("庄"));
	
#else
	m_button->setTitleForState(CAControlStateAll, "庄");
#endif
	CAButton* m_button1 = CAButton::createWithFrame(CCRect(_px(10) * 2 + BUTTON_LONG, buttonY, BUTTON_LONG, _px(90)), CAButtonTypeSquareRect);
	m_button1->setBackGroundViewForState(CAControlStateNormal, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_normal.png")));
	m_button1->setBackGroundViewForState(CAControlStateHighlighted, CAScale9ImageView::createWithImage(CAImage::create("source_material/ex4.png")));
	m_button1->setBackGroundViewForState(CAControlStateSelected, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_selected.png")));
	m_button1->setTitleColorForState(CAControlStateNormal, CAColor_white);
	m_button1->setTitleColorForState(CAControlStateHighlighted, CAColor_red);
	m_button1->addTarget(this, CAControl_selector(FirstViewController::CFarmerBton), CAControlEventTouchUpInSide);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_button1->setTitleForState(CAControlStateAll, UTF8("闲"));
#else	
	m_button1->setTitleForState(CAControlStateAll, "闲");
#endif

	CAButton* m_button2 = CAButton::createWithFrame(CCRect(_px(10) * 4 + BUTTON_LONG * 3, buttonY, BUTTON_LONG, _px(90)), CAButtonTypeSquareRect);
	m_button2->addTarget(this, CAControl_selector(FirstViewController::CClear_ONE), CAControlEventTouchUpInSide);
	m_button2->setBackGroundViewForState(CAControlStateNormal, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_normal.png")));
	m_button2->setBackGroundViewForState(CAControlStateHighlighted, CAScale9ImageView::createWithImage(CAImage::create("source_material/ex4.png")));
	m_button2->setBackGroundViewForState(CAControlStateSelected, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_selected.png")));
	m_button2->setTitleColorForState(CAControlStateNormal, CAColor_white);
	m_button2->setTitleColorForState(CAControlStateHighlighted, CAColor_red);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_button2->setTitleForState(CAControlStateAll, UTF8("退"));
#else
	m_button2->setTitleForState(CAControlStateAll, "退");
#endif
	CAButton* m_button3 = CAButton::createWithFrame(CCRect(this->getView()->getBounds().size.width - BUTTON_LONG, secondViewY2 - _px(60), BUTTON_LONG, _px(60)), CAButtonTypeSquareRect);
	m_button3->addTarget(this, CAControl_selector(FirstViewController::CClear_ALL), CAControlEventTouchUpInSide);
	m_button3->setBackGroundViewForState(CAControlStateNormal, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_normal.png")));
	//m_button3->setBackGroundViewForState(CAControlStateHighlighted, CAScale9ImageView::createWithImage(CAImage::create("source_material/ex4.png")));
	m_button3->setBackGroundViewForState(CAControlStateSelected, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_selected.png")));
	m_button3->setTitleColorForState(CAControlStateNormal, CAColor_white);
	
	m_button3->setTitleColorForState(CAControlStateHighlighted, CAColor_red);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_button3->setTitleForState(CAControlStateAll, UTF8("清除"));
#else
	m_button3->setTitleForState(CAControlStateAll, "清除");
#endif
	CAButton* m_button4 = CAButton::createWithFrame(CCRect(_px(10) * 3 + BUTTON_LONG * 2, buttonY, BUTTON_LONG, _px(90)), CAButtonTypeSquareRect);
	m_button4->addTarget(this, CAControl_selector(FirstViewController::CCutButton), CAControlEventTouchUpInSide);
	m_button4->setBackGroundViewForState(CAControlStateNormal, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_normal.png")));
	m_button4->setBackGroundViewForState(CAControlStateHighlighted, CAScale9ImageView::createWithImage(CAImage::create("source_material/ex4.png")));
	m_button4->setBackGroundViewForState(CAControlStateSelected, CAScale9ImageView::createWithImage(CAImage::create("source_material/btn_rounded3D_selected.png")));
	m_button4->setTitleColorForState(CAControlStateNormal, CAColor_white);
	m_button4->setTitleColorForState(CAControlStateHighlighted, CAColor_red);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_button4->setTitleForState(CAControlStateAll, UTF8("切"));
#else
	m_button4->setTitleForState(CAControlStateAll, "切");
#endif
	getView()->addSubview(m_button);
	getView()->addSubview(m_button1);
	getView()->addSubview(m_button2);
	getView()->addSubview(m_button3);
	getView()->addSubview(m_button4);
	
}


void FirstViewController::switchStateChange(CAControl* btn, CCPoint point)
{
	CASwitch* stateS = (CASwitch*)btn;
	if (stateS->isOn()==true){
		state = true;
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		UtilManager::shareUtilManager()->toast(UTF8("不更新大路和绿黑路~"), this);
	#else
		UtilManager::shareUtilManager()->toast("不更新大路和绿黑路~", this);
	#endif

	}
	else
	{
		
		state = false;
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		UtilManager::shareUtilManager()->toast(UTF8("更新大路和绿黑路~"), this);
	#else
		UtilManager::shareUtilManager()->toast("更新大路和绿黑路~", this);
	#endif
	}
}

void FirstViewController::viewDidUnload(){

}
void FirstViewController::CCutButton(CAControl* btn, CCPoint point){
	
	CATextField* rowNumField = (CATextField*)getView()->getSubviewByTag(1008);
	const char* rowChar = rowNumField->getText().c_str();
	int  a = atoi(rowChar);
	if (a<m_MultiRoadData.size()&&a>0)
	{
		
		CALabel* cutMessage = (CALabel*)this->getView()->getSubviewByTag(12);
		cutMessage->setText(" ");
		int i = 0;
		int num = m_MultiRoadData.size() - a;
		vector<int>::iterator itor = m_MultiRoadData.begin();
		for (int i = 0; i < num; i++)

		{

			itor = m_MultiRoadData.erase(itor);
		}

		if (state == true)
		{
		
			ClearRoadForRow();
			CountMultiRoad();
			DrawbackgroundColor();
			ReashMultiRoadForRow();
			//预判断下一个颜色
			lastNextcolor();
			//统计当前的绿黑背景个数
			CountColorNum();
			return;
		
		
		}

		ClearRoadForRow();
		
	
		m_BLUE_GRAYRoadData.clear();
		BGRoad.clear();
		
		
		m_vecBigRoadData.clear();
		bigRoad.clear();
		//刷新第一个视图的label必须放在前面，这里这个方法不是单纯的刷新，方法最开始是给第一个视图label赋值
		CountMultiRoad();
		//ReashMultiRoadForRow();
		//CompoundColor();
		CompoundColor(ADD_RED_TAG);
		CompoundBigRoadColor();
		DrawbackgroundColor();
		ReashMultiRoadForRow();
		ReashBigRoad();
		ReashBLUE_GRAYRoad();
		//预判断下一个颜色
		lastNextcolor();
		//统计当前的绿黑背景个数
		CountColorNum();
	}
	else{
	
		CALabel* cutMessage = (CALabel*)this->getView()->getSubviewByTag(12);
		//cutMessage->setText(UTF8("输入无效"));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		cutMessage->setText(UTF8("输入无效"));
#else
		cutMessage->setText("输入无效");
#endif
	}
}
void FirstViewController::CMultiRoadButton(CAControl* btn, CCPoint point){

	CATextField* rowNumField = (CATextField*)getView()->getSubviewByTag(1006);
	 const char* rowChar = rowNumField->getText().c_str();
	 int  a = atoi(rowChar);
	 if (a<3||a>10)
	 {
		 CALabel* message = (CALabel*)this->getView()->getSubviewByTag(11);
		
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		 message->setText(UTF8("输入无效"));
#else
		 message->setText("输入无效");
#endif
		 return;
	 }
	 if (a>2&&a<11)
	 {
		 CALabel* message = (CALabel*)this->getView()->getSubviewByTag(11);
		 message->setText("");
		 RowNum = a;
		 ClearRoadForRow();
		 //SubDataView1->refreshData();
		 CountMultiRoad();
		 
		 m_BLUE_GRAYRoadData.clear();
		 BGRoad.clear();
         ReashMultiRoadForRow();
		 
		 CompoundColor(ADD_RED_TAG);
		 DrawbackgroundColor();
		 ReashBLUE_GRAYRoad();
		 //预判断下一个颜色
		 lastNextcolor();
		 //统计当前的绿黑背景个数
		 CountColorNum();
	 }
}
void FirstViewController::CLandlordBton(CAControl* btn, CCPoint point){
	
	//清除颜色，把2维数组赋值为0
	ClearRoadForRow();
	m_MultiRoadData.push_back(1);
	//计算显示是否越界，把对应的值赋值给数组(计算第一个图的a[i][j])
	CountMultiRoad();
	//计算第一副图的背景色
	
	
	if (state == false)
	{
		CompoundColor(ADD_RED_TAG);
	}
	else
	{
		m_BLUE_GRAYRoadData.push_back(1);
		BGRoad.addRoadData(1);
	}
	
    //CompoundColor();
	//画第一副图的背景色
	DrawbackgroundColor();
		
	m_vecBigRoadData.push_back(1);
	bigRoad.addRoadData(1);
	//刷新某一个cell
	//ReashMultiRoad(ADD_RED_TAG);
	//ReashMultiRoad();
	
	
	ReashMultiRoadForRow(); 
	ReashBLUE_GRAYRoad();
	
	ReashBigRoad();
	
	//预判断下一个颜色
	lastNextcolor();
	//统计当前的绿黑背景个数
	CountColorNum();
}
void FirstViewController::CFarmerBton(CAControl* btn, CCPoint point){
	
	//清除字的颜色，把2维数组赋值为0
	ClearRoadForRow();
	m_MultiRoadData.push_back(2);
	//计算显示是否越界，把对应的值赋值给数组
	CountMultiRoad();
	//计算第一副图的背景色
	if (state == false)
	{
		CompoundColor(ADD_RED_TAG);
	} else
	{
	m_BLUE_GRAYRoadData.push_back(2);
	BGRoad.addRoadData(2);
	}
	//CompoundColor();
	//画第一副图的背景色
	DrawbackgroundColor();

	m_vecBigRoadData.push_back(2);
	bigRoad.addRoadData(2);
	//ReashMultiRoad(ADD_BLUE_TAG);
	//ReashMultiRoad();
	
	ReashMultiRoadForRow();
	ReashBigRoad();
	ReashBLUE_GRAYRoad();
	//预判断下一个颜色
	lastNextcolor();
	//统计当前的绿黑背景个数
	CountColorNum();
}

void FirstViewController::CClear_ONE(CAControl* btn, CCPoint point){
	
	//清除字的颜色，把2维数组赋值为0
	ClearRoadForRow();
	//清除先要计算这个
	BackBlue_Blackspace();

	if (m_MultiRoadData.size()!=0)
	{
		m_MultiRoadData.pop_back();
	}
	//计算显示是否越界，把对应的值赋值给数组
	CountMultiRoad();
	//ReashMultiRoad();


	
	Backspace();
   
	
	
	
	//CompoundColor(ADD_BLUE_TAG);

	DrawbackgroundColor();
	ReashMultiRoadForRow();
	ReashBigRoad();
	/*ClearViewColor();*/

	
	ReashBLUE_GRAYRoad();
	//预判断下一个颜色
	lastNextcolor();
	//统计当前的绿黑背景个数
	CountColorNum();
}
void FirstViewController::CClear_ALL(CAControl* btn, CCPoint point){
	
	m_MultiRoadData.clear();
	
	m_vecBigRoadData.clear();
	bigRoad.clear();
	//ReashMultiRoad(CLEAR_ALL_TAG);
	//ReashMultiRoad();
	//CountMultiRoad();
	ReashMultiRoadForRow();

	ClearRoadForRow();
	ReashBigRoad();
	//ClearALLViewColor();
	

	m_BLUE_GRAYRoadData.clear();
	BGRoad.clear();
	ReashBLUE_GRAYRoad();
	//统计当前的绿黑背景个数
	lastNextcolor();
	CountColorNum();
}
void FirstViewController::ReashMultiRoad(){


	int startrow;
	if (m_MultiRoadData.size() / RowNum == 22 && m_MultiRoadData.size() % RowNum != 0){
		startrow = 1;
	}
	else if (m_MultiRoadData.size() / RowNum > 22){

		if (m_MultiRoadData.size() % RowNum)
		{
			startrow = m_MultiRoadData.size() / RowNum - 22 + 1;
		}
		else
		{
			startrow = m_MultiRoadData.size() / RowNum - 22;
		}

	}
	else
	{
		startrow = 0;
	}


	int z = startrow*RowNum;
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++){


			if (z < m_MultiRoadData.size() - startrow*RowNum)
			{
				a[i][j] = m_MultiRoadData[z];
				z++;
			}
		}
	}

	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++)
		{


			if (a[i][j] == WHITE)
			{
				SubDataView1->pushBtn_WHITE(0, i, j);

			}
			else if (a[i][j] == BLUE)
			{
				SubDataView1->pushBtn_BLUE(0, i, j);

			}
			else if (a[i][j] == RED)
			{
				SubDataView1->pushBtn_RED(0, i, j);

			}

		}
	}
}
void FirstViewController::ReashMultiRoad(int TAG){
	//bigRoad.addRoadData(1);
	
	int startrow;
	if (m_MultiRoadData.size() / RowNum == 22 && m_MultiRoadData.size() % RowNum != 0){
	startrow = 1;
	}
	else if (m_MultiRoadData.size() / RowNum > 22){

	if (m_MultiRoadData.size() % RowNum)
	{
	startrow = m_MultiRoadData.size() / RowNum - 22 + 1;
	}
	else
	{
	startrow = m_MultiRoadData.size() / RowNum - 22;
	}

	}
	else
	{
	startrow = 0;
	}

	
	
	//------------------------------------
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++)
		{

			if (TAG == CLEAR_ALL_TAG)
			{
				a[i][j] = WHITE;
				m_MultiRoadData.clear();
			//	SubDataView1->pushBtn_WHITE(0, i, j);
			
			}
			if (a[i][j] == WHITE)
			{

				if (TAG == ADD_RED_TAG)
				{
			//		SubDataView1->pushBtn_RED(0, i, j);
					a[i][j] = RED;
					return;
				}
				else if (TAG == ADD_BLUE_TAG)
				{
				//	SubDataView1->pushBtn_BLUE(0, i, j);
					a[i][j] = BLUE;
					return;
				}
				
				else if (TAG == CLEAR_ONE_TAG&&m_MultiRoadData.size()>0){

					if (i == 0 && a[RowNum-1][j - 1] != WHITE)
					{
						a[RowNum-1][j - 1] = WHITE;
						m_MultiRoadData.pop_back();
					//	SubDataView1->pushBtn_WHITE(0, RowNum-1, j - 1);
						return;
					}
					else if (i != 0)
					{
						a[i - 1][j] = WHITE;
						m_MultiRoadData.pop_back();
					//	SubDataView1->pushBtn_WHITE(0, i - 1, j);
						return;
					}
					
				}	
				
			}

		}
	}
	//--------------------------------------
	
}
void FirstViewController::ClearRoadForRow(){

	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < 10; i++)
		{ 
			
			SubDataView1->pushBtn_WHITE(0, i, j);
			SubDataView1->pushBtn_WHITETEST(0, i, j);
			a[i][j] = 0;
		}
	}
}

void FirstViewController::ClearMultiRoadLastColor(){
	
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++)
		{
		if (a[i][j] == WHITE&&a[0][0]!=WHITE){
			if (m_MultiRoadData.size() > 0){

				if (i == 0 && a[RowNum - 1][j - 1] != WHITE)
				{
					a[RowNum - 1][j - 1] = WHITE;
					m_MultiRoadData.pop_back();
					//	SubDataView1->pushBtn_WHITE(0, RowNum-1, j - 1);
					return;
				}
				else if (i != 0)
				{
					a[i - 1][j] = WHITE;
					m_MultiRoadData.pop_back();
					//	SubDataView1->pushBtn_WHITE(0, i - 1, j);
					return;
				  }

			  }

		   }
		}
	}
}
void FirstViewController::ReashMultiRoadForRow(){

     //偏移值
	
	
	
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++)
		{


			if (a[i][j] == WHITE)
			{
				SubDataView1->pushBtn_WHITE(0, i, j);
			
			}
			else if (a[i][j] == BLUE)
			{
				SubDataView1->pushBtn_BLUE(0, i, j);
				
			}
			else if (a[i][j] == RED)
			{
				SubDataView1->pushBtn_RED(0, i, j);
			
			}

		}
	}
}
void FirstViewController::ReashBigRoad(){
	//bigRoad.addRoadData(1);
	int startrow = bigRoad.m_Draw.getRowNum();
	startrow -= 22;
	if (startrow < 0) startrow = 0;
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			//if (a[i][j] == WHITE)
			//{
				//SubDataView1->pushBtn_BLUE(0, i, j);
				//a[i][j] = BLUE;
				
			int nMark = bigRoad.m_Draw.getData(j + startrow, i);
				if (nMark == 1)
				{
					SubDataView3->pushBtn_RED(0, i, j);
					

				}
				else if(nMark == 2){

					SubDataView3->pushBtn_BLUE(0, i, j);
				}else 
				{
					SubDataView3->pushBtn_WHITE(0, i, j);
				}
                 //return;
			
			//}

		}
	}
}
void FirstViewController::ReashBLUE_GRAYRoad(){
	//bigRoad.addRoadData(1);
	int startrow = BGRoad.m_Draw.getRowNum();
	startrow -= 22;
	if (startrow < 0) startrow = 0;
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			//if (a[i][j] == WHITE)
			//{
			//SubDataView1->pushBtn_BLUE(0, i, j);
			//a[i][j] = BLUE;

			int nMark = BGRoad.m_Draw.getData(j + startrow, i);
			if (nMark == 1)
			{
			//	m_BLUE_GRAYRoadData.push_back(1);
				SubDataView2->pushBtn_BLUEVIEWTEST(0, i, j);

				
			}
			else if (nMark == 2){
			//	m_BLUE_GRAYRoadData.push_back(2);
				SubDataView2->pushBtn_BLACKVIEWTEST(0, i, j);
			}
			else
			{
				SubDataView2->pushBtn_WHITE(0, i, j);
			}
			//return;

			//}

		}
	}
}



void FirstViewController::Backspace(){
	
	//int nIndex = MARK_PLAYER;
	//m_vecBigRoadData.push_back(nIndex);


	//int nSize = m_wndGrid.m_vecDataList.size();
	int nSize = m_vecBigRoadData.size();
	if (nSize > 0)
	{
		m_vecBigRoadData.pop_back();
	}

	bigRoad.clear();
	vector<int>::iterator itor = m_vecBigRoadData.begin();
	for (int i = 0; i < m_vecBigRoadData.size(); i++)
	{
		bigRoad.addRoadData(m_vecBigRoadData[i]);
	}
	//m_wndRoad.RefreashRoad(bigRoad);
	
}
void FirstViewController::BackBlue_Blackspace(){

// 	if (state==true)
// 	{
// 		int nSize = m_BLUE_GRAYRoadData.size();
// 		if (nSize > 0)
// 		{
// 			m_BLUE_GRAYRoadData.pop_back();
// 		}
// 
// 		BGRoad.clear();
// 
// 
// 		vector<int>::iterator itor = m_BLUE_GRAYRoadData.begin();
// 		for (int i = 0; i < m_BLUE_GRAYRoadData.size(); i++)
// 		{
// 			BGRoad.addRoadData(m_BLUE_GRAYRoadData[i]);
// 		}
// 		return;
// 	}

	//m_nNumRows = 10;
	int nSize = m_MultiRoadData.size();
	int nCol = 0;
	int nRow = 0;

	
	if (nSize > 0)
	{
		nRow = nSize / RowNum;
		nCol = nSize%RowNum;
		
		
		if (nCol==0)
		{
			nRow = nRow - 1;
			nCol = RowNum;
		}
		nCol = nCol - 1;
		
		
		
		if (nCol >1 && nRow >0)
		{
			//int n1 = a[0][0];
			//int n2 = a[0][1];
			//int n3 = a[1][0];
			//int n4 = a[1][1];

			//int nMark = a[nRow][nCol];

			//int n5 = a[nCol - 1][nRow];
			//int n6 = a[nCol - 1][nRow - 1];
			//int n7 = a[nCol][nRow - 1];
			//int n8 = a[nCol][nRow];
			//int nRet1 = (n1 + n2 + n3 + n4) % 2;
			//int nRet2 = (n5 + n6 + n7 + n8) % 2;

			//&& a[nCol - 1][nRow] != WHITE && a[nCol][nRow] == WHITE
			
			//绿色
			int nSize = m_BLUE_GRAYRoadData.size();
			if (nSize > 0)
				{
					m_BLUE_GRAYRoadData.pop_back();
				}
			   
					BGRoad.clear();
			    
				
				vector<int>::iterator itor = m_BLUE_GRAYRoadData.begin();
				for (int i = 0; i < m_BLUE_GRAYRoadData.size(); i++)
				{
					BGRoad.addRoadData(m_BLUE_GRAYRoadData[i]);
				}
				//return;
			
			
			//return;
		}

	}


}
void FirstViewController::CompoundColor(int TAG){
	//定义行，列
		//int row, col;
	
		m_BLUE_GRAYRoadData.clear();
		
	
	   BGRoad.clear();
	
		
		for (int j = 1; j < 22; j++){

		for (int i = 2; i < RowNum; i++){
			
		
			int n1 = a[0][j - 1];
			int n2 = a[1][j - 1];
			int n3 = a[0][j];
			int n4 = a[1][j];

			int n5 = a[i - 1][j];
			int n6 = a[i - 1][j - 1];
			int n7 = a[i][j - 1];
			int n8 = a[i][j];

			int nRet1 = (n1 + n2 + n3 + n4) % 2;
			int nRet2 = (n5 + n6 + n7 + n8) % 2;
			if (n8 == 0)
			{
				return;
			}
			if (nRet1 == nRet2)
			{
				//绿色
				//SubDataView1->pushBtn_BLUETEST(0, i, j);
				m_BLUE_GRAYRoadData.push_back(1);
				BGRoad.addRoadData(1);
				//return;

			}
			else
			{
				//黑色
				//SubDataView1->pushBtn_GRAYTEST(0, i, j);
				m_BLUE_GRAYRoadData.push_back(2);
				BGRoad.addRoadData(2);
				//return;
			}

	 
		
	}
		
}
}


	



	

void FirstViewController::ClearALLViewColor(){
	//清除背景色
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 22; j++)
		{

			
			SubDataView1->pushBtn_WHITETEST(0, i, j);
		}
	}

	
}
void FirstViewController::ClearViewColor(){
	//清除一个背景色
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			//if (a[i][j] == WHITE)
			//{
			//	SubDataView1->pushBtn_WHITETEST(0, i-1, j);
			//	return;
			//}
			if (i>1&&j>0)
			{
				if (a[0][j] == WHITE&&a[9][j - 1] != WHITE)
				{

					SubDataView1->pushBtn_WHITETEST(0, 0, j);
					return;
				}
				else if (a[i][j] == WHITE&&a[i][j - 1] != WHITE)
				{
					
					SubDataView1->pushBtn_WHITETEST(0, i , j);
					return;
				}
			}
			
			
		}
	}
	

}
void FirstViewController::BackMultiRoadSpace(){
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < 10; i++)
		{

		
			if (m_MultiRoadData.size()>0)
				 {
					 if (i == 0 && a[9][j - 1] != WHITE)
					 {
						 a[9][j - 1] = WHITE;
						 m_MultiRoadData.pop_back();

						 return;
					 }
					 else if (i != 0)
					 {
						 a[i - 1][j] = WHITE;
						 m_MultiRoadData.pop_back();

						 return;
					 }
				 }

					

				

			}

		
	}
}/*
void FirstViewController::CompoundColor(){

	for (int j = 1; j < 22; j++){

		for (int i = 2; i < RowNum; i++){
			int n1 = a[0][j-1];
			int n2 = a[1][j-1];
			int n3 = a[0][j];
			int n4 = a[1][j];

			int n5 = a[i - 1][j];
			int n6 = a[i - 1][j - 1];
			int n7 = a[i][j - 1];
			int n8 = a[i][j];

			int nRet1 = (n1 + n2 + n3 + n4) % 2;
			int nRet2 = (n5 + n6 + n7 + n8) % 2;
			if (n8==0)
			{
				return;
			}
			if (nRet1 == nRet2)
			{
				//绿色
				SubDataView1->pushBtn_BLUETEST(0, i, j);
				m_BLUE_GRAYRoadData.push_back(1);
				BGRoad.addRoadData(1);
				
			}
			else
			{
				//黑色
				SubDataView1->pushBtn_GRAYTEST(0, i, j);
				m_BLUE_GRAYRoadData.push_back(2);
				BGRoad.addRoadData(2);
			
			}


		}

	}


	
}
*/
void FirstViewController::CompoundBigRoadColor(){


	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++)
		{


			if (a[i][j] == WHITE)
			{
				//m_vecBigRoadData.push_back(0);
				//bigRoad.addRoadData(0);
			}
			else if (a[i][j] == BLUE)
			{
				m_vecBigRoadData.push_back(2);
				//根据1,2 确定i，j坐标
				bigRoad.addRoadData(2);

			}
			else if (a[i][j] == RED)
			{
				m_vecBigRoadData.push_back(1);
			
				bigRoad.addRoadData(1);

			}

		}
	}
}
void FirstViewController::CountMultiRoad(){
	int startrow;
	if (m_MultiRoadData.size() == 0) return;
	if (m_MultiRoadData.size() / RowNum == 22 && m_MultiRoadData.size() % RowNum != 0){
		startrow = 1;
	}
	else if (m_MultiRoadData.size() / RowNum > 22){

		if (m_MultiRoadData.size() % RowNum)
		{
			startrow = m_MultiRoadData.size() / RowNum - 22 + 1;
		}
		else
		{
			startrow = m_MultiRoadData.size() / RowNum - 22;
		}

	}
	else
	{
		startrow = 0;
	}

	int z = startrow*RowNum;


	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < RowNum; i++){


			if (z < m_MultiRoadData.size())
			{
				a[i][j] = m_MultiRoadData[z];
				z++;
			}

		}
	}

}
void FirstViewController::DrawbackgroundColor(){
	for (int j = 1; j < 22; j++){

		for (int i = 2; i < RowNum; i++){
			int n1 = a[0][j - 1];
			int n2 = a[1][j - 1];
			int n3 = a[0][j];
			int n4 = a[1][j];

			int n5 = a[i - 1][j];
			int n6 = a[i - 1][j - 1];
			int n7 = a[i][j - 1];
			int n8 = a[i][j];

			int nRet1 = (n1 + n2 + n3 + n4) % 2;
			int nRet2 = (n5 + n6 + n7 + n8) % 2;
			if (n8 == 0)
			{
				return;
			}
			if (nRet1 == nRet2)
			{
				//绿色
				SubDataView1->pushBtn_BLUETEST(0, i, j);
				//m_BLUE_GRAYRoadData.push_back(1);
				//BGRoad.addRoadData(1);

			}
			else
			{
				//黑色
				SubDataView1->pushBtn_GRAYTEST(0, i, j);
				//m_BLUE_GRAYRoadData.push_back(2);
				//BGRoad.addRoadData(2);

			}


		}

	}


}
void FirstViewController::lastNextcolor(){

	//m_BLUE_GRAYRoadData.clear();
	//BGRoad.clear();
	for (int j = 1; j < 22; j++){

		for (int i = 2; i < RowNum; i++){


			int n1 = a[0][j - 1];
			int n2 = a[1][j - 1];
			int n3 = a[0][j];
			int n4 = a[1][j];

			int n5 = a[i - 1][j];
			int n6 = a[i - 1][j - 1];
			int n7 = a[i][j - 1];
			int n8 = a[i][j];

			
			if (n8 == 0&&a[0][j]&&a[1][j])
			{
				
				n8 = 1;
				int nRet1 = (n1 + n2 + n3 + n4) % 2;
				int nRet2 = (n5 + n6 + n7 + n8) % 2;
				if (nRet1 == nRet2)
				{

					CALabel*label1 = (CALabel*)this->getView()->getSubviewByTag(778);
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
					label1->setText(UTF8("庄"));
            #else
					label1->setText("庄");
            #endif
					
			CALabel*label2 = (CALabel*)this->getView()->getSubviewByTag(889);
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)		
			        label2->setText(UTF8("闲"));
            #else
			        label2->setText("闲");
            #endif
				}
				
				else{
					CALabel*label1 = (CALabel*)this->getView()->getSubviewByTag(778);
                    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
					label1->setText(UTF8("闲"));
                    #else
					label1->setText("闲");
                    #endif
					CALabel*label2 = (CALabel*)this->getView()->getSubviewByTag(889);
                    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)		
					label2->setText(UTF8("庄"));
                    #else
					label2->setText("庄");
                  #endif
				}

				return;
			}
			else{
			
				CALabel*label1 = (CALabel*)this->getView()->getSubviewByTag(778);
				label1->setText("");
				//第二个灰
				CALabel*label2 = (CALabel*)this->getView()->getSubviewByTag(889);
				label2->setText("");
			}
			


		}

	}
}
void FirstViewController::CountColorNum(){

	int colorGrayNum=0, colorGreenNum=0;
	for (int j = 1; j < 22; j++){

		for (int i = 2; i < RowNum; i++){
			int n1 = a[0][j - 1];
			int n2 = a[1][j - 1];
			int n3 = a[0][j];
			int n4 = a[1][j];

			int n5 = a[i - 1][j];
			int n6 = a[i - 1][j - 1];
			int n7 = a[i][j - 1];
			int n8 = a[i][j];

			int nRet1 = (n1 + n2 + n3 + n4) % 2;
			int nRet2 = (n5 + n6 + n7 + n8) % 2;
			if (n8 == 0)
			{
				char bufGreen[10];
				sprintf(bufGreen, "%d", colorGreenNum);

				char bufGray[10];
				sprintf(bufGray, "%d", colorGrayNum);


				CALabel*label1 = (CALabel*)this->getView()->getSubviewByTag(777);
				label1->setText(bufGreen);
				CALabel*label2 = (CALabel*)this->getView()->getSubviewByTag(888);
				label2->setText(bufGray);
				return;
			}
			if (nRet1 == nRet2)
			{
				colorGreenNum++;



			}
			else
			{

				colorGrayNum++;


			}


		}

	}
	char bufGreen[10];
	sprintf(bufGreen, "%d", colorGreenNum);

	char bufGray[10];
	sprintf(bufGray, "%d", colorGrayNum);
	CALabel*label1 = (CALabel*)this->getView()->getSubviewByTag(777);
	label1->setText(bufGreen);
	CALabel*label2 = (CALabel*)this->getView()->getSubviewByTag(888);
	label2->setText(bufGray);
}