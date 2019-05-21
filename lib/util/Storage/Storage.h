#include <string>
#include <map>

class Storage
{
private:
    std::map<std::string, std::string> store;

public:
    bool init();
    void setValue(std::string key, std::string value);
    std::string getValue(std::string key);
};