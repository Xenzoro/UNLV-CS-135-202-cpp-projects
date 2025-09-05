#include "ast02.cpp"
int main(int argc, char *argv[]) { 
    srand((int)((argc == 2) ? atoi(argv[1]) : 0));  //RNG
    return ast02();
}