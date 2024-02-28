//
// Created by BEN CISNEROS.
//

#include <iostream>

#include "pokedex.hpp"
#include "pokebag.hpp"
#include "medicine.hpp"
#include "myException.hpp"

int main2(int argc, char* argv[]) {
  if (argc < 1) {
    std::cout << "ERROR: invalid number of command-line arguments." << std::endl;
    exit(0);
  }

  // NOTE: dynamic memory is needed for this test

  // ====================================================================
  // ** testing Pokedex

  std::string file = argv[1];

  std::cout << "Waking up Professor Jimi with file '" << file << "'" << std::endl;
  std::cout << "Professor Jimi's response: Whyyyyyyyy?\n" << std::endl;

  Pokedex* pokedex = new Pokedex;
  pokedex->wakeupProfessorJimi(file);

  // ====================================================================
  // ** testing Pokebag
  Pokebag pokebag;

  // ** comparing pokedexes
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> comparing pokedex" << std::endl;

  try {
    std::cout << "Pokedex equals to Pokedex ? " << (pokedex->equals(*pokedex)) << std::endl;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ** adding Pokedex to Pokebag
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> adding pokedex to the Pokebag" << std::endl;
  pokebag.add(pokedex);

  // ** creating Medicine
  std::cout << "\n>> using medicine on Pikachu" << std::endl;
  Medicine m1, m2, m3;
  Pokemon* pokemon = new Pokemon(*pokedex->searchByName("Pikachu"));
  m1.setPokemon(pokemon);

  std::cout << ">> displaying medicine information" << std::endl;
  std::cout << m1.toString() << std::endl;

  std::cout << ">> using medicine on Meowth" << std::endl;
  pokemon = new Pokemon(*pokedex->searchByName("Meowth"));
  m2.setPokemon(pokemon);

  std::cout << ">> displaying medicine information" << std::endl;
  std::cout << m2.toString() << std::endl;

  std::cout << ">> using medicine on Ekans" << std::endl;
  pokemon = new Pokemon(*pokedex->searchByName("Ekans"));
  m3.setPokemon(pokemon);

  std::cout << ">> displaying medicine information" << std::endl;
  std::cout << m3.toString() << std::endl;

  // ====================================================================
  // ** testing polymorphism

  Item* items[4] = {pokedex, &m1, &m2, &m3};

  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> iterating through an array of Items" << std::endl;

  int i = 0;
  for (auto it : items) {
    std::cout << std::string(40, '~') << "[ITEM #" << ++i << "]" << std::string(40, '~') << std::endl;
    std::cout << it->toString() << std::endl;
  }

  // ====================================================================
  // ** comparing objects

  try {
    std::cout << "\n>> comparing Pokedex ? " << pokedex->compare(*pokedex) << std::endl;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  try {
    std::cout << "\n>> equals Pokedex ? " << pokedex->equals(*pokedex) << std::endl;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ====================================================================
  // ** generates errors

  try {
    std::cout << "\n>> transforming Pokedex into Medicine..." << std::endl;
    pokedex->asMedicine();
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  try {
    std::cout << "\n>> transforming Pokedex into Pokeball..." << std::endl;
    pokedex->asPokeball();
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  try {
    std::cout << "\n>> transforming Pokedex into Pokedex..." << std::endl;
    pokedex->asPokedex();
    std::cout << "   should not throw an exception!" << std::endl;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  std::cout << "\n** DONE TESTING Pokebag **" << std::endl;
  std::cout << std::string(60, '=') << std::endl;

  return 0;
}