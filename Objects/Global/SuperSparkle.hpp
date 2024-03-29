#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct SuperSparkle : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
    };

    // Entity Vars
    StateMachine<SuperSparkle> state;
    Animator animator;
    Player *player;
    int32 timer;
    bool32 canSpawnSparkle;

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
    void State_SuperSparkle();
    void State_HyperSparkle();

    RSDK_DECLARE(SuperSparkle);
};
} // namespace GameLogic