#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_FBZSetup : RSDK::GameObject::Entity {

    // Enums & Structs (remove if none)
    // add backgrounds?

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
    };

    // Entity Vars (remove if none)

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
    void TriggerExterior();
    void TriggerInterior();
    void TriggerScreenLock();
    void TriggerAbortBoundMarker(); // i rlly hate how this is BoundMarker instead of BoundsMarker
    void TriggerIntro();            // also why are these Trigger... instead of Trigger_...

    // Draw States (remove if none)

    RSDK_DECLARE(S3K_FBZSetup);
};
} // namespace GameLogic