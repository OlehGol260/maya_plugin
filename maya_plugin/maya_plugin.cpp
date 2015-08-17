#include "stdafx.h"
#include "maya_plugin.h"
#include "common.h"

MStatus MayaPlugin::doIt(const MArgList& args) {
	auto activeList = MSelectionList();
	MGlobal::getActiveSelectionList(activeList);
	int activeListLength = activeList.length();
	auto activeListVerticesNum = 0;

	std::string filepath = args.asString(0).asChar();
	std::ofstream myFile(filepath);

	if (!myFile.is_open())
	{
		auto errmsg = "invalid filepath specified: " + filepath;
		MGlobal::displayError(errmsg.c_str());
		return MS::kFailure;
	}

	myFile << "-------------------BEGINING-----------------\n";
	for (auto i = 0; i < activeListLength; ++i) {
		auto d = MDagPath();
		activeList.getDagPath(i, d);
		//d.extendToShape();
		MFnMesh mesh(d.node());
		MColor color;
		mesh.getColor(0, color);
		std::stringstream str;
		str << "r = " << color.r << " g= " << color.g << " b= " << color.b;
		MGlobal::displayInfo(str.str().c_str());

		storeVerticesToFile(mesh, myFile);
		storeNormalsToFile(mesh, myFile);

		activeListVerticesNum += mesh.numVertices();
	}
	myFile << "-------------------THE END-----------------\n";
	auto vert = std::to_string(activeListVerticesNum);
	//auto vert = std::to_string(activeListLength);
	MGlobal::displayInfo(vert.c_str());

	myFile.close();
	return MS::kSuccess;
}

void MayaPlugin::storeVerticesToFile(const MFnMesh & mesh, std::ofstream & file)
{
	file << mesh.fullPathName() << " vertices\n";
	MFloatPointArray vertices;
	mesh.getPoints(vertices);
	writeArrayToFile<MFloatPointArray>(file, vertices);
}

void MayaPlugin::storeNormalsToFile(const MFnMesh & mesh, std::ofstream & file)
{
	file << mesh.fullPathName() << " normals\n";
	MFloatVectorArray normals;
	mesh.getNormals(normals);
	writeArrayToFile<MFloatVectorArray>(file, normals);
}

void* MayaPlugin::creator() {
	return new MayaPlugin;
}


