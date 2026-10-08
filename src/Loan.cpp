#include "Loan.h"
#include <utility>
#include <sstream>
Loan::Loan(int b,int m,std::string d,bool r):bookId_(b),memberId_(m),issueDate_(std::move(d)),returned_(r){} int Loan::getBookId()const{return bookId_;} int Loan::getMemberId()const{return memberId_;} const std::string& Loan::getIssueDate()const{return issueDate_;} bool Loan::isReturned()const{return returned_;} void Loan::markReturned(){returned_=true;} std::string Loan::toCsv()const{std::ostringstream o;o<<bookId_<<'|'<<memberId_<<'|'<<issueDate_<<'|'<<(returned_?1:0);return o.str();}
