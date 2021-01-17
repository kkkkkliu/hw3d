#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <iostream>
#include <memory>
#include <random>


class Graphics {
	friend class Bindable;
public:
	Graphics(HWND hWnd );
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics() = default;
	void EndFrame();
	void ClearBuffer(float red, float green, float blue) noexcept;
	void DrawTestTriangle(float angle);
	void DrawIndexed(UINT count) noexcept;
	void SetProjection(DirectX::FXMMATRIX proj) noexcept;
	DirectX::XMMATRIX GetProjection() const noexcept;
private:
	Microsoft::WRL::ComPtr< ID3D11Device> pDevice;
	Microsoft::WRL::ComPtr< IDXGISwapChain> pSwap;
	Microsoft::WRL::ComPtr< ID3D11DeviceContext> pContext;
	Microsoft::WRL::ComPtr< ID3D11RenderTargetView> pTarget;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> pDSV;

	DirectX::XMMATRIX projection;
};