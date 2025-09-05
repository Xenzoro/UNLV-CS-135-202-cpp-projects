//
// Created by BEN CISNEROS.
//

#include <iostream>
#include <string>

#include "pokedex.hpp"
#include "myException.hpp"

int main(int argc, char* argv[]) {
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

  Pokedex pokedex;
  pokedex.wakeupProfessorJimi(file);

  // ===================================================================
  // ** testing Pokedex

  int from = 4, to = 20;
  try {
    std::cout << std::string(80, '.') << std::endl;

    from = 4;
    to = 20;
    Entries** listByRange = pokedex.listByRange(from, to);

    std::cout << ">> Testing listByRange(" << std::to_string(from) << ","
              << std::to_string(to) << ") **\n" << std::endl;

    for (Entries* ptr = *listByRange; ptr < *listByRange + (to - from); ++ptr)
      std::cout << ptr->toString() << std::endl;
    delete[] listByRange;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ** this generates error!
  try {
    std::cout << std::endl;
    std::cout << std::string(80, '.') << std::endl;

    from = pokedex.count();
    to = 10;
    Entries** listByRange = pokedex.listByRange(from, to);

    std::cout << ">> Testing listByRange(" << std::to_string(from) << ","
              << std::to_string(to) << ") **\n" << std::endl;
    for (Entries* ptr = *listByRange; ptr < *listByRange + (to - from); ++ptr)
      std::cout << ptr->toString() << std::endl;
    delete[] listByRange;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ** this generates error!
  try {
    std::cout << std::endl;
    std::cout << std::string(80, '.') << std::endl;

    from = 0;
    to = pokedex.count();
    Entries** listByRange = pokedex.listByRange(from, to);

    std::cout << ">> Testing listByRange(" << std::to_string(from) << ","
              << std::to_string(to) << ") **\n" << std::endl;

    for (Entries* ptr = *listByRange; ptr < *listByRange + (to - from); ++ptr)
      std::cout << ptr->toString() << std::endl;
    delete[] listByRange;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ** this generates error!
  try {
    std::cout << std::endl;
    std::cout << std::string(80, '.') << std::endl;

    from = 15;
    to = 15;
    Entries** listByRange = pokedex.listByRange(from, to);

    std::cout << ">> Testing listByRange(" << std::to_string(from) << ","
              << std::to_string(to) << ") **\n" << std::endl;

    for (Entries* ptr = *listByRange; ptr < *listByRange + (to - from); ++ptr)
      std::cout << ptr->toString() << std::endl;
    delete[] listByRange;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ** testing Pokedex
  try {
    std::cout << std::endl;
    std::cout << std::string(80, '.') << std::endl;

    from = pokedex.count() - 5;
    to = pokedex.count() - 1;
    Entries** listByRange = pokedex.listByRange(from, to);

    std::cout << ">> Testing listByRange(" << std::to_string(from) << ","
              << std::to_string(to) << ") **\n" << std::endl;

    for (Entries* ptr = *listByRange; ptr < *listByRange + (to - from); ++ptr)
      std::cout << ptr->toString() << std::endl;
    delete[] listByRange;
  } catch (const myException& ex) {
    std::cout << ex.what() << std::endl;
  }

  // ===================================================================
  // ** testing Pokemon of fire type

  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;

  int size;
  Entries** listByType = pokedex.listByType(PokemonType::water, size);

  std::cout << ">> Testing listByteType(" << Pokemon::PokemonTypeToString(PokemonType::water)
            << ") **\n" << std::endl;
  for (Entries* ptr = *listByType; ptr < *listByType + size; ++ptr)
    std::cout << ptr->toString() << std::endl;
  delete[] listByType;

  // ** testing Pokemon of water type
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;

  listByType = pokedex.listByType(PokemonType::fire, size);

  std::cout << ">> Testing listByteType(" << Pokemon::PokemonTypeToString(PokemonType::water)
            << ") **\n" << std::endl;

  for (Entries* ptr = *listByType; ptr < *listByType + size; ++ptr)
    std::cout << ptr->toString() << std::endl;
  delete[] listByType;

  // ** testing Pokemon of poison type
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;

  listByType = pokedex.listByType(PokemonType::poison, size);

  std::cout << ">> Testing listByteType(" << Pokemon::PokemonTypeToString(PokemonType::poison)
            << ") **\n" << std::endl;

  for (Entries* ptr = *listByType; ptr < *listByType + size; ++ptr)
    std::cout << ptr->toString() << std::endl;
  delete[] listByType;

  // ===================================================================
  // ** testing Pokemon

  // ** searching by name
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> Looking for Newtwo..." << std::endl;

  Pokemon* pokemon = pokedex.searchByName("Newtwo");

  if (!pokemon) {
    std::cout << "Pokemon not found!!!" << std::endl;
  } else {
    std::cout << "Printing Pokemon's information" << std::endl;
    std::cout << pokemon->toString() << std::endl;
  }

  // ** searching by name
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> Looking for Pikachu..." << std::endl;

  pokemon = pokedex.searchByName("Pikachu");

  if (!pokemon) {
    std::cout << "Pokemon not found!!!" << std::endl;
  } else {
    std::cout << "Printing Pokemon's information" << std::endl;
    std::cout << pokemon->toString() << std::endl;
  }

  // ** searching by name
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> Looking for Venonat..." << std::endl;

  pokemon = pokedex.searchByName("Venonat");

  if (!pokemon) {
    std::cout << "Pokemon not found!!!" << std::endl;
  } else {
    std::cout << "Printing Pokemon's information" << std::endl;
    std::cout << pokemon->toString() << std::endl;
  }

  // ** contains Pokemon
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> Contains Pikachu..." << std::endl;

  if (pokedex.contains(*pokemon))
    std::cout << "Pokemon found!!!" << std::endl;

  // ** check for equality between two pokemons
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> Are two objects equals?" << std::endl;
  Pokemon* pikachu, * nidoranF, * pidgeotto, * kadabra;

  std::cout << "Looking for Pikachu..." << std::endl;

  pikachu = pokedex.searchByName("Pikachu");
  if (pikachu)
    std::cout << "Pikachu found!!!" << std::endl;

  std::cout << "Looking for Female Nidoran..." << std::endl;

  nidoranF = pokedex.searchByName("NidoranF");
  if (nidoranF)
    std::cout << "Female Nidoran found!!!" << std::endl;

  std::cout << "Looking for Pidgeotto..." << std::endl;

  pidgeotto = pokedex.searchByName("Pidgeotto");
  if (pidgeotto)
    std::cout << "Female Pidgeotto found!!!" << std::endl;

  std::cout << "Looking for Kadabra..." << std::endl;

  kadabra = pokedex.searchByName("Kadabra");
  if (pidgeotto)
    std::cout << "Female Kadabra found!!!" << std::endl;

  std::cout << "\n>> Pikachu equal()" << std::endl;
  std::cout << "Pikachu equals to Pikachu ? " << pikachu->equals(*pikachu) << std::endl; // true
  std::cout << "Pikachu equals to Nidoran ? " << pikachu->equals(*nidoranF) << std::endl; // false
  std::cout << "Pikachu equals to Pidgeotto ? " << pikachu->equals(*pidgeotto) << std::endl; // false
  std::cout << "Pikachu equals to Kadabra ? " << pikachu->equals(*kadabra) << std::endl; // false

  std::cout << "\n>> Female Nidoran equal()" << std::endl;
  std::cout << "Nidoran equals to Pikachu ? " << nidoranF->equals(*pikachu) << std::endl; // false
  std::cout << "Nidoran equals to Nidoran ? " << nidoranF->equals(*nidoranF) << std::endl; // true
  std::cout << "Nidoran equals to Pidgeotto ? " << nidoranF->equals(*pidgeotto) << std::endl; // false
  std::cout << "Nidoran equals to Kadabra ? " << nidoranF->equals(*kadabra) << std::endl; // false

  std::cout << "\n>> Pidgeotto equal()" << std::endl;
  std::cout << "Pidgeotto equals to Pikachu ? " << pidgeotto->equals(*pikachu) << std::endl; // false
  std::cout << "Pidgeotto equals to Nidoran ? " << pidgeotto->equals(*nidoranF) << std::endl; // false
  std::cout << "Pidgeotto equals to Pidgeotto ? " << pidgeotto->equals(*pidgeotto) << std::endl; // true
  std::cout << "Pidgeotto equals to Kadabra ? " << pidgeotto->equals(*kadabra) << std::endl; // false

  std::cout << "\n>> Kadabra equal()" << std::endl;
  std::cout << "Kadabra equals to Pikachu ? " << kadabra->equals(*pikachu) << std::endl; // false
  std::cout << "Kadabra equals to Nidoran ? " << kadabra->equals(*nidoranF) << std::endl; // false
  std::cout << "Kadabra equals to Pidgeotto ? " << kadabra->equals(*pidgeotto) << std::endl; // false
  std::cout << "Kadabra equals to Kadabra ? " << kadabra->equals(*kadabra) << std::endl; // true

  pokedex.clear();

  std::cout << "\n** DONE TESTING Pokedex **" << std::endl;
  std::cout << std::string(60, '=') << std::endl;

  return 0;
}