#include "HinaGUI/HinaViewer.h"

int main()
{
    HinaGUI::HinaViewer viewer;
    viewer.init("/Users/xayah/Desktop/BFU-Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
    viewer.launch();
    viewer.kill();
    return 0;
}
