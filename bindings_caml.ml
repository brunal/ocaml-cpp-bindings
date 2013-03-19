type rectangle_t
external rectangle: (int * int) -> int -> int -> rectangle_t = "make_rectangle"
external perimeter: rectangle_t -> int = "perimeter"
external area: rectangle_t -> int = "area"
