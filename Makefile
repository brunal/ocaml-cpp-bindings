all: module binary

module: dummy
	make -C dummy

binary: module caml_code.ml
	ocamlopt -I . -I dummy \
	-cclib -lstdc++ -ccopt "-Ldummy/rectangle_lib" -cclib -lrectangle \
	dummy/dummy.cmxa caml_code.ml

clean:
	rm a.out *.cm* *.o