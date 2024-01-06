#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct FlingRamp : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
        Hitbox hitbox;
    };

    // Standard Entity Events
    void Create(void *data);
    void Draw();
    void Update();
    void LateUpdate();
    static void StaticUpdate();
    static void StageLoad();
    static void StaticLoad(Static *sVars);
    static void Serialize();

#if RETRO_INCLUDE_EDITOR
    static void EditorLoad();
    void EditorDraw();
#endif

    RSDK_DECLARE(FlingRamp);
};
} // namespace GameLogic