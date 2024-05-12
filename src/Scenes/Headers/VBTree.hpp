#pragma once

#include "../Scenes.hpp"

#include "../../Entity/header/Player.hpp"
#include "../../Entity/header/Tile.hpp"

#include "../../Util/SceneManager.hpp"
#include "../../Util/GUIManager.hpp"
#include "../../GUI/Button.hpp"
#include "../../GUI/TextZone.hpp"

class VBTree : public Scene
{
public:
    VBTree()
    {
        mainMenuMusic = LoadMusicStream("rescources/sounds/music/Underclocked.mp3");
        PlayMusicStream(mainMenuMusic);

    }

    void Render() override
    {

    };
private:
    Music mainMenuMusic;
    //Estructura*
};