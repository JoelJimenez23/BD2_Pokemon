#include "SceneMainMenu.hpp"

void SceneDocumen::ButtonRet(){
    SceneMainMenu *Walk;
    Walk = new SceneMainMenu();
    SceneManager::LoadScene(Walk);
}