//---------------------------------------------------------------------------

#ifndef BaseFigureH
#define BaseFigureH
//---------------------------------------------------------------------------
#include "vcl.h"
class BaseFigure
{
    protected:
	double x, y, orientation, scale;
	void clear(TCanvas *Canvas);
	public:
	BaseFigure(double x, double y)
	{
		this->x = x;
		this->y = y;
		scale = 1;
        orientation = 0;
	}
	AnsiString getCenter();
	void setCenter(double x_move, double y_move);
	double getAngle();
	double getScale();
	~BaseFigure(){}
};
#endif
