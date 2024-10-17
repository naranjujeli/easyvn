cmake_minimum_required (VERSION 3.11)
 
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main 
)
FetchContent_MakeAvailable(ftxui)
 
project(easyvn LANGUAGES CXX VERSION 1.0.0)
file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(easyvn "${CPP_FILES}")
target_include_directories(easyvn PRIVATE include PRIVATE src/include)

target_link_libraries(easyvn
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component 
)
