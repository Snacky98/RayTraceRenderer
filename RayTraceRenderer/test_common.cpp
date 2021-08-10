#include "pch.h"

int error_ctr;

// this very specific and ugly function is to help report and count errors during tests
void report_failure(string errmsg) {
	cerr << errmsg + "\n";
	error_ctr++;
}
