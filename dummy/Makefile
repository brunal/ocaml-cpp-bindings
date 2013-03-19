all: rectangle bindings

bindings: bindings_cpp.cpp bindings_caml.ml
	g++ -o bindings_cpp.o -I`ocamlc -where` -fPIC -c bindings_cpp.cpp
	ocamlmklib -o dummy bindings_cpp.o
	ocamlopt -c -for-pack Dummy bindings_caml.ml
	ocamlopt -pack -o dummy.cmx bindings_caml.cmx
	ocamlmklib -o dummy dummy.cmx

rectangle: rectangle_lib
	make -C rectangle_lib

clean:
	rm *.a *.o *.cm* *.so