#include <iostream>
#include <vector>

int main()
{
   std::vector<std::string> vec { "Hello", " world!"};

   for (const std::string & str : vec)
   {
      std::cout << str;
   }
   std::cout << std::endl;

   return 0;
}