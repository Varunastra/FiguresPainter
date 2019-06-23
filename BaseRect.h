//---------------------------------------------------------------------------

#ifndef BaseRectH
#define BaseRectH
#include "BaseFigure.h"
//---------------------------------------------------------------------------
class BaseRect : public BaseFigure
{
    private:
	double width, height, x1, x2, y1, y2, x3, x4, y3, y4, x1_save, x2_save, x3_save, x4_save, y1_save, y2_save, y3_save, y4_save, scaled_width, scaled_height;
	void calculations();
	public:
	BaseRect(double x, double y, double width, double height) : BaseFigure(x, y)
	{
		this->width = width;
		this->height = height;
		setScale(1);
        rotation(0);
	}
	void draw(TCanvas *Canvas);
	double getSquare();
	double getPerimetr();
    void rotation(double angle);
	void setScale(double sc);
	void setCenter(double x_move, double y_move);
	void setHeight(double h);
	void setWidth(double w);
    void setCoord(double xc1, double yc1, double xc2, double yc2, double xc3, double yc3, double xc4, double yc4);
};
#endif
