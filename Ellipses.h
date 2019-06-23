//---------------------------------------------------------------------------

#ifndef EllipsesH
#define EllipsesH
//---------------------------------------------------------------------------
#include "vcl.h"
#include "Circle.h"
class Ellipses : public Circle
{
	private:
	double r, draw_r;
	public:
	Ellipses(double x, double y, double R, double r) : Circle(x, y, R)
	{
		this->r = r;
		draw_r = r;
	}
	double getSquare();
	double getPerimetr();
	void setScale(double sc);
	void draw(TCanvas *Canvas);
	void rotation(double angle);
	void set_r(double radius);
	~Ellipses(){};
};
#endif
