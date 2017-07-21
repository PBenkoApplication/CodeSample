#include "TestSceneBallGame.h"
#include "Mathematics/Math.h"
#include "GUI/GUIHandler.h"
#include <filesystem>
#include <sstream>
#include <fstream>
#include "BallGameClasses/PlayerStateNormal.h"
#include "BallGameClasses/PlayerStateInvertedMovement.h"

namespace BAME
{
	TestSceneBallGame::TestSceneBallGame(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer) :
		ITestScene(sceneManager, inputManager, audioPlayer)
	{
	}


	TestSceneBallGame::~TestSceneBallGame()
	{
		for(auto item : mItemPool)
		{
			delete item;
		}

		mItemPool.clear();

		for (auto item : mActiveItemList)
		{
			delete item;
		}
		mActiveItemList.clear();
	}


	void TestSceneBallGame::Init()
	{
		InitGameProperties();

		InitSceneWithCamera();
		InitGUIElements();
		InitSounds();
		mSceneManager.SetActiveScene("MainScene");
	}
	void TestSceneBallGame::InitSceneWithCamera()
	{
		mScene = mSceneManager.CreateScene("MainScene");
		mCamera.Init(&mInputManager, 1280, 720, float(Math::ToRadians(60)), Vector3f(0, 3, 10), Vector3f(0, 0, -1), Vector3f(0, 1, 0), 0.01f, 1000.0f);
		mCamera.SetRotationSensitivity(0.5f);
		mCamera.SetTranslationSensitivity(0.5f);
		mSceneManager.SetActiveCamera(&mCamera);
		mInputManager.SetMouseSensitivity(0.001f);
	}
	void TestSceneBallGame::InitSounds()
	{
		mSoundListener = mAudioPlayer.CreateSoundListener();
		mAudioPlayer.SetListener(mSoundListener);
		mBackGroundMusic = mAudioPlayer.CreateSound("Resources/Sounds/Theme.wav");
		mBackGroundSource = mAudioPlayer.CreateSoundSource(mBackGroundMusic, 1.f, 0.3f, Vector3f::Zero(), Vector3f::Zero(), true);
		mAudioPlayer.Add(mBackGroundSource);
		mAudioPlayer.Play(mBackGroundSource);

		mGameOverMusic = mAudioPlayer.CreateSound("Resources/Sounds/Game Over.wav");
		mSourceGameOverMusic = mAudioPlayer.CreateSoundSource(mGameOverMusic, 1.f, 0.5f, Vector3f::Zero(), Vector3f::Zero(), true);
		mAudioPlayer.Add(mSourceGameOverMusic);

		mGameWonMusic = mAudioPlayer.CreateSound("Resources/Sounds/Lee_Rosevere_-_11_-_Theme_from_Penguins_on_Parade.wav");
		mSourceGameWonMusic = mAudioPlayer.CreateSoundSource(mGameWonMusic, 1.f, 0.3f, Vector3f::Zero(), Vector3f::Zero(), true);
		mAudioPlayer.Add(mSourceGameWonMusic);


		mSoundBlockDefaultHit = mAudioPlayer.CreateSound("Resources/Sounds/arcade.wav");
		mSourceBlockDefaultHit = mAudioPlayer.CreateSoundSource(mSoundBlockDefaultHit, 1.f, 1.f, Vector3f::Zero(), Vector3f::Zero(), false);
		mAudioPlayer.Add(mSourceBlockDefaultHit);


		mSoundPlayerDefaultHit = mAudioPlayer.CreateSound("Resources/Sounds/bounce.wav");
		mSourcePlayerDefaultHit = mAudioPlayer.CreateSoundSource(mSoundPlayerDefaultHit, 1.f, 1.f, Vector3f::Zero(), Vector3f::Zero(), false);
		mAudioPlayer.Add(mSourcePlayerDefaultHit);


		mSoundPowerUpHit = mAudioPlayer.CreateSound("Resources/Sounds/powerup.wav");
		mSourcePowerUpNoCollisionHit = mAudioPlayer.CreateSoundSource(mSoundPowerUpHit, 1.f, 1.f, Vector3f::Zero(), Vector3f::Zero(), false);
		mAudioPlayer.Add(mSourcePowerUpNoCollisionHit);

		mSoundCheering = mAudioPlayer.CreateSound("Resources/Sounds/cheering.wav");
		mSourceCheering = mAudioPlayer.CreateSoundSource(mSoundCheering, 1.f, 0.5f, Vector3f::Zero(), Vector3f::Zero(), false);
		mAudioPlayer.Add(mSourceCheering);
	}
	void TestSceneBallGame::InitAudioPlayer()
	{
		mSoundListener = mAudioPlayer.CreateSoundListener();
		mAudioPlayer.SetListener(mSoundListener);
	}
	void TestSceneBallGame::InitPowerUps()
	{

		for (auto i = 0; i < 4; i++)
			mItemPool.push_back(new Item());

		mItemPool[0]->Init(mPowerUpWidth, mPowerUpHeight, ItemType::NoCollisionBall);
		mItemPool[1]->Init(mPowerUpWidth, mPowerUpHeight, ItemType::SpeedUpBall);
		mItemPool[2]->Init(mPowerUpWidth, mPowerUpHeight, ItemType::InvertPlayerMovement);
		mItemPool[3]->Init(mPowerUpWidth, mPowerUpHeight, ItemType::StickyBall);

		for (auto item : mItemPool)
			item->SetMiddlePosition(Vector2f(0.5, 0.5f));

	}
	void TestSceneBallGame::InitGameProperties()
	{
		mBlockTexturePathList =
		{
			"Resources/bevelBlock.jpg",
			"Resources/bevelBlock_blue.png",
			"Resources/bevelBlock_green.png",
			"Resources/bevelBlock_red.png",
			"Resources/bevelBlock_yellow.png"
		};


		mPlayerSpeed = 1;
		mBallWidth = 0.03f;
		mBallHeight = mBallWidth * 1.7f;

		mIsBallSticky = true;
		mIsPowerUpNoCollisionActive = false;
		mIsPowerUpStickyActive = false;
		mIsPowerUpSpeedActive = false;
		mIsPowerUpInvertMovementRunning = false;
		mIsGameWon = false;
		mIsGameOver = false;
		mGameHasEnded = false;
		mGameIsRunning = true;

		mGameIsStarted = false;

		mBallSpeedNormal = 0.6f;

		mPlayerWidth = 0.1f;
		mPlayerHeight = 0.04f;

		mPowerUpWidth = 0.03f;
		mPowerUpHeight = 0.03f * 1.77f;

		mPowerUpActiveTime = 10.f;
		mPowerUpStickyActiveTime = 10.f;
		mPowerUpSpeedActiveTime = 10.f;
		mPowerUpInvertPlayerMovementActiveTime = 5.f;

		mBallSpeed = mBallSpeedNormal;

		mBallDirection = Vector2f(-1.f, 2.f).Normalized();
	}
	void TestSceneBallGame::InitGUIElements()
	{

		GenerateLevel("Resources/Levels/GeneratedLevel.lvl");

		mBackground.Init(1.f, 1.f, "Resources/space.png", true);
		mBackground.SetPosition(Vector2f(0.f, 0.f));


		mPlayer.Init(mPlayerWidth, mPlayerHeight, "Resources/bevelBlock.jpg", true);
		mPlayer.SetPosition(Vector2f(0.5f - mPlayerWidth / 2.f, 0.f));

		mBall.Init(mBallWidth, mBallHeight, "Resources/Ball.png", true);
		mBall.SetPosition(Vector2f(0.5f, 0.5f));


		InitPowerUps();
		LoadLevel("Resources/Levels/GeneratedLevel.lvl");

		mDarkenBox.Init(1.f, 1.f, "Resources/Darken.png", true);
		mDarkenBox.SetPosition(Vector2f(0.f, 0.f));

		mGameOverText.Init(0.33f, 0.33f * 1.7f, "Resources/GameOverText.png");
		mGameOverText.SetPosition(Vector2f(0.33f, 0.33f));

		mGameWonText.Init(0.33f, 0.33f * 1.7f, "Resources/GameWonText.png");
		mGameWonText.SetPosition(Vector2f(0.33f, 0.33f));

		mStartInstructionText.Init(0.33f, 0.33f * 1.7f, "Resources/StartInstructionText.png", true);
		mStartInstructionText.SetPosition(Vector2f(0.33f, 0.33f));

		mExitInstruction.Init(0.33f, 0.33f * 1.7f, "Resources/ExitInstruction.png", true);
		mExitInstruction.SetPosition(Vector2f(0.33f, 0.33f));

		mRedBox.Init(1.f, 1.f, "Resources/transparentRed.png");
		mRedBox.SetPosition(Vector2f(0.f, 0.f));
	}


	void TestSceneBallGame::HandleInput(float frameTimeFloat)
	{
		if (mInputManager.GetKey(Key::LEFT))
		{
			mPlayer.Move(Vector2f(mPlayerSpeed *-frameTimeFloat, 0.f));
		}
		if (mInputManager.GetKey(Key::RIGHT))
		{
			mPlayer.Move(Vector2f(mPlayerSpeed *frameTimeFloat, 0.f));
		}
	}

	void TestSceneBallGame::RunRedFlash(float frameTimeFloat)
	{
		static float totalTime = 0.f;

		if (totalTime < 0.5f)
		{
			totalTime += frameTimeFloat;

			float elapsedTime = static_cast<float>(mRedBoxTimer.ElapsedTime());
			if (elapsedTime > 0.05f)
			{
				if (mRedBox.IsVisible())
					mRedBox.SetVisbility(false);
				else
					mRedBox.SetVisbility(true);
				mRedBoxTimer.Start();
			}
		}
	}

	bool TestSceneBallGame::CheckGameWon()
	{
		int activeBlocks = 0;
		for (auto& block : mBlockList)
		{
			if (block.IsVisible())
				activeBlocks++;
		}
		return activeBlocks == 0;
	}

	void TestSceneBallGame::HandleStickyBall()
	{
		if (mIsBallSticky)
		{
			Vector2f playerPos = mPlayer.GetMiddlePosition();
			mBall.SetMiddlePosition(playerPos + Vector2f(0.f, (mPlayerHeight + mBallHeight) / 2.f));

			if(mInputManager.GetKeyDown(Key::SPACE))
			{
				if (!mGameIsStarted)
				{
					StartGame();
				}
				mBallDirection = Vector2f(Math::getRandNumberF(0.5f, 1.f), Math::getRandNumberF(0.5f, 2.f)).Normalized();
				mIsBallSticky = false;
			}
			
		}
	}

	void TestSceneBallGame::StartGame()
	{
			mGameIsStarted = true;
			mStartInstructionText.SetVisbility(false);
			mDarkenBox.SetVisbility(false);
			mExitInstruction.SetVisbility(false);
	}

	void TestSceneBallGame::ShowWinSequence()
	{
		mExitInstruction.SetVisbility(true);
		mGameWonText.SetVisbility(true);
		mGameIsRunning = false;
		mAudioPlayer.Stop(mBackGroundSource);
		mAudioPlayer.Play(mSourceCheering);
		mAudioPlayer.Play(mSourceGameWonMusic);
	}

	void TestSceneBallGame::ShowGameOverSequence()
	{
		mAudioPlayer.Stop(mBackGroundSource);
		mAudioPlayer.Play(mSourceGameOverMusic);
		mDarkenBox.SetVisbility(true);
		mGameOverText.SetVisbility(true);
		mExitInstruction.SetVisbility(true);
	}

	void TestSceneBallGame::ShowEndSequence()
	{
		if (mIsGameWon)
		{
			ShowWinSequence();
		}
		else if (mIsGameOver)
		{

			ShowGameOverSequence();
		}
	}

	void TestSceneBallGame::Update(double frameTime)
	{
		float frameTimeFloat = static_cast<float>(frameTime);

		if (mGameIsRunning)
		{
			HandleInput(frameTimeFloat);

			mBall.Move(mBallSpeed * frameTimeFloat * mBallDirection);

			DoCollisionDetection();

			HandleStickyBall();

			UpdatePowerUps(frameTime);


			if (!mIsGameWon)
			{
				if(CheckGameWon())
				{
					mIsGameWon = true;
					mGameIsRunning = false;
				}
			}
		}
		else
		{
			if (mGameIsStarted && !mGameHasEnded)
			{
				ShowEndSequence();
				mGameHasEnded = true;
			}

			if(mIsGameOver)
			{
				RunRedFlash(frameTime);
			}
		}
	}
	void TestSceneBallGame::UpdateListener() const
	{
		mAudioPlayer.SetListenerPosition(mCamera.GetPosition());
		mAudioPlayer.SetListenerOrientation(mCamera.GetForward(), mCamera.GetUpDirection());
	}

	void TestSceneBallGame::CheckBoxCollision()
	{
		ePOSITION posInfo;
		if (CheckIntersectBallAndBoxes(posInfo))
		{
			if (!mIsPowerUpNoCollisionActive)
			{
				Vector2f normal;
				switch (posInfo)
				{
				case ePOSITION::LEFT:
					normal = { -1, 0 };
					break;
				case ePOSITION::RIGHT:
					normal = { 1, 0 };
					break;
				case ePOSITION::TOP:
					normal = { 0, 1 };
					break;
				case ePOSITION::BOTTOM:
					normal = { 0, -1 };
					break;
				default:
					break;
				}
				mBallDirection = GetReflectionVector(mBallDirection, normal);
			}

			SpawnRandomItem(mBall.GetMiddlePosition());

			mAudioPlayer.Play(mSourceBlockDefaultHit);

		}
	}

	void TestSceneBallGame::CheckBallPlayerCollision()
	{
		ePOSITION infoPos;
		if (mBall.CheckCollisionSphere(mPlayer, infoPos))
		{
			if (!mIsPowerUpStickyActive)
			{
				Vector2f normal;
				switch (infoPos)
				{
				case ePOSITION::LEFT:
					normal = { -1, 0 };
					break;
				case ePOSITION::RIGHT:
					normal = { 1, 0 };
					break;
				case ePOSITION::TOP:
					normal = { 0, 1 };
					break;
				case ePOSITION::BOTTOM:
					normal = { 0, -1 };
					break;
				default:
					break;
				}
				mBallDirection = GetReflectionVector(mBallDirection, normal);
			}
			else
				mIsBallSticky = true;

			mAudioPlayer.Play(mSourcePlayerDefaultHit);
		}
	}

	void TestSceneBallGame::CheckBallWindowBorderCollision()
	{
		Vector2f ballPos = mBall.GetPosition();
		Vector2f ballMiddlePos = mBall.GetMiddlePosition();
		if (ballPos.GetX() < 0)
		{
			mBallDirection = GetReflectionVector(mBallDirection, Vector2f(1, 0));
			mBall.SetPosition(Vector2f(0, ballPos.GetY()));
		}
		if (ballPos.GetX() > 1.0f - mBallWidth)
		{
			mBallDirection = GetReflectionVector(mBallDirection, Vector2f(-1, 0));

			mBall.SetPosition(Vector2f(1.0f - mBallWidth, ballPos.GetY()));
		}
		if (ballPos.GetY() > 1.0f - mBallWidth)
		{
			mBallDirection = GetReflectionVector(mBallDirection, Vector2f(0, -1));

			mBall.SetPosition(Vector2f(ballPos.GetX(), 1.0f - mBallWidth));
		}

		if (ballMiddlePos.GetY() < -mBallHeight && !mIsGameOver)
		{
			mIsGameOver = true;
			mGameIsRunning = false;
		}
	}

	void TestSceneBallGame::PositionPlayerInBounds()
	{
		Vector2f posPlayer = mPlayer.GetPosition();
		if (posPlayer.GetX() < 0)mPlayer.SetPosition(Vector2f(0, posPlayer.GetY()));
		float maxXPlayerPos = 1.0f - mPlayerWidth;
		if (posPlayer.GetX() > maxXPlayerPos)mPlayer.SetPosition(Vector2f(maxXPlayerPos, posPlayer.GetY()));
	}

	void TestSceneBallGame::DoCollisionDetection()
	{

		PositionPlayerInBounds();

		if (!mIsBallSticky)
		{
			CheckBoxCollision();


			CheckBallPlayerCollision();

			CheckBallWindowBorderCollision();
		}
	}

	void TestSceneBallGame::UpdatePowerUps(float frameTime)
	{
		for (int i = mActiveItemList.size() - 1; i >= 0; --i)
		{
			mActiveItemList[i]->Move(Vector2f(0.f, -frameTime * 0.3f));


			auto playerItemCollision = mPlayer.CheckCollision(*mActiveItemList[i]);
			if (playerItemCollision)
			{
				switch (mActiveItemList[i]->GetItemType())
				{
				case ItemType::SpeedUpBall:
					mPowerUpSpeedTimer.Start();
					mBallSpeed = mBallSpeedNormal * 1.5;
					mIsPowerUpSpeedActive = true;
					break;
				case ItemType::InvertPlayerMovement:
					mPowerUpInvertPlayerMovementTimer.Start();
					mIsPowerUpInvertMovementRunning = true;
					mPlayer.SetState(new PlayerStateInvertedMovement());
					break;
				case ItemType::NoCollisionBall:
					mPowerUpNoCollisionTimer.Start();
					mIsPowerUpNoCollisionActive = true;
					break;
				case ItemType::StickyBall:
					mPowerUpStickyTimer.Start();
					mIsPowerUpStickyActive = true;
					break;
				default:;
				}

				if (mActiveItemList[i]->GetPosition().GetY() < -mPowerUpHeight || playerItemCollision)
				{
					mActiveItemList[i]->Kill();
					mItemPool.push_back(mActiveItemList[i]);
					mActiveItemList.erase(mActiveItemList.begin() + i);

				}

				mAudioPlayer.Play(mSourcePowerUpNoCollisionHit);
			}
		}


		if (mIsPowerUpNoCollisionActive && mPowerUpNoCollisionTimer.ElapsedTime() > mPowerUpActiveTime)
			mIsPowerUpNoCollisionActive = false;

		if (mIsPowerUpStickyActive && mPowerUpStickyTimer.ElapsedTime() > mPowerUpStickyActiveTime)
			mIsPowerUpStickyActive = false;

		if (mIsPowerUpSpeedActive && mPowerUpSpeedTimer.ElapsedTime() > mPowerUpSpeedActiveTime)
		{
			mIsPowerUpSpeedActive = false;
			mBallSpeed = mBallSpeedNormal;
		}

		if (mIsPowerUpInvertMovementRunning && mPowerUpInvertPlayerMovementTimer.ElapsedTime() > mPowerUpInvertPlayerMovementActiveTime)
		{
			mPlayer.SetState(new PlayerStateNormal());
		}



	}

	void TestSceneBallGame::SpawnRandomItem(Vector2f const& ballPosition)
	{
		ItemType itemType = ItemType::No_Item;

		if (CalculatePowerUpPropability(10))
		{
			itemType = ItemType::NoCollisionBall;
		}
		else if (CalculatePowerUpPropability(10))
		{
			itemType = ItemType::InvertPlayerMovement;
		}
		else if (CalculatePowerUpPropability(5))
		{
			itemType = ItemType::SpeedUpBall;
		}
		else if (CalculatePowerUpPropability(2))
		{
			itemType = ItemType::StickyBall;
		}

		if (itemType == ItemType::No_Item)
			return;

		for (int i = 0; i < mItemPool.size(); i++)
		{
			if (mItemPool[i]->GetItemType() == itemType)
			{
				mItemPool[i]->SetActive(ballPosition);
				mActiveItemList.push_back(mItemPool[i]);
				mItemPool.erase(mItemPool.begin() + i);
				break;
			}
		}
	}

	bool TestSceneBallGame::CheckIntersectBallAndBoxes(ePOSITION& posInfo)
	{
		bool hit = false;
		int blocksActiveCount = 0;
		for (auto& block : mBlockList)
		{
			if (block.IsVisible())
			{
				if ((mBall.GetMiddlePosition() - block.GetMiddlePosition()).Length() < 0.1f)
				{
					hit = mBall.CheckCollisionSphere(block, posInfo);

					if (hit)
					{
						block.SetVisbility(false);
						return true;
					}
				}
			}
		}


		return false;
	}

	void TestSceneBallGame::Render()
	{
	}

	void TestSceneBallGame::Dispose()
	{
	}


	void TestSceneBallGame::GenerateLevel(std::string const& filePath) const
	{
		std::string mBlockNumbers;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				mBlockNumbers += std::to_string(Math::getRandNumber(0, int(mBlockTexturePathList.size()) - 1));
				if (j < 24)mBlockNumbers += " ";
			}
			if (i < 3)
				mBlockNumbers += "\n";
		}
		std::ofstream myfile;
		myfile.open(filePath);
		myfile << mBlockNumbers;
		myfile.close();
	}

	void TestSceneBallGame::LoadLevel(std::string const& filePath)
	{

		std::ifstream infile(filePath);


		std::string infileString;

		infile.seekg(0, std::ios::end);
		infileString.reserve(infile.tellg());
		infile.seekg(0, std::ios::beg);

		infileString.assign((std::istreambuf_iterator<char>(infile)),
			std::istreambuf_iterator<char>());


		auto lines = split(infileString, '\n');

		std::vector<std::vector<int>> mBoxNumbers;

		for (auto& line : lines)
		{
			auto boxes = split(line, ' ');

			std::vector<int> numbersInLine;
			for (int i = 0; i < boxes.size() && i < 25; i++)
			{
				numbersInLine.push_back(stoi(boxes.at(i)));
			}

			mBoxNumbers.push_back(numbersInLine);
		}


		int blocksPerLine = 25;
		float blockWidth = 1.f / blocksPerLine;
		float blockHeight = 0.04f;

		int blockCount = int(mBoxNumbers.size()) * blocksPerLine;

		int zeroCount = 0;
		for (int i = 0; i < mBoxNumbers.size(); i++)
		{
			for (int j = 0; j < mBoxNumbers[i].size(); j++)
			{
				if (mBoxNumbers.at(i).at(j) == 0)
					zeroCount++;
			}
		}

		blockCount -= zeroCount;

		mBlockList= std::vector<SimpleBox>(blockCount);

		int zeros = 0;
		for (int i = 0; i < mBoxNumbers.size(); i++)
		{
			for (int j = 0; j < mBoxNumbers[i].size(); j++)
			{
				int index = j + i * (blocksPerLine)-zeros;

				int textureIndex = mBoxNumbers.at(i).at(j);
				if (textureIndex == 0)
				{
					zeros++;
					continue;
				}
				auto mTexturePath = mBlockTexturePathList.at(textureIndex);

				mBlockList.at(index).Init(blockWidth, blockHeight, mTexturePath, true);

				mBlockList.at(index).SetPosition(Vector2f(j * blockWidth, 1.0f - (i + 1) * blockHeight));
			}
		}
	}

	bool TestSceneBallGame::CalculatePowerUpPropability(int oneToPropability) const
	{
		int number = Math::getRandNumber(1, oneToPropability);

		if (number == 1)
		{
			return true;
		}
		return false;
	}

	Vector2f TestSceneBallGame::GetReflectionVector(Vector2f const& inVector, Vector2f const& normale) const
	{
		auto norm = normale.Normalized();
		return (inVector - (2 * (inVector.Dot(norm)) * norm)).Normalized();
	}

	void TestSceneBallGame::split(const std::string& s, char delim, std::vector<std::string>& elems)
	{
		std::stringstream ss;
		ss.str(s);
		std::string item;
		while (std::getline(ss, item, delim))
		{
			elems.push_back(item);
		}
	}

	std::vector<std::string> TestSceneBallGame::split(const std::string& s, char delim)
	{
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}
}
