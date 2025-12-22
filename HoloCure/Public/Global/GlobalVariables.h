#pragma once

constexpr int32_t g_window_size_x = 1280;
constexpr int32_t g_window_size_y = 720;

extern int32_t scroll_x;
extern int32_t scroll_y;

extern HWND g_hWnd;

enum class RenderGroup : uint8_t
{
    BACKGROUND = 0,
    MONSTER,
    BOSS,
    PLAYER,
    COUNT
};

enum class CharacterType : int32_t
{
    PLAYER         = 1 << 0,
    MONSTER        = 1 << 1,
    PLAYER_BULLET  = 1 << 2,
    MONSTER_BULLET = 1 << 3,
};
