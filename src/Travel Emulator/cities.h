// cities.h The city class
#pragma once
using namespace System;
public ref class cities {
 public:
  int id;
  String ^ name;
  cities(String ^ name);
  cities(int id, String ^ name);
  String^ getName();
  int getID();
 private:
  static int count = 0;
};
