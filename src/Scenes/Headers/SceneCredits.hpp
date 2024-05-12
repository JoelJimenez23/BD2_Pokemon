#pragma once

#include "SceneMainMenu.hpp"

class Credits : public Scene
{
public:
    Credits()
    {
        mainMenuMusic = LoadMusicStream("rescources/sounds/music/Underclocked.mp3");
        PlayMusicStream(mainMenuMusic);

        Rod = new Button("RODRIGO", GetScreenWidth() / 2 - 150, 125);
        Rog = new Button("ROGER", GetScreenWidth() / 2 - 150, GetScreenHeight() - 225);
        Ang = new Button("ANGELLO", GetScreenWidth() / 2 - 150, GetScreenHeight() - 350);
        Art = new Button("ARTURO", GetScreenWidth() / 2 - 150, GetScreenHeight() - 475);
        Joe = new Button("JOEL", GetScreenWidth() / 2 - 150, GetScreenHeight() - 100);
    }

    static void nothing(){

    }

    void Render() override
    {
        UpdateMusicStream(mainMenuMusic);

        DrawText("By Rodrigo", 2, GetScreenHeight() - 22, 20, WHITE);

        DrawRectangle(GetScreenWidth() / 3, 90, GetScreenWidth() / 3, 2, BLACK);

        Rod->Render(nothing);
        Rog->Render(nothing);
        Ang->Render(nothing);
        Art->Render(nothing);
        Joe->Render(nothing);
    };
private:
    Music mainMenuMusic;
    Button *Rod, *Ang, *Rog, *Joe, *Art;
};