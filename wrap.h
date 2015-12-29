#ifndef WRAP_H
#define WRAP_H

#include "/home/gagan/work/w/dxflib-3.12.2-src/src/dl_creationadapter.h"
#include "/home/gagan/work/w/dxflib-3.12.2-src/src/dl_dxf.h"

typedef DL_Dxf wDXF;
typedef DL_WriterA wWriter;
typedef DL_LineData wLineData;
typedef DL_Attributes wAttributes;
typedef DL_PointData wPointData;
typedef DL_LayerData wLayerData;
typedef DL_LinetypeData wLinetypeData;
typedef DL_StyleData wStyleData;
typedef DL_BlockData wBlockData;
extern "C" {
  wDXF* new_DXF();
  wWriter* out_DXF(wDXF* dxf,const char* fn);
  wLineData* new_LineData(double x, double y, double z,
                            double x2, double y2, double z2);
  wAttributes* new_Attributes();
  wAttributes* new_AttributesWithValues(const char* layer,
                int color, int width,
                const char* linetype,
                double linetypeScale);
  wPointData* new_PointData(double x, double y, double z);
  wLayerData* new_LayerData(const char* name, int flags);
  wLinetypeData* new_LinetypeData(const char*, const char*, int, int, double);
  wBlockData* new_BlockData(const char* name, int flags, double bpx, double bpy, double bpz);
  wStyleData* new_StyleData(const char* name, int flags, double fixedTextHeight,
                            double widthFactor, double obliqueAngle,
                            int textGenerationFlags, double lastHeightUsed,
                            const char* primaryFontFile,
                            const char* bigFontFile);

  bool writeHeader_DXF(wDXF* dxf, wWriter* dw);
  void sectionEnd(wWriter *dw);
  void sectionTables(wWriter *dw);
  void writeVPort(wDXF* dxf, wWriter *dw);
  void tableLineTypes(wWriter* dw, int no);
  void writeTableLinetype(wDXF* dxf, wWriter* dw, DL_LinetypeData data);
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
  void writePoint(wDXF* dxf, wWriter* dw, DL_PointData *pd, DL_Attributes *a);
  void writeLine(wDXF* dxf, wWriter* dw, DL_LineData *pd, DL_Attributes *a);
  void writeObjects(wDXF* dxf, wWriter* dw);
  void writeObjectsEnd(wDXF* dxf, wWriter* dw);
  void eof_DXF(wWriter* dw);
  void writerClose_DXF(wWriter* dw);
  void free_DXF(wDXF* dxf, wWriter* dw);
}
#endif // WRAP_H
