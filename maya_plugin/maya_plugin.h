#pragma once
#include "stdafx.h"

class MayaPlugin : public MPxCommand {
public:
	MayaPlugin() {}
	virtual MStatus doIt(const MArgList&);
	static void* creator();
};