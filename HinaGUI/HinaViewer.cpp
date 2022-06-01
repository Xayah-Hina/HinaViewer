#include "HinaViewer.h"

using namespace HinaGUI;

void HinaViewer::parse(const nlohmann::json &json)
{
    DescInitable::parse(json);
    desc_ = new HinaViewerDesc();
}

void HinaViewer::resize(int width, int height)
{
    desc_->as<HinaViewerDesc>()->width = width;
}
