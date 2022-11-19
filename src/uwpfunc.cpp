#include "uwpfunc.h"
#include <string>
#include <windows.h>
#include <fileapifromapp.h>

using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Storage;

//Platform::String^ local_folder = Windows::Storage::ApplicationData::Current->LocalFolder->Path+L"\\";
extern "C" {
	void uwp_get_localfolder(const char* path, char* outChar)
	{
		char win32_cpu_model_name[128] = { 0 };
		auto local_folder = Windows::Storage::ApplicationData::Current->LocalFolder->Path+ L"\\";
		std::wstring ws(local_folder->Data());
		std::string str(ws.begin(), ws.end());
		std::string str2(path);
		str += str2;
		strcpy(outChar, str.c_str());
	}
	void uwp_create_save_dir(void) 
	{
		auto local_folder = Windows::Storage::ApplicationData::Current->LocalFolder->Path + L"\\saves";
		CreateDirectoryFromAppW(local_folder->Data(), NULL);
	}
}
