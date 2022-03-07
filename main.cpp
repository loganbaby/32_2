#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"

inline void findActor(std::string path) {
  std::ifstream file("movies.json");
  if (file.is_open()) {
    nlohmann::json j;
    file >> j;
    //std::cout << j["disobedient"]["actors"][1]["name"];
    std::cout << "Enter the name of actor" << std::endl;
    std::cout << "For example: 'Viktor Harinak'" << std::endl;
    std::cout << ">>> ";
    std::string name = "";
    std::getline(std::cin, name);
    std::cin.ignore();

    for (auto it = j.begin(); it != j.end(); it++) {
      nlohmann::json movie = it.value();
      nlohmann::json movies = movie["actors"];

      int j = 0;
      for (auto jt = movies.begin(); jt != movies.end(); jt++, j++) {
        std::string foundName = to_string(jt.value());
        std::cout << movies[j];
      }
    } 
  } else {
    std::cout << "File not found!" << std::endl;
  }
  file.close();
}

inline void showJson(std::string path) {
  std::ifstream file("movies.json");
  if (file.is_open()) {
    nlohmann::json j;
    file >> j;
    std::cout << std::setw(4) << j << std::endl;
  } else {
    std::cout << "File not found!" << std::endl;
  }
  file.close();
}

enum class CommandType { SHOW_JSON = 1, FIND_ACTOR, EXIT };

int main() { 
  int command = 0;

  while (command != static_cast<int>(CommandType::EXIT)) {
    std::cout << "Enter the command" << std::endl;
    std::cout << static_cast<int>(CommandType::SHOW_JSON) << "# Show Json file"
              << std::endl;
    std::cout << static_cast<int>(CommandType::FIND_ACTOR) << "# Find actor"
              << std::endl;
    std::cout << static_cast<int>(CommandType::EXIT) << "# Exit" << std::endl;
    std::cout << ">>> ";
    std::cin >> command;
    std::cin.ignore();

    switch (command) {
      case static_cast<int>(CommandType::SHOW_JSON):
        showJson("movies.json");
        break;
      case static_cast<int>(CommandType::FIND_ACTOR):
        findActor("movies.json");
        break;
      default:
        std::cout << "Wrong input! Try again!" << std::endl;
    }

    system("pause");
    system("cls");
  }
}