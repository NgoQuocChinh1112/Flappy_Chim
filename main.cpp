#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
    initGame();
    runGame();
    waitUntilKeyPressed();
    closeGame();
    return 0;
}
