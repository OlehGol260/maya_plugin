// maya_plugin.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "maya_plugin.h"
#include "maya\MFnPlugin.h"
#include "maya\MObject.h"

void* MayaPlugin::creator() { return new MayaPlugin; }

MStatus MayaPlugin::doIt(const MArgList& argList) {
	MGlobal::displayInfo("Hello World!");
	return MS::kSuccess;
}

MStatus initializePlugin(MObject obj) {
	MFnPlugin plugin(obj, "Chad Vernon", "1.0", "Any");
	MStatus status = plugin.registerCommand("retrieve", MayaPlugin::creator);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
}

MStatus uninitializePlugin(MObject obj) {
	MFnPlugin plugin(obj);
	MStatus status = plugin.deregisterCommand("helloWorld");
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
}
