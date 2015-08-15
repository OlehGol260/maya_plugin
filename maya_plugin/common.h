#pragma once

#include "stdafx.h"

template<class T>
void writeArrayToFile(std::ofstream& file, const T& array) {
	if (!file.is_open()) {
		return;
	}
	for (auto i = 0; i < array.length(); ++i) {
		file << pointToString(array[i]);
	}
	file << "--------------------------------------------\n";
}

template<class T>
std::string pointToString(const T& point) {
	return std::string("x:\t" + std::to_string(point.x) + ";\ty:\t" +
		std::to_string(point.y) + ";\tz:\t" + 
		 std::to_string(point.z) + '\n');
}