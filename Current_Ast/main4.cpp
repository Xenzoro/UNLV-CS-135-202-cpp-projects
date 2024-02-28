//
// Created by BEN CISNEROS.
//

#include <vector>

#include "pokedex.hpp"
#include "greatball.hpp"
#include "masterball.hpp"
#include "ultraball.hpp"
#include "medicine.hpp"
#include "species.hpp"

int main4(int argc, char* argv[]) {
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

  // ====================================================================
  // ** creating different species of pokemon

  std::cout << std::string(80, '.') << std::endl;
  std::cout << ">> creating different species of Pokemons" << std::endl;
  std::vector<Species*> species;
  Entries** entries = pokedex.getEntries();
  for (Entries* ptr = *entries; ptr < *entries + pokedex.count(); ++ptr)
    species.push_back(ptr->getList());

  std::cout << "  * fire group" << std::endl;
  for (auto s : species)
    if (s->isFire()) {
      Pokemon* p = dynamic_cast<Pokemon*>(s);
      if (p)
        std::cout << std::string(3, ' ') << " [+] " << p->getName() << std::endl;
    }

  std::cout << "\n  * water group" << std::endl;
  for (auto s : species)
    if (s->isWater()) {
      Pokemon* p = dynamic_cast<Pokemon*>(s);
      if (p)
        std::cout << std::string(3, ' ') << " [+] " << p->getName() << std::endl;
    }

  std::cout << "\n  * grass group" << std::endl;
  for (auto s : species)
    if (s->isGrass()) {
      Pokemon* p = dynamic_cast<Pokemon*>(s);
      if (p)
        std::cout << std::string(3, ' ') << " [+] " << p->getName() << std::endl;
    }

  std::cout << "\n  * electric group" << std::endl;
  for (auto s : species)
    if (s->isElectric()) {
      Pokemon* p = dynamic_cast<Pokemon*>(s);
      if (p)
        std::cout << std::string(3, ' ') << " [+] " << p->getName() << std::endl;
    }

  std::cout << "\n  * none group" << std::endl;
  for (auto s : species)
    if (s->isNone()) {
      Pokemon* p = dynamic_cast<Pokemon*>(s);
      if (p)
        std::cout << std::string(3, ' ') << " [+] " << p->getName() << std::endl;
    }

  std::cout << "\n** DONE TESTING species **" << std::endl;
  std::cout << std::string(60, '=') << std::endl;

  return 0;
}