#include <iostream>
#include "rectangle_lib/rectangle.hpp"

extern "C" {
	#include <caml/mlvalues.h>
	#include <caml/memory.h>
}


extern "C"
CAMLprim value
make_rectangle(value pos_tuple, value width, value height)
{
	value fx = Field(pos_tuple, 0),
		  fy = Field(pos_tuple, 1);
	int x = Int_val(fx),
		y = Int_val(fy),
		w = Int_val(width),
		h = Int_val(height);

	Rectangle r(x,y,w,h);

	r.print();
	return *reinterpret_cast<value*>(&r);
}

extern "C"
CAMLprim value
perimeter(value rectangle) {
	Rectangle r = *reinterpret_cast<Rectangle*>(&rectangle);
	int p = r.perimetre();
	return *reinterpret_cast<value*>(&p);
}

extern "C"
CAMLprim value
area(value rectangle) {
	Rectangle r = *reinterpret_cast<Rectangle*>(&rectangle);
	int p = r.surface();
	return *reinterpret_cast<value*>(&p);
}
