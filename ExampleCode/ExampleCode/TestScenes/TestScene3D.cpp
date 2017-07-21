#include "TestScene3D.h"
#include "Graphics/Material/MaterialCollection.h"
#include "Geometry/TriangleMesh/Plane.h"
#include "Mathematics/Math.h"
#include "GUI/GUIHandler.h"
#include "ExceptionHandling/BAMELog.h"
#include "ObjectLoader/ObjectLoader.h"
#include "ObjectLoader/ThreadedObjectLoader.h"
#include "ObjectLoader/Assimp/AssimpObjectLoader.h"

namespace BAME
{
	TestSceneBenko::TestSceneBenko(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer) : ITestScene(sceneManager, inputManager, audioPlayer),
	mSoundListener(nullptr),
	mShootSound(nullptr),
	mShootSource(nullptr),
	mScene(nullptr)
	{
	}

	TestSceneBenko::~TestSceneBenko()
	{
	}

	void TestSceneBenko::AddSkyBox()
	{
		mSkyBox = Skybox(100);
		mScene->SetSkybox(&mSkyBox, "Resources/skyboxUniverse.dds");
	}

	void TestSceneBenko::InitAudio()
	{
		InitAudioPlayer();
		AddBackGroundMusic();
	}

	void TestSceneBenko::Init()
	{
		InitSceneDefaultWithCamera();

		AddSolarSystem();
		AddDirectLight();
		AddSpotLight();
		AddGroundPlane();
		AddGUICross();
		AddLights();
		AddGlossyCube();
		AddObjectsFromObjFile();
		AddSkyBox();
		AddParticleSystem();

		InitAudio();
		

		mSceneManager.SetActiveScene("MainScene");
	}

	void TestSceneBenko::UpdateAudio()
	{
		UpdateListener();
	}

	void TestSceneBenko::UpdateBoneMesh(float frameTime)
	{
		mPeggy.UpdateBones(frameTime);
	}

	void TestSceneBenko::Update(double frameTime)
	{
		ProcessInput(frameTime);

		UpdatePointLight(static_cast<float>(frameTime));
		UpdateSpotLight(static_cast<float>(frameTime));
		UpdateLights(static_cast<float>(frameTime));
		UpdateSolarSystem(static_cast<float>(frameTime));
		UpdateGroundPlane(static_cast<float>(frameTime));
		UpdateCube(static_cast<float>(frameTime));
		UpdateBoneMesh(static_cast<float>(frameTime));
		UpdateAudio();	
	}

	void TestSceneBenko::Render()
	{
	}

	void TestSceneBenko::Dispose()
	{
	}

	void TestSceneBenko::AddBackGroundMusic()
	{
		mShootSound = mAudioPlayer.CreateSound("Resources/Sounds/Lee_Rosevere_-_10_-_4th_Ave_Walkup.wav");
		mShootSource = mAudioPlayer.CreateSoundSource(mShootSound, 1, 1, Vector3f(0, 0, 0), Vector3f(0, 0, 0), true);
		mAudioPlayer.Add(mShootSource);
		mAudioPlayer.Play(mShootSource);
	}

	void TestSceneBenko::InitAudioPlayer()
	{
		mSoundListener = mAudioPlayer.CreateSoundListener();
		mAudioPlayer.SetListener(mSoundListener);
	}

	void TestSceneBenko::UpdateListener() const
	{
		mAudioPlayer.SetListenerPosition(mCamera.GetPosition());
		mAudioPlayer.SetListenerOrientation(mCamera.GetForward(), mCamera.GetUpDirection());
	}

	void TestSceneBenko::AddObjectsFromObjFile()
	{
		waveObjMat = MaterialCollection::GetMaterial(MaterialCollection::MaterialType::Obsidian);
		waveObjMat.SetEnvironmentMap("Resources/skyboxUniverse.dds");
		waveObjMat.SetDiffuseMap("Resources/transparentRed.png");


		ThreadedObjectLoader::AddToLoadList(std::string("Resources/Porsche_911_GT2.obj"), waveobj);
		ThreadedObjectLoader::AddToLoadList(std::string("Resources/Suzanne.obj"), waveobj2);
		ThreadedObjectLoader::AddToLoadList(std::string("Resources/testFlower.obj"), waveobj3);
		ThreadedObjectLoader::LoadAllObjects();

		for (auto& obj : waveobj)
		{
			obj.SetMaterial(&waveObjMat);

			placeWaveObj.AddGeo(&obj);
		}

		placeAnkerWaveObj.AddPlacement(&placeWaveObj);
		placeWaveObj.Scale(Vector3f(3, 3, 3));
		placeAnkerWaveObj.Translate(Vector3f(-100, 2.5, 50));

		for (auto& obj : waveobj2)
		{
			obj.SetMaterial(&waveObjMat);

			placeWaveObj2.AddGeo(&obj);
		}
		placeAnkerWaveObj2.AddPlacement(&placeWaveObj2);
		placeWaveObj2.Scale(Vector3f(3, 3, 3));
		placeAnkerWaveObj2.Translate(Vector3f(-100, 2.5, 70));


		for (auto& obj : waveobj3)
		{
			obj.SetMaterial(&waveObjMat);

			placeWaveObj3.AddGeo(&obj);
		}
		placeAnkerWaveObj3.AddPlacement(&placeWaveObj3);
		placeWaveObj3.Scale(Vector3f(3, 3, 3));
		placeAnkerWaveObj3.Translate(Vector3f(-100, 2.5, 90));

		AssimpObjectLoader::GetInstance()->LoadBoneMesh("Resources/RiggedMeshes/Peggy.fbx", mPeggy);
		mPeggy.SetMaterial(&waveObjMat);
		mPlaceStickFigure.AddGeo(&mPeggy);

		mPlaceStickFigure.Scale(Vector3f(0.1, 0.1, 0.05));
		mPlaceStickFigure.Rotate(90, Vector3f(0,1,0));
		mPlaceStickFigure.Translate(Vector3f(-40, 0, 0));


		mScene->Add(&placeAnkerWaveObj);
		mScene->Add(&placeAnkerWaveObj2);
		mScene->Add(&placeAnkerWaveObj3);
		mScene->Add(&mPlaceStickFigure);

	}

	void TestSceneBenko::ProcessInput(float frameTime)
	{
		if (mInputManager.GetKeyDown(Key::V))
		{
			mCamera.Shake(0.3);
		}

		static float stepTime = 0.f;

		stepTime += static_cast<float>(frameTime);;


		if (mInputManager.GetKey(Key::O))
		{
			float strength = mParticleSystem.GetStrength();
			mParticleSystem.SetStrength(strength + frameTime * 10);
		}
		if (mInputManager.GetKey(Key::I))
		{
			float strength = mParticleSystem.GetStrength();
			mParticleSystem.SetStrength(strength - frameTime);
		}

		static bool staticMechanics = false;
		if (mInputManager.GetKeyDown(Key::C))
		{
			staticMechanics = !staticMechanics;

			if(staticMechanics)
			{
				mParticleSystem.SetMechanics(Mechanics::Static);
			}
			else
				mParticleSystem.SetMechanics(Mechanics::Dynamic);

		}

		
		static bool pcfEnabled = true;
		if (mInputManager.GetKeyDown(Key::L))
		{
			pcfEnabled = !pcfEnabled;
			mSunMaterial.SetShadowPCF(pcfEnabled);
		}

		if (mInputManager.GetKeyDown(Key::NUM_1))
		{
			mSunMaterial.SetPCFKernelFactor(ShadowProperties::PCF_Kernel::PCF_4x4);
		}

		if (mInputManager.GetKeyDown(Key::NUM_2))
		{
			mSunMaterial.SetPCFKernelFactor(ShadowProperties::PCF_Kernel::PCF_8x8);
		}

		if (mInputManager.GetKeyDown(Key::NUM_3))
		{
			mSunMaterial.SetPCFKernelFactor(ShadowProperties::PCF_Kernel::PCF_16x16);
		}
	}

	void TestSceneBenko::UpdateParticleSystem(float frameTime)
	{
		mParticleSystem.Update(frameTime);
	}

	void TestSceneBenko::InitSceneDefaultWithCamera()
	{
		mScene = mSceneManager.CreateScene("MainScene");
		mCamera.Init(&mInputManager, 1280, 720, float(Math::ToRadians(60)), Vector3f(0, 3, 0), Vector3f(0.f, 0.f, -1.f), Vector3f(0, 1, 0), 0.001f, 100.0f);
		mCamera.SetRotationSensitivity(0.5f);
		mCamera.SetTranslationSensitivity(0.5f);
		mSceneManager.SetActiveCamera(&mCamera);
		mInputManager.SetMouseSensitivity(0.001f);

		mScene->SetShadowRendering(true);
	}

	void TestSceneBenko::AddParticleSystem()
	{
		mParticleSystem.Init(1000, 2,2, Vector3f::Zero(),Vector3f(0,-9.81,0));

		mParticleSystem.SetTexture("Resources/Ball.png");

		mScene->AddParticleSystem(&mParticleSystem);
	}

	

	void TestSceneBenko::AddGroundPlane()
	{
		mWaterPlane = Plane(300, 300, 50, 50);
		mWaterPlaneMaterial = MaterialCollection::GetMaterial(MaterialCollection::MaterialType::Obsidian);
		mWaterPlaneMaterial.SetShaderType(PresetShaderType::LightningShader);
		mWaterPlaneMaterial.SetGlossiness(10.f);


		mWaterPlaneMaterial.SetDiffuseMap("Resources/cobblestone/diffuse.png");
		mWaterPlaneMaterial.SetSpecularMap("Resources/cobblestone/specular.png");
		mWaterPlaneMaterial.SetBumpMap("Resources/cobblestone/normal.png");
		mWaterPlaneMaterial.SetDisplacementMap("Resources/cobblestone/height.png");
		mWaterPlaneMaterial.SetParallaxOcclusion(true);

		mWaterPlane.SetMaterial(&mWaterPlaneMaterial);
		mWaterPlanePlacement.AddGeo(&mWaterPlane);
		mScene->Add(&mWaterPlanePlacement);
	}

	void TestSceneBenko::UpdateGroundPlane(float frameTime)
	{
		static bool togglePOM = false;
		if (mInputManager.GetKeyDown(Key::P))
		{
			togglePOM = !togglePOM;
			mWaterPlaneMaterial.SetParallaxOcclusion(togglePOM);
		}
	}

	void TestSceneBenko::AddGUICross()
	{
		mCross.Init(0.025f, 0.025f * 1.77f, "Resources/crosshair.png", "Resources/crosshair.png");
		mCross.SetPosition(Vector3f(0.4875f, 0.477875f, 1.f));
		GUIHandler::Get().Add(&mCross);
	}

	void TestSceneBenko::AddDirectLight()
	{
		directLight.Init(Vector3f(0.5, -0.5, 0).Normalized());
		directLight.SetColor(ColorRGB(.6, .6, .6f));
		mScene->Add(&directLight);
	}

	void TestSceneBenko::AddPointLight()
	{
		mPointLight.Init(2, Vector3f(0.f, 3.f, 0.f), 5, 10);
		mPointLight.SetColor(ColorRGB(1, 0.8, 0));
		mScene->Add(&mPointLight);
	}

	void TestSceneBenko::UpdatePointLight(float frameTime)
	{
		Vector3f MiddlePointPoint(0.f, -20.f, 0.f);
		float RadiusPoint = 10.f;
		static float AnglePoint = 0.f;
		static Vector3f positionPoint(0.f, 6.f, 0.f);
		AnglePoint += frameTime;
		positionPoint.SetX(MiddlePointPoint.GetX() + RadiusPoint * cos(AnglePoint));
		positionPoint.SetZ(MiddlePointPoint.GetZ() + RadiusPoint * sin(AnglePoint));
		mPointLight.SetPosition(positionPoint);
	}

	void TestSceneBenko::AddSpotLight()
	{
		mSpotLight.Init(Vector3f(0, -1, 0), Vector3f(10, 5, 0), Math::ToRadians(40), Math::ToRadians(60), 1);
		mSpotLight.SetColor(ColorRGB(1, 1, 1));

		mScene->Add(&mSpotLight);
	}

	void TestSceneBenko::UpdateSpotLight(float frameTime)
	{
		static float frameTimeTotal = 0;

		frameTimeTotal += frameTime;

		mSpotLight.SetPosition(Vector3f(-40, 5 + sin(frameTimeTotal) * 3, 0));
	}

	void TestSceneBenko::AddSolarSystem()
	{
		mSunMaterial = MaterialCollection::GetMaterial(MaterialCollection::MaterialType::Gold);
		mSunMaterial.SetShaderType(PresetShaderType::LightningShader);
		mSunMaterial.SetGlossiness(1000.f);

		mSunMaterial.SetDiffuseMap("Resources/cobblestone/diffuse.png",true);
		mSunMaterial.SetSpecularMap("Resources/cobblestone/specular.png");
		mSunMaterial.SetBumpMap("Resources/cobblestone/normal.png");
		mSunMaterial.SetDisplacementMap("Resources/cobblestone/height.png");

		mSun.SetMaterial(&mSunMaterial);
		mSunPlacement.AddGeo(&mSun);

		mEarthMaterial.SetShaderType(PresetShaderType::LightningShader);
		mEarthMaterial.SetAmbient(0.f, 0.f, 0.06f);
		mEarthMaterial.SetGlossiness(1.f);
		mEarthMaterial.SetSpecular(1.f, 1.f, 1.f);
		mEarthMaterial.SetDiffuseMap("Resources/earthTexture.png");
		mEarthMaterial.SetEnvironmentMap("Resources/skyboxUniverse.dds", true);

		mEarth = Sphere(1, 50, 50);
		mEarth.SetMaterial(&mEarthMaterial);
		mEarthPlacement.AddGeo(&mEarth);

		mMoonMaterial = MaterialCollection::GetMaterial(MaterialCollection::MaterialType::Silver);
		mMoonMaterial.SetShaderType(PresetShaderType::LightningShader);
		mMoonMaterial.SetGlossiness(1000.f);
		mMoonMaterial.SetBumpMap("Resources/waterBumpMap.png");
		mMoon.SetMaterial(&mMoonMaterial);
		mMoonPlacement.AddGeo(&mMoon);

		mSolarSystemPlacement.Translate(Vector3f(20, 3, 20));
		mEarthOrbitPlacement.Translate(Vector3f(15, 0, 0));
		mMoonOrbitPlacement.Translate(Vector3f(2, 0, 0));
		mMoonPlacement.Scale(Vector3f(0.5, 0.5, 0.5));
		mSunPlacement.Scale(Vector3f(3, 3, 3));
		mSolarSystemPlacement.AddPlacement(&mSunPlacement);
		mSolarSystemPlacement.AddPlacement(&mEarthOrbitPlacement);
		mEarthOrbitPlacement.AddPlacement(&mEarthPlacement);
		mEarthOrbitPlacement.AddPlacement(&mMoonOrbitPlacement);
		mMoonOrbitPlacement.AddPlacement(&mMoonPlacement);
		mScene->Add(&mSolarSystemPlacement);
	}

	void TestSceneBenko::UpdateSolarSystem(float frameTime)
	{
		mSunPlacement.Rotate(frameTime * 5, Vector3f(-0.3, 0.3, 0.3));
		mEarthOrbitPlacement.Rotate(frameTime * 10, Vector3f(0, 1, 0));
		mEarthPlacement.Rotate(frameTime * 100, Vector3f(0.3, 0.7, 0));
		mMoonOrbitPlacement.Rotate(frameTime * 60, Vector3f(0, 1, 0));
		mMoonPlacement.Rotate(frameTime * 100, Vector3f(0.5, 0.5, 0));
	}

	void TestSceneBenko::AddGlossyCube()
	{
		mCube = Cube(6);
		mPlaceCube.AddGeo(&mCube);
		mPlaceCubeAnker.Translate(Vector3f(20, 6, -20));

		mPlaceCubeAnker.AddPlacement(&mPlaceCube);

		mMatCube = MaterialCollection::GetMaterial(MaterialCollection::MaterialType::Silver);
		mMatCube.SetShaderType(PresetShaderType::LightningShader);
		mMatCube.SetEnvironmentMap("Resources/skyboxUniverse.dds");

		mMatCube.SetDiffuseMap("Resources/ancient.jpg");
		mMatCube.SetBumpMap("Resources/ancientNormal.jpg");
		mMatCube.SetDisplacementMap("Resources/ancientHeight.jpg");

		mCube.SetMaterial(&mMatCube);

		mScene->Add(&mPlaceCubeAnker);
	}

	void TestSceneBenko::UpdateCube(float frameTime)
	{
		mPlaceCube.Rotate(20 * frameTime, Vector3f(0.5, 0, 0.5));
	}

	void TestSceneBenko::AddLights()
	{
		int pointLightCount = 100;
		mPointLightList.resize(pointLightCount);
		mPointLightPropertyList.resize(pointLightCount);

		for (int i = 0; i < mPointLightList.size(); i++)
		{
			float xPos = Math::getRandNumberF(-40, 40);
			float zPos = Math::getRandNumberF(-40, 40);
			mPointLightList[i].Init(Math::getRandNumberF(2, 10), Vector3f(0, 0, 0), 2, Math::getRandNumberF(4, 15));
			
			mPointLightList[i].SetColor(ColorRGB(Math::getRandNumberF(0, 1), Math::getRandNumberF(0, 1), Math::getRandNumberF(0, 1)));

			mPointLightPropertyList[i].Init(Vector3f(xPos, 3.f, zPos), 10, Math::getRandNumberF(0, 359), Math::getRandNumberF(0.1, 3), Math::getRandNumber(0, 1));

			mScene->Add(&mPointLightList[i]);
		}
	}

	void TestSceneBenko::UpdateLights(float frameTime)
	{
		for (int i = 0; i < mPointLightList.size(); i++)
		{
			Vector3f MiddlePointPoint = mPointLightPropertyList[i].MiddlePoint;
			float Radius = mPointLightPropertyList[i].Radius;
			float newAngle = mPointLightPropertyList[i].Angle;
			float speed = mPointLightPropertyList[i].Speed;
			bool clockwise = mPointLightPropertyList[i].Clockwise;

			Vector3f newPos(0.f, MiddlePointPoint.GetY(), 0.f);
			newAngle += frameTime;
			mPointLightPropertyList[i].Angle = newAngle;

			if (clockwise)
			{
				newPos.SetX(MiddlePointPoint.GetX() + Radius * cos(newAngle) * speed);
				newPos.SetZ(MiddlePointPoint.GetZ() + Radius * sin(newAngle) * speed);
			}
			else
			{
				newPos.SetX(MiddlePointPoint.GetX() + Radius * sin(newAngle) * speed);
				newPos.SetZ(MiddlePointPoint.GetZ() + Radius * cos(newAngle) * speed);
			}

			mPointLightList[i].SetPosition(newPos);
		}
	}

}
