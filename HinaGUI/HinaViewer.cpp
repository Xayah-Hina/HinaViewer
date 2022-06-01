#include "HinaViewer.h"

using namespace HinaGUI;

void HinaViewer::parse(const nlohmann::json &json)
{
    DescInitable::parse(json);
    auto res = new HinaViewerDesc();

    res->pos_x = json["pos_x"];
    res->pos_y = json["pos_y"];
    res->width = json["width"];
    res->height = json["height"];

    desc_ = res;
}

void HinaViewer::resize(int width, int height)
{
    desc_->as<HinaViewerDesc>()->width = width;
    desc_->as<HinaViewerDesc>()->height = height;
}
