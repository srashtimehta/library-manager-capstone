# C++ Application Capstone — Library Manager

Portfolio-ready C++17 Library Manager, based on the earlier Object-Oriented Library Manager project.

## Capstone upgrades
- Refactored into `Book`, `Member`, `Loan`, and `Library` components.
- Added validation/error handling for duplicate IDs, invalid input, unavailable books, and invalid returns.
- Added reporting/analytics: total, available, issued books, members, and active loans.
- Added automated tests.
- Added CMake and Makefile builds.
- Added persistent records in `library_records.txt`.
- Added documentation and a short walkthrough script.

## Build

### CMake
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/library_manager
```

### GCC
```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/Book.cpp src/Member.cpp src/Loan.cpp src/Library.cpp tests/test_library.cpp -o library_tests
./library_tests
```

### Clang (second compiler)
```bash
clang++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/Book.cpp src/Member.cpp src/Loan.cpp src/Library.cpp tests/test_library.cpp -o library_tests_clang
./library_tests_clang
```

## Features
1. List books and availability
2. Search by title/author
3. Issue a book
4. Return a book
5. View analytics/report
6. Save and reload records

## Submission checklist
- [x] Refactor + naming + error handling
- [x] Reporting/analytics
- [x] Automated tests
- [x] Clean build configuration
- [x] Documentation
- [x] Walkthrough script
