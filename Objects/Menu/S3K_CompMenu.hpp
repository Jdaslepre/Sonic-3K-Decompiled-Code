#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_CompMenu : RSDK::GameObject::Entity {

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SoundFX sfxButton;
        SoundFX sfxStarPost;
        SoundFX sfxFail;
        SoundFX sfxEvent;
        int32 field20_0x14;
        uint8 field_0x24;
    };

    // Entity Vars
    StateMachine<S3K_CompMenu> state;
    StateMachine<S3K_CompMenu> stateDraw;

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

    // Draw States
    void Draw_Fade();

    RSDK_DECLARE(S3K_CompMenu);
};
} // namespace GameLogic