#pragma once
#include "stdafx.h"

class MayaPlugin : public MPxCommand {
public:
	MayaPlugin() {}
	virtual MStatus doIt(const MArgList&) override;
	static void* creator();
private:
	void storeVerticesToFile(const MFnMesh& mesh, std::ofstream& file);
	void storeNormalsToFile(const MFnMesh& mesh, std::ofstream& file);
};