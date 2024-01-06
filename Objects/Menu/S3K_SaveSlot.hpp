#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_SaveSlot : RSDK::GameObject::Entity {

    // Macros/Definitions (remove if none)

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SoundFX sfxStarPost;
        SoundFX sfxEvent;
        SpriteAnimation aniFrames;
        Animator animator;
    };

    // Entity Vars
    StateMachine<S3K_SaveSlot> state;

    Animator animator1;
    Animator animator2;
    Animator animator3;
    Animator animator4;

    Vector2 someVector;

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

    RSDK_DECLARE(S3K_SaveSlot);
};
} // namespace GameLogic