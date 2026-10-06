#include "Book.h"
#include <utility>
#include <sstream>
Book::Book(int id,std::string title,std::string author,bool available):id_(id),title_(std::move(title)),author_(std::move(author)),available_(available){}
int Book::getId()const{return id_;} const std::string& Book::getTitle()const{return title_;} const std::string& Book::getAuthor()const{return author_;} bool Book::isAvailable()const{return available_;} void Book::setAvailable(bool v){available_=v;}
std::string Book::toCsv()const{std::ostringstream o;o<<id_<<'|'<<title_<<'|'<<author_<<'|'<<(available_?1:0);return o.str();}
