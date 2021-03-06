#pragma once
#include <string>

#include "SignalManager.h"
#include "SFML/Graphics.hpp"

#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 32
#define WALL_HEIGHT 48
#define WALL_WIDTH 32

#define CHARACTER_WIDTH 10
#define CHARACTER_HEIGHT 20

enum TextureTypes {
    TEXTURE_NONE,
    TEXTURE_FLOOR,
    TEXTURE_GRASS,
    TEXTURE_EMPTY_TILE,
    TEXTURE_WALL_WOODEN,
    TEXTURE_WALL_BRICK,
    TEXTURE_PLAYER,
    TEXTURE_GHOST,
    TEXTURE_BULLET,
    TEXTURE_GEM,
    TEXTURE_ICON_HEART,
    TEXTURE_ICON_BULLET,
    TEXTURE_ICON_HAMMER,
    TEXTURE_ICON_GEM,
    TEXTURE_DEFENCE_PLASMA_GUN
};

enum WallTypes {
    TEXTURE_WALL_HOR_100,
    TEXTURE_WALL_HOR_75,
    TEXTURE_WALL_HOR_50,
    TEXTURE_WALL_HOR_25,
    TEXTURE_WALL_HOR_10,
    TEXTURE_WALL_VERT_100,
    TEXTURE_WALL_VERT_75,
    TEXTURE_WALL_VERT_50,
    TEXTURE_WALL_VERT_25,
    TEXTURE_WALL_VERT_10,
    TEXTURE_WALL_TOTAL
};

enum PlayerTextures {
    TEXTURE_PLAYER_SW,
    TEXTURE_PLAYER_S,
    TEXTURE_PLAYER_SE,
    TEXTURE_PLAYER_E,
    TEXTURE_PLAYER_NE,
    TEXTURE_PLAYER_N,
    TEXTURE_PLAYER_NW,
    TEXTURE_PLAYER_W,
    TEXTURE_PLAYER_TOTAL
};

enum FontTypes {
    FONT_SIMPLE
};

namespace Engine {
class TextureManager
{
public:
    TextureManager( std::string programPath );
    static sf::Texture& getTexture( int type, int texturePart = 0 );
    static sf::Font& getFont( int type );
    
private:
    static void load( sf::Texture* texture, std::string path );
    static void loadFont( sf::Font* font, std::string path );
    static void loadSpriteSheet( sf::Texture texture[], int amount, std::string path, int textureHeight = TEXTURE_HEIGHT, int textureWidth = TEXTURE_WIDTH );
    
    static sf::Texture floorTexture;
    static sf::Texture grassTexture;
    static sf::Texture emptyTileTexture;
    static sf::Texture woodWallTextures[TEXTURE_WALL_TOTAL];
    static sf::Texture brickWallTextures[TEXTURE_WALL_TOTAL];
    static sf::Texture playerTexture[TEXTURE_PLAYER_TOTAL];
    static sf::Texture ghostTexture[TEXTURE_PLAYER_TOTAL];
    static sf::Texture bulletTexture;
    static sf::Texture gemTexture;
    static sf::Texture plasmaGunTexture;
    
    static sf::Texture heartIcon;
    static sf::Texture bulletIcon;
    static sf::Texture hammerIcon;
    static sf::Texture gemIcon;
    
    static sf::Font basicFont;
};
}


