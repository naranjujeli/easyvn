#include <stdlib.h>  // for EXIT_SUCCESS
#include <string>  // for string, operator+, basic_string, to_string, char_traits
#include <vector>  // for vector, __alloc_traits<>::value_type
#include "ftxui/component/component.hpp"  // for Menu, Renderer, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, Element, operator|, window, flex, vbox
 
using namespace ftxui;

Component Panel(std::string title, Component component) {
  return Renderer(component, [component, title] { 
    return window(text(title), component->Render()) | size(WIDTH, EQUAL, 65) | flex;
  });
}

Component MainMenu(std::vector<std::string> *menu_entries, int *menu_selected){
  auto component = Container::Vertical(
    {
        Panel("[f]iles", Menu(menu_entries, menu_selected)),
    }
  );


  auto diff = Renderer([&]{
    return vbox({
        text("diff")
        });
  });
  
  auto global = Container::Horizontal({
      component,
      diff | border | flex
  });

  return global;

}



// Component CommitForm(std::string *message, std::string *task, std::function<void()> hide_form) {
//
//   Component input_message = Input(message);
//   auto component = Container::Vertical({
//     input_message,
//   });
//   auto render =  Renderer(component, [&]{
//     return vbox({
//       hbox({text("Commit message:") | center | border}),
//     });
//   });
//
//   render |= CatchEvent([&](Event event) {
//     if(event == Event::Return && *message != "") {
//       // commit 
//       return true;
//     }
//     if (event == Event::Escape || event == Event::Character('c')) {
//       hide_form();
//       return true;
//     }
//     return false;
//   });
//
//   return render;
// }

 
int main() {
  int menu_selected[] = {0};

  std::vector<std::string> menu_entries = {
    "Ananas",
    "Raspberry",
    "Citrus",
  };
 
  int menu_selected_global = 0;

  bool popup_commit = false;
  std::string commit_message;
  std::string commit_task;
  
  auto hide_form = [&] { popup_commit = false;};
  auto show_form = [&] { popup_commit = true;};
  // Component commit_form = CommitForm(&commit_message, &commit_task, hide_form);
 
  auto screen = ScreenInteractive::Fullscreen();


  auto global = MainMenu(&menu_entries, menu_selected);

  // global |= Modal(commit_form, &popup_commit);

  global |= CatchEvent([&](Event event) {
    // if events could only be handled here we should make a state machine
    if (event == Event::Character('q')) {
        screen.ExitLoopClosure()();
      return true;
    }

    if(popup_commit) {
      if(event == Event::Return && commit_message != "") {
        // commit 
        return true;
      }
      if (event == Event::Escape || event == Event::Character('c')) {
        hide_form();
        return true;
      }
    } else {

    if(event == Event::Character('c')) {
      show_form();
      return true;
    }
    }
    return false;
  });

  screen.Loop(global);
  return EXIT_SUCCESS;
}
