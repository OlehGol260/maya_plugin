#include "stdafx.h"
#include "modelExporter.h"

MStatus ModelExporter::doIt(const MArgList& args)
{
	return MStatus::kSuccess;
}

void * ModelExporter::creator()
{
	return new ModelExporter;
}
