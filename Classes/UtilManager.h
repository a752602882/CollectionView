#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "CrossApp.h"
USING_NS_CC;


#define CAROOTWINDOW CAApplication::getApplication()->getRootWindow()

using namespace std;

class UtilManager : public CAObject
{
public:
	UtilManager(void);
	~UtilManager(void);

	static float getScale();//ªÒ»°desitiny scale

	void toast(string text, CAViewController* object);

	void toast(string text, string image, bool isSmall = false);

	void removeToast(float dt);

	CC_SYNTHESIZE(bool, m_bUserLogin, UserLogin);

	static UtilManager* shareUtilManager();

	static void scheduleOnce(SEL_SCHEDULE pfnSelector, CAObject *pTarget, float delay);

};