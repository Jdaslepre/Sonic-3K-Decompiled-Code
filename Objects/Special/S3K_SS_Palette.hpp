#pragma once
#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

struct S3K_SS_Palette : RSDK::GameObject::Entity {

    // Object/Static Vars
    struct Static : RSDK::GameObject::Static {
        int32 startColorID;
        int32 skyAlpha;
        int32 globeAlpha;
        SpriteAnimation aniFrames;
    };

    // Entity Vars
    bool32 useStageConfig;
    int32 paletteID;
    uint8 skyAlpha;
    uint8 globeAlpha;
    color playfieldA;
    color playfieldB;
    color bgColor1;
    color bgColor2;
    color bgColor3;
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

    RSDK_DECLARE(S3K_SS_Palette);
};
} // namespace GameLogic