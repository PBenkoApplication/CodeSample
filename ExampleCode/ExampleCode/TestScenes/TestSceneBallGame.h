#ifndef TESTSCENEBALLGAME_H
#define TESTSCENEBALLGAME_H
#include "ITestScene.h"
#include "BallGameClasses/Box.h"
#include "Core/Timer.h"
#include "ParticleSystem/ParticleSystem.h"
#include "BallGameClasses/Player.h"
#include "BallGameClasses/Ball.h"
#include "BallGameClasses/Item.h"
#include "BallGameClasses/SimpleBox.h"

namespace BAME
{
	class TestSceneBallGame : public ITestScene
	{
	public:
		void InitGameProperties();
		void Init() override;
		bool CalculatePowerUpPropability(int oneToPropability) const;
		void DoCollisionDetection();

		void UpdatePowerUps(float frameTime);
		void SpawnRandomItem(Vector2f const& ballPosition);
		void ShowGameOverSequence();
		void Update(double frameTime) override;
		Vector2f GetReflectionVector(Vector2f const& inVector, Vector2f const& normale) const;
		bool CheckIntersectBallAndBoxes(ePOSITION& posInfo);
		void Render() override;
		void Dispose() override;
		TestSceneBallGame(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer);
		~TestSceneBallGame();
		void split(const std::string& s, char delim, std::vector<std::string>& elems);
		std::vector<std::string> split(const std::string& s, char delim);
		void GenerateLevel(std::string const& filePath) const;
		void LoadLevel(std::string const& filePath);
		void InitSounds();
		void InitAudioPlayer();
		void UpdateListener() const;
	private:
		void InitSceneWithCamera();
		void CheckBoxCollision();
		void CheckBallPlayerCollision();
		void CheckBallWindowBorderCollision();
		void PositionPlayerInBounds();
		void InitPowerUps();
		Scene* mScene;
		Camera mCamera;
	
		ISoundListener* mSoundListener;
		ISound* mBackGroundMusic;
		ISoundSource* mBackGroundSource;
		ISound* mSoundBlockDefaultHit;
		ISoundSource* mSourceBlockDefaultHit;
		ISound* mSoundPlayerDefaultHit;
		ISoundSource* mSourcePlayerDefaultHit;
		ISound* mGameOverMusic;
		ISoundSource* mSourceGameOverMusic;
		ISound* mGameWonMusic;
		ISoundSource* mSourceGameWonMusic;
		ISound* mSoundCheering;
		ISoundSource* mSourceCheering;
		ISound* mSoundPowerUpHit;
		ISoundSource* mSourcePowerUpNoCollisionHit;

		bool mIsBallSticky;
		bool mIsGameWon;
		float mPlayerSpeed;
		float mBallSpeedNormal;
		void InitGUIElements();
		void HandleInput(float frameTimeFloat);
		void RunRedFlash(float frameTimeFloat);
		bool CheckGameWon();
		void HandleStickyBall();
		void StartGame();
		void ShowWinSequence();
		void ShowEndSequence();


		std::vector<SimpleBox> mBlockList;
		Vector2f mBallDirection;
		SimpleBox StartText;
		Player mPlayer;
		Ball mBall;
		SimpleBox mGameOverText;
		SimpleBox mGameWonText;
		SimpleBox mStartInstructionText;
		SimpleBox mRedBox;
		SimpleBox mDarkenBox;
		SimpleBox mBackground;
		SimpleBox mExitInstruction;
		std::vector<std::string> mBlockTexturePathList;

		float mBallSpeed;
		float mBallWidth;
		float mBallHeight;

		Timer mPowerUpNoCollisionTimer;
		Timer mPowerUpStickyTimer;
		Timer mPowerUpSpeedTimer;
		Timer mPowerUpInvertPlayerMovementTimer;
		Timer mRedBoxTimer;

		bool mIsPowerUpNoCollisionActive;
		bool mIsPowerUpStickyActive;
		bool mIsPowerUpSpeedActive;
		bool mIsPowerUpInvertMovementRunning;
		

		std::vector<Item*> mItemPool;
		std::vector<Item*> mActiveItemList;

		bool mGameIsRunning;
		bool mGameIsStarted;
		bool mIsGameOver;
		bool mGameHasEnded;

		float mPlayerWidth;
		float mPlayerHeight;

		float mPowerUpWidth;
		float mPowerUpHeight;

		float mPowerUpActiveTime;
		float mPowerUpStickyActiveTime;
		float mPowerUpSpeedActiveTime;
		float mPowerUpInvertPlayerMovementActiveTime;

	};
}
#endif