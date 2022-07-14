#include <iostream>
#include <vector>

bool contains(std::string what, std::string s, int& withindex)
{
    // store individual characters of what
    // into breakdown
    std::vector<char> breakdown = {};
    char whatchar{};
    for (int i = 0; i < what.length(); ++i)
    {
        whatchar = what[i];
        breakdown.push_back(whatchar);
    }

    int foundletterat = 0;

    for (int j = withindex; j < s.length(); ++j)
    {
        if (s[j] == breakdown[0])
        {
            foundletterat = j;
            withindex = j;
        }
    }
    
    bool foundword = false;
    int count = 0;
    
    for (int k = foundletterat; k < foundletterat + what.length(); ++k)
    {
        if(s[k] == breakdown[count])
            foundword = true;
        else
            foundword = false;
            
        ++count;
    }

    if (foundword)
        return true;
    else if(withindex<s.length()-what.length())
        contains(what, s, withindex);
    else
        return false;
}

int main(int argc, char *argv[])
{
    std::string intext = "i would ke kevin";
    std::string findtext = "kevin";

    int withindex = 0;

    if (contains(findtext, intext, withindex))
        std::cout << "Found";
    else
        std::cout << "Not found";
}
