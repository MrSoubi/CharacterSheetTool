#pragma once
#include "pch.h"
#include "Utils.h"

using namespace std;

std::string Utils::PlatformToString(Platform::String^ pString)
{
    std::wstring fooW(pString->Begin());
    std::string fooA(fooW.begin(), fooW.end());
    return std::string();
}

wstring Utils::to_wstring(const std::string& utf8)
{
    std::wstring wide;
    for (size_t i = 0; i < utf8.size();) {
        unsigned char lead = utf8[i];
        int charSize = 0;
        uint32_t charCode = 0; // Codepoint

        // Determine the size based on the lead byte
        if (lead < 0x80) {
            charSize = 1;
            charCode = lead;
        }
        else if ((lead >> 5) == 0x6) { // 110xxxxx
            charSize = 2;
            charCode = lead & 0x1F;
        }
        else if ((lead >> 4) == 0xE) { // 1110xxxx
            charSize = 3;
            charCode = lead & 0x0F;
        }
        else if ((lead >> 3) == 0x1E) { // 11110xxx
            charSize = 4;
            charCode = lead & 0x07;
        }
        else {
            // Error handling: invalid lead byte
            ++i; // Skip this character
            continue;
        }

        // Accumulate the additional bytes
        for (int j = 1; j < charSize; ++j) {
            if (i + j >= utf8.size()) {
                // Error handling: incomplete byte sequence
                charCode = 0;
                break;
            }
            unsigned char follow = utf8[i + j];
            if ((follow >> 6) != 0x2) { // 10xxxxxx
                // Error handling: not a continuation byte
                charCode = 0;
                break;
            }
            charCode = (charCode << 6) | (follow & 0x3F);
        }

        if (charCode <= 0xFFFF) {
            // Directly fits into a wchar_t
            wide.push_back(static_cast<wchar_t>(charCode));
        }
        else if (charCode <= 0x10FFFF) {
            // Convert to a surrogate pair
            charCode -= 0x10000;
            wide.push_back(static_cast<wchar_t>(0xD800 + (charCode >> 10)));
            wide.push_back(static_cast<wchar_t>(0xDC00 + (charCode & 0x03FF)));
        }
        else {
            // Error handling: codepoint out of range
        }

        i += charSize;
    }
    return wide;
}