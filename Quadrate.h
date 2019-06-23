//---------------------------------------------------------------------------

#ifndef QuadrateH
#define QuadrateH
#include "BaseRect.h"
//---------------------------------------------------------------------------
class Quadrate: public BaseRect
{
	public:
	Quadrate(double x, double y, double height, double width) : BaseRect (x, y, height, width)
	{
    }
};
#endif
