#include "Library.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
namespace { std::string lower(std::string s){std::transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return char(std::tolower(c));});return s;} std::vector<std::string> split(const std::string& s){std::vector<std::string> p;std::stringstream ss(s);std::string x;while(std::getline(ss,x,'|'))p.push_back(x);return p;} }
bool Library::addBook(const Book& b){if(findBook(b.getId()))return false;books_.push_back(b);return true;} bool Library::addMember(const Member& m){if(findMember(m.getId()))return false;members_.push_back(m);return true;}
Book* Library::findBook(int id){for(auto& b:books_)if(b.getId()==id)return &b;return nullptr;} const Book* Library::findBook(int id)const{for(const auto& b:books_)if(b.getId()==id)return &b;return nullptr;}
Member* Library::findMember(int id){for(auto& m:members_)if(m.getId()==id)return &m;return nullptr;} const Member* Library::findMember(int id)const{for(const auto& m:members_)if(m.getId()==id)return &m;return nullptr;}
std::vector<const Book*> Library::searchBooks(const std::string& q)const{auto n=lower(q);std::vector<const Book*> r;for(const auto& b:books_)if(lower(b.getTitle()).find(n)!=std::string::npos||lower(b.getAuthor()).find(n)!=std::string::npos)r.push_back(&b);return r;}
bool Library::issueBook(int bid,int mid,const std::string& d){auto* b=findBook(bid);if(!b||!findMember(mid)||!b->isAvailable())return false;b->setAvailable(false);loans_.emplace_back(bid,mid,d);return true;}
bool Library::returnBook(int bid){auto* b=findBook(bid);if(!b||b->isAvailable())return false;for(auto& l:loans_)if(l.getBookId()==bid&&!l.isReturned()){l.markReturned();b->setAvailable(true);return true;}return false;}
LibraryReport Library::getReport()const{LibraryReport r;r.totalBooks=books_.size();r.totalMembers=members_.size();for(const auto& b:books_)if(b.isAvailable())++r.availableBooks;r.issuedBooks=r.totalBooks-r.availableBooks;for(const auto& l:loans_)if(!l.isReturned())++r.activeLoans;return r;}
bool Library::save(const std::string& p)const{std::ofstream o(p);if(!o)return false;o<<"[BOOKS]\n";for(const auto& b:books_)o<<b.toCsv()<<'\n';o<<"[MEMBERS]\n";for(const auto& m:members_)o<<m.toCsv()<<'\n';o<<"[LOANS]\n";for(const auto& l:loans_)o<<l.toCsv()<<'\n';return true;}
bool Library::load(const std::string& p){std::ifstream in(p);if(!in)return false;books_.clear();members_.clear();loans_.clear();enum S{N,B,M,L};S s=N;std::string line;while(std::getline(in,line)){if(line=="[BOOKS]"){s=B;continue;}if(line=="[MEMBERS]"){s=M;continue;}if(line=="[LOANS]"){s=L;continue;}if(line.empty())continue;auto p2=split(line);try{if(s==B&&p2.size()==4)addBook(Book(std::stoi(p2[0]),p2[1],p2[2],p2[3]=="1"));else if(s==M&&p2.size()==2)addMember(Member(std::stoi(p2[0]),p2[1]));else if(s==L&&p2.size()==4)loans_.emplace_back(std::stoi(p2[0]),std::stoi(p2[1]),p2[2],p2[3]=="1");}catch(...){return false;}}return true;}
const std::vector<Book>& Library::books()const{return books_;} const std::vector<Member>& Library::members()const{return members_;} const std::vector<Loan>& Library::loans()const{return loans_;}
