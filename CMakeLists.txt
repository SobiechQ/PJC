cmake_minimum_required(VERSION 3.24)
project (PJC2)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG a33701196adfad74917046096bf5a2aa0ab0bb50
)
FetchContent_MakeAvailable(fmt)

add_executable(m W03/main.cpp)
add_executable(w03z01 W03/z01/main.cpp)
add_executable(w03z02 W03/z02/main.cpp)
add_executable(w04z W04/main.cpp)
add_executable(w04z01 W04/Z01/main.cpp)
add_executable(w04z02 W04/Z02/main.cpp)
add_executable(w04z03 W04/Z03/main.cpp)
add_executable(sobiechCrypt Projekt/test.cpp Projekt/records/VaultRecord.cpp Projekt/filesManager/FilesManager.cpp Projekt/filesManager/FilesManager.h Projekt/filesManager/File.h Projekt/filesManager/File.cpp Projekt/records/VaultRecord.h Projekt/cipher/myCrypt.h Projekt/category/CategoryManager.h Projekt/category/CategoryManager.cpp Projekt/comparator/Comparator.h Projekt/comparator/Comparator.cpp Projekt/interface/Interface.h Projekt/interface/Interface.cpp)
add_executable(w05 W05/main.cpp)
add_executable(w05z01 W05/z01/main.cpp)
target_link_libraries(w04z01 fmt)
target_link_libraries(w04z02 fmt)
target_link_libraries(w04z03 fmt)
target_link_libraries(sobiechCrypt fmt)
target_link_libraries(w05 fmt)
target_link_libraries(w05z01 fmt)

