all: rectangle bindings binary

rectangle: rectangle_lib
	make -C rectangle_lib

bindings: bindings_cpp.cpp bindings_caml.ml
	g++ -o bindings_cpp.o -I`ocamlc -where` -fPIC -c bindings_cpp.cpp
	ocamlopt -c bindings_caml.ml
	ocamlmklib -o bindings bindings_cpp.o
	ocamlmklib -o bindings bindings_caml.cmx

binary: rectangle bindings caml_code.ml
	ocamlopt -I . -cclib -lstdc++ -ccopt "-Lrectangle_lib" -cclib -lrectangle bindings.cmxa caml_code.ml

clean:
	rm a.out *.cm* *.a *.so *.o rectangle_lib/{*.a,*.o}