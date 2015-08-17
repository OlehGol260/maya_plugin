// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <array>
#include <sstream>

////////MAYA INCLUDES/////////
#include "maya/MString.h"
#include "maya/MArgList.h"
#include "maya/MFnPlugin.h"
#include <maya/MObject.h>
#include <maya/MGlobal.h>
#include "maya/MPxCommand.h"
#include "maya/MIOStream.h"
#include "maya/MFnMesh.h"
#include "maya/MSelectionList.h"
#include "maya/MDagPath.h"
#include "maya/MFloatPointArray.h"
#include "maya/MFloatVectorArray.h"
#include "maya/MFloatPoint.h"
#include "maya/MFloatVector.h"
#include "maya/MColor.h"
#include "maya/MPlugArray.h"
#include "maya/MItDependencyNodes.h"
#include "maya/MFnLambertShader.h"
#include "maya/MFnBlinnShader.h"
#include "maya/MFnPhongShader.h"
///////END MAYA INCLUDES//////
