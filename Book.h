#pragma once
#include <string>
class Book { int id_; std::string title_, author_; bool available_; public: Book(int id,std::string title,std::string author,bool available=true); int getId() const; const std::string& getTitle() const; const std::string& getAuthor() const; bool isAvailable() const; void setAvailable(bool); std::string toCsv() const; };
