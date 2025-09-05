cmake_minimum_required(VERSION 4.0)
project(_idea)

set(CMAKE_CXX_STANDARD 14)

add_executable(_idea
        codeStyles/codeStyleConfig.xml
        .gitignore
        editor.xml
        EDU_CS.iml
        modules.xml
        vcs.xml
        "../Past_Asts/Prev assignments CS202/SPR24_Assignment7/main.cpp")
