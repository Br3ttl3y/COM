#pragma once

// StackOverflow likes this type of exporting rather than using a DEF file.
// They consider DEF files "harder"; I'm too new to know the difference.
// https://bit.ly/2WwbOfA
extern "C" __declspec(dllexport) 
void _stdcall Cluck();

