cmake_minimum_required(VERSION 3.10)
project(BlackjackClassicPointers)
set(CMAKE_CXX_STANDARD 17)
set(SOURCES
    src/Card.cpp
    src/Deck.cpp
    src/Hand.cpp
    src/Participant.cpp
    src/Player.cpp
    src/Dealer.cpp
    src/History.cpp
    src/Game.cpp
    src/main.cpp
)
include_directories(src)
add_executable(BlackjackClassicPointers ${SOURCES})
# Include directories