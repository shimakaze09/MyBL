//
// Created by Admin on 26/02/2025.
//

#include <MyBL/RsrcMngr.h>
#include <MyBL/Image.h>

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;
using namespace My;

int main() {
  Image img(1024, 1024, 3);
  img.SetAll(rgbf{ 1,0,1 });
  string dir = "../data/test/02_RsrcMngr/";
  string path = dir + "rst0.png";
  if (!fs::exists(dir) || !fs::directory_entry(dir).is_directory())
    fs::create_directories(dir);
  img.Save(path);

  auto nimg = RsrcMngr<Image>::Instance().GetOrCreate(path);
  nimg->SetAll(rgbf{ 1,0.5,1 });
  nimg->Save(dir + "rst1.png");
  RsrcMngr<Image>::Instance().Clear();

  return 0;
}