// ---------------------------------------------------------------------
// RSDK Project: S3KT Example Mods
// Object Name: SuperSparkle
// *Decompiled by: Jd1206
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(SuperSparkle);

void SuperSparkle::Update() { this->state.Run(this); }

void SuperSparkle::LateUpdate()
{
    if (this->state.Matches(nullptr)) {
        if (this->player->superState == Player::SUPERSTATE_SUPER)
            this->state.Set(&SuperSparkle::State_SuperSparkle);

        else if (this->player->superState == Player::SUPERSTATE_HYPER)
            this->state.Set(&SuperSparkle::State_HyperSparkle);
    }
}

void SuperSparkle::StaticUpdate() {}

void SuperSparkle::Draw()
{
    Player *player = this->player;
    Animator sparkleAnimator;

    uint8 timerDelay;
    uint8 timerDelay2;

    int32 angle;
    int32 timer;
    int32 calculatedAngle;

    Vector2 drawPos;

    if (this->state.Matches(&SuperSparkle::State_HyperSparkle)) {

        sparkleAnimator.SetAnimation(sVars->aniFrames, 1, true, 1);

        angle = this->angle;

        // Sparkle 1

        timer = this->timer % 8;

        drawPos.x = player->position.x;
        drawPos.y = player->position.y;

        calculatedAngle = Math::Cos1024(angle);
        drawPos.x += timer * 0x180 * calculatedAngle;

        calculatedAngle = Math::Sin1024(angle);
        drawPos.y += timer * 0x180 * calculatedAngle;

        sparkleAnimator.frameID = timer;

        if (timer < 0)
            sparkleAnimator.frameID = timer + 1;

        sparkleAnimator.frameID >>= 1;
        sparkleAnimator.DrawSprite(&drawPos, false);

        // Sparkle 2

        timerDelay  = timer + 2;
        timerDelay2 = timer + 9;

        if (timerDelay > -1)
            timerDelay2 = timerDelay;

        timer = timerDelay - (timerDelay2 & 0xfffffff8);

        drawPos.x = player->position.x;
        drawPos.y = player->position.y;

        calculatedAngle = Math::Cos1024(angle + 0x100);
        drawPos.x += timer * 0x180 * calculatedAngle;

        calculatedAngle = Math::Sin1024(angle + 0x100);
        drawPos.y += timer * 0x180 * calculatedAngle;

        sparkleAnimator.frameID = timer;

        if (timer < 0)
            sparkleAnimator.frameID = timer + 1;

        sparkleAnimator.frameID >>= 1;
        sparkleAnimator.DrawSprite(&drawPos, false);

        // Sparkle 3

        timerDelay  = timer + 2;
        timerDelay2 = timer + 9;

        if (timerDelay > -1)
            timerDelay2 = timerDelay;

        timer = timerDelay - (timerDelay2 & 0xfffffff8);

        drawPos.x = player->position.x;
        drawPos.y = player->position.y;

        calculatedAngle = Math::Cos1024(angle + 0x200);
        drawPos.x += timer * 0x180 * calculatedAngle;

        calculatedAngle = Math::Sin1024(angle + 0x200);
        drawPos.y += timer * 0x180 * calculatedAngle;

        sparkleAnimator.frameID = timer;

        if (timer < 0)
            sparkleAnimator.frameID = timer + 1;

        sparkleAnimator.frameID >>= 1;
        sparkleAnimator.DrawSprite(&drawPos, false);

        // Sparkle 4

        timerDelay  = timer + 2;
        timerDelay2 = timer + 9;

        if (timerDelay > -1)
            timerDelay2 = timerDelay;

        timer = timerDelay - (timerDelay2 & 0xfffffff8);

        drawPos.x = player->position.x;
        drawPos.y = player->position.y;

        calculatedAngle = Math::Cos1024(angle + 0x300);
        drawPos.x += timer * 0x180 * calculatedAngle;

        calculatedAngle = Math::Sin1024(angle + 0x300);
        drawPos.y += timer * 0x180 * calculatedAngle;

        if (timer < 0)
            timer += 1;

        sparkleAnimator.frameID = timer >> 1;
        sparkleAnimator.DrawSprite(&drawPos, false);
    }
}

void SuperSparkle::Create(void *data)
{
    if (!sceneInfo->inEditor) {
        this->active = ACTIVE_NORMAL;
        this->player = (Player *)data;
    }
}

void SuperSparkle::StageLoad() { sVars->aniFrames.Load("3K_Global/SuperSparkle.bin", SCOPE_STAGE); }

#if RETRO_INCLUDE_EDITOR
void SuperSparkle::EditorDraw() {}

void SuperSparkle::EditorLoad() {}
#endif

void SuperSparkle::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(SuperSparkle);
}

void SuperSparkle::Serialize() {}

// Basically just the mania one with 3K changes
// They're basically identical though

void SuperSparkle::State_SuperSparkle()
{
    SET_CURRENT_STATE();

    Player *player = this->player;

    if (!player) {
        this->Destroy();
    }
    else {
        if (player->groundedStore)
            this->canSpawnSparkle = abs(player->velocity.y) + abs(player->velocity.x) > TO_FIXED(6);

        if (this->canSpawnSparkle) {
            if (++this->timer == 14) {
                this->timer = 0;

                Debris *sparkle = CREATE_ENTITY(Debris, NULL, player->position.x, player->position.y);
                sparkle->state.Set(&Debris::State_Move);
                sparkle->timer = 16;

                /* Enabled by some global variable for some reason? the alpha is always 0x100 for some reason tho
                sparkle->inkEffect    = INK_ADD;
                */

                sparkle->alpha     = 0x100;
                sparkle->drawGroup = Zone::sVars->objectDrawGroup[1];
                sparkle->drawGroup = player->drawGroup;
                sparkle->animator.SetAnimation(sVars->aniFrames, 0, true, 0);
            }
        }
        else {
            this->timer = 0;
        }

        if (player->superState != Player::SUPERSTATE_SUPER || player->active == ACTIVE_NEVER)
            this->Destroy();
    }
}

void SuperSparkle::State_HyperSparkle()
{
    SET_CURRENT_STATE();

    Player *player = this->player;
    int32 angle;

    if (!player) { // if/else check taken from SuperSparkle_State_SuperSparkle, custom
        this->Destroy();
    }
    else {
        this->visible   = true; // was originally in the create func, didn't work for some reason
        this->drawGroup = player->drawGroup;
        this->timer += 1;

        if ((player->direction | FLIP_Y) == FLIP_Y)
            angle = 16;
        else
            angle = -16;

        this->angle += angle;

        if (player->superState != Player::SUPERSTATE_HYPER || player->active == ACTIVE_NEVER) // custom as well
            this->Destroy();
    }
}

} // namespace GameLogic