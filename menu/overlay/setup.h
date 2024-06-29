#pragma once

namespace overlay_window {
	WNDCLASSEX window_class;
	HWND hwnd;
	LPCSTR name;
	std::string app;
}

namespace direct_x9_interface
{
	IDirect3D9Ex* directd39 = NULL;
	IDirect3DDevice9Ex* p_device = NULL;
	D3DPRESENT_PARAMETERS p_params = { NULL };
	MARGINS margin = { -1 };
	MSG message = { NULL };
}

ImFont* verdana;
ImFont* visuals;
bool is_startup = true;
auto config_ = Config{ };

int last_tick = 0;

void click_though(bool click)
{
	if (click)
	{
		SetWindowLong(overlay_window::hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);
	}
	else
	{
		SetWindowLong(overlay_window::hwnd, GWL_EXSTYLE, WS_EX_LAYERED);
	}
}

void input_handler() {
	for (int i = 0; i < 5; i++) ImGui::GetIO().MouseDown[i] = false;
	int button = -1;
	if (GetAsyncKeyState(VK_LBUTTON)) button = 0;
	if (button != -1) ImGui::GetIO().MouseDown[button] = true;
}

void render_menu();

LRESULT CALLBACK window_procedure(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

bool init_directx() {
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &direct_x9_interface::directd39))) {
		return false;
	}

	D3DPRESENT_PARAMETERS Params = { 0 };
	Params.Windowed = TRUE;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.hDeviceWindow = overlay_window::hwnd;
	Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	Params.BackBufferWidth = vars.screen_width;
	Params.BackBufferHeight = vars.screen_height;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	Params.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	if (FAILED(direct_x9_interface::directd39->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, overlay_window::hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Params, 0, &direct_x9_interface::p_device))) {
		direct_x9_interface::directd39->Release();
		return false;
	}

	config_.Setup();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantTextInput || ImGui::GetIO().WantCaptureKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	auto& style = ImGui::GetStyle();
	style.WindowPadding = { 0, 0 };
	style.WindowBorderSize = 1;

	style.FramePadding = { 5, 2 };
	style.FrameBorderSize = 1;
	style.FrameRounding = 0;

	style.ScrollbarSize = 6;

	ImVec4* colors = style.Colors;
	colors[ImGuiCol_WindowBg] = ImColor(33, 31, 33); // done
	colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 0); // done

	colors[ImGuiCol_Text] = ImColor(140, 140, 140); // done
	colors[ImGuiCol_BorderShadow] = ImColor(70, 66, 68, 160); // done
	colors[ImGuiCol_Border] = ImColor(0, 0, 0, 255); // done

	colors[ImGuiCol_CheckMark] = ImColor(34, 34, 34); // done
	colors[ImGuiCol_PopupBg] = ImColor(33, 31, 33); // done

	colors[ImGuiCol_FrameBg] = ImColor(23, 23, 23); // done
	colors[ImGuiCol_FrameBgHovered] = ImColor(19, 19, 19); // done
	colors[ImGuiCol_FrameBgActive] = ImColor(23, 23, 23); // done

	colors[ImGuiCol_Button] = ImColor(33, 31, 33); // done
	colors[ImGuiCol_ButtonHovered] = ImColor(33, 31, 33); // done
	colors[ImGuiCol_ButtonActive] = ImColor(33, 31, 33); // done

	colors[ImGuiCol_Header] = ImColor(50, 50, 50); // done
	colors[ImGuiCol_HeaderHovered] = ImColor(70, 66, 68); // done
	colors[ImGuiCol_HeaderActive] = ImColor(33, 31, 33); // done

	colors[ImGuiCol_ScrollbarBg] = ImColor(0, 0, 0, 0); // done
	colors[ImGuiCol_ScrollbarGrab] = ImColor(23, 23, 23); // done
	colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(23, 23, 23); // done
	colors[ImGuiCol_ScrollbarGrabActive] = ImColor(23, 23, 23); // done

	colors[ImGuiCol_ModalWindowDimBg] = { 0.f, 0.f, 0.f, 0.1f };
	colors[ImGuiCol_NavWindowingDimBg] = { 0.f, 0.f, 0.f, 0.0f };
	colors[ImGuiCol_NavWindowingHighlight] = { 0.f, 0.f, 0.f, 0.0f };

	ImGui_ImplWin32_Init(overlay_window::hwnd);
	ImGui_ImplDX9_Init(direct_x9_interface::p_device);
	direct_x9_interface::directd39->Release();
	return true;
}

void setup_window() {
	overlay_window::window_class = {
		sizeof(WNDCLASSEX), 0, window_procedure, 0, 0, nullptr, LoadIcon(nullptr, IDI_APPLICATION), LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr, overlay_window::name, LoadIcon(nullptr, IDI_APPLICATION)
	};

	RegisterClassEx(&overlay_window::window_class);
	if (vars.game_hwnd) {
		static RECT TempRect = { NULL };
		static POINT TempPoint;
		GetClientRect(vars.game_hwnd, &TempRect);
		ClientToScreen(vars.game_hwnd, &TempPoint);
		TempRect.left = TempPoint.x;
		TempRect.top = TempPoint.y;
		vars.screen_width = TempRect.right;
		vars.screen_height = TempRect.bottom;
	}

	overlay_window::hwnd = CreateWindowEx(NULL, overlay_window::name, overlay_window::name, WS_POPUP | WS_VISIBLE, vars.screen_left, vars.screen_top, vars.screen_width, vars.screen_height, NULL, NULL, 0, NULL);
	click_though(true);

	DwmExtendFrameIntoClientArea(overlay_window::hwnd, &direct_x9_interface::margin);
	SetWindowLong(overlay_window::hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	ShowWindow(overlay_window::hwnd, SW_SHOW);
	UpdateWindow(overlay_window::hwnd);
}