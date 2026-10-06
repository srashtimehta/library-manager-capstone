#pragma once
#include <string>
class Loan { int bookId_, memberId_; std::string issueDate_; bool returned_; public: Loan(int bookId,int memberId,std::string issueDate,bool returned=false); int getBookId() const; int getMemberId() const; const std::string& getIssueDate() const; bool isReturned() const; void markReturned(); std::string toCsv() const; };
