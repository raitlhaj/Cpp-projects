#include <iostream>
#include<cstdlib>
class OpenFile
{
  public:
  OpenFile ( std::string filename)
  {
    std::cout<<filename<<" is opened";
  }


};

auto main() -> int
{
  OpenFile f("text");
  OpenFile f2(f);


  return EXIT_SUCCESS;
  
}

