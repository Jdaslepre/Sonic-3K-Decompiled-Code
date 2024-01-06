#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_BSSetup : RSDK::GameObject::Entity {

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
        SoundFX sfxBeep;
        SoundFX sfxStarPost;
        SoundFX sfxFail;
        SoundFX sfxEvent;
        SoundFX sfxTwinkle;
        SoundFX sfxSpecialRing;
        uint8 field_0x17;
        int32 field_0x24;
        uint8 field_0x25;
        uint16 field21_0x16;
        bool32 field35_0x25;
        uint8 field34_0x24;

        int32 field_0x1a;
        int32 field_0x19;
        int32 field_0x23;
        int32 field_0x21;
        int32 field_0x20;
        int32 field_0x278;
        int32 field_0x1e;
        int32 field_0x22;
        uint8 field_0x18;
        uint8 field_0x1b;
        uint8 field_0x1c;
        uint8 field_0x1d;
        uint8 field_0x1f;
    };

    // Entity Vars
    StateMachine<S3K_BSSetup> state;

    Animator charactersAnimator;
    Animator tailsAnimator;
    Animator sonicAnimator;
    Animator knuxAnimator;
    Animator eggmanAnimator;
    Animator logoAnimator;
    Animator numbersAnimator;
    Animator numHighlightAnimator;
    Animator starAnimator;
    Animator messageAnimator;

    Animator field_0x198;
    Animator field_0x1b8;

    int64 field_0x1f8;
    int64 field_0x200;

    int32 field_0x228;
    int32 field_0x230;
    int32 field_0x238;
    int32 field_0x240;
    int32 field_0x248;
    uint8 field_0x260;
    int32 field_0x22c;
    int32 field_0x234;
    int32 field_0x23c;
    int32 field_0x244;
    int32 field_0x24c;
    int32 field_0x264;
    int32 field_0x1d;
    int32 field_0x1f;

    int32 field_0x80;
    uint8 field_0x160;

    int32 field_0x278; // timer maybe?
    int32 field_0x120;
    int32 field_0x12a;
    int32 field_0x12e;
    int32 field_0x27c;

    Vector2 someDrawPos;
    Vector2 someOtherDrawPos;

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
    void State_Title_Init();
    void State_Title();
    void State_Title2();
    void State_Menu();

    // Draw States (remove if none)

    // Macros (remove if none)

    RSDK_DECLARE(S3K_BSSetup);
};
} // namespace GameLogic