#pragma once
#include <Windows.h>
#include <d3d9.h>

#include "include/imgui.h"
#include "include/imgui_impl_dx9.h"
#include "include/imgui_impl_win32.h"

struct DrawSettings
{
	bool draw = false;
	bool filter = true;
	bool drawIntro = false;
	bool drawAddress = false;
	bool drawFamily = false;
	bool drawHealth = false;

	bool drawDebug = false;
};

class Menu
{
public:
	Menu(LPDIRECT3DDEVICE9 pd3dDevice, HWND hwnd);

	void OnDeviceReleased();
	void OnPresent();
	void Process(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	void ToggleFlight(bool flight);
	void ProcessFlight(UINT msg, WPARAM wparam);
	void SetDevice(LPDIRECT3DDEVICE9 pd3dDevice);
	void Log(const char* fmt, ...);

	bool IsFocus() const noexcept;
	void SetFocus(bool value) noexcept;

	DrawSettings m_drawSettings;
private:
	void Draw();

	bool m_focus = false;
	bool m_flight = false;
	float m_flightSpeed = 50.f;

	bool m_visible = true;

	ImGuiTextBuffer logBuffer;

	LPDIRECT3DDEVICE9 m_pd3dDevice;
	HWND m_hwnd;
};

void DrawInstanceViewer();