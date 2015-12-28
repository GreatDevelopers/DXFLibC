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
  void eof_DXF(wWriter* dw);
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
  void writerClose_DXF(wWriter* dw);
  void free_DXF(wDXF* dxf, wWriter* dw);
}
#endif // WRAP_H
