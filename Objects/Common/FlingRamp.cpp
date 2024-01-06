// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: FlingRamp
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(FlingRamp);

void FlingRamp::Update()
{
    uint8 direction;
    char cVar2;
    int32 velX;

    this->visible = DebugMode::sVars->debugActive;

    foreach_active(Player, player)
    {
        if (player->onGround == true) {
            direction = this->direction;
            if (direction == FLIP_Y) {
                if (player->direction == FLIP_X && (velX = player->velocity.x, velX == -0x40000 || velX + 0x40000 < 0 != (velX |= 0x40000))) {
                something:
                    if (Player::CheckCollisionTouch(player, this, &sVars->hitbox)) {

                        player->onGround = false;
                        velX             = -TO_FIXED(4);

                        if (player->direction == FLIP_NONE)
                            velX = TO_FIXED(4);

                        player->velocity.x += velX;
                        player->velocity.y = -TO_FIXED(7);
                        player->animator.SetAnimation(player->aniFrames, Player::ANI_SPRING_CS, true, 0);
                        player->rotation = 0;
                    }
                }
            }
            else if (direction == FLIP_X) {
                cVar2 = player->direction;
            anotherThing:
                if ((cVar2 == FLIP_NONE) && (0x3ffff < player->velocity.x))
                    goto something;
            }
            else if (direction == FLIP_NONE) {
                cVar2 = player->direction;
                if (cVar2 != FLIP_X)
                    goto anotherThing;
                if (player->velocity.x < -0x3ffff)
                    goto something;
            }
        }
    }
}

void FlingRamp::LateUpdate() {}

void FlingRamp::StaticUpdate() {}

void FlingRamp::Draw(void)
{
    int16 frameID;
    uint8 direction;
    Animator debugIconAnimator;

    uint8 prevDirection = this->direction;

    if (prevDirection == FLIP_NONE) {
        frameID   = 6;
        direction = FLIP_NONE;
    }
    else if (prevDirection == FLIP_Y) {
        frameID   = 12;
        direction = FLIP_X;
    }
    else {
        if (prevDirection != FLIP_X) {
            frameID = 12;
            goto LAB_710013fb44;
        }
        direction = FLIP_NONE;
        frameID   = 12;
    }

    this->direction = direction;
LAB_710013fb44:

    debugIconAnimator.SetAnimation(sVars->aniFrames, 0, true, frameID);
    this->drawFX = FX_FLIP;
    debugIconAnimator.DrawSprite(&this->position, false);
    this->direction = prevDirection;
}

void FlingRamp::Create(void *data)
{
    if (!sceneInfo->inEditor) {
        this->active    = ACTIVE_BOUNDS;
        this->visible   = false;
        this->drawGroup = Zone::sVars->hudDrawGroup;
    }
}

void FlingRamp::StageLoad()
{
    sVars->aniFrames.Load("Editor/EditorIcons.bin", SCOPE_STAGE);
    sVars->hitbox.left   = -16;
    sVars->hitbox.top    = -16;
    sVars->hitbox.right  = 16;
    sVars->hitbox.bottom = 16;
}

#if RETRO_INCLUDE_EDITOR
void FlingRamp::EditorDraw() {}

void FlingRamp::EditorLoad() {}
#endif

void FlingRamp::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(FlingRamp);
}

void FlingRamp::Serialize() { RSDK_EDITABLE_VAR(FlingRamp, VAR_UINT8, direction); }

} // namespace GameLogic