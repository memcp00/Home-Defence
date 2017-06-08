#pragma once
#include <vector>
#include <fstream>
#include <cmath>

#include "SFML/Graphics.hpp"
#include "../engine/VideoDriver.h"
#include "../engine/TextureManager.h"
#include "Tile.h"
#include "../characters/Player.h"

#define TILE_WIDTH TEXTURE_WIDTH
#define TILE_HEIGHT TEXTURE_HEIGHT

#define MIN_DISTANCE_BETWEEN_STATIONS 20
#define MAX_LINE_LENGTH 10

namespace World {

class WorldManager
{
public:
    void GenerateMap( std::string path );
    
    void renderMap( Engine::VideoDriver* videoDriver );
    
    int getStartPosX();
    int getStartPosY();
    
    //returns tile type at the given isometric position
    int getTileIndexAtIsoPos( int isoX, int isoY );
    //returns which side of tile character is located
    int getCharacterPositionOnTile( int index, int isoX, int isoY );
    
    //character functions
    void movePlayer( int direction );
    int getPlayerX();
    int getPlayerY();
    bool validateCharacterCoords( int x, int y );
    
private:
    std::vector<Tile> map;
    
    //map size in tiles (how many tiles make up each side)
    int tilesXCount, tilesYCount;
    
    //player starting positions
    int startPosX, startPosY;
    
    //characters
    Player* player;
    
    void orientWalls();
    void resetTileWalls( int index );
    
    void convertCartToIso( int& isoX, int& isoY, int cartX, int cartY );
    void convertIsoToCart( int& cartX, int& cartY, int isoX, int isoY );
    
    int convertIndexToY( int index );
    int convertIndexToX( int index );
    void convertIndexToIso( int& posx, int& posy, int index );
    int convertPositionToIndex( int posx, int posy );
    int getDistanceBetweenTiles( int startTile, int endTile );
    //checks if the neighbor tile has a wall. Used in orientWalls() function
    //takes the current tile index, neighbor direction (e.g. -1, 0)
    bool isNeighborWall( int currentIndex, int neighborDirectionX, int neighborDirectionY );
    //similar to isNeighborWall(), except it checks whether the neighbor tile is the right type
    bool validateNeighborTile( int currentIndex, int neighborDirectionX, int neighborDirectionY, int tileType );
    //checks if character is on the edge of the tile, where the walls are located
    //used for checking character collision with walls
    bool isCharacterOnEdge( int tileIndex, int posx, int posy );
    //check if the given position is inside the tile
    bool isPosInsideTile( int tileIndex, int posx, int posy );
    
    //will render a tile with walls, and an entity if it is on the tile
    void renderTile( Engine::VideoDriver* videoDriver, int tileIndex, int tileIsoX, int tileIsoY );
    
};

}



