#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_SS_Player : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        uint16 jumpPressState;
        uint16 sphereBounceDelay;
        SpriteAnimation sonicFrames;
        SpriteAnimation tailsFrames;
        SpriteAnimation knuxFrames;
        SpriteAnimation amyFrames;
        SoundFX sfxJump;
    };

    // Entity Vars
    int32 gravityStrength;
    bool32 sidekick;
    StateMachine<S3K_SS_Player> stateInput;
    int32 controllerID;
    bool32 up;
    bool32 down;
    bool32 left;
    bool32 right;
    bool32 jumpPress;
    Animator animator;
    Animator tailAnimator;
    SpriteAnimation aniFrames;

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

    // Extra Entity Functions
    void Input_Gamepad();
    void Input_Following();

    RSDK_DECLARE(S3K_SS_Player);
};
} // namespace GameLogic