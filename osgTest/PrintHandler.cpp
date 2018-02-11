#include "PrintHandler.h"


void PrintHandler::getUsage(osg::ApplicationUsage &usage) const
{
	usage.addKeyboardMouseBinding("xhx", "PrintHandler");
}

bool PrintHandler::handle(const osgGA::GUIEventAdapter &, osgGA::GUIActionAdapter &)
{
	return true;
}
