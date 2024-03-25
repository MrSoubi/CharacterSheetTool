#pragma once

#include "pch.h"

using namespace std;

class Utils
{
public:
	static string PlatformToString(Platform::String^ pString);
	static wstring to_wstring(const string& str);
};