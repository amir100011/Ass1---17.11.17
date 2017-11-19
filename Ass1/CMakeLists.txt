cmake_minimum_required(VERSION 3.8)
project(Ass1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
       include/Commands.h
        include/Environment.h
        include/Files.h
        include/FileSystem.h
       include/GlobalVariables.h
        src/BaseFile.cpp
       src/Directory.cpp
       src/Files.cpp
        src/Environment.cpp
        src/Main.cpp
        src/BaseCommand.cpp
       # src/testMain.cpp
        src/FIleSystem.cpp
        src/Commands.cpp
       # src/FileTest2.cpp
        src/rename.cpp
        src/generalFunctions.cpp
        include/generalFunctions.h
        src/HistoryCommand.cpp
        src/RmCommand.cpp)


add_executable(Ass1 ${SOURCE_FILES})