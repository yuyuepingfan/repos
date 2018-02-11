#pragma once
#include <osgGA/GUIEventHandler>

class PrintHandler : public osgGA::GUIEventHandler
{
public:
	virtual void getUsage(osg::ApplicationUsage &) const;
	virtual bool handle(const osgGA::GUIEventAdapter &, osgGA::GUIActionAdapter &);

};

