#include "Character.h"

void Character::setDirection( int direction )
{
    this->direction = direction;
}

void Character::move( int& newPosx, int& newPosy )
{
    newPosx = this->posx;
    newPosy = this->posy;
    switch ( this->direction )
    {
        case TEXTURE_PLAYER_SW:
            newPosy += this->speed;
            newPosx -= this->speed;
            break;
        case TEXTURE_PLAYER_S:
            newPosy += this->speed;
            break;
        case TEXTURE_PLAYER_SE:
            newPosx += this->speed;
            newPosy += this->speed;
            break;
        case TEXTURE_PLAYER_E:
            newPosx += this->speed;
            break;
        case TEXTURE_PLAYER_NE:
            newPosy -= this->speed;
            newPosx += this->speed;
            break;
        case TEXTURE_PLAYER_N:
            newPosy -= this->speed;
            break;
        case TEXTURE_PLAYER_NW:
            newPosy -= this->speed;
            newPosx -= this->speed;
            break;
        case TEXTURE_PLAYER_W:
            newPosx -= this->speed;
            break;
    }
        
}

void Character::setPosition( float posx, float posy )
{
    this->posx = posx;
    this->posy = posy;
}

void Character::draw( Engine::VideoDriver* videoDriver )
{
    videoDriver->drawTexture( Engine::TextureManager::getTexture( textureIndex, direction ), 
                                      this->posx, this->posy );
}

int Character::getX()
{
    return this->posx;
}

int Character::getY()
{
    return this->posy;
}


void Character::takeDamage( int damage )
{
    this->health -= damage;
}

int Character::getHealth()
{
    return health;
}

void Character::setHealth( int value )
{
    health = value;
}

bool Character::checkCollision( int posx, int posy )
{
    if ( posx >= this->posx && posx <= this->posx + CHARACTER_WIDTH )
    {
        if ( posy >= this->posy && posy <= this->posy + CHARACTER_HEIGHT )
        {
            return true;
        }
    }
    return false;
}

