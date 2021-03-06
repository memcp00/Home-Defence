#include "GameStateBuild.h"

using namespace GameStates;

GameStateBuild::GameStateBuild( World::WorldManager* worldManager, int windowWidth, int windowHeight )
{
    this->worldManager = worldManager;
    this->screen = new Screens::GameBuildScreen( windowWidth, windowHeight );
}


void GameStateBuild::update( int money, int mouseX, int mouseY, int windowWidth, int windowHeight )
{
    this->screen->updateUI( money );
    worldManager->selectTile( mouseX - windowWidth / 2, mouseY - windowHeight / 2 );
}

void GameStateBuild::draw( Engine::VideoDriver* videoDriver )
{
    this->screen->renderFrame( videoDriver, worldManager );
}

void GameStateBuild::reset()
{
    
}

void GameStateBuild::handleMouseClick( int mouseX, int mouseY, int& money )
{
    if ( screen->handleClick( mouseX, mouseY ) )
        return; //mouse click was handled in uimanager, so do not continue
    
    int buildMode = screen->getBuildMode();
    if ( buildMode == MODE_BUILD_WALLS )
    {
        int selectedWall = screen->getSelectedWallType();
        int selectedWallCost = screen->getSelectedWallCost( selectedWall );
        if ( money >= selectedWallCost )
        {
            if ( worldManager->buildWall( selectedWall ) )
            {
                money -= selectedWallCost;
            }
        }
    }
    else if ( buildMode == MODE_BUILD_DEFENCES )
    {
        int selectedDefence = screen->getSelectedDefence();
        int selectedDefenceCost = screen->getSelectedDefenceCost( selectedDefence );
        if ( money >= selectedDefenceCost )
        {
            if ( worldManager->createDefence( selectedDefence ) )
            {
                money -= selectedDefenceCost;
            }
        }
    }
}