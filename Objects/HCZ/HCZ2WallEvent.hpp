#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct HCZ2WallEvent : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        StateMachine<HCZ2WallEvent> state;
        SoundFX sfxRumble;
        SoundFX sfxImpact;
        Hitbox hitbox;
        TileLayer *moveLayer;
    };

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
    void State_Idle();
    void State_Move();

    RSDK_DECLARE(HCZ2WallEvent);
};
} // namespace GameLogic