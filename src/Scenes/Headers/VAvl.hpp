#pragma once

#include "Scenes.hpp"

#include "Entity/header/Player.hpp"
#include "Entity/header/Tile.hpp"

#include "Util/SceneManager.hpp"
#include "Util/GUIManager.hpp"
#include "GUI/Button.hpp"
#include "GUI/TextZone.hpp"

#include "cstdlib"

//#include "../structures/avl/avl.hpp"

class VAVL : public Scene
{
public:
    VAVL()
    {
        mainMenuMusic = LoadMusicStream("rescources/sounds/music/Underclocked.mp3");
        PlayMusicStream(mainMenuMusic);

        insert = new Button("insert", 25, 100);
        find = new Button("find", 25, 200);
        remove = new Button("remove", 25, 300);
        range = new Button("range", 25, 400);
        ret = new Button("return", 25, 500);
    }

    static void ins(){

    }

    static void rem(){

    }

    static void fi(){

    }

    static void ran(){

    }

    static void retur(){

    }

    void Render() override
    {
        UpdateMusicStream(mainMenuMusic);

        DrawText("By Rodrigo", 2, GetScreenHeight() - 22, 20, WHITE);


        insert->Render(ins);
        remove->Render(rem);
        find->Render(fi);
        range->Render(ran);
        ret->Render(retur);

        int key = GetKeyPressed();
        int num = 0;
        while (!IsKeyPressed(KEY_ENTER)){

            if (isdigit(key)) {
                num += key;
                num *= 10;
            }
        }

        DrawText("Enter text:", 0, 0, 50, BLACK);
        DrawRectangleLines(300, 2, 200, 40, BLACK);
        DrawText(to_string(num).c_str(), 310, 0, 50, BLACK);

    };
private:
    Music mainMenuMusic;
    Button *insert, *remove, *find, *range, *ret;
    //Estructura*
};