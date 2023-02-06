#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "logic.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::istringstream;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    //open file
    ifstream thisfile;
    thisfile.open(fileName);
    //check if it exists
    if(!thisfile.is_open()){
        return nullptr;
    }
    //create variables
    int maxRow = 0;
    int maxCol = 0;
    char**level = createMap(maxRow, maxCol);
    //________________________________OG FUNCTION___________________________________
    // //open file stream
	// ifstream thisfile;
	// thisfile.open(fileName);
    // //check if file exists
    // if(!thisfile.is_open()){
	// 	//cout << "Cannot open "<< fileName;
    //     //throw std::invalid_argument("Cannot open file");
    //     return nullptr;
	// }else{
    //     //get first line and assign maxRow/maxCol
    //     string row1;
    //     getline(thisfile, row1);
    //     istringstream inSS(row1);
    //     inSS >> maxRow;
    //     if(inSS.fail() || maxRow <= 0 || maxRow >= INT32_MAX){
    //         //throw std::invalid_argument("Bad maxRow value");
    //         return nullptr;
    //     }
    //     inSS >> maxCol;
    //     if(inSS.fail() || maxCol <= 0 || maxCol >= INT32_MAX){
    //         //throw std::invalid_argument("Bad maxCol value");
    //         return nullptr;
    //     }
    //     if(maxRow*maxCol >= INT32_MAX){
    //         //throw std::invalid_argument("Map too big");
    //         return nullptr;
    //     }
    //     //cout << row1 << endl;
    //     //get second line and set player row and col
    //     string row2;
    //     getline(thisfile, row2);
    //     istringstream SS(row2);
    //     SS >> player.row;
    //     if(inSS.fail() || maxRow < player.row || player.row < 0){
    //         //throw std::invalid_argument("Bad player.row value");
    //         return nullptr;
    //     }
    //     SS >> player.col;
    //     if(inSS.fail() || player.col < 0 || player.col > maxCol){
    //         //throw std::invalid_argument("Bad player.col value");
    //         return nullptr;
    //     }
    //     //create 2D array
    //     // int tracker = 0;
    //     // char** level = new char*[maxRow];
    //     // for(int i = 0; i < maxRow; ++i){
    //     //     ++tracker;
    //     //     level[i] = new char[maxCol];
    //     // }
    //     char** level = createMap(maxRow, maxCol);
    //     //cout << tracker << endl;
    //     //go through rest of file to build out 2D array
    //     string row;
    //     //iterate through rows
    //     for(int i = 0; i < maxRow; ++i){
    //         getline(thisfile,row);
    //         istringstream inSS(row);
    //         //cout << row << endl;
    //         for(int j = 0; j < maxCol; j++){
    //             inSS >> level[i][j];
    //             //cout << j << " ";
    //             if(inSS.fail()){
    //                 //throw std::invalid_argument("Bad map value");
    //                 return nullptr;
    //             }
    //             char validValues[8] = {'-', 'o', '$', '@', 'M', '+', '?', '!'};
    //             bool valid = false;
    //             bool escape = false;
    //             for(int c = 0; c < 8; ++c){
    //                 if(level[i][j] == validValues[c]){
    //                     valid = true;
    //                     break;
    //                 }
    //                 if(level[i][j] == '!' || level[i][j] == '?'){
    //                     escape = true;
    //                 }
    //             }
    //             if(!valid){
    //                 //throw std::invalid_argument("Bad map value");
    //                 return nullptr;
    //             }
    //             // if(!escape){
    //             //     return nullptr;
    //             // }
    //         }
    //     }
    //     //set player in map
    //     if(maxRow*maxCol < 1){
    //         return nullptr;
    //     }
    //     level[player.row][player.col] = 'o';
    //     //cout << maxRow << maxCol << player.row << player.col << endl;
        return level;
    //}
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if(nextRow < 0 || nextCol < 0){
        //throw std::invalid_argument("Bad input int");
    }
    if(input == 'e' || input == 'q'){
    }else if(input == 'w'){
        nextRow--;
    }else if(input == 'a'){
        nextCol--;
    }else if(input == 's'){
        nextRow++;
    }else if(input == 'd'){
        nextCol++;
    }else{
        //throw std::invalid_argument("Bad input char");
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    char** level = new char*[maxRow];
    for(int i = 0; i < maxRow; i++){
        level[i] = new char[maxCol];
    }
    for(int i = 0; i < maxRow; ++i){
        for(int j = 0; j < maxCol; ++j){
            level[i][j] = '-';
        }
    }
    return level;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map != nullptr && maxRow > 0){
        for(int i = 0; i < maxRow; ++i){
            delete[] map[i];
        }
        delete[] map;
        map = nullptr;
        maxRow = 0;
    }else{
        maxRow = 0;
        map = nullptr;
    }
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    //create new dimesnions and preserve old dimensions
    int ogRow = maxRow;
    int ogCol = maxCol;
    maxRow *= 2;
    maxCol *= 2;
    if(maxRow <= 0 || maxCol <= 0){
        //throw std::invalid_argument("Bad map dimensions");
        return nullptr;
    }
    //create new map array
    char** newmap = createMap(maxRow, maxCol);
    //copy old map contents over to new map
    for(int i = 0; i < ogRow; ++i){
        for(int j = 0; j < ogCol; ++j){
            newmap[i][j] = map[i][j];
        }
    }
    //copy contents down
    for(int i = ogRow; i < maxRow; ++i){
        for(int j = 0; j < ogCol; ++j){
            newmap[i][j] = map[i-ogRow][j];
            if(map[i-ogRow][j] == 'o'){
                newmap[i][j] = '-';
            }
        }
        
    }
    //copy right
    for(int i = 0; i < ogRow; ++i){
        for(int j = ogCol; j < maxCol; ++j){
            newmap[i][j] = map[i][j-ogCol];
            if(map[i][j-ogCol] == 'o'){
                newmap[i][j] = '-';
            }
        }
    }
    //copy diagnal down
    for(int i = ogRow; i < maxRow; ++i){
        for(int j = ogCol; j < maxCol; ++j){
            newmap[i][j] = map[i-ogRow][j-ogCol];
            if(map[i-ogRow][j-ogCol] == 'o'){
                newmap[i][j] = '-';
            }
        }
    }
    //deallocate old memory
    deleteMap(map, ogRow);
    return newmap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    //check if next move is into a pillar, out of bounds, or into a monster
    if(nextRow >=  maxRow){
        //cout << "You cannot move into a monster!" << endl;
        return 0;
    }else if(nextCol >= maxCol){
        return 0;
    }else if(nextRow < 0){
        return 0;
    }else if(nextCol < 0){
        return 0;
    }else if(map[nextRow][nextCol] == '+'){
        //cout << "You cannot move into a pillar!" << endl;
        return 0;
    }else if(map[nextRow][nextCol] == 'M'){
        //cout << "You cannot move out of bounds" << endl;
        return 0;
    }
    //check for treasure
    if(map[nextRow][nextCol] == '$'){
        player.treasure++;
        map[player.row][player.col] = '-';
        player.col = nextCol;
        player.row = nextRow;
        map[nextRow][nextCol] = 'o';
        return 2;
    //check for amulet
    }else if(map[nextRow][nextCol] == '@'){
        map[player.row][player.col] = '-';
        player.col = nextCol;
        player.row = nextRow;
        map[nextRow][nextCol] = 'o';
        return 3;
    //check for door
    }else if(map[nextRow][nextCol] == '?'){
        map[player.row][player.col] = '-';
        player.col = nextCol;
        player.row = nextRow;
        map[nextRow][nextCol] = 'o';
        return 4;
    //check for map exit
    }else if(map[nextRow][nextCol] == '!'){
        if(player.treasure > 0){
            map[player.row][player.col] = '-';
            player.col = nextCol;
            player.row = nextRow;
            map[nextRow][nextCol] = 'o';
            return 5;
        }else{
            return 0;
        }
    }else{
        map[player.row][player.col] = '-';
        player.col = nextCol;
        player.row = nextRow;
        map[nextRow][nextCol] = 'o';
        return 1;
    }
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    bool attack = false;
    //check up, iterate over rows < player.row
    for(int i = player.row - 1; i >= 0; --i){
        if(map[i][player.col] == '+'){
            break;
        }else if(map[i][player.col] == 'M'){
            map[i][player.col] = '-';
            map[i+1][player.col] = 'M';
        }
    }
    //check down, iterate over rows > player.row
    for(int i = player.row + 1; i < maxRow; ++i){
        if(map[i][player.col] == '+'){
            break;
        }else if(map[i][player.col] == 'M'){
            map[i][player.col] = '-';
            map[i-1][player.col] = 'M';
        }
    }
    //check left, iterate over columns < player.col
    for(int i = player.col - 1; i >= 0; --i){
        if(map[player.row][i] == '+'){
            break;
        }else if(map[player.row][i] == 'M'){
            map[player.row][i] = '-';
            map[player.row][i+1] = 'M';
        }
    }
    //check right from player, iterate over columns > player.col
    for(int i = player.col + 1; i < maxCol; ++i){
        if(map[player.row][i] == '+'){
            break;
        }else if(map[player.row][i] == 'M'){
            map[player.row][i] = '-';
            map[player.row][i-1] = 'M';
        } 
    }
    if(map[player.row][player.col] == 'M'){
        attack = true;
    }
    return attack;
}
