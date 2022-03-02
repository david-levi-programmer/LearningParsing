#include <fstream>
#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void ParseString(std::string& srcString, std::vector<std::string>& subStrings, char token)
{
    assert(!srcString.empty());

    auto start = 0U;
    auto end = 0U;

    while (end != std::string::npos)
    {
        end = srcString.find(token, start);
        if ((end - start) > 0)
        {
            subStrings.push_back(srcString.substr(start, (end - start)));
        }
        start = end + 1;
    }
}
//^all reusable
int main()
{
    std::string line;
    std::vector<std::string> subStrings;
    std::map<std::string, std::string> dataMap;
    std::fstream file("Config/Config.ini", std::ios_base::in);

    if (!file)
    {
        //error loading file
        //works for release builds
    }

    assert(file);

    while (!file.eof())
    {
        std::getline(file, line);
        ParseString(line, subStrings, '=');

        dataMap[subStrings[0]] = subStrings[1];
        subStrings.clear();
    }

    //std::vector<std::string> subStrings;

    //ParseString(sentence, subStrings, '-');

    //for (const auto& word : subStrings)
    //{
    //    std::cout << word << std::endl;
    //}

    system("pause");
    return 0;
}