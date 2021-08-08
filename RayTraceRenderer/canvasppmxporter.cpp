#include "pch.h"
#include <fstream>

CanvasPPMExporter::CanvasPPMExporter(Canvas canv, string filename, string dir) {
	this->canv = canv;
	this->outFileName = filename;
	this->outDir = dir;
}

CanvasPPMExporter::~CanvasPPMExporter() {;}

void CanvasPPMExporter::doExport() {
	fstream outFile;

	outFile.open(this->outFileName);
	
}

void CanvasPPMExporter::setFilename(string newName) {
	this->outFileName = newName;
}

void CanvasPPMExporter::setCanvas(Canvas newCanv) {
	this->canv = newCanv;
}

Canvas CanvasPPMExporter::getCanvas() {
	return this->canv;
}

string CanvasPPMExporter::getFileName() {
	return this->outFileName;
}