#include "DescInitable.h"

#include <fstream>

void HinaGUI::Base::DescInitable::init(const std::string &json_file)
{
    json_file_ = json_file;
    nlohmann::json json = nlohmann::json::parse(std::ifstream(json_file));
    parse(json);
}

void HinaGUI::Base::DescInitable::parse(const nlohmann::json &json)
{
    desc_ = nullptr;
}
