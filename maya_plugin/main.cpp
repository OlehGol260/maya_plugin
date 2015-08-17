#include "stdafx.h"
#include "maya_plugin.h"
#include "materialExporter.h"

MStatus initializePlugin(MObject obj) {
	MFnPlugin plugin(obj, "OlehGol", "1.0", "Any");
	MStatus status;
	status = plugin.registerCommand("countAndSave", MayaPlugin::creator);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	status = plugin.registerCommand("exportMaterial", MaterialExporter::creator);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
}
MStatus uninitializePlugin(MObject obj) {
	MFnPlugin plugin(obj);
	MStatus status;
	status = plugin.deregisterCommand("countAndSave");
	CHECK_MSTATUS_AND_RETURN_IT(status);
	status = plugin.deregisterCommand("exportMaterial");
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
}