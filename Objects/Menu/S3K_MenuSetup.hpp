#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_MenuSetup : RSDK::GameObject::Entity {

    // Macros/Definitions (remove if none)

    // Enums & Structs (remove if none)

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        SpriteAnimation aniFrames;
        int16 unknown1;
        int32 unknown2;
    };

    // Entity Vars
    uint8 id;
    Vector2 size;

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
    static void somethingNoSave();

    // States (remove if none)

    // Draw States (remove if none)

    RSDK_DECLARE(S3K_MenuSetup);
};
} // namespace GameLogic