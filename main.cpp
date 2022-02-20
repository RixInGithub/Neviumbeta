#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include "oscfg.hpp"
/* using std::cout; using std::cin;
using std::endl; using std::string;
namespace fs = std::filesystem;
using fs::current_path;*/
using namespace std; // Oh, okay... I have this line.
// string allCmds[1] = {"migrate"};
string isOwner = getenv("isOwner");
string cmd = "";
char answer1 = '?';

int main() {
  start();
  cout << "\033[0;32m" << ") ";
  cin >> cmd;
  
  /* switch(cmd) {
    case "migrate":
      
      switch(isOwner) {
        case "true":
          std::string answer1;
          std::cout << "Are you sure? [y/n] ";
          
          switch(answer1) {
            case "y":
              std::cout << "No new updates";
              break;
            case "n":
              break;
            default:
              std::cout << "Can't compare answer. Please try again later."
              break;
              return;
          }
        default:
          std::cout << "Can't migrate, not the owner."
      }
    default:
      std::cout << "No command found.";
  } */
  if (cmd == "migrate") { // <- Single quotes or duoble quotes? Double
    if (isOwner == "true") {
      cout << "Are you sure? [y/n]";
      cin >> answer1;
      if (answer1 == 'y') {
        cout << "No new updates";
      } else if (answer1 == 'n') {
        cout << ""; // Do nothing
      } else
       cout << "Can't compare answer. Please try again later.";
        return 0;
    } else if (isOwner != "true")
      std::cout << "Can't migrate, not the owner.";
  } else if (cmd != "migrate") { // Here is the error
    std::cout << "No command found.";
  }
  main();

  return 0;
}

/* void start() {
  system("clear");
  cout << "\x1B[44m";
  // system("Color 17");
  cout << "Nevium Beta\x1B[0m\n";
} */

// Double quotes is for strings
// Single is for chars

// Also using namespace std is so you dont have to use std:: on every single line 


// what grade r u?
// and what pronouns u use
// i dont wanna offend ppl
// alsp like my repls
// i also saw your shell
// not bad
// would actually like to see more linux cmds
// ls, cd, head, tail, sudo, etc
// is this gonna be windows
// probably be better in c#


// Well I'm just getting started, because I heard that C++ is a strong language. And I didn't start C++ bevause Python is slow ( well I use it ) it's just the speed of it.
// Oh, that's great! Because you could really help, so I'm glad you are experienced C++ before XD
