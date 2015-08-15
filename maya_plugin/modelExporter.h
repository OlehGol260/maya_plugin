#pragma once

#include "stdafx.h"

class ModelExporter : public MPxCommand
{
public:
	ModelExporter() {};
	virtual MStatus doIt(const MArgList& args) override;
	static void* creator();
};
