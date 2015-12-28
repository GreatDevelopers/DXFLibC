g++ -c wrap.cpp -fPIC
clang++ -shared -o libfoo.so wrap.o ../dxflib-3.12.2-src/libdxflib.a
