#pragma once
#include <string>
class Member { int id_; std::string name_; public: Member(int id,std::string name); int getId() const; const std::string& getName() const; std::string toCsv() const; };
