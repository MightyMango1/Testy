cmake_minimum_required(VERSION 3.10)
project(AddCard)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
add_executable(addCard
    ./server/cpp/programs/create.cpp
    ./server/cpp/src/card.cpp
    ./server/database/database.cpp
)

# Link to SQLite
target_link_libraries(addCard sqlite3)