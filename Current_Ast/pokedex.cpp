#include "pokedex.hpp"
#include "myException.hpp"
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
{

}