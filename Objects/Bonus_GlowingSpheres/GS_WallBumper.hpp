#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct GS_WallBumper : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        Hitbox hitbox;
        SpriteAnimation aniFrames;
        SoundFX sfxBumper;
    };

    // Entity Vars
    int32 timer;
    Animator animator;

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

    // Extra Entity Functions (remove if none)

    // States (remove if none)

    // Draw States (remove if none)

    RSDK_DECLARE(GS_WallBumper);
};
} // namespace GameLogic