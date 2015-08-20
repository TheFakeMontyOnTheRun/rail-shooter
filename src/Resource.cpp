#include <string>
#include "Resource.h"

Resource::Resource( const std::string &resPath ) {
  this->resId = 2;
  this->resPath = (std::string*)&resPath;
}
