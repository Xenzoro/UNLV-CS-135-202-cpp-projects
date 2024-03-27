/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_5
    * Description:The objective of this assignment is to utilize the outlined bullet points
    * to illustrate a segment of
      the game development process, specifically focusing on crafting a
      once-popular game (which may not enjoy the same level of popularity today,
      reflecting back to the era when Professor Jimi and I were considerably younger) using C++.
      Through this assignment, you will gain familiarity with the substantial workload typically
      associated with certain applications, as well as learn to implement a selection of popular
      design patterns tailored for them. Additionally, there is an opportunity for extra credit
      by extending certain classes to introduce new Pok´emon characters and arenas. It is important
      to note that while this portion of the assignment is optional, you may only proceed with
      it once your program functions correctly. Further details about the second assignment
      for extra credit can be found on Canvas.
    * Input: numbers from input txt files/ or user input
    * Output: a visual representation of rooms
*/
#ifndef EDU_CS_POKEMON_HPP
#define EDU_CS_POKEMON_HPP
#include <string>
#include "Move.hpp"

enum PokemonType
{
    normal, fire, water, electric, grass, ice, fighting,
    poison, ground, flying, psychic, bug, rock, ghost,
    dragon, none
};

class Pokemon
{
public:
    Pokemon();
    Pokemon(int,std::string,int, int, PokemonType,PokemonType,std::string, std::string, Move*,int);
    Pokemon(const Pokemon&);
    Pokemon& operator=(const Pokemon&);
    ~Pokemon();
    int getNumber() const;
    std::string getName() const;
    int getDefense();
    int getHp() const;
    void decrementHp(int);
    int getTotalMoves() const;
    Move* getMoves();
    PokemonType getPrimary() const;
    PokemonType getSecond() const;
    std::string getWeakness() const;
    std::string toString();
    int compare(const Pokemon&);
    bool equals(const Pokemon&);
public:
    static std::string PokemonTypeToString(PokemonType type);
    static PokemonType getPokemonType (std::string);
private:
    int num_;
    std::string name_;
    int hp_;
    int defense_;
    int totalMoves_;
    Move* moves_;
    std::string weakness_;
    std::string resistance_;
    PokemonType primary_;
    PokemonType second_;
};

#endif //EDU_CS_POKEMON_HPP
