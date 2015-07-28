#pragma once


#include "maya\MArgList.h"
#include "maya\MGlobal.h"
#include "maya\MPxCommand.h"


class MayaPlugin : public MPxCommand {
public:
	MayaPlugin() {}
	virtual MStatus doIt(const MArgList&);
	static void* creator();
};