#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_AIZIntro : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
    };

    // Entity Vars
    StateMachine<S3K_AIZIntro> state;
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

    // States
    void State_Init();
    void State_Idle();

    RSDK_DECLARE(S3K_AIZIntro);
};
} // namespace GameLogic