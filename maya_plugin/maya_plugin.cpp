// maya_plugin.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "maya_plugin.h"


MStatus MayaPlugin::doIt(const MArgList& args) {
	auto set_list = MSelectionList();
	auto code = MGlobal::getActiveSelectionList(set_list);
	int set_list_length = set_list.length();

	int num_vertices = 0;

	for (int i = 0; i < set_list_length; ++i) {
		auto d = MDagPath();
		set_list.getDagPath(i, d);
		d.extendToShape();
		MFnMesh mesh(d.node());
		num_vertices += mesh.numVertices(); 
	}

	auto vert = std::to_string(num_vertices);
	const MString myString = vert.c_str();
	MGlobal::displayInfo(myString);

	return MS::kSuccess;
}

/////////////essential part////////////////
void* MayaPlugin::creator() {
	return new MayaPlugin;
}
MStatus initializePlugin(MObject obj) {
	MFnPlugin plugin(obj, "Autodesk", "1.0", "Any");
	plugin.registerCommand("hello", MayaPlugin::creator);
	return MS::kSuccess;
}
MStatus uninitializePlugin(MObject obj) {
	MFnPlugin plugin(obj);
	plugin.deregisterCommand("hello");
	return MS::kSuccess;
}
