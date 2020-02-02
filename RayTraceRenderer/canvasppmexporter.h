#pragma once
#include "pch.h"

class CanvasPPMExporter
{
private:
	Canvas canv;
	string outFileName;
	string outDir;

	friend class Canvas;

public:
	CanvasPPMExporter(Canvas = Canvas(), string = "outfile.ppm", string outDir = "\\");
	~CanvasPPMExporter();

	void doExport();
	
	void setFilename(string);
	void setCanvas(Canvas);

	Canvas getCanvas();
	string getFileName();
};

