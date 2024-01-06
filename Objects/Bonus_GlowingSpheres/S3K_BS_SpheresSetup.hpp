#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_BS_SpheresSetup : RSDK::GameObject::Entity {

    // Macros/Definitions (remove if none)

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        // one of these has to be a timer
        int32 field12_0x14;
        int16 field7_0xa;
        int16 field5_0x6;
        int16 field6_0x8;
        int16 field8_0xc;
        int16 field11_0x12;
        int16 field9_0xe;
        int16 field10_0x10;
    };

    // Entity Vars
    StateMachine<S3K_BS_SpheresSetup> state;

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
    void State_Normal();
    void State_FadeOut();

    // Draw States (remove if none)

    RSDK_DECLARE(S3K_BS_SpheresSetup);
};
} // namespace GameLogic