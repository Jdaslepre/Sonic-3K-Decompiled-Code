#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct GenericTrigger : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        StateMachine<GenericTrigger> callbacks[16];
        int32 playerID;
        uint16 aniFrames;
        GenericTrigger *ptr;
    };

    // Entity Vars
    Vector2 size;
    uint8 triggerID;
    int32 activationLimit;
    bool32 ran;
    int32 parameter;
    bool32 allPlayers;
    Hitbox hitbox;
    Animator animator;

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

    RSDK_DECLARE(GenericTrigger);
};
} // namespace GameLogic