#include <iostream>
#include <vector>

bool Contains(std::string what, std::string s)
{
    bool result = false;
     
    std::vector<char> breakdown = {};
     
    char whatchar = ' ';
	
    // store individual characters of what
    // into breakdown
    for(int i = 0; i < what.length(); ++i)
    {
         whatchar = what[i];
         breakdown.push_back(whatchar);
    }
	
    int held = 0;
	
    for(int i = 0; i < s.length(); ++i)
    {
     // if first key letter is found in s
     if(s[i] == breakdown [0])
     {
          held = i;
   
          for(int j = 1;j<what.length();++j)
          {
               if(s[j+held] == breakdown[j])
               result = true;
          }
     }
 }
     
 return result;
}

int main(int argc, char *argv[])
{
    std::string textin = "i would yes";
	
    if(Contains("yes", textin))
        std::cout << "Found";
    else
        std::cout << "Not found";
}
