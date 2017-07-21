#ifndef TESTSCENEBENKO_H
#define TESTSCENEBENKO_H

#include "Geometry/TriangleMesh/Skydome.h"
#include "Geometry/TriangleMesh/Plane.h"
#include "GUI/Button.h"
#include "Geometry/TriangleMesh/Cube.h"
#include "ITestScene.h"
#include "Geometry/TriangleMesh/Skybox.h"
#include "Geometry/TriangleMesh/WavefrontObject.h"
#include "ParticleSystem/ParticleSystem.h"
#include "Geometry/BoneMesh/BoneMesh.h"
#include "Skinning/SkeletonMesh.h"
#include "Geometry/TriangleMesh/Cone.h"


namespace BAME
{
	class TestSceneBenko :public ITestScene
	{
	public:
		TestSceneBenko(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer);
		~TestSceneBenko();
		void AddSkyBox();
		void InitAudio();
		void Init() override;


		void UpdateAudio();
		void UpdateBoneMesh(float frameTime);
		void Update(double frameTime) override;
		void Render() override;
		void Dispose() override;

	private:

		void InitSceneDefaultWithCamera();
		void InitAudioPlayer();
		void AddParticleSystem();
		void AddObjectsFromObjFile();
		void AddBackGroundMusic();
		void AddGroundPlane();
		void AddGUICross();
		void AddDirectLight();
		void AddGlossyCube();
		void AddLights();
		void AddPointLight();
		void AddSpotLight();
		void AddSolarSystem();


		void ProcessInput(float frameTime);
		void UpdateParticleSystem(float frameTime);
		void UpdateListener() const;
		void UpdatePointLight(float frameTime);
		void UpdateGroundPlane(float frameTime);
		void UpdateSolarSystem(float frameTime);
		void UpdateSpotLight(float frameTime);
		void UpdateCube(float frameTime);
		void UpdateLights(float frameTime);
		void UpdateObjectsFromObjFile(float frameTime);


		struct PointLightsProperties
		{
			void Init(Vector3f middlePoint, float radius, float startAngle = 0, float speed = 1, bool clockwise = true)
			{
				MiddlePoint = middlePoint;
				Radius = radius;
				Angle = startAngle;
				Speed = speed;
				Clockwise = clockwise;
			}

			Vector3f MiddlePoint;
			float Radius;
			float Angle;
			float Speed;
			bool Clockwise;
		};

		ISoundListener* mSoundListener;
		ISound* mShootSound;
		ISoundSource* mShootSource;

		Scene* mScene;
		Camera mCamera;

		Plane mWaterPlane;
		Material mWaterPlaneMaterial;
		Placement mWaterPlanePlacement;
		Button mCross;

		DirectLight directLight;
		PointLight mPointLight;
		SpotLight mSpotLight;
		std::vector<PointLightsProperties> mPointLightPropertyList;
		std::vector<PointLight> mPointLightList;

		ParticleSystem mParticleSystem;
		ParticleSystem mParticleSystemTrees;

		Sphere mSun;
		Sphere mEarth;
		Sphere mMoon;
		Skydome mSkydome;
		Skybox mSkyBox;
		Cube mCube;
		Cone mCone;

		Material mMatCone;

		std::vector<WavefrontObject> waveobj;
		std::vector<WavefrontObject> waveobj2;
		std::vector<WavefrontObject> waveobj3;
		std::vector<WavefrontObject> waveobj4;

		BoneMesh mBoneMeshStickFigur;

		SkeletonMesh mPeggy;
		SkeletonMesh mPeggy2;
		Placement mPlacePeggy2;

		Placement mPlaceStickFigure;

		Material mSunMaterial;
		Material mEarthMaterial;
		Material mMoonMaterial;
		Material mSkydomeMaterial;
		Material mMatCube;
		Material waveObjMat;


		Placement mSolarSystemPlacement;
		Placement mEarthOrbitPlacement;
		Placement mMoonOrbitPlacement;
		Placement mSunPlacement;
		Placement mEarthPlacement;
		Placement mMoonPlacement;
		Placement mSkydomePlacement;
		Placement mPlaceCube;
		Placement mPlaceCubeAnker;
		Placement placeWaveObj;
		Placement placeWaveObj2;
		Placement placeWaveObj3;
		Placement placeWaveObj4;
		Placement placeAnkerWaveObj;
		Placement placeAnkerWaveObj2;
		Placement placeAnkerWaveObj3;
		Placement placeAnkerWaveObj4;
	};
}
#endif
