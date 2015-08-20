#ifndef RESOURCE_H
#define RESOURCE_H

class Resource {
 public:
  Resource( const std::string &resPath );
  int resId;
  std::string *resPath;
};
#endif
