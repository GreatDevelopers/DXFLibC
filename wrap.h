#ifndef WRAP_H
#define WRAP_H

#include "/home/gagan/work/w/dxflib-3.12.2-src/src/dl_creationadapter.h"
#include "/home/gagan/work/w/dxflib-3.12.2-src/src/dl_dxf.h"

typedef DL_Dxf wDXF;
typedef DL_WriterA wWriter;

extern "C" {
  wDXF* new_DXF();
  wWriter* out_DXF(wDXF* dxf,const char* fn);
  bool writeHeader_DXF(wDXF* dxf, wWriter* dw);
  void sectionEnd_DXF(wWriter *dw);
  void sectionTables_DXF(wWriter *dw);
  void writeVPort_DXF(wDXF* dxf, wWriter *dw);
  void tableLineTypes_DXF(wWriter* dw, int no);
  void writeTableLineType_DXF(wDXF* dxf, wWriter* dw, DL_LinetypeData data);
  void tableEnd(wWriter *dw);
  void tableLayers(wWriter *dw, int no);
  void writeLayer(wDXF* dxf, wWriter* dw, DL_LayerData ld, DL_Attributes a);
  void tableStyle(wWriter* dw, int no);
  void writeStyle(wDXF* dxf, wWriter* dw, DL_StyleData sd);

  void writeView(wDXF* dxf, wWriter* dw);
  void writeUcs(wDXF* dxf, wWriter* dw);
  void tableAppid(wWriter* dw, int no);
  void writeAppid(wDXF* dxf, wWriter* dw, const char* str);

  void writeDimStyle(wDXF* dxf, wWriter* dw, double dimasz, double dimexe,
                      double dimexo, double dimgap, double dimtxt);

  void writeBlockRecord(wDXF* dxf, wWriter* dw);
  void writeBlockRecordChar(wDXF* dxf, wWriter* dw, const char* str);

  void sectionBlocks(wWriter* dw);
  void writeBlock(wDXF* dxf, wWriter* dw, DL_BlockData bd);
  void writeEndBlock(wDXF* dxf, wWriter* dw, const char* bn);

  void sectionEntities(wWriter* dw);
  void writePoint(wDXF* dxf, wWriter* dw, DL_PointData pd, DL_Attributes a);
  void writeLine(wDXF* dxf, wWriter* dw, DL_LineData pd, DL_Attributes a);
  void writeObjects(wDXF* dxf, wWriter* dw);
  void writeObjectsEnd(wDXF* dxf, wWriter* dw);
  void eof_DXF(wWriter* dw);
  void writerClose_DXF(wWriter* dw);
  void free_DXF(wDXF* dxf, wWriter* dw);
}
#endif // WRAP_H
