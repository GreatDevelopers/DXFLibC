#include "wrap.h"
#include <stdio.h>
extern "C" {

  wDXF* new_DXF() {
    return reinterpret_cast<wDXF*>(new DL_Dxf());
  }

  wWriter* out_DXF(wDXF* dxf, const char* fn) {
    DL_Codes::version exportVersion = DL_Codes::AC1015;
    wWriter* dw = dxf->out(fn, exportVersion);
    if(dw==NULL) {
      printf("Cannot Open File for writing");
      return NULL;
    }
    return dw;
  }

  bool writeHeader_DXF(wDXF* dxf, wWriter* dw) {
    dxf->writeHeader(*dw);
  }

  void eof_DXF(wWriter* dw) {
    dw->dxfEOF();
  }

  void sectionEnd_DXF(wWriter *dw) {
    dw->sectionEnd();
  }

  void sectionTables_DXF(wWriter *dw) {
    dw->sectionTables();
  }

  void writeVPort_DXF(wDXF* dxf, wWriter *dw) {
    dxf->writeVPort(*dw);
  }

  void tableLineTypes_DXF(wWriter* dw, int no) {
    dw->tableLinetypes(no);
  }

  void writeTableLineType_DXF(wDXF* dxf, wWriter* dw, DL_LinetypeData data) {
    dxf->writeLinetype(*dw, data);
  }

  void tableEnd(wWriter *dw) {
    dw->tableEnd();
  }

  void tableLayers(wWriter *dw, int no) {
    dw->tableLayers(no);
  }

  void writeLayer(wDXF* dxf, wWriter* dw, DL_LayerData ld, DL_Attributes a) {
    dxf->writeLayer(*dw, ld, a);
  }

  void tableStyle(wWriter* dw, int no) {
    dw->tableStyle(no);
  }

  void writeStyle(wDXF* dxf, wWriter* dw, DL_StyleData sd) {
    dxf->writeStyle(*dw, sd);
  }

  void writeView(wDXF* dxf, wWriter* dw) {
    dxf->writeView(*dw);
  }
  void writeUcs(wDXF* dxf, wWriter* dw) {
    dxf->writeUcs(*dw);
  }
  void tableAppid(wWriter* dw, int no) {
    dw->tableAppid(no);
  }
  void writeAppid(wDXF* dxf, wWriter* dw, const char* str) {
    dxf->writeAppid(*dw, str);
  }

  void writeDimStyle(wDXF* dxf, wWriter* dw, double dimasz, double dimexe,
                      double dimexo, double dimgap, double dimtxt) {
    dxf->writeDimStyle(*dw, dimasz, dimexe, dimexo, dimgap, dimtxt);
  }

  void writeBlockRecord(wDXF* dxf, wWriter* dw) {
    dxf->writeBlockRecord(*dw);
  }

  void writeBlockRecordChar(wDXF* dxf, wWriter* dw, const char* str) {
    dxf->writeBlockRecord(*dw, str);
  }

  void sectionBlocks(wWriter* dw) {
    dw->sectionBlocks();
  }
  void writeBlock(wDXF* dxf, wWriter* dw, DL_BlockData bd) {
    dxf->writeBlock(*dw, bd);
  }

  void writeEndBlock(wDXF* dxf, wWriter* dw, const char* bn) {
    dxf->writeEndBlock(*dw, bn);
  }

  void sectionEntities(wWriter* dw) {
    dw->sectionEntities();
  }
  void writePoint(wDXF* dxf, wWriter* dw, DL_PointData pd, DL_Attributes a) {
    dxf->writePoint(*dw, pd, a);
  }
  void writeLine(wDXF* dxf, wWriter* dw, DL_LineData pd, DL_Attributes a) {
    dxf->writeLine(*dw, pd, a);
  }

  void writeObjects(wDXF* dxf, wWriter* dw) {
    dxf->writeObjects(*dw);
  }
  void writeObjectsEnd(wDXF* dxf, wWriter* dw) {
    dxf->writeObjectsEnd(*dw);
  }

  void writerClose_DXF(wWriter* dw) {
    dw->close();
  }

  void free_DXF(wDXF* dxf, wWriter* dw) {
    delete dw;
    delete dxf;
  }
}
