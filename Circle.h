//---------------------------------------------------------------------------

#ifndef CircleH
#define CircleH
//---------------------------------------------------------------------------
#include "BaseFigure.h"
class Circle : public BaseFigure
{
	protected:
	double R, draw_R;
	public:
	Circle(double x, double y, double R) : BaseFigure(x, y)
	{
		this->R = R;
        draw_R = R;
	}
	~Circle(){}
	void draw(TCanvas *Canvas);
	double getPerimetr();
	double getSquare();
	void setScale(double sc);
	void set_R(double radius);
};
#endif
