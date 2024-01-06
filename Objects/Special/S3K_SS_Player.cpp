// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_SS_Player
// Object Author:
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{
RSDK_REGISTER_OBJECT(S3K_SS_Player);

void S3K_SS_Player::Update()
{
    S3K_SS_Setup *setup = RSDK_GET_ENTITY(SLOT_SPECIAL_SETUP, S3K_SS_Setup);

    this->stateInput.Run(this);

    if (this->onGround) {
        if (this->jumpPress) {
            this->velocity.y = -TO_FIXED(16);
            this->onGround   = false;
            this->animator.SetAnimation(this->aniFrames, 2, false, 0);
            sVars->sfxJump.Play(false, 255);
        }
    }
    else {
        this->gravityStrength += this->velocity.y;

        int32 speed = !setup->speedupLevel ? 16 : setup->speedupLevel;
        this->velocity.y += (speed << 12);
        if (this->gravityStrength >= 0) {
            this->gravityStrength = 0;
            this->onGround        = true;

            if (!this->sidekick) {
                if (this->animator.animationID == 3)
                    setup->globeSpeed >>= 1;

                setup->globeSpeedInc = 2;
            }

            if (setup->speedupLevel)
                this->animator.SetAnimation(this->aniFrames, 1, false, 0);
            else
                this->animator.SetAnimation(this->aniFrames, 0, false, 0);
        }
    }

    this->position.y = (this->gravityStrength >> 1) - (this->gravityStrength >> 4);
    this->position.y += sceneInfo->entitySlot ? TO_FIXED(186) : TO_FIXED(170);

    if (this->animator.animationID == 1) {
        this->animator.timer += abs(setup->globeSpeed);
        this->animator.speed = abs(setup->globeSpeed);

        if (this->animator.timer > 0x1F) {
            this->animator.timer &= 0x1F;

            if (setup->globeSpeed <= 0) {
                if (--this->animator.frameID < 0)
                    this->animator.frameID = 11;
            }
            else if (++this->animator.frameID > 11) {
                this->animator.frameID = 0;
            }
        }
    }
    else if (this->animator.animationID >= 2) {
        this->animator.speed = MAX(abs(setup->speedupLevel), 0x10);
        this->animator.Process();
    }

    this->tailAnimator.speed = abs(setup->speedupLevel) + 40;
    this->tailAnimator.Process();
}

void S3K_SS_Player::LateUpdate() {}
void S3K_SS_Player::StaticUpdate() {}

void S3K_SS_Player::Draw()
{
    Vector2 drawPos;
    drawPos.x = TO_FIXED(screenInfo->center.x);
    drawPos.y = this->position.y;
    this->animator.DrawSprite(&drawPos, true);

    if (GET_CHARACTER_ID(sceneInfo->entitySlot + 1))
        this->tailAnimator.DrawSprite(&drawPos, true);
}

void S3K_SS_Player::Create(void *data)
{
    if (!sceneInfo->inEditor) {
        this->active        = ACTIVE_NORMAL;
        this->visible       = true;
        this->drawGroup     = 4;
        this->updateRange.x = TO_FIXED(128);
        this->updateRange.y = TO_FIXED(128);

        switch (GET_CHARACTER_ID(sceneInfo->entitySlot + 1)) {
            default:
            case ID_SONIC: this->aniFrames = sVars->sonicFrames; break;

            case ID_TAILS:
                this->aniFrames = sVars->tailsFrames;
                this->tailAnimator.SetAnimation(this->aniFrames, 4, true, 0);
                break;

            case ID_KNUCKLES: this->aniFrames = sVars->knuxFrames; break;

#if MANIA_USE_PLUS
            case ID_AMY: this->aniFrames = sVars->amyFrames; break;
#endif
        }

        if (sceneInfo->entitySlot == 0) {
            this->stateInput.Set(&S3K_SS_Player::Input_Gamepad);
            this->controllerID = Input::CONT_P1;
            this->sidekick     = false;
        }
        else {
            this->stateInput.Set(&S3K_SS_Player::Input_Following);
            this->controllerID = Input::CONT_P2;
            this->sidekick     = true;
        }
    }
}

void S3K_SS_Player::StageLoad()
{
    sVars->sonicFrames.Load("3K_Special/Sonic.bin", SCOPE_STAGE);
    sVars->tailsFrames.Load("3K_Special/Tails.bin", SCOPE_STAGE);
    sVars->knuxFrames.Load("3K_Special/Knuckles.bin", SCOPE_STAGE);
    sVars->amyFrames.Load("3K_Special/Amy.bin", SCOPE_STAGE);

    if (globals->playerID == ID_NONE)
        globals->playerID = ID_DEFAULT_PLAYER;

    RSDKTable->ResetEntitySlot(SLOT_PLAYER1, sVars->classID, NULL); // yeah so like. we kinda need the first player?

    if (GET_CHARACTER_ID(2) != ID_NONE)
        RSDKTable->ResetEntitySlot(SLOT_PLAYER2, sVars->classID, NULL);

    sVars->sfxJump.Get("Global/Jump.wav");
}

#if RETRO_INCLUDE_EDITOR
void S3K_SS_Player::EditorDraw() {}

void S3K_SS_Player::EditorLoad() {}
#endif

void S3K_SS_Player::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(S3K_SS_Player); }

void S3K_SS_Player::Serialize() {}

void S3K_SS_Player::Input_Gamepad()
{
    SET_CURRENT_STATE();

    if (globals->useMobileBehavior)
        TouchHelpers::RunTouchInfoLogic(this->controllerID, (screenInfo->center.x - 0x54), NULL, (screenInfo->center.x + 0x54), 40, NULL, NULL);

    if (this->controllerID < PLAYER_COUNT) {
        ControllerState *controller = &controllerInfo[this->controllerID];
        AnalogState *stick          = &analogStickInfoL[this->controllerID];

        this->up    = controller->keyUp.down;
        this->down  = controller->keyDown.down;
        this->left  = controller->keyLeft.down;
        this->right = controller->keyRight.down;

        this->up |= stick->keyUp.down;
        this->down |= stick->keyDown.down;
        this->left |= stick->keyLeft.down;
        this->right |= stick->keyRight.down;

        this->up |= stick->vDelta > 0.3;
        this->down |= stick->vDelta < -0.3;
        this->left |= stick->hDelta < -0.3;
        this->right |= stick->hDelta > 0.3;

        if (this->left && this->right) {
            this->left  = false;
            this->right = false;
        }
        this->jumpPress = controller->keyA.press || controller->keyB.press || controller->keyC.press || controller->keyX.press;

        if (controller->keyStart.press || unknownInfo->pausePress) {
            if (sceneInfo->state == ENGINESTATE_REGULAR) {
                PauseMenu *pauseMenu = RSDK_GET_ENTITY(SLOT_PAUSEMENU, PauseMenu);
                if (!pauseMenu->classID) {
                    RSDKTable->ResetEntitySlot(SLOT_PAUSEMENU, PauseMenu::sVars->classID, NULL);
                    pauseMenu->triggerPlayer  = this->Slot();
                    pauseMenu->disableRestart = true;
                }
            }
        }
    }
}

void S3K_SS_Player::Input_Following()
{
    SET_CURRENT_STATE();

    S3K_SS_Player *player1 = RSDK_GET_ENTITY(SLOT_PLAYER1, S3K_SS_Player);
    S3K_SS_Player *player2 = RSDK_GET_ENTITY(SLOT_PLAYER2, S3K_SS_Player);

    sVars->jumpPressState <<= 1;
    sVars->jumpPressState |= player1->jumpPress;

    this->jumpPress = sVars->jumpPressState >> 5;

    Dev::PrintUInt32(Dev::PRINT_NORMAL, "delay", sVars->sphereBounceDelay);

    if (sVars->sphereBounceDelay && (--sVars->sphereBounceDelay, !sVars->sphereBounceDelay)) {
        player2->velocity.y = TO_FIXED(65512); // jesus christ tails, you really fly don't you
        player2->onGround   = false;
        player2->animator.SetAnimation(player2->aniFrames, 3, false, 0);

        sVars->sfxJump.Play(false, 255);
    }

    Dev::Print(Dev::PRINT_NORMAL, "");
}

} // namespace GameLogic