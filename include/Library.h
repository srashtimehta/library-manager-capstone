#pragma once
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <string>
#include <vector>
struct LibraryReport { std::size_t totalBooks{},availableBooks{},issuedBooks{},totalMembers{},activeLoans{}; };
class Library { std::vector<Book> books_; std::vector<Member> members_; std::vector<Loan> loans_; public: bool addBook(const Book&); bool addMember(const Member&); Book* findBook(int); const Book* findBook(int) const; Member* findMember(int); const Member* findMember(int) const; std::vector<const Book*> searchBooks(const std::string&) const; bool issueBook(int,int,const std::string&); bool returnBook(int); LibraryReport getReport() const; bool save(const std::string&) const; bool load(const std::string&); const std::vector<Book>& books() const; const std::vector<Member>& members() const; const std::vector<Loan>& loans() const; };
