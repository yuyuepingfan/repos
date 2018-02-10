#include <QtCore/QCoreApplication>
#pragma once
#pragma comment(lib, "./x64/Debug/Common.lib")
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandler>
#include <osgViewer/ViewerEventHandlers>
#include "../Common/Common.h"


int main(int argc, char *argv[])
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->addEventHandler(new osgViewer::HelpHandler);
	 osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("C:/Users/yuyue/Downloads/OpenSceneGraph-Data-3.4.0/OpenSceneGraph-Data/cow.osg");
	viewer->setSceneData(node.get());
	return viewer->run();
}
