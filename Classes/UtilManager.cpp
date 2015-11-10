#include"UtilManager.h"


#define TOAST_VIEW_TAG 11223344
#define TOAST_TIME 1.0


static UtilManager *_util = NULL;

UtilManager* UtilManager::shareUtilManager() {

	if (_util == NULL) {
		_util = new UtilManager();
	}
	return _util;
}

UtilManager::UtilManager(void)
{
}


UtilManager::~UtilManager(void)
{
	CC_SAFE_RELEASE_NULL(_util);
}

void UtilManager::scheduleOnce(SEL_SCHEDULE pfnSelector, CAObject *pTarget, float delay) {

	CAScheduler::schedule(pfnSelector, pTarget, 0, 0, delay, false);
}
void UtilManager::toast(string text, CAViewController* object) {

	CAApplication::getApplication()->getRootWindow()->removeSubviewByTag(TOAST_VIEW_TAG);

	CCSize winSize = CAApplication::getApplication()->getWinSize();
	//CAView *back = CAView::createWithCenter(CCRect(winSize.width*0.5, winSize.height*0.5, _dip(winSize.width)*0.3, _dip(winSize.height)*0.3));
	CAView *back = CAView::createWithCenter(CCRect(winSize.width*0.5, winSize.height*0.5, 250 * getScale(), 100 * getScale()));
	back->setTag(TOAST_VIEW_TAG);
	back->setColor(ccc4(31, 31, 31, 200));//40

	CALabel *title = CALabel::createWithCenter(CADipRect(_dip(back->getBounds().size.width*0.5),
		_dip(back->getBounds().size.height*0.5), 2500 * getScale(), 100 * getScale()));
	//	title->setText(UTF8ToGBK::transferToGbk(text));
	title->setText(text);
	//title->setText("sssss");
	//	title->setFontName(getChineseFont());
	title->setColor(CAColor_white);
	title->setTextAlignment(CATextAlignmentCenter);
	title->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
	title->setFontSize(_px(15));
	back->addSubview(title);
	//CAApplication::getApplication()->getRootWindow()->getRootViewController()->getView()->addSubview(back);
	back->runAction(CCFadeOut::create(1));

	//CAApplication::getApplication()->getRootWindow()->addSubview(back);
	object->getView()->addSubview(back);
	//CCLog("%s", get_date_now().c_str());
	scheduleOnce(schedule_selector(UtilManager::removeToast), this, TOAST_TIME);
}

void UtilManager::toast(string text, string image, bool isSmall) {

	CAApplication::getApplication()->getRootWindow()->removeSubviewByTag(TOAST_VIEW_TAG);

	CCSize winSize = CAApplication::getApplication()->getWinSize();

	CAImageView *back = CAImageView::create();
	if (isSmall == false) {
		//CAView *back = CAView::createWithCenter(CCRect(winSize.width*0.5, winSize.height*0.5, _dip(winSize.width)*0.3, _dip(winSize.height)*0.3));
		back->setCenter(CCRect(winSize.width*0.5, winSize.height*0.55, _px(120), _px(120)));
	}
	else {
		back->setCenter(CCRect(winSize.width*0.5, winSize.height*0.4, _px(120), _px(120)));
	}
	back->setTag(TOAST_VIEW_TAG);
	back->setImage(CAImage::create("image/scape_storage.png"));
	//back->setColor(ccc4(31, 31, 31, 200));//40

	CALabel *title = CALabel::createWithCenter(CADipRect(_dip(back->getBounds().size.width*0.5),
		_dip(back->getBounds().size.height*0.8), 100, 100));
	//title->setText(UTF8ToGBK::transferToGbk(text));
	//title->setFontName(getChineseFont());
	title->setColor(CAColor_white);
	title->setTextAlignment(CATextAlignmentCenter);
	title->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
	title->setFontSize(_px(22));
	back->addSubview(title);

	CAImageView *icon = CAImageView::create();
	if (isSmall == false) {
		//CAView *back = CAView::createWithCenter(CCRect(winSize.width*0.5, winSize.height*0.5, _dip(winSize.width)*0.3, _dip(winSize.height)*0.3));
		icon->setCenter(CADipRect(_dip(back->getBounds().size.width*0.5), _dip(back->getBounds().size.height*0.4), 90 / 1.5, 68 / 1.5));
	}
	else {
		icon->setCenter(CADipRect(_dip(back->getBounds().size.width*0.5), _dip(back->getBounds().size.height*0.4), 72 / 1.5, 72 / 1.5));
	}
	//CAImageView *icon = CAImageView::createWithCenter(CADipRect(_dip(back->getBounds().size.width*0.5),_dip(back->getBounds().size.height*0.4), 105/1.5, 95/1.5));
	icon->setImage(CAImage::create(image));
	back->addSubview(icon);

	CAApplication::getApplication()->getRootWindow()->addSubview(back);
	//CCLog("%s", get_date_now().c_str());

	icon->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.3), CCFadeOut::create(TOAST_TIME / 2.0)));
	back->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.3), CCFadeOut::create(TOAST_TIME)));

	scheduleOnce(schedule_selector(UtilManager::removeToast), this, TOAST_TIME);
}


void UtilManager::removeToast(float dt) {

	//CCLog("%s", get_date_now().c_str());
	CAApplication::getApplication()->getRootWindow()->removeSubviewByTag(TOAST_VIEW_TAG);

}

float UtilManager::getScale() {

	return CAApplication::getApplication()->getAdaptationRatio();
}