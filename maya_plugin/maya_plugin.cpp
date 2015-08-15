// maya_plugin.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "maya_plugin.h"
#include "common.h"

MStatus MayaPlugin::doIt(const MArgList&) {
	auto set_list = MSelectionList();
	auto code = MGlobal::getActiveSelectionList(set_list);
	int set_list_length = set_list.length();
	auto num_vertices = 0;
	std::string filename = "E:\myfile.txt";
	std::ofstream myFile(filename);

	if (!myFile.is_open())
	{
		return MS::kFailure;
	}
	myFile << "-------------------BEGINING-----------------\n";
	for (auto i = 0; i < set_list_length; ++i) {
		auto d = MDagPath();
		set_list.getDagPath(i, d);
		d.extendToShape();
		MFnMesh mesh(d.node());

		storeVerticesToFile(mesh, myFile);
		storeNormalsToFile(mesh, myFile);

		int numbOfVertices = mesh.numVertices();
		num_vertices += numbOfVertices; 
	}
	myFile << "-------------------THE END-----------------\n";
	auto vert = std::to_string(num_vertices);
	const MString myString = vert.c_str();
	MGlobal::displayInfo(myString);

	myFile.close();
	return MS::kSuccess;
}

void MayaPlugin::storeVerticesToFile(const MFnMesh & mesh, std::ofstream & file)
{
	file << mesh.fullPathName();
	file << " vertices\n";
	MFloatPointArray vertices;
	mesh.getPoints(vertices);
	writeArrayToFile<MFloatPointArray>(file, vertices);
}

void MayaPlugin::storeNormalsToFile(const MFnMesh & mesh, std::ofstream & file)
{
	file << mesh.fullPathName();
	file << " normals\n";
	MFloatVectorArray normals;
	mesh.getNormals(normals);
	writeArrayToFile<MFloatVectorArray>(file, normals);
}

/////////////essential part////////////////
void* MayaPlugin::creator() {
	return new MayaPlugin;
}

MStatus initializePlugin(MObject obj) {
	MFnPlugin plugin(obj, "Autodesk", "1.0", "Any");
	plugin.registerCommand("countAndSave", MayaPlugin::creator);
	return MS::kSuccess;
}
MStatus uninitializePlugin(MObject obj) {
	MFnPlugin plugin(obj);
	plugin.deregisterCommand("countAndSave");
	return MS::kSuccess;
}
