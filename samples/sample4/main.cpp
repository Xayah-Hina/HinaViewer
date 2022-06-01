#include "HinaGUI/HinaViewer.h"

int main()
{
    HinaGUI::HinaViewer viewer;
    viewer.init("/Users/xayah/Desktop/BFU-Graphics/HinaGUI/samples/sample3/1.json");
    viewer.launch();
    viewer.kill();
    return 0;
}
