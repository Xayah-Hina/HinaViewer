#include "HinaGUI/HinaViewer.h"

int main()
{
    HinaGUI::HinaViewer viewer;
    viewer.init("C:/Users/Administrator/Desktop/BFU_Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
//    viewer.init("/Users/xayah/Desktop/BFU-Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
    viewer.launch();
    viewer.kill();
    return 0;
}
