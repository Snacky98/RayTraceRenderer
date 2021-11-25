#include "pch.h"

namespace Renderer {
	namespace Test {
		int error_ctr = 0;

		// this very specific and ugly function is to help report and count errors during tests
		void report_failure(string errmsg) {
			cerr << errmsg + "\n";
			error_ctr++;
		}
	}
}

