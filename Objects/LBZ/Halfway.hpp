#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct Halfway : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
        int32 screenPan;
        int32 somethingUnknown;
        uint8 anotherUnknown;
    };

    // Entity Vars
    StateMachine<Halfway> state;
    Animator animator;
    int8 type;
    int32 field_0x98;
    int32 field_0x9c;
    int32 field_0xa0;

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
    void State_DeathEggFall();
    void State_DeathEggCrash();

    // Draw States (remove if none)

    RSDK_DECLARE(Halfway);
};
} // namespace GameLogic