/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2016, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */

#include "nav-precomp.h" // Precomp header
#include <mrpt/nav/tpspace/CPTG4.h>
#include <mrpt/system/os.h>


using namespace mrpt;
using namespace mrpt::nav;
using namespace mrpt::system;
using namespace mrpt::utils;

CPTG4::CPTG4(const mrpt::utils::TParameters<double> &params ) : CPTG_DiffDrive_CollisionGridBased(params)
{
	this->K = params["K"];
	// The constant curvature turning radius used in this PTG:
	R = V_MAX / W_MAX;
}

std::string CPTG4::getDescription() const
{
	char str[100];
	os::sprintf(str,100,"Type#4PTG:C|C");
	return std::string(str);
}

void CPTG4::ptgDiffDriveSteeringFunction( float alpha, float t,float x, float y, float phi, float &v, float &w ) const
{
	MRPT_UNUSED_PARAM(phi); MRPT_UNUSED_PARAM(x); MRPT_UNUSED_PARAM(y);
	float	u = fabs(alpha) * 0.5f; /// 6.0f;

	if (t< u*R/V_MAX)
	{
		// l-
		v = -V_MAX;
		w = W_MAX;
	}
	else
	if ( t< (u + M_PI*0.5f) * R/V_MAX )
	{
		// l+
		v = V_MAX;
		w = W_MAX;
	}
	else
	{
		// END:
		v = w = 0;
	}

	// Turn in the opposite direction??
	if (alpha<0)
		w*=-1;

	v*=K;
	w*=K;

}

bool CPTG4::PTG_IsIntoDomain( double x, double y ) const
{
	// Aprox domain: The circle at (0,R):
	return (square(x)+square(fabs(y)-R))<=R;
}


