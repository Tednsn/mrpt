/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2019, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#define NODELETS_TEST_VERBOSE
#include "NodeletsTest_impl.cpp"
#include <mrpt/core/exceptions.h>
#include <iostream>

int main()
{
	try
	{
		NodeletsTest();
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "MRPT exception caught: " << e.what() << std::endl;
		return -1;
	}
}
