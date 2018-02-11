
#pragma comment(lib, "../osgTest/x64/Debug/Common.lib")
#include "../Common/Common.h"
#include <osgViewer/Viewer>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osgDB/ReaderWriter>
#include <osgDB/ReadFile>
#include <osg/Texture2D>
#include <osg/Material>
#include <osgViewer/ViewerEventHandlers>



int main(int argc, char *argv[])
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Image> image = osgDB::readImageFile("girl.jpg");
	if (!image->valid())
	{
		return -1;
	}

	osg::ref_ptr<osg::Texture2D> tex = new osg::Texture2D;
	tex->setImage(image.get());

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::ShapeDrawable> shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 0.2f));
	geode->addChild(shape);
	osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();
	stateSet->setTextureAttributeAndModes(0, tex.get());

	//创建材质
	osg::ref_ptr<osg::Material> mat = new osg::Material();
	mat->setDiffuse(osg::Material::FRONT, osg::Vec4(0.5f, 0.0f, 0.2f, 1.0f));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	mat->setShininess(osg::Material::FRONT, 90.0f);
	stateSet->setAttribute(mat.get());



	osg::ref_ptr<osg::Group> root = new osg::Group;
	root->addChild(geode);

	osg::ref_ptr <osg::Geode> geode2 = new osg::Geode;
	osg::ref_ptr<osg::Geometry> gty = new osg::Geometry;

	//定义定点
	osg::ref_ptr<osg::Vec3Array> arr = new osg::Vec3Array;
	arr->push_back(osg::Vec3(0.0, 0.0, 0.0));
	arr->push_back(osg::Vec3(1, 0, 0));
	arr->push_back(osg::Vec3(1, 0, 1));
	arr->push_back(osg::Vec3(0, 0, 1));
	//定义法线
	osg::ref_ptr<osg::Vec3Array> normal = new osg::Vec3Array();
	gty->setNormalArray(normal);
	gty->setNormalBinding(osg::Geometry::BIND_OVERALL);
	normal->push_back(osg::Vec3(0.f, -1.f, 0.f));
	//定义颜色
	osg::ref_ptr<osg::Vec4Array> colorArr = new osg::Vec4Array();
	gty->setColorArray(colorArr);
	gty->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	colorArr->push_back(osg::Vec4(0.f, 0.f, 0.f, 0.f));
	colorArr->push_back(osg::Vec4(0.5f, 0.5f, 0.5f, 0.f));
	colorArr->push_back(osg::Vec4(1.f, 1.f, 1.f, 0.f));
	colorArr->push_back(osg::Vec4(0.5f, 0.f, 0.5f, 0.f));

	gty->setVertexArray(arr);
	gty->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
	geode2->addDrawable(gty);
	root->addChild(geode2);
	viewer->setSceneData(root.get());
	
	viewer->addEventHandler(new osgViewer::HelpHandler);
	viewer->addEventHandler(new osgViewer::StatsHandler);
	return viewer->run();
}
