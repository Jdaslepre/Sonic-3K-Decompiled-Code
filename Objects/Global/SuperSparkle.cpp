// ---------------------------------------------------------------------
// RSDK Project: Sonic 3K
// Object Name: SuperSparkle
// Decompiled by: Jd1206
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(SuperSparkle);

void SuperSparkle::Update() { }

void SuperSparkle::LateUpdate()
{
    this->state.Run(this);

    if (this->player->superState != Player::SUPERSTATE_SUPER && this->player->active == ACTIVE_NEVER)
        this->Destroy();
}

void SuperSparkle::StaticUpdate() {}

void SuperSparkle::Draw()
{
    if (this->state.Matches(&SuperSparkle::State_HyperSparkle)) {

        // Sparkle 1

        int32 timer     = this->timer % 8;
        Vector2 drawPos = this->player->position;

        drawPos.x += timer * 0x180 * Math::Cos1024(this->angle);
        drawPos.y += timer * 0x180 * Math::Sin1024(this->angle);

        this->animator.frameID = ((timer < 0) ? timer + 1 : timer) >> 1;
        this->animator.DrawSprite(&drawPos, false);

        // Sparkle 2

        uint8 tOffset  = timer + 2;
        uint8 tOffset2 = timer + 9;

        if (tOffset > -1)
            tOffset2 = tOffset;

        timer   = tOffset - (tOffset2 & -8);
        drawPos = this->player->position;

        drawPos.x += timer * 0x180 * Math::Cos1024(this->angle + 0x100);
        drawPos.y += timer * 0x180 * Math::Sin1024(this->angle + 0x100);

        this->animator.frameID = ((timer < 0) ? timer + 1 : timer) >> 1;
        this->animator.DrawSprite(&drawPos, false);

        // Sparkle 3

        tOffset  = timer + 2;
        tOffset2 = timer + 9;

        if (tOffset > -1)
            tOffset2 = tOffset;

        timer   = tOffset - (tOffset2 & -8);
        drawPos = this->player->position;

        drawPos.x += timer * 0x180 * Math::Cos1024(this->angle + 0x200);
        drawPos.y += timer * 0x180 * Math::Sin1024(this->angle + 0x200);

        this->animator.frameID = ((timer < 0) ? timer + 1 : timer) >> 1;
        this->animator.DrawSprite(&drawPos, false);

        // Sparkle 4

        tOffset  = timer + 2;
        tOffset2 = timer + 9;

        if (tOffset > -1)
            tOffset2 = tOffset;

        timer   = tOffset - (tOffset2 & -8);
        drawPos = this->player->position;

        drawPos.x += timer * 0x180 * Math::Cos1024(this->angle + 0x300);
        drawPos.y += timer * 0x180 * Math::Sin1024(this->angle + 0x300);

        if (timer < 0)
            ++timer;

        this->animator.frameID = timer >> 1;
        this->animator.DrawSprite(&drawPos, false);
    }
}

void SuperSparkle::Create(void *data)
{
    if (!sceneInfo->inEditor) {
        this->active = ACTIVE_NORMAL;
        this->player = (Player *)data;

        if (this->player->classID == Player::sVars->classID) {
            if (!this->player->jumpAbilityStateHyper) {
                this->state.Set(&SuperSparkle::State_SuperSparkle);
            }
            else {
                this->visible = true;
                this->animator.SetAnimation(sVars->aniFrames, 1, true, 0);
                this->state.Set(&SuperSparkle::State_HyperSparkle);
            }
        }
    }
}

void SuperSparkle::StageLoad() { sVars->aniFrames.Load("3K_Global/SuperSparkle.bin", SCOPE_STAGE); }

#if RETRO_INCLUDE_EDITOR
void SuperSparkle::EditorDraw() {}

void SuperSparkle::EditorLoad() {}
#endif

void SuperSparkle::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(SuperSparkle); }

void SuperSparkle::Serialize() {}

void SuperSparkle::State_SuperSparkle()
{
    SET_CURRENT_STATE();

    if (this->player->onGround)
        this->canSpawnSparkle = abs(player->velocity.y) + abs(this->player->velocity.x) > TO_FIXED(6);

    if (this->canSpawnSparkle) {
        if (++this->timer == 14) {
            this->timer = 0;

            Debris *sparkle = CREATE_ENTITY(Debris, NULL, this->player->position.x, this->player->position.y);
            sparkle->state.Set(&Debris::State_Move);
            sparkle->timer = 16;

            if (globals->bossAttackRestartMilliseconds)
                sparkle->inkEffect = INK_ADD;

            sparkle->alpha     = 0x100;
            sparkle->drawGroup = Zone::sVars->objectDrawGroup[1]; // ???
            sparkle->drawGroup = this->player->drawGroup;
            sparkle->animator.SetAnimation(sVars->aniFrames, 0, true, 0);

            if (S3K_DDZSetup::sVars) {
                if (!(S3K_DDZSetup::sVars + 0xc)) { // currently unknown
                    sparkle->velocity.x = -TO_FIXED(6);
                }
                else {
                    sparkle->velocity.x += this->player->velocity.x;
                }
            }
        }
    }
    else {
        this->timer = 0;
    }
}

void SuperSparkle::State_HyperSparkle()
{
    SET_CURRENT_STATE();

    this->drawGroup = this->player->drawGroup;
    ++this->timer;

    if ((this->player->direction | FLIP_Y) == FLIP_Y)
        this->angle += 16;
    else
        this->angle -= 16;
}

} // namespace GameLogic