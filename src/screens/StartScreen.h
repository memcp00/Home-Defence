#pragma once 

#include "Screen.h"
#include "../ui/UIButton.h"

namespace Screens {
    
class StartScreen : public Screen {
public:
    StartScreen( int windowWidth, int windowHeight );
    
private:
    UI::UILabel title;
    UI::UIButton startButton;
    UI::UIButton quitButton;
    
    const int buttonWidth = 250, buttonHeight = 50;
};

}

