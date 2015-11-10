#include "RootWindow.h"
#include "FirstViewController.h"

RootWindow* RootWindow::create()
{
    RootWindow* _window = new RootWindow();
    _window->init();
    _window->autorelease();
    return _window;
}

RootWindow::RootWindow()
{

}

RootWindow::~RootWindow()
{

}

bool RootWindow::init()
{
    if (!CAWindow::init())
    {
        return false;
    }
    
	FirstViewController* _viewController = new FirstViewController();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	_viewController->setNavigationBarItem(CANavigationBarItem::create(UTF8("海燕-绿黑百变法")));
#else
	_viewController->setNavigationBarItem(CANavigationBarItem::create("海燕-绿黑百变法"));
#endif
	CANavigationController* navi = new CANavigationController();
	navi->initWithRootViewController(_viewController);
	navi->init();
    _viewController->init();
    this->setRootViewController(navi);
    _viewController->release();
    
    return true;
}
