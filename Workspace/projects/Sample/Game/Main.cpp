#include <Pazu/Engine.h>
#include <Pazu/Window.h>
#include <Pazu/Event/EventManager.h>
#include <Pazu/Event/SystemEvent.h>
#include <Pazu/Event/KeyboardEvent.h>
#include <Pazu/Graphics/Device.h>
#include <Pazu/Graphics/Context.h>
#include <Pazu/Asset/AssetManager.h>
#include <Pazu/Asset/ShaderAsset.h>
#include <Pazu/Math/Matrix.h>
#include <Pazu/Display.h>
#include <Pazu/Time.h>
#include <Pazu/System/SystemManager.h>
#include <Pazu/System/CameraSystem.h>
#include <Pazu/System/RendererSystem.h>
#include <Pazu/Entity.h>
#include <Pazu/Asset/StaticModelAsset.h>
#include <Pazu/Asset/AnimatedModelAsset.h>
#include <Pazu/Component/Model/StaticModelComponent.h>
#include <Pazu/Component/Model/AnimatedModelComponent.h>
#include <Pazu/Component/Model/Surface/Material.h>
#include <Pazu/Component/Camera/Camera3DComponent.h>
#include <Pazu/Component/Camera/Camera2DComponent.h>
#include <Pazu/Math/Mathf.h>
#include <Pazu/File.h>
#include "MyWindowEvent.h"
#include "MyMouseEvent.h"
using namespace Pazu;

int main(int argc, char *argv[])
{
	std::locale::global(std::locale("tr_TR"));
	Engine::Init(Graphics::Api::Direct3D11);
	const auto window = std::make_shared<Window>("Window Title", Window::DefaultPosition, Size(800, 600), WindowFlag::Resizable);
	const auto graphicsDevice = std::make_shared<Graphics::Device>();
	const auto graphicsContext = std::make_shared<Graphics::Context>(graphicsDevice, window);
	graphicsContext->SetClearColor(Color::Black);

	const auto systemManager = std::make_shared<SystemManager>();
	const auto eventManager = std::make_shared<EventManager>();

	const auto systemEvent = std::make_shared<SystemEvent>();
	const auto windowEvent = std::make_shared<MyWindowEvent>(graphicsContext, systemManager);
	const auto keyboardEvent = std::make_shared<KeyboardEvent>();
	const auto mouseEvent = std::make_shared<MyMouseEvent>();
	eventManager->Add(systemEvent);
	eventManager->Add(windowEvent);
	eventManager->Add(keyboardEvent);
	eventManager->Add(mouseEvent);

	systemManager->Add<CameraSystem>();
	systemManager->Add<RendererSystem>(systemManager->Get<CameraSystem>(), graphicsDevice, graphicsContext);

	AssetManager assetManager(graphicsDevice);

	const auto animatedDude = std::make_shared<Entity>();
	animatedDude->Add<AnimatedModelComponent>(assetManager.Load<AnimatedModelAsset>("Models/Characters/DudeSkinned.fbx"));
	auto &animatedDudeTransform = animatedDude->GetTransform();
	const auto animatedDudeModel = animatedDude->Get<AnimatedModelComponent>();
	animatedDudeTransform.SetPosition(0.f, 0.f, 7.f);
	animatedDudeTransform.SetRotation(-90.f, 0.f, 0.f);
	const auto animatedDudeBodyBone = animatedDudeModel->GetSkeleton().FindBone("Body");
	const auto animatedDudeRightLegBone = animatedDudeModel->GetSkeleton().FindBone("RightForeArm");
	const auto animatedDudeLeftLegBone = animatedDudeModel->GetSkeleton().FindBone("LeftArm");

	const auto dude = std::make_shared<Entity>();
	dude->Add<StaticModelComponent>(assetManager.Load<StaticModelAsset>("Models/Characters/Dude.fbx"));
	auto &dudeTransform = dude->GetTransform();

	const auto dude2 = std::make_shared<Entity>(*dude);
	auto &dude2Transform = dude2->GetTransform();
	dude2Transform.SetX(3.f);
	dude2Transform.SetParent(dudeTransform);

	Bone v;
	std::vector<Bone> bones;
	// Skeleton dd(bones);

	constexpr auto sd = std::ranges::contiguous_range<const std::list<Bone> &>;

	const auto rock = std::make_shared<Entity>();
	rock->Add<StaticModelComponent>(assetManager.Load<StaticModelAsset>("Models/Environment/FlyingRock.fbx"));
	auto &rockTransform = rock->GetTransform();
	auto rockModel = rock->Get<StaticModelComponent>();
	rockTransform.SetX(-3.f);
	rockTransform.SetY(2.f);
	rockTransform.SetPitch(-90.f);
	rockTransform.SetYaw(180.f);
	rockTransform.SetParent(dude2Transform);

	const auto rock2 = std::make_shared<Entity>();
	rock2->Add<StaticModelComponent>(assetManager.Load<StaticModelAsset>("Models/Environment/FlyingRock.fbx"));
	auto &rock2Transform = rock2->GetTransform();
	rock2Transform.SetScale(0.5f);
	rock2Transform.SetPitch(45.f);
	rock2Transform.SetX(-5.f);
	rock2Transform.SetY(2.75f);
	rock2Transform.SetParent(rockTransform);

	const auto camera = std::make_shared<Entity>();
	auto &cameraTransform = camera->GetTransform();
	cameraTransform.SetPosition(0.f, 0.f, 12.f);
	cameraTransform.SetRotation(Vector3::Forward);
	camera->Add<Camera3DComponent>();
	mouseEvent->SetCamera(camera);

	systemManager->Register<RendererSystem>(animatedDude);
	systemManager->Register<RendererSystem>(dude);
	systemManager->Register<RendererSystem>(dude2);
	systemManager->Register<RendererSystem>(rock);
	systemManager->Register<RendererSystem>(rock2);
	systemManager->Register<CameraSystem>(camera);

	const auto stream = File::Get().Open("Log.txt");
	if (stream)
	{
		stream->Write("Merhaba notepad.");
		stream->Write(" Merhaba notepad.");
		Log::Get().Print<LogMode::Info>(stream->ReadLine());
	}

	Log::Get().Print<LogMode::Info>(std::to_string(Mathf::Max({1.f, 2.f, 3.f, 4.f, 5.f})));

	float turnVal = 0.f;
	float elapsedTime = 0.f;
	bool globalSpace = false;
	Time time;
	while (!systemEvent->ShouldQuit())
	{
		time.Update();
		eventManager->Update();
		systemManager->Update();
		elapsedTime += time.GetDelta();
		turnVal = Mathf::PingPong(Mathf::ToDegrees(elapsedTime), 140.f) - 70.f;

		if (time.CalculateFps())
			Log::Get().Print<LogMode::None>("Fps: " + std::to_string(time.GetFps()));

		const auto turnSpeed = 60.15f * time.GetDelta();
		dude2Transform.Rotate(0.f, turnSpeed, 0.f);

		if (keyboardEvent->GetKeyDown(Key::Escape))
			break;
		else if (keyboardEvent->GetKeyHit(Key::F))
			window->SetFullscreen(!window->GetFullscreen());
		else if (keyboardEvent->GetKeyHit(Key::Num1))
			window->SetSize({800, 600});
		else if (keyboardEvent->GetKeyHit(Key::Num2))
			window->SetSize({1920, 1080});
		else if (keyboardEvent->GetKeyHit(Key::K))
		{
			for (const auto &mode : Display::Get().GetModes())
			{
				Log::Get().Print<LogMode::Info>("WindowDisplayMode Index: " + std::to_string(mode.index));
				Log::Get().Print<LogMode::Info>("WindowDisplayMode Name: " + mode.name);
			}
		}
		else if (keyboardEvent->GetKeyHit(Key::L))
		{
			const auto &mode = Display::Get().GetWindowMode(*window);
			Log::Get().Print<LogMode::Info>("WindowDisplayMode Index: " + std::to_string(mode.index));
			Log::Get().Print<LogMode::Info>("WindowDisplayMode Name: " + mode.name);
			for (const auto &videoMode : mode.videoModes)
			{
				Log::Get().Print<LogMode::Info>("WindowDisplayMode VideoSize: " + videoMode.size.ToString());
				for (const auto &refreshRate : videoMode.refreshRates)
					Log::Get().Print<LogMode::Info>("WindowDisplayMode VideoRefreshRate: " + std::to_string(refreshRate));
			}
		}
		else if (keyboardEvent->GetKeyHit(Key::R))
			systemManager->Unregister<CameraSystem>(camera);
		else if (keyboardEvent->GetKeyHit(Key::T))
			systemManager->Register<CameraSystem>(camera);
		else if (keyboardEvent->GetKeyHit(Key::G))
			graphicsContext->SetWireframe(!graphicsContext->GetWireframe());
		else if (keyboardEvent->GetKeyHit(Key::H))
			graphicsContext->SetCullFace(!graphicsContext->GetCullFace());
		else if (keyboardEvent->GetKeyHit(Key::V))
			graphicsContext->SetVsync(!graphicsContext->GetVsync());
		else if (stream && keyboardEvent->GetKeyHit(Key::C))
			stream->WriteLine("Merhaba notepad.");
		else if (stream && keyboardEvent->GetKeyHit(Key::X))
			Log::Get().Print<LogMode::Info>(stream->ReadLine());
		else if (stream && keyboardEvent->GetKeyHit(Key::B))
			Log::Get().Print<LogMode::Info>(stream->Read());
		else if (keyboardEvent->GetKeyHit(Key::Num3))
			globalSpace = !globalSpace;
		// if (animatedDudeBodyBone)
		// 	animatedDudeBodyBone->transform.SetYaw(turnVal);
		// if (animatedDudeRightLegBone && animatedDudeLeftLegBone)
		// {
		// animatedDudeLeftLegBone->transform.SetRoll(turnVal + 100.f, true);
		// animatedDudeRightLegBone->transform.SetYaw(-turnVal + 70.f, true);
		// }

		if (keyboardEvent->GetKeyDown(Key::Num4))
			rockModel->GetSurfaces().front()->GetMaterial()->SetDiffuseColor(rockModel->GetSurfaces().front()->GetMaterial()->GetDiffuseColor() - Color(0.f, 0.f, 0.f, time.GetDelta()));
		else if (keyboardEvent->GetKeyDown(Key::Num5))
			rockModel->GetSurfaces().front()->GetMaterial()->SetDiffuseColor(rockModel->GetSurfaces().front()->GetMaterial()->GetDiffuseColor() + Color(0.f, 0.f, 0.f, time.GetDelta()));

		if (mouseEvent->GetButtonHit(Button::Left))
			mouseEvent->SetRelativeMode(!mouseEvent->GetRelativeMode());

		const auto moveSpeed = 5.f * time.GetDelta();
		if (keyboardEvent->GetKeyDown(Key::W))
			cameraTransform.Translate(Vector3::Forward * moveSpeed, globalSpace);
		if (keyboardEvent->GetKeyDown(Key::S))
			cameraTransform.Translate(Vector3::Backward * moveSpeed, globalSpace);
		if (keyboardEvent->GetKeyDown(Key::D))
			cameraTransform.Translate(Vector3::Right * moveSpeed, globalSpace);
		if (keyboardEvent->GetKeyDown(Key::A))
			cameraTransform.Translate(Vector3::Left * moveSpeed, globalSpace);
		if (keyboardEvent->GetKeyDown(Key::Space))
			cameraTransform.Translate(Vector3::Up * moveSpeed, globalSpace);
		if (keyboardEvent->GetKeyDown(Key::LeftControl))
			cameraTransform.Translate(Vector3::Down * moveSpeed, globalSpace);

		if (keyboardEvent->GetKeyDown(Key::E))
			cameraTransform.Rotate(Vector3::Forward, 15.f * moveSpeed, globalSpace);
		if (keyboardEvent->GetKeyDown(Key::Q))
			cameraTransform.Rotate(-Vector3::Forward, 15.f * moveSpeed, globalSpace);

		if (keyboardEvent->GetKeyDown(Key::Up) && keyboardEvent->GetKeyDown(Key::LeftShift))
			dudeTransform.Rotate(Vector3::Up * 15.f * moveSpeed, globalSpace);
		else if (keyboardEvent->GetKeyDown(Key::Up))
			dudeTransform.Translate(Vector3::Forward * moveSpeed, globalSpace);

		if (keyboardEvent->GetKeyDown(Key::Down) && keyboardEvent->GetKeyDown(Key::LeftShift))
			dudeTransform.Rotate(Vector3::Backward * 15.f * moveSpeed, globalSpace);
		else if (keyboardEvent->GetKeyDown(Key::Down))
			dudeTransform.Translate(Vector3::Backward * moveSpeed, globalSpace);

		if (keyboardEvent->GetKeyDown(Key::Right) && keyboardEvent->GetKeyDown(Key::LeftShift))
			dudeTransform.Rotate(Vector3::Right * 15.f * moveSpeed, globalSpace);
		else if (keyboardEvent->GetKeyDown(Key::Right))
			dudeTransform.Translate(Vector3::Right * moveSpeed, globalSpace);

		if (keyboardEvent->GetKeyDown(Key::Left) && keyboardEvent->GetKeyDown(Key::LeftShift))
			dudeTransform.Rotate(Vector3::Left * 15.f * moveSpeed, globalSpace);
		else if (keyboardEvent->GetKeyDown(Key::Left))
			dudeTransform.Translate(Vector3::Left * moveSpeed, globalSpace);

		// dude2Transform->SetPosition(cameraTransform->GetX(), cameraTransform->GetY() - 2.f, cameraTransform->GetZ() - 5.f);

		// if (keyboardEvent->GetKeyDown(Key::Tab))
		// {
		// Log::Get().Print<LogMode::None>("Turn Value: " + std::to_string(turnVal));
		// dude2Transform.SetX(dudeTransform.GetX());
		// Log::Get().Print<LogMode::None>("X: " + std::to_string(dudeTransform.GetX()) + " Y: " + std::to_string(dudeTransform.GetY()) + " Z: " + std::to_string(dudeTransform.GetZ()));

		// cameraTransform.CalculateWorld();
		// Vector3 camAngles = cameraTransform.GetMatrix().Euler();
		// Log::Get().Print<LogMode::None>("Pitch: " + std::to_string(camAngles.x) + " Yaw: " + std::to_string(camAngles.y) + " Roll: " + std::to_string(camAngles.z));

		// TransformRotation tempCamTransform;
		// tempCamTransform.SetQuaternion(cameraTransform.GetQuaternion());
		// Log::Get().Print<LogMode::None>("Pitch: " + std::to_string(tempCamTransform.GetPitch()) + " Yaw: " + std::to_string(tempCamTransform.GetYaw()) + " Roll: " + std::to_string(tempCamTransform.GetRoll()));
		// Log::Get().Print<LogMode::None>("Pitch: " + std::to_string(cameraTransform.GetPitch()) + " Yaw: " + std::to_string(cameraTransform.GetYaw()) + " Roll: " + std::to_string(cameraTransform.GetRoll()));
		// Log::Get().Print<LogMode::None>("Alpha Value: " + std::to_string(rockModel->GetSurfaces().front()->GetMaterial()->GetDiffuseColor().w));
		// }

		graphicsContext->Clear();
		systemManager->Draw();
		graphicsContext->Present();
	}
	window->SetFullscreen(false);
	return 0;
}
