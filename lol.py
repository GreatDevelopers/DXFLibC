from ctypes import *
z  = cdll.LoadLibrary("/home/gagan/work/w/untitled/libfoo.so")
dxf = z.new_DXF()
dw = z.out_DXF(dxf, c_char_p(b"/home/gagan/lol"))
z.writeHeader_DXF(dxf, dw)
z.eof_DXF(dw)
z.writerClose_DXF(dw)
z.free_DXF(dxf, dw)
