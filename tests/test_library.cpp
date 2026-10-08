#include "Library.h"
#include <cassert>
#include <iostream>
int main(){Library l;assert(l.addBook(Book(1,"C++ Basics","Author A")));assert(!l.addBook(Book(1,"Duplicate","Author B")));assert(l.addMember(Member(10,"Test User")));assert(!l.addMember(Member(10,"Duplicate")));assert(l.issueBook(1,10,"2026-10-06"));assert(!l.issueBook(1,10,"2026-10-06"));assert(!l.findBook(1)->isAvailable());assert(l.searchBooks("c++").size()==1);assert(l.returnBook(1));auto r=l.getReport();assert(r.totalBooks==1&&r.availableBooks==1&&r.issuedBooks==0&&r.totalMembers==1&&r.activeLoans==0);std::cout<<"All library tests passed.\n";}
