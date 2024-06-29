#pragma once

void main_loop()
{
	static RECT OldRect;
	ZeroMemory(&direct_x9_interface::message, sizeof(MSG));

	while (direct_x9_interface::message.message != WM_QUIT) {
		if (PeekMessage(&direct_x9_interface::message, overlay_window::hwnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&direct_x9_interface::message);
			DispatchMessage(&direct_x9_interface::message);
		}
		HWND ForegroundWindow = GetForegroundWindow();
		if (ForegroundWindow == vars.game_hwnd) {
			HWND TempProcessHwnd = GetWindow(ForegroundWindow, GW_HWNDPREV);
			SetWindowPos(overlay_window::hwnd, TempProcessHwnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		RECT TempRect;
		POINT TempPoint;
		ZeroMemory(&TempRect, sizeof(RECT));
		ZeroMemory(&TempPoint, sizeof(POINT));

		GetClientRect(vars.game_hwnd, &TempRect);
		ClientToScreen(vars.game_hwnd, &TempPoint);

		TempRect.left = TempPoint.x;
		TempRect.top = TempPoint.y;
		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = vars.game_hwnd;

		POINT TempPoint2;
		GetCursorPos(&TempPoint2);
		io.MousePos.x = TempPoint2.x - TempPoint.x;
		io.MousePos.y = TempPoint2.y - TempPoint.y;

		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else {
			io.MouseDown[0] = false;
		}

		if (TempRect.left != OldRect.left || TempRect.right != OldRect.right || TempRect.top != OldRect.top || TempRect.bottom != OldRect.bottom) {
			OldRect = TempRect;
			vars.screen_width = TempRect.right;
			vars.screen_height = TempRect.bottom;
			direct_x9_interface::p_params.BackBufferWidth = vars.screen_width;
			direct_x9_interface::p_params.BackBufferHeight = vars.screen_height;
			SetWindowPos(overlay_window::hwnd, (HWND)0, TempPoint.x, TempPoint.y, vars.screen_width, vars.screen_height, SWP_NOREDRAW);
			direct_x9_interface::p_device->Reset(&direct_x9_interface::p_params);
		}
		render_menu();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	if (direct_x9_interface::p_device != NULL) {
		direct_x9_interface::p_device->EndScene();
		direct_x9_interface::p_device->Release();
	}
	if (direct_x9_interface::directd39 != NULL) {
		direct_x9_interface::directd39->Release();
	}

	DestroyWindow(overlay_window::hwnd);
	UnregisterClass(overlay_window::window_class.lpszClassName, overlay_window::window_class.hInstance);
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK window_procedure(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message) {
	case WM_DESTROY:
		if (direct_x9_interface::p_device != NULL) {
			direct_x9_interface::p_device->EndScene();
			direct_x9_interface::p_device->Release();
		}
		if (direct_x9_interface::directd39 != NULL) {
			direct_x9_interface::directd39->Release();
		}
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (direct_x9_interface::p_device != NULL && wParam != SIZE_MINIMIZED) {
			ImGui_ImplDX9_InvalidateDeviceObjects();
			direct_x9_interface::p_params.BackBufferWidth = LOWORD(lParam);
			direct_x9_interface::p_params.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = direct_x9_interface::p_device->Reset(&direct_x9_interface::p_params);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}