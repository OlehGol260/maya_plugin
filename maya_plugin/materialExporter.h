#pragma once

#include "stdafx.h"

class MaterialExporter : public MPxCommand
{
public:
	MaterialExporter() {};
	virtual MStatus doIt(const MArgList& args) override;
	static void* creator();
private:
	void saveColor(const MFnDependencyNode& node, const std::string& name, std::ofstream & file);
	void saveBumpMap(const MObject& obj, std::ofstream & file);
};
