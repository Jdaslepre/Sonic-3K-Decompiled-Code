// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: GS_WallBumper
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "GS_WallBumper.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(GS_WallBumper);

void GS_WallBumper::Update()
{
    foreach_active(Player, player)
    {
        if (Player::CheckCollisionTouch(player, this, &sVars->hitbox)) {
            if (this->position.x < player->position.x) {
                player->velocity.x = TO_FIXED(8);
                player->direction  = FLIP_NONE;
                player->animator.SetAnimation(player->aniFrames, Player::ANI_SPRING_CS, true, 0);
            }
            else {
                player->velocity.x = -TO_FIXED(8);
                player->direction  = FLIP_X;
                player->animator.SetAnimation(player->aniFrames, Player::ANI_SPRING_CS_REV, true, 0);
            }

            player->animationReserve = Player::ANI_SPRING_CS;
            sVars->sfxBumper.Play(false, 255);
            this->active   = ACTIVE_NORMAL;
            this->unknown1 = 10;
        }

        if (this->unknown1 > 0) {
            this->animator.Process();

            int32 var1     = this->unknown1;
            int32 var2     = var1 - 1;
            this->unknown1 = var1;

            if (!var2 || var1 < 1) {
                this->animator.SetAnimation(sVars->aniFrames, 0, true, 0);
                this->active = ACTIVE_BOUNDS;
            }
        }
    }
}

void GS_WallBumper::LateUpdate() {}

void GS_WallBumper::StaticUpdate() {}

void GS_WallBumper::Draw() { this->animator.DrawSprite(NULL, false); }

void GS_WallBumper::Create(void *data)
{
    this->visible       = true;
    this->drawGroup     = Zone::sVars->objectDrawGroup[1];
    this->active        = ACTIVE_BOUNDS;
    this->drawFX        = FX_FLIP;
    this->updateRange.x = 0x400000;
    this->updateRange.y = 0x400000;
    this->alpha         = 255;

    this->animator.SetAnimation(sVars->aniFrames, 0, true, 0);
}

void GS_WallBumper::StageLoad()
{
    sVars->aniFrames.Load("3K_BS_Spheres/WallBumper.bin", SCOPE_STAGE);
    sVars->hitbox.left   = -25;
    sVars->hitbox.top    = -64;
    sVars->hitbox.right  = 25;
    sVars->hitbox.bottom = 64;
    sVars->sfxBumper.Get("Stage/Bumper.wav");
}

#if RETRO_INCLUDE_EDITOR
void GS_WallBumper::EditorDraw() {}

void GS_WallBumper::EditorLoad() {}
#endif

void GS_WallBumper::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(GS_WallBumper); }

void GS_WallBumper::Serialize() { RSDK_EDITABLE_VAR(GS_WallBumper, VAR_INT8, direction); }

} // namespace GameLogic