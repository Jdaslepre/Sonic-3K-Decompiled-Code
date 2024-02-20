#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_SS_Horizon : GameObject::Entity {

    // Object/Static Vars
    struct Static : GameObject::Static {
        SpriteAnimation aniFrames;
    };

    // Entity Vars
    Animator animator;

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

    RSDK_DECLARE(S3K_SS_Horizon);
};
} // namespace GameLogic