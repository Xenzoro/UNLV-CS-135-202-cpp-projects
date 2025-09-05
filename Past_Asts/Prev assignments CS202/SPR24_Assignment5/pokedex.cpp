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
#include "pokedex.hpp"
#include "myException.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.hpp"
Pokedex::Pokedex()
{
        count_ = 0;
        size_ = DEFAULT_SIZE;
        // This is a 1D array of pointers
        //theses pointers point to different items
        pokedex_ = new Entries*[size_];
}

Pokedex& Pokedex::operator=(const Pokedex& temp) //operator allows us to equal non prim vars
{   //avoid a shallow copy, make a deep one.

    this->count_ = temp.count_;
    this->size_ = temp.size_;
}

Pokedex::~Pokedex()
{
    delete[] pokedex_;
    count_ = 0 ;
    pokedex_ = nullptr;
}
//                entry list     specified index
void Pokedex::add(Pokemon* pList, int index)
{
    //* is the value stored at that address while = is the address itself
    if(!Pokedex::contains(pList,index)){
        resize();

        pokedex_[index]->add(*pList);

        count_++;
            }
}

bool Pokedex::contains(Pokemon *, int)
{

}

int Pokedex::count() const
{
    return count_;
}

void Pokedex::clear()
{
    //doesnt this only delete the outer pointer since pokedex_ is
    //entries**? No, it deletes all of it

  delete[] pokedex_;
  pokedex_ = nullptr; //think this is right
  count_ = 0;
}
//returns dymamic array of pokemon Entries
Entries** Pokedex::getEntries()
{
    return pokedex_; //this only returns the address to the first element..
                     // not the entire array right?
}
Entries** Pokedex::listByType(PokemonType type, int& size)
{
    //this is a 1D array of pointers to entries
    int count = 0;
    Entries** temp = new Entries*[size_];

    for(int i = 0; i < count_; i++)
    {   //does this account for both primary and secondary types?
                                   //no, only primary
        if(pokedex_[i]->getList()->getPrimary() == type)
        {
            //doesnt this cause an issue because only ONE type is being passed in as a
            // parameter?
            if(pokedex_[i]->getList()->getSecond() == type) {

                temp[count] = pokedex_[i];
                count++;
            }
        }
    }
    size = count;
    return temp;
}
Entries** Pokedex::listByRange(int start, int end) throw(myException)
{
    if(start < 0 || end > count_ || start > end)
    {
        throw myException("Invalid range");
    }
    int size = end - start;
    Entries** temp = new Entries*[size];
    for(int i = start; i < end; i++)
    {
        temp[i] = pokedex_[i];
    }
    return temp;
}

Pokemon* Pokedex::searchByName(std::string name) {
    //checks how many pokemon we have and iterates through the list.
    for (int i = 0; i < count_; i++) {
        // if the name is found in the list, return the pokemon
        if (pokedex_[i]->find(name)) {
            return pokedex_[i]->find(name);
        }
    }
    return nullptr;
}
void Pokedex::wakeupProfessorJimi(std::string file)
{
    std::ifstream ifile;
    ifile.open(file);

    if(!ifile.is_open())
    {
        throw myException("File not found");
    }
    //rest of entireity of the remainting string
    std::string temp0;
    //substring of temp0 with a specific length required for storing data
    std::string temp1;
    //I think this is what I need
    Pokemon* pokeTemp;

    while(!ifile.eof())
    {
        while(getline(ifile,temp0 )){

         temp1 = temp0.substr(0, temp0.find(','));
         temp0 = temp0.substr(delete)
         //temp0 = temp0.substr(temp0.find(',') + 1, temp0.length());

            }
        }





}