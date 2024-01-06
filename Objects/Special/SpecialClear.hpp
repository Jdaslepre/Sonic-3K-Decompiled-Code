#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct SpecialClear : RSDK::GameObject::Entity {

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
#if !MANIA_USE_PLUS
        SpriteAnimation continueFrames;
#endif
        SoundFX sfxScoreAdd;
        SoundFX sfxScoreTotal;
        SoundFX sfxEvent;
        SoundFX sfxContinue;
        SoundFX sfxTwinkle;
        SoundFX sfxSuperEmerald;
        int32 field16_0x18;
        int16 field21_0x20;
        int16 field22_0x22;
        uint8 field_0x14;
    };

    // Entity Vars
    int8 type;
    StateMachine<SpecialClear> state;
    Animator animator;
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

    // States
    void State_Init();

    // Draw States (remove if none)

    // Macros (remove if none)

    RSDK_DECLARE(SpecialClear);
};
} // namespace GameLogic