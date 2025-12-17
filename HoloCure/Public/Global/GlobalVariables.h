#pragma once

constexpr int32_t g_window_size_x = 1280;
constexpr int32_t g_window_size_y = 720;
extern HWND g_hWnd;

enum class RenderGroup : uint8_t
{
    BACKGROUND = 0,
    MONSTER,
    BOSS,
    PLAYER,
    COUNT
};
