cmake_minimum_required(VERSION 3.15)
project(telegram_article)

set(CMAKE_CXX_STANDARD 17)

add_executable(tgnews src/main.cpp src/Parser.h src/Parser.cpp src/stat.h)