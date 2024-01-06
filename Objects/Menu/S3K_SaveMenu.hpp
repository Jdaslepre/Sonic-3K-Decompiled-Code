#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_SaveMenu : RSDK::GameObject::Entity {

    // Macros/Definitions (remove if none)

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SoundFX sfxButton;
        SoundFX sfxSlot;
        SoundFX sfxBumper;
        SoundFX sfxWarp;

        int32 field16_0x10;
        int32 field18_0x15;
        int32 field_0x14;
    };

    // Entity Vars
    TileLayer *BGLayer;

    int32 field_0x54;
    int32 field_0x5d;
    int32 field_0x57;
    int32 field_0x5b;

    StateMachine<S3K_SaveMenu> state;
    StateMachine<S3K_SaveMenu> stateDraw;
    int32 field_0xd8;
    String dataSelectString;
    Animator field151_0x98;
    int32 field_0xdc;
    int32 field_0x80; // weird state var... thing, remove?
    Animator animator;
    uint16 fade;
    int32 field_0xda;

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
    void State_Navigate();
    void State_FadeIn();

    // Draw States
    void Draw_Fade();

    RSDK_DECLARE(S3K_SaveMenu);
};
} // namespace GameLogic