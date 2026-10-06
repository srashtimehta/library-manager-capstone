#include "Member.h"
#include <utility>
#include <sstream>
Member::Member(int id,std::string name):id_(id),name_(std::move(name)){} int Member::getId()const{return id_;} const std::string& Member::getName()const{return name_;} std::string Member::toCsv()const{std::ostringstream o;o<<id_<<'|'<<name_;return o.str();}
