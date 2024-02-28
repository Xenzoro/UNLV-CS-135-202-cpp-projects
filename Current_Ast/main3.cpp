//
// Created by BEN CISNEROS.
//

#include <iostream>

#include "pokedex.hpp"
#include "greatball.hpp"
#include "masterball.hpp"
#include "ultraball.hpp"
#include "medicine.hpp"

int main3(int argc, char* argv[]) {
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
  // ** testing Pokemons

  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> creating 6 Pokemons" << std::endl;

  Pokemon* p1, * p2, * p3, * p4, * p5, * p6;
  std::cout << "** creating an instance of Pikachu" << std::endl;
  p1 = new Pokemon(*pokedex->searchByName("Pikachu"));
  std::cout << p1->toString() << std::endl;

  std::cout << "** creating an instance of Bulbasaur" << std::endl;
  p2 = new Pokemon(*pokedex->searchByName("Bulbasaur"));
  std::cout << p2->toString() << std::endl;

  std::cout << "** creating an instance of Charmander" << std::endl;
  p3 = new Pokemon(*pokedex->searchByName("Charmander"));
  std::cout << p3->toString() << std::endl;

  std::cout << "** creating an instance of Squirtle" << std::endl;
  p4 = new Pokemon(*pokedex->searchByName("Squirtle"));
  std::cout << p4->toString() << std::endl;

  std::cout << "** creating an instance of Pidgey" << std::endl;
  p5 = new Pokemon(*pokedex->searchByName("Pidgey"));
  std::cout << p5->toString() << std::endl;

  std::cout << "** creating an instance of Psyduck" << std::endl;
  p6 = new Pokemon(*pokedex->searchByName("Psyduck"));
  std::cout << p6->toString() << std::endl;

  // ====================================================================
  // ** testing polymorphism

  Greatball* g1, * g2, * g3;
  Ultrabrall* u1, * u2, * u3;
  Masterball* m1, * m2, * m3;

  int HP = 0;

  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> creating 9 Pokeballs" << std::endl;
  std::cout << "** creating 3 Greatballs" << std::endl;
  g1 = new Greatball(25);
  g2 = new Greatball(25);
  g3 = new Greatball(25);

  std::cout << "** creating 3 Ultraballs" << std::endl;
  u1 = new Ultrabrall(55);
  u2 = new Ultrabrall(55);
  u3 = new Ultrabrall(55);

  std::cout << "** creating 3 Masterballs" << std::endl;
  m1 = new Masterball(150);
  m2 = new Masterball(150);
  m3 = new Masterball(150);

  // ====================================================================
  // ** testing greatball

  // ** capturing pikachu
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Pikachu with Greatball" << std::endl;
  std::cout << " * Pikachu's HP: " << p1->getHp() << std::endl;
  std::cout << " * Greatball's energy: " << g1->getEnergy() << std::endl;
  std::cout << " * Greatball on action..." << std::endl;

  HP = p1->getHp();
  p1->decrementHp(g1->getEnergy());
  g1->decrementEnergy(HP);
  if (p1->getHp() <= 0 && g1->getEnergy() > 0) {
    std::cout << " * Pikachu was captured successfully" << std::endl;
    std::cout << "    - Pikachu's HP: " << p1->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << g1->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Pikachu b/c" << std::endl;
    std::cout << "    - Pikachu's HP: " << p1->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << g1->getEnergy() << std::endl;
  }

  // ** capturing bulbasaur
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Bulbasaur with Greatball" << std::endl;
  std::cout << " * Bulbasaur's HP: " << p2->getHp() << std::endl;
  std::cout << " * Greatball's energy: " << g2->getEnergy() << std::endl;
  std::cout << " * Greatball on action..." << std::endl;

  HP = p2->getHp();
  p2->decrementHp(g2->getEnergy());
  g2->decrementEnergy(HP);
  if (p2->getHp() <= 0 && g2->getEnergy() > 0) {
    std::cout << " * Bulbasaur was captured successfully" << std::endl;
    std::cout << "    - Bulbasaur's HP: " << p2->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << g2->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Bulbasaur b/c" << std::endl;
    std::cout << "    - Bulbasaur's HP: " << p2->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << g2->getEnergy() << std::endl;
  }

  // ** capturing squirtle
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Charmander with Greatball" << std::endl;
  std::cout << " * Charmander's HP: " << p3->getHp() << std::endl;
  std::cout << " * Greatball's energy: " << g3->getEnergy() << std::endl;
  std::cout << " * Greatball on action..." << std::endl;

  HP = p3->getHp();
  p3->decrementHp(g3->getEnergy());
  g3->decrementEnergy(HP);
  if (p3->getHp() <= 0 && g3->getEnergy() > 0) {
    std::cout << " * Charmander was captured successfully" << std::endl;
    std::cout << "    - Charmander's HP: " << p3->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << g3->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Charmander b/c" << std::endl;
    std::cout << "    - Charmander's HP: " << p3->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << g3->getEnergy() << std::endl;
  }

  delete p1;
  delete p2;
  delete p3;

  // ====================================================================
  // ** testing ultraball

  p1 = new Pokemon(*pokedex->searchByName("Pikachu"));
  p2 = new Pokemon(*pokedex->searchByName("Bulbasaur"));
  p3 = new Pokemon(*pokedex->searchByName("Charmander"));

  // ** capturing pikachu
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Pikachu with Ultraball" << std::endl;
  std::cout << " * Pikachu's HP: " << p1->getHp() << std::endl;
  std::cout << " * Ultraball's energy: " << u1->getEnergy() << std::endl;
  std::cout << " * Ultraball on action..." << std::endl;

  HP = p1->getHp();
  p1->decrementHp(u1->getEnergy());
  u1->decrementEnergy(HP);
  if (p1->getHp() <= 0 && u1->getEnergy() > 0) {
    std::cout << " * Pikachu was captured successfully" << std::endl;
    std::cout << "    - Pikachu's HP: " << p1->getHp() << std::endl;
    std::cout << "    - Ultraball's energy: " << u1->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Pikachu b/c" << std::endl;
    std::cout << "    - Pikachu's HP: " << p1->getHp() << std::endl;
    std::cout << "    - Ultraball's energy: " << u1->getEnergy() << std::endl;
  }

  // ** capturing bulbasaur
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Bulbasaur with Ultraball" << std::endl;
  std::cout << " * Bulbasaur's HP: " << p2->getHp() << std::endl;
  std::cout << " * Ultraball's energy: " << u2->getEnergy() << std::endl;
  std::cout << " * Ultraball on action..." << std::endl;

  HP = p2->getHp();
  p2->decrementHp(u2->getEnergy());
  u2->decrementEnergy(HP);
  if (p2->getHp() <= 0 && u2->getEnergy() > 0) {
    std::cout << " * Bulbasaur was captured successfully" << std::endl;
    std::cout << "    - Bulbasaur's HP: " << p2->getHp() << std::endl;
    std::cout << "    - Ultraball's energy: " << u2->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Bulbasaur b/c" << std::endl;
    std::cout << "    - Bulbasaur's HP: " << p2->getHp() << std::endl;
    std::cout << "    - Ultraball's energy: " << u2->getEnergy() << std::endl;
  }

  // ** capturing squirtle
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Squirtle with Ultraball" << std::endl;
  std::cout << " * Squirtle's HP: " << p3->getHp() << std::endl;
  std::cout << " * Ultraball's energy: " << u3->getEnergy() << std::endl;
  std::cout << " * Ultraball on action..." << std::endl;

  HP = p3->getHp();
  p3->decrementHp(u3->getEnergy());
  u3->decrementEnergy(HP);
  if (p3->getHp() <= 0 && u3->getEnergy() > 0) {
    std::cout << " * Charmander was captured successfully" << std::endl;
    std::cout << "    - Charmander's HP: " << p3->getHp() << std::endl;
    std::cout << "    - Ultraball's energy: " << u3->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Squirtle b/c" << std::endl;
    std::cout << "    - Charmander's HP: " << p3->getHp() << std::endl;
    std::cout << "    - Ultraball's energy: " << u3->getEnergy() << std::endl;
  }

  // ** delete the Pokemons
  delete p1;
  delete p2;
  delete p3;

  // ====================================================================
  // ** testing masterball

  // ** capturing squirtle
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Squirtle with Masterball" << std::endl;
  std::cout << " * Squirtle's HP: " << p1->getHp() << std::endl;
  std::cout << " * Masterball's energy: " << u1->getEnergy() << std::endl;
  std::cout << " * Masterball on action..." << std::endl;

  HP = p4->getHp();
  p4->decrementHp(m1->getEnergy());
  m1->decrementEnergy(HP);
  if (p4->getHp() <= 0 && m1->getEnergy() > 0) {
    std::cout << " * Squirtle was captured successfully" << std::endl;
    std::cout << "    - Squirtle's HP: " << p4->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << m1->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Squirtle b/c" << std::endl;
    std::cout << "    - Squirtle's HP: " << p4->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << m1->getEnergy() << std::endl;
  }

  // ** capturing pidgey
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Pidgey with Masterball" << std::endl;
  std::cout << " * Pidgey's HP: " << p1->getHp() << std::endl;
  std::cout << " * Masterball's energy: " << u1->getEnergy() << std::endl;
  std::cout << " * Masterball on action..." << std::endl;

  HP = p5->getHp();
  p5->decrementHp(m2->getEnergy());
  m2->decrementEnergy(HP);
  if (p5->getHp() <= 0 && m2->getEnergy() > 0) {
    std::cout << " * Pidgey was captured successfully" << std::endl;
    std::cout << "    - Pidgey's HP: " << p5->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << m2->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Pidgey b/c" << std::endl;
    std::cout << "    - Pidgey's HP: " << p5->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << m2->getEnergy() << std::endl;
  }

  // ** capturing psyduck
  std::cout << std::endl;
  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> catching Psyduck with Masterball" << std::endl;
  std::cout << " * Psyduck's HP: " << p1->getHp() << std::endl;
  std::cout << " * Masterball's energy: " << u1->getEnergy() << std::endl;
  std::cout << " * Masterball on action..." << std::endl;

  HP = p6->getHp();
  p6->decrementHp(m3->getEnergy());
  m3->decrementEnergy(HP);
  if (p6->getHp() <= 0 && m3->getEnergy() > 0) {
    std::cout << " * Psyduck was captured successfully" << std::endl;
    std::cout << "    - Psyduck's HP: " << p6->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << m3->getEnergy() << std::endl;
  } else {
    std::cout << " * Could not capture Psyduck b/c" << std::endl;
    std::cout << "    - Psyduck's HP: " << p6->getHp() << std::endl;
    std::cout << "    - Greatball's energy: " << m3->getEnergy() << std::endl;
  }

  // ** delete the Pokemons
  delete p4;
  delete p5;
  delete p6;

  // ** delete the Greatballs
  delete g1;
  delete g2;
  delete g3;

  // ** delete the Ultraballs
  delete u1;
  delete u2;
  delete u3;

  // ** delete the Masterballs
  delete m1;
  delete m2;
  delete m3;

  std::cout << "\n** DONE TESTING Pokeballs **" << std::endl;
  std::cout << std::string(60, '=') << std::endl;

  return 0;
}
