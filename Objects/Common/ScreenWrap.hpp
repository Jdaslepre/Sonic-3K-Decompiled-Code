#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct ScreenWrap : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        ScreenWrap *ptr;
    };

    // Entity Vars
    StateMachine<ScreenWrap> state;
    Vector2 buffer;
    uint8 type;
    bool32 deactivated;

    int32 field_0x6c;
    int32 field_0x80;
    int32 field_0x68;
    uint16 someheight;
    int32 field_0x78;
    int32 field_0x7a;
    int32 field_0x76;

    uint8 field_0xa0;
    int32 field_0xa4;

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

    // States
    void State_Vertical();
    void State_Horizontal();

    RSDK_DECLARE(ScreenWrap);
};
} // namespace GameLogic