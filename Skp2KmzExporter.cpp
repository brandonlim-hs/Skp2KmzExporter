#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include "slapi\import_export\modelexporterplugin.h"

typedef SketchUpModelExporterInterface* (*GetExporterPtr) (void);

int _tmain(int argc, char* argv[]) {
	if (argc == 0) return 0;

	HINSTANCE Handle = LoadLibrary("skp2kmz.dll");
 
	if (!Handle) throw "Unable to find skp2kmz.dll, make sure it is a 64bit dll.";

	GetExporterPtr ExporterPtr = 
		(GetExporterPtr) GetProcAddress(Handle, "GetSketchUpModelExporterInterface");

  if (!ExporterPtr) throw "Unable to find skp2kmz.dll, make sure it is a 64bit dll.";

	SketchUpModelExporterInterface* Exporter = ExporterPtr();

  try {
    if (Exporter->GetFileExtensionCount() > 0) {
      for (int i = 1; i < argc; i++) {
        const std::string input_skp(argv[i]);
        const std::string ext = Exporter->GetFileExtension(0);
        const std::string output = input_skp.substr(0, input_skp.find_last_of(".")) + "." + ext;
        Exporter->ConvertFromSkp(input_skp, output, NULL, NULL);
      }
    }
  } catch (...) {
    throw "Unable to load skp2kmz.dll, missing collada.dll and slapi.dll.";
  }

	FreeLibrary(Handle);
	return 0;
}
