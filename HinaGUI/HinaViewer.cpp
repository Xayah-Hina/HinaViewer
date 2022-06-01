#include "HinaViewer.h"

using namespace HinaGUI;

void HinaViewer::init(const std::string &json_file)
{
    DescInitable::init(json_file);

    auto name = desc_->as<HinaViewerDesc>()->name;
    auto width = desc_->as<HinaViewerDesc>()->width;
    auto height = desc_->as<HinaViewerDesc>()->height;
    auto pos_x = desc_->as<HinaViewerDesc>()->pos_x;
    auto pos_y = desc_->as<HinaViewerDesc>()->pos_y;

    window_ = new Core::Window();
    window_->init(name, width, height, pos_x, pos_y);
}

void HinaViewer::parse(const nlohmann::json &json)
{
    DescInitable::parse(json);
    auto res = new HinaViewerDesc();

    res->name = json["name"];
    res->pos_x = json["pos_x"];
    res->pos_y = json["pos_y"];
    res->width = json["width"];
    res->height = json["height"];

    desc_ = res;
}

void HinaViewer::launch()
{
    window_->render();
}

void HinaViewer::kill()
{
    window_->kill();
}

void HinaViewer::resize(int width, int height)
{
    desc_->as<HinaViewerDesc>()->width = width;
    desc_->as<HinaViewerDesc>()->height = height;
}

void HinaViewer::set_background_color(const Eigen::Vector4f &color)
{

}
