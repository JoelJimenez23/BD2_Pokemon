#include "SceneMainMenu.hpp"

void Visualize::ButtonRet(){
    SceneMainMenu *Walk;
    Walk = new SceneMainMenu();
    SceneManager::LoadScene(Walk);
}