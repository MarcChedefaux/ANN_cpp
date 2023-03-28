.ONESHELL:
.SILENT:
.PHONY : doc

prepare: src_build test_build
	cd src/build
	cmake ..
	cd ../../test/build
	cmake ..

p : prepare

src_build:
	mkdir -p src/build

test_build:
	mkdir -p test/build

build_test:
	make -s -C ./test/build

test : build_test
	./test/build/ANN_test

t : test

build : 
	make -s -C ./src/build

run : build
	./src/build/ANN

r : run

doc :
	cd ./doc
	doxygen doxyfile
	make -s -C ./latex
	cp ./latex/refman.pdf ./Documentation.pdf
	rm ./latex/refman.aux ./latex/refman.idx ./latex/refman.ilg ./latex/refman.ind ./latex/refman.log ./latex/refman.pdf ./latex/refman.toc

d:doc
