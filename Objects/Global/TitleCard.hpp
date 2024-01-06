#pragma once
#include "Game.hpp"
#include "../Common/FXFade.hpp"

using namespace RSDK;

namespace GameLogic
{

struct TitleCard : RSDK::GameObject::Entity {

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
        String secondaryWord;
        String strName;
    };

    // Entity Vars
    StateMachine<TitleCard> state;
    String strName;
    uint8 actID;
    Animator actIDAnimator;
    Animator fontAnimator;
    bool32 noBanner;

    FXFade *storedFade;
    Animator gameNameAnimator;

    // uh
    uint8 storedStrWidth;

    Vector2 bannerPos;

    int32 field_0x98;
    int32 field_0xa0;
    int32 field_0xac;

    int32 field_0xb4;

    Vector2 primaryWordPos;
    // some data here and there
    Vector2 secondaryWordPos;

    int32 field_0xd0;
    int32 field_0xd4;
    int32 field_0xc0;
    int32 field_0xc8;
    int32 field_0xcc;
    int32 field_0xdc;

    uint8 field_0x9c;
    uint8 field_0xb0;
    uint8 field_0xc4;
    uint8 field_0xd8;
    uint8 field_0xe0;
    int32 field_0x80;

    uint8 field_0xf8;
    uint8 field_0xe2;
    uint8 field_0x96;

    int32 field_0xe1; // type not checked

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
    void State_MoveIn();
    void State_Wait();
    void State_WaitFade();
    void State_MoveOut();

    // Draw States (remove if none)

    // Macros (remove if none)

    RSDK_DECLARE(TitleCard);
};
} // namespace GameLogic