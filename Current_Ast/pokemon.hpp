//
// Created by origi on 2/27/2024.
//

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
