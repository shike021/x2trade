cmake_minimum_required(VERSION 3.10)
project(arbitrage_bot)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.71 REQUIRED COMPONENTS system asio json log log_setup)

include_directories(include)
link_directories(${Boost_LIBRARY_DIRS})

add_executable(arbitrage_bot
    src/config.cpp
    src/http_client_pool.cpp
    src/logger.cpp
    src/main.cpp
    src/strategy.cpp
    src/websocket_client.cpp
)

target_link_libraries(arbitrage_bot
    ${Boost_LIBRARIES}
    pthread
)
