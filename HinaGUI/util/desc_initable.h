#ifndef HINAGUI_DESCINITABLE_H
#define HINAGUI_DESCINITABLE_H

#include "nlohmann/json.hpp"

#include <string>
#include <fstream>

class DescInitable
{
public:
    /**
     * [TO OVERRIDE THiS]
     */
    struct Desc
    {
        virtual ~Desc() = default;

        template<typename Derived, typename std::enable_if<std::is_base_of<Desc, Derived>::value>::type * = nullptr>
        Derived *as()
        {
            return dynamic_cast<Derived *>(this);
        }
    };

public:
    /**
     * [TO OVERRIDE THiS]
     */
    virtual void init(const std::string &json_file)
    {
        json_file_ = json_file;
        nlohmann::json json = nlohmann::json::parse(std::ifstream(json_file));
        parse(json);
    }

protected:
    /**
     * [TO OVERRIDE THiS]
     */
    virtual void parse(const nlohmann::json &json)
    { desc_ = nullptr; }

    Desc *desc_ = nullptr; // DISABLE arbitrary altering from outside
    std::string json_file_;
};


#endif //HINAGUI_DESCINITABLE_H
