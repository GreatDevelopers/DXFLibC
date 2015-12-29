from ctypes import *
z  = cdll.LoadLibrary("/home/gagan/work/w/untitled/libfoo.so")

dxf = z.new_DXF()
dw = z.out_DXF(dxf, c_char_p(b"/home/gagan/lol"))

z.writeHeader_DXF(dxf, dw)

z.sectionEnd(dw)
z.sectionTables(dw)
z.writeVPort(dxf, dw)

z.tableLineTypes(dw,3)

z.writeTableLinetype(dxf, dw, z.new_LinetypeData(c_char_p(b"BYBLOCK"), c_char_p(b"BYBLOCK"), c_int(0), c_int(0), c_float(0.0)))
z.writeTableLinetype(dxf, dw, z.new_LinetypeData(c_char_p(b"BYLAYER"), c_char_p(b"BYLAYER"), c_int(0), c_int(0), c_float(0.0)))
z.writeTableLinetype(dxf, dw, z.new_LinetypeData(c_char_p(b"CONTINUOUS"), c_char_p(b"Continuous"), c_int(0), c_int(0), c_float(0.0)))

z.tableEnd(dw)

z.tableLayers(dw,3)

z.writeLayer(dxf, dw, z.new_LayerData(c_char_p(b"0"), c_int(0)), z.new_Attributes(c_char_p(b""),
                       c_int(1),
                       c_int(100),
                       c_char_p(b"CONTINUOUS"), c_double(1.0)));

z.writeLayer(dxf, dw, z.new_LayerData(c_char_p(b"mainlayer"), c_int(0)), z.new_Attributes(c_char_p(b""),
                       c_int(2),
                       c_int(100),
                       c_char_p(b"CONTINUOUS"), c_double(1.0)));

z.writeLayer(dxf, dw, z.new_LayerData(c_char_p(b"anotherlayer"), c_int(0)), z.new_Attributes(c_char_p(b""),
                       c_int(3),
                       c_int(100),
                       c_char_p(b"CONTINUOUS"), c_double(1.0)));


z.tableEnd(dw)

z.tableStyle(dw, 1)
z.writeStyle(dxf, dw, z.new_StyleData(c_char_p(b"standard"), c_int(0), c_float(2.5), c_float(1.0), c_float(0.0), c_int(0), c_float(2.5), c_char_p(b"txt"), c_char_p(b"")))

z.tableEnd(dw)

z.writeView(dxf,dw)
z.writeUcs(dxf,dw)

z.tableAppid(dw,1)
z.writeAppid(dxf,dw, c_char_p(b"ACAD"))

z.tableEnd(dw)

z.writeDimStyle(dxf, dw, c_int(1), c_int(1), c_int(1), c_int(1), c_int(1))

z.writeBlockRecord(dxf, dw)
z.writeBlockRecord(dxf, dw, c_char_p(b"myblock1"))
z.writeBlockRecord(dxf, dw, c_char_p(b"myblock2"))

z.tableEnd(dw)

z.sectionEnd(dw)

z.sectionBlocks(dw)

z.writeBlock(dxf, dw, z.new_BlockData(c_char_p(b"*Model_Space"), c_int(0), c_double(0.0), c_double(0.0), c_double(0.0)));
z.writeEndBlock(dxf, dw, c_char_p(b"*Model_Space"));
z.writeBlock(dxf, dw, z.new_BlockData(c_char_p(b"*Paper_Space"), c_int(0), c_double(0.0), c_double(0.0), c_double(0.0)));
z.writeEndBlock(dxf, dw, c_char_p(b"*Paper_Space"));
z.writeBlock(dxf, dw, z.new_BlockData(c_char_p(b"*Paper_Space0"), c_int(0), c_double(0.0), c_double(0.0), c_double(0.0)));
z.writeEndBlock(dxf, dw, c_char_p(b"*Paper_Space0"));
z.writeBlock(dxf, dw, z.new_BlockData(c_char_p(b"myblock1"), c_int(0), c_double(0.0), c_double(0.0), c_double(0.0)));
z.writeEndBlock(dxf, dw, c_char_p(b"myblock1"));
z.writeBlock(dxf, dw, z.new_BlockData(c_char_p(b"myblock2"), c_int(0), c_double(0.0), c_double(0.0), c_double(0.0)));
z.writeEndBlock(dxf, dw, c_char_p(b"myblock2"));

z.sectionEnd(dw)

z.sectionEntities(dw)

md = z.new_AttributesWithValues(c_char_p(b"mainlayer"), c_int(256), c_int(-1), c_char_p(b"BYLAYER"), c_int(1))

ld = z.new_LineData(c_double(25), c_double(30), c_double(0), c_double(100), c_double(120), c_double(0))

z.writePoint(dxf, dw, z.new_PointData(c_double(1),c_double(2),c_double(3)),md)
z.writeLine(dxf, dw, ld, md)

z.sectionEnd(dw)

z.writeObjects(dxf, dw)
z.writeObjectsEnd(dxf, dw)

z.eof_DXF(dw)
z.writerClose_DXF(dw)

z.free_DXF(dxf, dw)
