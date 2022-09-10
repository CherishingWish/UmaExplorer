#include <filesystem>
#include <locale>
#include <string>
#include <thread>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <MinHook.h>
#include <fstream>
#include <nlohmann/json.hpp>

#include <vector>
#include <map>
#include <unordered_map>

#include <jsoncons/json.hpp>
#include <jsoncons_ext/msgpack/msgpack.hpp>

#include "dirent.h"

#include "edb.hpp"
#include "responses.hpp"
#include "mdb.hpp"
#include "il2cpp_symbols.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"

#include <d3d11.h>
#include <tchar.h>


#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>

#include "parallel_hashmap/phmap.h"

using phmap::flat_hash_map;


using namespace std;
using namespace std::literals;


using njson = nlohmann::json;
using namespace jsoncons;

extern LPVOID copysheet;
extern LPVOID getfield_addr;
extern bool first;


bool first = true;
LPVOID copysheet = 0;
LPVOID getfield_addr;

int cid = 0;
int sid = 0;
int gd = 0;
char str_cid[100];
char str_sid[100];
char str_gd[100];

void* test;

int global_story_id;
int global_chara_id;

int global_fps = 60;
char file_fps[100];

#define WSTR2( s ) L##s
#define WSTR( s ) WSTR2( s )

int imguiwindow();

struct Matrix4x4 // TypeDefIndex: 2062
{
	float m00; // 0x0
	float m10; // 0x4
	float m20; // 0x8
	float m30; // 0xC
	float m01; // 0x10
	float m11; // 0x14
	float m21; // 0x18
	float m31; // 0x1C
	float m02; // 0x20
	float m12; // 0x24
	float m22; // 0x28
	float m32; // 0x2C
	float m03; // 0x30
	float m13; // 0x34
	float m23; // 0x38
	float m33; // 0x3C
};

struct Vector3 // TypeDefIndex: 2063
{
	float x; // 0x0
	float y; // 0x4
	float z; // 0x8
};

struct Quaternion // TypeDefIndex: 2064
{
	// Fields
	float x; // 0x0
	float y; // 0x4
	float z; // 0x8
	float w; // 0xC
};

struct FacialDataUpdateInfo // TypeDefIndex: 16768
{
	// Fields
	LPVOID faceCur; // 0x0
	LPVOID faceNext; // 0x8
	LPVOID mouth; // 0x10
	LPVOID eyeCur; // 0x18
	LPVOID eyeNext; // 0x20
	LPVOID eyebrow; // 0x28
	LPVOID eyeTrack; // 0x30
	LPVOID ear; // 0x38
	LPVOID effect; // 0x40
	int faceKeyIndex; // 0x48
	int mouthKeyIndex; // 0x4C
	int eyeKeyIndex; // 0x50
	int eyebrowKeyIndex; // 0x54
	int eyeTrackKeyIndex; // 0x58
	int earKeyIndex; // 0x5C
	int effectKeyIndex; // 0x60
};

struct LiveTimelineWorkSheet // TypeDefIndex: 17060
{
	// Fields
	LPVOID VersionList; // 0x0
	LPVOID unknown1; //0x08
	LPVOID unknown2; //0x10
	LPVOID version; // 0x18
	int targetCameraIndex; // 0x20
	bool enableAtRuntime; // 0x24
	bool enableAtEdit; // 0x25
	short unknown3; //0x26
	float TotalTimeLength; // 0x28
	bool Lyrics; // 0x2C
	char unknown4; //0x2D
	short unknown5; //0x2E
	LPVOID SheetType; // 0x30
	LPVOID timescaleKeys; // 0x38
	LPVOID cameraPosKeys; // 0x40
	LPVOID cameraLookAtKeys; // 0x48
	LPVOID cameraFovKeys; // 0x50
	LPVOID cameraRollKeys; // 0x58
	LPVOID cameraMotionKeys; // 0x60
	LPVOID handShakeCameraKeys; // 0x68
	LPVOID eventKeys; // 0x70
	LPVOID charaMotSeqList; // 0x78
	LPVOID bgColor1List; // 0x80
	LPVOID bgColor2List; // 0x88
	LPVOID monitorControlList; // 0x90
	LPVOID animationList; // 0x98
	LPVOID textureAnimationList; // 0xA0
	LPVOID transformList; // 0xA8
	LPVOID rendererList; // 0xB0
	LPVOID objectList; // 0xB8
	LPVOID waveObjectList; // 0xC0
	LPVOID audienceList; // 0xC8
	LPVOID propsList; // 0xD0
	LPVOID propsAttachList; // 0xD8
	LPVOID cameraSwitcherKeys; // 0xE0
	LPVOID ripSyncKeys; // 0xE8
	LPVOID ripSync2Keys; // 0xF0
	LPVOID postEffectDOFKeys; // 0xF8
	LPVOID postEffectBloomDiffusionKeys; // 0x100
	LPVOID radialBlurKeys; // 0x108
	LPVOID postFilmKeys; // 0x110
	LPVOID postFilm2Keys; // 0x118
	LPVOID postFilm3Keys; // 0x120
	LPVOID FluctuationKeys; // 0x128
	LPVOID VortexKeys; // 0x130
	LPVOID fadeKeys; // 0x138
	LPVOID cameraLayerKeys; // 0x140
	LPVOID projecterList; // 0x148
	LPVOID facial1Set; // 0x150
	LPVOID other4EyeTrackKeys; // 0x158
	LPVOID ToneCurveKeys; // 0x160
	LPVOID ExposureKeys; // 0x168
	LPVOID other4FacialArray; // 0x170
	LPVOID facialNoiseKeys; // 0x178
	LPVOID charaMotionNoiseKeys; // 0x180
	LPVOID formationOffsetSet; // 0x188
	LPVOID volumeLightKeys; // 0x190
	LPVOID hdrBloomKeys; // 0x198
	LPVOID particleList; // 0x1A0
	LPVOID particleGroupList; // 0x1A8
	LPVOID WashLightList; // 0x1B0
	LPVOID laserList; // 0x1B8
	LPVOID blinkLightList; // 0x1C0
	LPVOID uvScrollLightList; // 0x1C8
	LPVOID facialToonSet; // 0x1D0
	LPVOID globalLightDataLists; // 0x1D8
	LPVOID globalFogDataLists; // 0x1E0
	LPVOID colorCorrectionDataLists; // 0x1E8
	LPVOID lightShaftsKeysLine; // 0x1F0
	LPVOID monitorCameraPosKeys; // 0x1F8
	LPVOID monitorCameraLookAtKeys; // 0x200
	LPVOID multiCameraPosKeys; // 0x208
	LPVOID multiCameraLookAtKeys; // 0x210
	LPVOID lensFlareList; // 0x218
	LPVOID environmentDataLists; // 0x220
	LPVOID sweatLocatorList; // 0x228
	LPVOID effectList; // 0x230
	LPVOID tiltShiftKeys; // 0x238
	LPVOID a2uConfigList; // 0x240
	LPVOID a2uList; // 0x248
	LPVOID titleKeys; // 0x250
	LPVOID spotlight3dList; // 0x258
	LPVOID nodeScaleList; // 0x260
	LPVOID charaFootLightKeys; // 0x268
	LPVOID chromaticAberrationList; // 0x270
	LPVOID lightProjectionList; // 0x278
	LPVOID billboardList; // 0x280
	LPVOID postFilm1MultiCameraKeys; // 0x288
	LPVOID postEffectBloomDiffusionMultiCameraKeys; // 0x290
	LPVOID multiCameraColorCorrectionDataLists; // 0x298
	LPVOID multiCameraTiltShiftDataLists; // 0x2A0
	LPVOID multiCameraRadialBlurDataLists; // 0x2A8
	LPVOID postEffectDOFMultiCameraKeys; // 0x2B0
	LPVOID AdditionalLightList; // 0x2B8
	LPVOID MultiLightShadowKeys; // 0x2C0
	LPVOID MobControlKeys; // 0x2C8
	LPVOID CyalumeControlKeys; // 0x2D0
	LPVOID charaWind; // 0x2D8
	LPVOID CharaPartsKeys; // 0x2E0
	LPVOID EyeCameraPosList; // 0x2E8
	LPVOID EyeCameraLookAtList; // 0x2F0
	LPVOID _keysArray; // 0x2F8
};

struct RaceResultCutInHelper
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID unknown3; //0x10
	LPVOID _timelineController; // 0x18
	LPVOID _onRenderImageEffect; //0x20
	LPVOID _loadedPath; //0x28
	LPVOID _sound; //0x30
	LPVOID OnStartAction; //0x38
	LPVOID OnEndAction; //0x40
	LPVOID OnGetCharaIdAction; //0x48
	LPVOID GetUserModelControllerAction; //0x50
	LPVOID OnPreSetupCharacterModelAction; //0x58
	LPVOID OnCreateAfterCharacterModelAction; //0x60
	LPVOID OnGetLoadedBackGroundAction; //0x68
	LPVOID _keepGlobalToonColor; //0x70
	LPVOID unknown4; //0x78
	LPVOID _characterRenderOrder; //0x80
	LPVOID _characterModelInstanceList; //0x88
	LPVOID _characterList; //0x90
	LPVOID TrainingBgChildDic; //0x98
	LPVOID _motionSwapController; //0xA0
	LPVOID _cyspringControlTargetController; //0xA8
	LPVOID ChildCutInHelperList; // 0xB0
	LPVOID _tempLoadPath; // 0xB8
	LPVOID _tempParent; // 0xC0
	LPVOID _isPlayedFixedUpdateForHighSpeed; // 0xC8
	LPVOID _preInstantiateInfo; // 0xD0
	LPVOID _cachedObjectRoot; // 0xD8
	LPVOID unknown5; //0xE0
	LPVOID _effectCamera; // 0xE8
	LPVOID _multiCameraDepthIndex; // 0xF0
	LPVOID _monitorInfoList; // 0xF8
	LPVOID _monitorRenderTexture; // 0x100
	LPVOID _loadedResourceDic; // 0x108
	LPVOID _cameraObject; // 0x110
	LPVOID _modelControllerArray; // 0x118
	LPVOID _courseBillboardBoundArray; // 0x120
	LPVOID _cameraMotionClip; // 0x128
	LPVOID _characterMotionClip; // 0x130
	LPVOID _facialDriven; // 0x138
	LPVOID _earDriven; // 0x140
	LPVOID _clipPlane; // 0x148
	LPVOID _playIndex; // 0x150
	LPVOID  _timelineCharacter; // 0x158
	LPVOID  _frameBuffer; // 0x160
	LPVOID _onPreCull; // 0x168
	LPVOID _onPostRender; // 0x170
	LPVOID _maskArray; // 0x178
	LPVOID _characterEnvParam; // 0x180
	LPVOID _courseEnvParam; // 0x188
	LPVOID _cacheMyTransform; // 0x190
	LPVOID _cacheCameraTransform; // 0x198
	LPVOID  _prefabRendererList; // 0x1A0
	LPVOID _charaPropList; // 0x1A8
	LPVOID _toBackgroundCameraRenderTexture; // 0x1B0
	LPVOID _uiImageCommandBuffer; // 0x1B8
};

struct RaceSkillCutInHelper
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID unknown3; //0x10
	LPVOID _timelineController; // 0x18
	LPVOID _onRenderImageEffect; //0x20
	LPVOID _loadedPath; //0x28
	LPVOID _sound; //0x30
	LPVOID OnStartAction; //0x38
	LPVOID OnEndAction; //0x40
	LPVOID OnGetCharaIdAction; //0x48
	LPVOID GetUserModelControllerAction; //0x50
	LPVOID OnPreSetupCharacterModelAction; //0x58
	LPVOID OnCreateAfterCharacterModelAction; //0x60
	LPVOID OnGetLoadedBackGroundAction; //0x68
	LPVOID _keepGlobalToonColor; //0x70
	LPVOID unknown4; //0x78
	LPVOID _characterRenderOrder; //0x80
	LPVOID _characterModelInstanceList; //0x88
	LPVOID _characterList; //0x90
	LPVOID TrainingBgChildDic; //0x98
	LPVOID _motionSwapController; //0xA0
	LPVOID _cyspringControlTargetController; //0xA8
	LPVOID ChildCutInHelperList; // 0xB0
	LPVOID _tempLoadPath; // 0xB8
	LPVOID _tempParent; // 0xC0
	LPVOID _isPlayedFixedUpdateForHighSpeed; // 0xC8
	LPVOID _preInstantiateInfo; // 0xD0
	LPVOID _cachedObjectRoot; // 0xD8
	LPVOID unknown5; //0xE0
	LPVOID _effectCamera; // 0xE8
	LPVOID _multiCameraDepthIndex; // 0xF0
	LPVOID _monitorInfoList; // 0xF8
	LPVOID _monitorRenderTexture; // 0x100
	LPVOID _loadedResourceDic; // 0x108
	LPVOID _baseHorseInfo; // 0x110
	LPVOID _onGetHorseIndex; // 0x118
	LPVOID _onGetSubKey; // 0x120
	LPVOID _raceManager; // 0x128
	LPVOID _onCheckPrefabTimeline; // 0x130
	LPVOID _charaColor1; // 0x138
	LPVOID _charaColor2; // 0x140
	LPVOID _charaSubColor1; // 0x148
	LPVOID _charaSubColor2; // 0x150
	LPVOID _assetReferenceTable; // 0x158
	LPVOID _preInstantiatedFixedCharaInfoList; // 0x160
	LPVOID _preInstantiatedUserCharaInfoList; // 0x168
	LPVOID _getFlashPlayerAction; // 0x170
	LPVOID _isEnablePlayFlash; // 0x178
	LPVOID _onSetWaitTap; // 0x180
	LPVOID _onSetTapJumpFrame; // 0x188
	LPVOID _onGachaGateAction; // 0x190
	LPVOID _onPlayVoice; // 0x198
	LPVOID _onSetWaitVoiceEnd; // 0x1A0
	LPVOID _onSimpleCommand; // 0x1A8
	LPVOID _onPlayEnv; // 0x1B0
	LPVOID _onSetVolumeEnv; // 0x1B8
	LPVOID _frameBuffer; // 0x1C0
	LPVOID _owner; // 0x1C8
	LPVOID _isBGMVolumeFade; // 0x1D0
	LPVOID _backgroundCommandBuffer; // 0x1D8
	LPVOID _uiImageCommandBuffer; // 0x1E0
	LPVOID _addLight; // 0x1E8
	LPVOID _lightRoot; // 0x1F0
	LPVOID _multiLightShadowController; // 0x1F8
	LPVOID _isInitializeShadowController; // 0x200
	LPVOID _backGroundCamera; // 0x208
	LPVOID _consignedCameraRootObj; // 0x210
	LPVOID _frameBufferAddedCameraList; // 0x218
	LPVOID _toCutInCameraRenderTexture; // 0x220
	LPVOID _toBackgroundCameraRenderTexture; // 0x228
	LPVOID _limitBrealTempDataList; // 0x230
	LPVOID _envPlayback; // 0x238

};

struct umastring
{
	LPVOID Empty; //0x00
	LPVOID unknown1; //0x08
	LPVOID m_stringLength; //0x10
	char m_firstChar; // 0x14
};

struct umachar
{
	LPVOID unknown1;
	LPVOID unknown2;
	LPVOID unknown3;
	long long length;
	short charstart;
};

struct CharacterSystemText
{

	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	int CharacterId; // 0x10
	int VoiceId; // 0x14
	LPVOID Text; // 0x18
	LPVOID CueSheet; // 0x20
	int CueId; // 0x28
	int MotionSet; // 0x2C
	int Scene; // 0x30
	int UseGallery; // 0x34
	int CardId; // 0x38
	int unknown3; // 0x3C
	LPVOID LipSyncData; // 0x40
	int Gender; // 0x48
	int MotionSecondSet; // 0x4C
	int MotionSecondStart; // 0x50
	int unknown4; // 0x54
	long long StartDate; // 0x58
	LPVOID _cueSheetString; // 0x60

};


struct CutInCharacterCreateInfo
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	int _characterType; // 0x10
	int _charaIndex; // 0x14
	LPVOID _parent; // 0x18
	int _charaId; // 0x20
	int _clothId; // 0x24
	int _headId; // 0x28
	int IsUseDressDataHeadModelSubId; // 0x2C
	int _zekkenNo; // 0x30
	bool _isWet; // 0x34
	bool _isDirt; // 0x35
	short unknown3; // 0x36
	int OverrideClothCategory; // 0x38
};

struct CutInCharacter
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	CutInCharacterCreateInfo* _createInfo; // 0x10
	LPVOID _createType; // 0x18
	LPVOID _model; // 0x20
	LPVOID _ikController; // 0x28
	LPVOID _isAddIKControllerFromCutIn; // 0x30
	LPVOID  _sweatController; // 0x38
	LPVOID _animator; // 0x40
	LPVOID _isCreateAnimator; // 0x48
	LPVOID _modelRendererHolder; // 0x50
	LPVOID _footShadowController; // 0x58
	LPVOID __isAddFootShadowController; // 0x60
	LPVOID _eyeTraceController; // 0x68
	LPVOID _emissiveScrollList; // 0x70
	LPVOID _cutInMode; // 0x78
	LPVOID _cachedPos; // 0x80
	int unknown3; //0x88
	LPVOID _cachedRot; // 0x8C
	LPVOID unknown4; // 0x94
	LPVOID _cachedScale; // 0x9C
	int unknown5; //0xA4
	int k__BackingField; // 0xA8
	int _originClothCategory; // 0xAC
};

struct CharacterBuildInfo
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	int _cardId; // 0x10
	int _charaId; // 0x14
	int _mobId; // 0x18
	int _headModelSubId; // 0x1C
	int _isUseDressDataHeadModelSubId; // 0x20
	int _bodyModelSubId; // 0x24
	int _dressId; // 0x28
	int _controllerType; // 0x2C
	int _zekken; // 0x30
	int unknown3; //0x34
	LPVOID _name; // 0x38
	int _genderType; // 0x40
	int _heightType; // 0x44
	int _bodySize; // 0x48
	int _bustType; // 0x4C
	int _height; // 0x50
	int _skinType; // 0x54
	int _socksType; // 0x58
};

struct TimelineKeyCharacterDataList
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID unknown3; //0x10
	LPVOID unknown4; //0x18
	LPVOID unknown5; //0x20
	LPVOID unknown6; //0x28
	LPVOID unknown7; //0x30
	LPVOID unknown8; //0x38
	LPVOID unknown9; //0x40
	int _selectCharaId; //0x48
	int _selectClothId; // 0x4C
	int _selectHeadId; // 0x50
};

struct TimelineCharacterGroupData
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID _types; // 0x10
	LPVOID _chara; // 0x18
	int _characterColorNum; // 0x20
	int CharacterWindNum; // 0x24
	int _characterShadowNum; // 0x28
	int _characterFootSmokeNum; // 0x2C
	int _characterSweatNum; // 0x30
	int _characterCollisionNum; // 0x34
	int CharacterSpringCollisionNum; // 0x38
	int _characterIKNum; // 0x3C
	int CharacterPartsNum; // 0x40
	int unknown3; //0x44
	TimelineKeyCharacterDataList* _characterKeys; // 0x48
};

struct TimelineCharacter
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID _controller; // 0x10
	TimelineCharacterGroupData* _data; // 0x18
	LPVOID _transformObject; // 0x20
	LPVOID _transform; // 0x28
	LPVOID _animation; // 0x30
	int _motionTriggeredKeyIndex; // 0x38
	int _selectCharaId; // 0x3C
	int _selectClothId; // 0x40
	int _selectHeadId; // 0x44
	int _isUseDressDataHeadModelSubId; // 0x48
	int _charaIndex; // 0x4C
	LPVOID _animator; // 0x50
	CutInCharacter* _cutInCharacter; // 0x58
};

struct Owner
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	int HorseIndex; // 0x10
	int SubKey; // 0x14
	int CharaId; // 0x18
	int CardId; // 0x1C
	LPVOID FrameBuffer; // 0x20
	int IsReadyJumpFrame; // 0x28
	int JumpFrame; // 0x2C
	bool IsJumpedFrame; // 0x30
	bool IsWaitVoiceEnd; // 0x31
	short unknown3; // 0x32
	int WaitTapFrame; // 0x34
};

struct GachaMainViewController
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID unknown3; //0x10
	LPVOID unknown4; //0x18
	LPVOID unknown5; //0x20
	LPVOID unknown6; //0x28
	LPVOID _viewInfo; // 0x30
	bool _isSkipAct; // 0x38
	bool _isNextCut; // 0x39
	bool _isRequestedChangeView; // 0x3A
	bool unknown7; //0x3B
	int unknown8; //0x3C
	LPVOID _rootObj; // 0x40
	LPVOID _context; // 0x48
	LPVOID _cutList; // 0x50
	LPVOID _playingIndex; // 0x58
	LPVOID _soundLoadCharaIdsGacha; // 0x60
	LPVOID _soundLoadSeCueSheetList; // 0x68
	LPVOID _cardBGCamera; // 0x70
	LPVOID _cardCamera; // 0x78
	LPVOID _cardCameraTrs; // 0x80
	LPVOID _isLockGameCanvas; // 0x88
};

struct MoveNext
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID state; // 0x10
	LPVOID current; // 0x18
	GachaMainViewController* _this; // 0x20
	int cardCount; // 0x28
	int cutCount; // 0x2C
	int index; // 0x30
};

struct ReservedCutIn
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	int InstanceNum; // 0x10
	int HorseIndex; // 0x14
	LPVOID CutInName; // 0x18
	int Category; // 0x20
	int SkillId; // 0x24
	float Time; // 0x28
	bool IsBGMVolumeFade; // 0x2C
};

struct GachaCutInR3SkillCutIn
{
	LPVOID unknown1; //0x00
	LPVOID unknown2; //0x08
	LPVOID Something_bool; // 0x10
	LPVOID _context; // 0x18
	LPVOID _isDisableBgObject; // 0x20
	LPVOID Info; // 0x28
	int _startFrame; // 0x30
	int _subKey; // 0x34
	LPVOID _namePlate; // 0x38
	LPVOID _se; // 0x40
};

struct ObjectTree
{
	string name;
	void* gameObj;
	int instanceID;
	vector<void*> components;
	vector<void*> children;
	bool activeSelf;
	bool activeInHierarchy;
};

namespace
{

	void create_debug_console()
	{
		AllocConsole();

		FILE* _;
		// open stdout stream
		freopen_s(&_, "CONOUT$", "w", stdout);
		freopen_s(&_, "CONOUT$", "w", stderr);
		freopen_s(&_, "CONIN$", "r", stdin);

		SetConsoleTitle(L"Umapyoi");

		// set this to avoid turn japanese texts into question mark
		SetConsoleOutputCP(CP_UTF8);
		std::locale::global(std::locale(""));
	}

	std::string current_time()
	{
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch());
		return std::to_string(ms.count());
	}

	void write_file(std::string file_name, char* buffer, int len)
	{
		FILE* fp;
		fopen_s(&fp, file_name.c_str(), "wb");
		if (fp != nullptr)
		{
			fwrite(buffer, 1, len, fp);
			fclose(fp);
		}
	}


	//开始测试Object

	void* object_orig = nullptr;

	void* object_hook(void* type, bool includeInactive)
	{

		void* ret = reinterpret_cast<decltype(object_hook)*>(object_orig)(type, includeInactive);

		return ret;

	}

	void* type_orig = nullptr;

	void* type_hook(umastring* _typename)
	{

		void* ret = reinterpret_cast<decltype(type_hook)*>(type_orig)(_typename);

		return ret;

	}

	void* arrayindex_orig = nullptr;

	void* arrayindex_hook(void* _this, long index)
	{

		void* ret = reinterpret_cast<decltype(arrayindex_hook)*>(arrayindex_orig)(_this, index);

		return ret;

	}

	void* objectname_orig = nullptr;

	umastring* objectname_hook(void* _this)
	{

		umastring* ret = reinterpret_cast<decltype(objectname_hook)*>(objectname_orig)(_this);

		return ret;

	}

	void* parent_orig = nullptr;

	void* parent_hook(void* _this)
	{

		void* ret = reinterpret_cast<decltype(parent_hook)*>(parent_orig)(_this);

		return ret;

	}

	void* gameobject_orig = nullptr;

	void* gameobject_hook(void* _this)
	{

		void* ret = reinterpret_cast<decltype(gameobject_hook)*>(gameobject_orig)(_this);

		return ret;

	}

	void* scene_orig = nullptr;

	void* scene_hook(void* _this)
	{

		void* ret = reinterpret_cast<decltype(scene_hook)*>(scene_orig)(_this);

		return ret;

	}

	void* scenename_orig = nullptr;

	umastring* scenename_hook(void* _this)
	{

		umastring* ret = reinterpret_cast<decltype(scenename_hook)*>(scenename_orig)(_this);

		return ret;

	}

	void* activescene_orig = nullptr;

	void* activescene_hook()
	{

		void* ret = reinterpret_cast<decltype(activescene_hook)*>(activescene_orig)();

		return ret;

	}

	void* childcount_orig = nullptr;

	int childcount_hook(void* _this)
	{

		int ret = reinterpret_cast<decltype(childcount_hook)*>(childcount_orig)(_this);

		return ret;

	}

	void* child_orig = nullptr;

	void* child_hook(void* _this, int index)
	{

		void* ret = reinterpret_cast<decltype(child_hook)*>(child_orig)(_this, index);

		return ret;

	}

	void* hierarchyActive_orig = nullptr;

	bool hierarchyActive_hook(void* _this)
	{

		bool ret = reinterpret_cast<decltype(hierarchyActive_hook)*>(hierarchyActive_orig)(_this);

		return ret;

	}

	void* activeSelf_orig = nullptr;

	bool activeSelf_hook(void* _this)
	{

		bool ret = reinterpret_cast<decltype(activeSelf_hook)*>(activeSelf_orig)(_this);

		return ret;

	}

	void* setActive_orig = nullptr;

	void setActive_hook(void* _this, bool value)
	{

		reinterpret_cast<decltype(setActive_hook)*>(setActive_orig)(_this, value);

		return;

	}

	void* position_orig = nullptr;

	Vector3 position_hook(void* _this)
	{

		Vector3 ret = reinterpret_cast<decltype(position_hook)*>(position_orig)(_this);

		return ret;

	}

	void* obj_inst_orig = nullptr;

	int obj_inst_hook(void* _this)
	{

		int ret = reinterpret_cast<decltype(obj_inst_hook)*>(obj_inst_orig)(_this);

		return ret;

	}

	void* inst_obj_orig = nullptr;

	void* inst_obj_hook(int instanceID)
	{

		void* ret = reinterpret_cast<decltype(inst_obj_hook)*>(inst_obj_orig)(instanceID);

		return ret;

	}

	void* rotation_orig = nullptr;

	Vector3 rotation_hook(void* _this)
	{

		Vector3 ret = reinterpret_cast<decltype(rotation_hook)*>(rotation_orig)(_this);

		return ret;

	}

	void* scale_orig = nullptr;

	Vector3 scale_hook(void* _this)
	{

		Vector3 ret = reinterpret_cast<decltype(scale_hook)*>(scale_orig)(_this);

		return ret;

	}

	void* components_orig = nullptr;

	void* components_hook(void* _this, void* type, bool useSearchTypeAsArrayReturnType = 1, bool recursive = 0, bool includeInactive = 1, bool reverse = 0, void* resultList = NULL)
	{

		void* ret = reinterpret_cast<decltype(components_hook)*>(components_orig)(_this, type, useSearchTypeAsArrayReturnType, recursive, includeInactive, reverse, resultList);

		return ret;

	}

	void* reftype_orig = nullptr;

	void* reftype_hook(void* _this, umastring* searchType)
	{

		void* ret = reinterpret_cast<decltype(reftype_hook)*>(reftype_orig)(_this, searchType);

		return ret;

	}

	void* refload_orig = nullptr;

	void* refload_hook(umastring* assemblyString)
	{

		void* ret = reinterpret_cast<decltype(refload_hook)*>(refload_orig)(assemblyString);

		return ret;

	}

	void* refmethod_orig = nullptr;

	void* refmethod_hook(void* _this, umastring* name, void* types)
	{

		void* ret = reinterpret_cast<decltype(refmethod_hook)*>(refmethod_orig)(_this, name, types);

		return ret;

	}

	void* arrayset_orig = nullptr;

	void arrayset_hook(void* _this, void* value, int index)
	{

		reinterpret_cast<decltype(arrayset_hook)*>(arrayset_orig)(_this, value, index);

		return;

	}

	void* create_orig = nullptr;

	void* create_hook(void* _this, void* type)
	{

		void* ret = reinterpret_cast<decltype(create_hook)*>(create_orig)(_this, type);

		return ret;

	}




	//


	void* s2c_orig = nullptr;

	umachar* s2c_hook(void* _this)
	{

		umachar* ret = reinterpret_cast<decltype(s2c_hook)*>(s2c_orig)(_this);

		return ret;

	}

	string UmaGetString(umastring* in) {
		string out = "";
		long long length = s2c_hook(in)->length;
		short* start = &(s2c_hook(in)->charstart);
		for (int i = 0; i <= length - 1; i++) {
			out += *(start++);
		}
		return out;
	}

	void* race_orig = nullptr;

	void* race_hook(void* _this, int characterId, void* dress, void* personalityType, int rank, void* grade, void* raceType)
	{

		void* ret = reinterpret_cast<decltype(race_hook)*>(race_orig)(_this, characterId, dress, personalityType, rank, grade, raceType);

		printf("someting strange is at %p \n", ret);
		printf("characterID is %p \n", characterId);
		printf("rank is %p \n", rank);

		return ret;

	}

	void* cutin_orig = nullptr;

	umastring* cutin_hook(int characterId, void* dress, int personalityType, int rank, int grade, int raceType)
	{
		char body[100];
		char path[100];

		umastring* ret = reinterpret_cast<decltype(cutin_hook)*>(cutin_orig)(characterId, dress, personalityType, rank, grade, raceType);

		ret = (umastring*)il2cpp_symbols::get_string("3d/Motion/RaceResult/Body/Chara/chr1001_00/anm_res_chr1001_001");

		printf("Please enter charaId:");
		scanf("%d", &cid);
		printf("Please enter subId:");
		scanf("%d", &sid);
		printf("Please enter grade:");
		scanf("%d", &gd);

		_itoa(cid, str_cid, 10);
		_itoa(sid, str_sid, 10);
		_itoa(gd, str_gd, 10);

		strcpy(path, "3d/Motion/RaceResult/Body/Chara/chr");
		strcat(path, str_cid);
		strcat(path, "_00/");
		if (gd == 100) {
			strcat(path, "anm_res_crd");
			strcat(path, str_sid);
			strcat(path, "_001");
		}
		else {
			strcat(path, "anm_res_chr");
			strcat(path, str_cid);
			strcat(path, "_001");
		}

		printf("Body path is %s \n", path);

		ret = (umastring*)il2cpp_symbols::get_string(path);

		/*
		printf("Anim Played! \n");
		printf("Return Path is %p \n", ret);
		printf("To char Path is %p \n", s2c_hook(ret));
		printf("To char Path is %p \n", *(LPVOID*)s2c_hook(ret));
		long long length = s2c_hook(ret)->length;
		short* start = &(s2c_hook(ret)->charstart);
		printf("To char Path is %d \n", length);
		printf("To char Path is ");
		for (int i = 0; i <= length - 1; i++) {
			printf("%c", *(start++));
		}
		printf("\n");
		printf("After is %p \n", *(LPVOID*)start);
		*/

		/*
		printf("My path is %p\n", value);
		printf("Test path is %p\n", value->unknown1);
		printf("Test path is %p\n", value->unknown2);
		printf("Test path is %p\n", value->unknown3);
		printf("Test path is %p\n", value->_timelineController);
		printf("Test path is %p\n", value->_onRenderImageEffect);
		printf("Test path is %p\n", value->_loadedPath);
		printf("Test path is %p\n", value->_sound);
		printf("Test path is %p\n", value->OnStartAction);
		printf("Test path is %p\n", value->OnEndAction);
		printf("Test path is %p\n", value->OnGetCharaIdAction);
		printf("Test path is %p\n", value->GetUserModelControllerAction);
		printf("Test path is %p\n", value->OnPreSetupCharacterModelAction);
		printf("Test path is %p\n", value->OnCreateAfterCharacterModelAction);
		printf("Test path is %p\n", value->OnGetLoadedBackGroundAction);
		printf("Test path is %p\n", value->_keepGlobalToonColor);
		printf("Test path is %p\n", value->unknown4);
		printf("Test path is %p\n", value->_characterRenderOrder);
		printf("Test path is %p\n", value->_characterModelInstanceList);
		printf("Test path is %p\n", value->_characterList);
		printf("Test path is %p\n", value->TrainingBgChildDic);
		printf("Test path is %p\n", value->_motionSwapController);
		printf("Test path is %p\n", value->_cyspringControlTargetController);
		printf("Test path is %p\n", value->ChildCutInHelperList);
		printf("Test path is %p\n", value->_tempLoadPath);
		printf("Test path is %p\n", value->_tempParent);
		printf("Test path is %p\n", value->_isPlayedFixedUpdateForHighSpeed);
		printf("Test path is %p\n", value->_preInstantiateInfo);
		printf("Test path is %p\n", value->_cachedObjectRoot);
		printf("Test path is %p\n", value->unknown5);
		printf("Test path is %p\n", value->_effectCamera);
		printf("Test path is %p\n", value->_multiCameraDepthIndex);
		printf("Test path is %p\n", value->_monitorInfoList);
		printf("Test path is %p\n", value->_monitorRenderTexture);
		printf("Test path is %p\n", value->_loadedResourceDic);
		printf("Test path is %p\n", value->_cameraObject);
		printf("Test path is %p\n", value->_modelControllerArray);
		printf("Test path is %p\n", value->_courseBillboardBoundArray);
		printf("Test path is %p\n", value->_cameraMotionClip);
		printf("Test path is %p\n", value->_characterMotionClip);
		printf("Test path is %p\n", value->_facialDriven);
		printf("Test path is %p\n", value->_earDriven);
		printf("Test path is %p\n", value->_clipPlane);
		printf("Test path is %p\n", value->_playIndex);
		printf("Test path is %p\n", value->_timelineCharacter);
		printf("Test path is %p\n", value->_frameBuffer);
		printf("Test path is %p\n", value->_onPreCull);
		printf("Test path is %p\n", value->_onPostRender);
		printf("Test path is %p\n", value->_maskArray);
		printf("Test path is %p\n", value->_characterEnvParam);
		printf("Test path is %p\n", value->_courseEnvParam);
		printf("Test path is %p\n", value->_cacheMyTransform);
		printf("Test path is %p\n", value->_cacheCameraTransform);
		printf("Test path is %p\n", value->_prefabRendererList);
		printf("Test path is %p\n", value->_charaPropList);
		printf("Test path is %p\n", value->_toBackgroundCameraRenderTexture);
		printf("Test path is %p\n", value->_uiImageCommandBuffer);
		printf("------------------------");
		*/
		/*
		TimelineCharacter** path = *(TimelineCharacter***)(value->_characterList);

		printf("Character path is %p\n", value->_characterList);
		printf("Character list path is %p\n", *(LPVOID*)(value->_characterList));
		printf("Character timeline path is %p\n", *(LPVOID*)*(LPVOID*)(value->_characterList));
		printf("Character timeline path1 is %p\n", path[0]);
		printf("Character timeline path2 is %p\n", path[1]);
		printf("Character ID is %d\n", path[0]->_selectCharaId);
		printf("Character Dress is %d\n", path[0]->_selectCharaId);
		printf("Character CutIn is %p\n", path[0]->_cutInCharacter);
		*/
		return ret;

	}

	void* camera_orig = nullptr;

	umastring* camera_hook(int characterId, void* dress, int personalityType, int rank, int grade, int raceType)
	{
		char camera[100];
		char path[100];

		umastring* ret = reinterpret_cast<decltype(camera_hook)*>(camera_orig)(characterId, dress, personalityType, rank, grade, raceType);

		ret = (umastring*)il2cpp_symbols::get_string("3d/Motion/RaceResult/Camera/Chara/chr1001_00/anm_res_chr1001_001_cam");

		strcpy(path, "3d/Motion/RaceResult/Camera/Chara/chr");
		strcat(path, str_cid);
		strcat(path, "_00/");
		if (gd == 100) {
			strcat(path, "anm_res_crd");
			strcat(path, str_sid);
			strcat(path, "_001_cam");
		}
		else {
			strcat(path, "anm_res_chr");
			strcat(path, str_cid);
			strcat(path, "_001_cam");
		}

		printf("Camera path is %s \n", path);

		ret = (umastring*)il2cpp_symbols::get_string(path);

		/*
		printf("Anim Played! \n");
		printf("Return Path is %p \n", ret);
		printf("To char Path is %p \n", s2c_hook(ret));
		printf("To char Path is %p \n", *(LPVOID*)s2c_hook(ret));
		long long length = s2c_hook(ret)->length;
		short* start = &(s2c_hook(ret)->charstart);
		printf("To char Path is %d \n", length);
		printf("To char Path is ");
		for (int i = 0; i <= length - 1; i++) {
			printf("%c", *(start++));
		}
		printf("\n");
		printf("After is %p \n", *(LPVOID*)start);
		*/
		return ret;

	}

	void* facial_orig = nullptr;

	umastring* facial_hook(int characterId, void* dress, int personalityType, int rank, int grade, int raceType)
	{
		char facial[100];
		char path[100];

		umastring* ret = reinterpret_cast<decltype(facial_hook)*>(facial_orig)(characterId, dress, personalityType, rank, grade, raceType);

		ret = (umastring*)il2cpp_symbols::get_string("3d/Motion/RaceResult/Facial/Chara/chr1001_00/anm_res_chr1001_001_face_driven");

		strcpy(path, "3d/Motion/RaceResult/Facial/Chara/chr");
		strcat(path, str_cid);
		strcat(path, "_00/");
		if (gd == 100) {
			strcat(path, "anm_res_crd");
			strcat(path, str_sid);
			strcat(path, "_001_face_driven");
		}
		else {
			strcat(path, "anm_res_chr");
			strcat(path, str_cid);
			strcat(path, "_001_face_driven");
		}

		printf("Facial path is %s \n", path);

		ret = (umastring*)il2cpp_symbols::get_string(path);

		/*
		printf("Anim Played! \n");
		printf("Return Path is %p \n", ret);
		printf("To char Path is %p \n", s2c_hook(ret));
		printf("To char Path is %p \n", *(LPVOID*)s2c_hook(ret));
		long long length = s2c_hook(ret)->length;
		short* start = &(s2c_hook(ret)->charstart);
		printf("To char Path is %d \n", length);
		printf("To char Path is ");
		for (int i = 0; i <= length - 1; i++) {
			printf("%c", *(start++));
		}
		printf("\n");
		printf("After is %p \n", *(LPVOID*)start);
		*/
		return ret;

	}

	void* ear_orig = nullptr;

	umastring* ear_hook(int characterId, void* dress, int personalityType, int rank, int grade, int raceType)
	{
		char ear[100];
		char path[100];

		umastring* ret = reinterpret_cast<decltype(ear_hook)*>(ear_orig)(characterId, dress, personalityType, rank, grade, raceType);

		ret = (umastring*)il2cpp_symbols::get_string("3d/Motion/RaceResult/Facial/Chara/chr1001_00/anm_res_chr1001_001_ear_driven");

		strcpy(path, "3d/Motion/RaceResult/Facial/Chara/chr");
		strcat(path, str_cid);
		strcat(path, "_00/");
		if (gd == 100) {
			strcat(path, "anm_res_crd");
			strcat(path, str_sid);
			strcat(path, "_001_ear_driven");
		}
		else {
			strcat(path, "anm_res_chr");
			strcat(path, str_cid);
			strcat(path, "_001_ear_driven");
		}

		printf("Ear path is %s \n", path);

		ret = (umastring*)il2cpp_symbols::get_string(path);

		/*
		printf("Anim Played! \n");
		printf("Return Path is %p \n", ret);
		printf("To char Path is %p \n", s2c_hook(ret));
		printf("To char Path is %p \n", *(LPVOID*)s2c_hook(ret));
		long long length = s2c_hook(ret)->length;
		short* start = &(s2c_hook(ret)->charstart);
		printf("To char Path is %d \n", length);
		printf("To char Path is ");
		for (int i = 0; i <= length - 1; i++) {
			printf("%c", *(start++));
		}
		printf("\n");
		printf("After is %p \n", *(LPVOID*)start);
		*/
		return ret;

	}

	void* music_orig = nullptr;

	umastring* music_hook(int charaId, int subId, int cardId, int rank, int grade, int raceType)
	{
		char music[100];
		char path[100];

		umastring* ret = reinterpret_cast<decltype(music_hook)*>(music_orig)(charaId, subId, cardId, rank, grade, raceType);

		ret = (umastring*)il2cpp_symbols::get_string("Cutt/CutIn/RaceResult/res_chr1007_001/res_chr1007_001");

		strcpy(path, "Cutt/CutIn/RaceResult/");
		if (gd == 100) {
			strcat(path, "res_crd");
			strcat(path, str_sid);
			strcat(path, "_001/");
			strcat(path, "res_crd");
			strcat(path, str_sid);
			strcat(path, "_001");
		}
		else {
			strcat(path, "res_chr");
			strcat(path, str_cid);
			strcat(path, "_001/");
			strcat(path, "res_chr");
			strcat(path, str_cid);
			strcat(path, "_001");
		}

		printf("Cutt path is %s \n", path);

		ret = (umastring*)il2cpp_symbols::get_string(path);

		/*
		printf("Anim Played! \n");
		printf("Return Path is %p \n", ret);
		printf("To char Path is %p \n", s2c_hook(ret));
		printf("To char Path is %p \n", *(LPVOID*)s2c_hook(ret));
		long long length = s2c_hook(ret)->length;
		short* start = &(s2c_hook(ret)->charstart);
		printf("To char Path is %d \n", length);
		printf("To char Path is ");
		for (int i = 0; i <= length - 1; i++) {
			printf("%c", *(start++));
		}
		printf("\n");
		printf("After is %p \n", *(LPVOID*)start);
		*/
		return ret;

	}

	void* sheet_orig = nullptr;

	CharacterSystemText* sheet_hook(void* _this, int charaId, int subId, int cardId, int rank, int grade, int raceType)
	{
		char sheet[100];

		charaId = cid;
		subId = sid;
		grade = gd;

		printf("Anim Played! \n");
		printf("charaId is %d \n", charaId);
		printf("subId is %d \n", subId);
		printf("cardId is %d \n", cardId);
		printf("rank is %d \n", rank);
		printf("grade is %d \n", grade);
		printf("raceType is %d \n", raceType);

		CharacterSystemText* ret = reinterpret_cast<decltype(sheet_hook)*>(sheet_orig)(_this, charaId, subId, cardId, rank, grade, raceType);

		/*
		ret = (umastring*)il2cpp_symbols::get_string("Cutt/CutIn/RaceResult/res_chr1007_001/res_chr1007_001");

		printf("Please enter music path:");
		scanf("%s", music);
		ret = (umastring*)il2cpp_symbols::get_string(music);
		*/



		return ret;

	}

	void* sound_orig = nullptr;

	umastring* sound_hook(int charaId)
	{
		charaId = cid;

		printf("Something pass sound trap! \n");

		umastring* ret = reinterpret_cast<decltype(sound_hook)*>(sound_orig)(charaId);

		return ret;

	}

	/*

	void* info_orig = nullptr;

	void* info_hook(CutInCharacter* _this, void* model, int type)
	{

		printf("Something Pass Info! \n");

		printf("Data is %p \n", _this->_createInfo->_characterType);
		printf("Data is %p \n", _this->_createInfo->_charaIndex);
		printf("Data is %p \n", _this->_createInfo->_parent);
		printf("Data is %p \n", _this->_createInfo->_charaId);
		printf("Data is %p \n", _this->_createInfo->_clothId);
		printf("Data is %p \n", _this->_createInfo->_headId);
		printf("Data is %p \n", _this->_createInfo->IsUseDressDataHeadModelSubId);
		printf("Data is %p \n", _this->_createInfo->_zekkenNo);
		printf("Data is %p \n", _this->_createInfo->_isWet);
		printf("Data is %p \n", _this->_createInfo->_isDirt);
		printf("Data is %p \n", _this->_createInfo->OverrideClothCategory);

		void* ret = reinterpret_cast<decltype(info_hook)*>(info_orig)(_this, model, type);

		return ret;

	}

	void* object_orig = nullptr;

	void object_hook(void* _this, CutInCharacter* charInfo)
	{

		printf("Something Pass Object! \n");

		printf("Data is %p \n", charInfo->_createInfo->_characterType);
		printf("Data is %p \n", charInfo->_createInfo->_charaIndex);
		printf("Data is %p \n", charInfo->_createInfo->_parent);
		printf("Data is %p \n", charInfo->_createInfo->_charaId);
		printf("Data is %p \n", charInfo->_createInfo->_clothId);
		printf("Data is %p \n", charInfo->_createInfo->_headId);
		printf("Data is %p \n", charInfo->_createInfo->IsUseDressDataHeadModelSubId);
		printf("Data is %p \n", charInfo->_createInfo->_zekkenNo);
		printf("Data is %p \n", charInfo->_createInfo->_isWet);
		printf("Data is %p \n", charInfo->_createInfo->_isDirt);
		printf("Data is %p \n", charInfo->_createInfo->OverrideClothCategory);





		reinterpret_cast<decltype(object_hook)*>(object_orig)(_this, charInfo);

		printf("Data is %p \n", *(LPVOID*)((long long)charInfo + 168));

		return;

	}

	void* model_orig = nullptr;

	void* model_hook(CharacterBuildInfo* _this, void* modelLoader)
	{

		printf("Something Pass Model! \n");

		if (_this->_zekken == 0) {
			printf("Changing Start! \n");
			_this->_charaId = 1001;
		}


		printf("Data is %p \n", _this->_cardId);
		printf("Data is %p \n", _this->_charaId);
		printf("Data is %p \n", _this->_dressId);
		printf("Data is %p \n", _this->_zekken);

		void* ret = reinterpret_cast<decltype(model_hook)*>(model_orig)(_this, modelLoader);

		printf("Changing Completed! \n");

		return ret;

	}

	void* create_orig = nullptr;

	void* create_hook(void* _this, CutInCharacterCreateInfo* info)
	{

		printf("Something Pass Create! \n");

		printf("Data is %p \n", info->_characterType);
		printf("Data is %p \n", info->_charaIndex);
		printf("Data is %p \n", info->_parent);
		printf("Data is %p \n", info->_charaId);
		printf("Data is %p \n", info->_clothId);
		printf("Data is %p \n", info->_headId);
		printf("Data is %p \n", info->IsUseDressDataHeadModelSubId);
		printf("Data is %p \n", info->_zekkenNo);
		printf("Data is %p \n", info->_isWet);
		printf("Data is %p \n", info->_isDirt);
		printf("Data is %p \n", info->OverrideClothCategory);

		void* ret = reinterpret_cast<decltype(create_hook)*>(create_orig)(_this, info);

		return ret;

	}


	void* chara_orig = nullptr;

	void chara_hook(TimelineCharacter* _this, int currentFrame)
	{
		printf("Something Pass Chara! \n");

		//_this->_data->_characterKeys->_selectCharaId = -1;

		printf("Data is %p \n", currentFrame);

		printf("Data is %p \n", _this->_data);
		printf("Data is %p \n", _this->_data->_characterKeys);
		printf("Data is %p \n", _this->_data->_characterKeys->_selectCharaId);
		printf("Data is %p \n", _this->_data->_characterKeys->_selectClothId);
		printf("Data is %p \n", _this->_data->_characterKeys->_selectHeadId);

		printf("Data is %p \n", _this->_selectCharaId);
		printf("Data is %p \n", _this->_selectClothId);
		printf("Data is %p \n", _this->_selectHeadId);

		reinterpret_cast<decltype(chara_hook)*>(chara_orig)(_this, currentFrame);

		printf("Work Completed!");

		return;

	}

	void* setup_orig = nullptr;

	void setup_hook(CutInCharacter* _this, void* model)
	{
		printf("Something Pass Setup! \n");

		reinterpret_cast<decltype(setup_hook)*>(setup_orig)(_this, model);

		return;

	}

	void* backup_orig = nullptr;

	void backup_hook(void* _this)
	{
		printf("Something Pass BackUP! \n");

		reinterpret_cast<decltype(backup_hook)*>(backup_orig)(_this);

		return;

	}

	void* control_orig = nullptr;

	void* control_hook(void* _this, CutInCharacterCreateInfo* info)
	{
		printf("Something Pass Control! \n");

		printf("Data is %p \n", *(LPVOID*)((long long)_this+280));

		void* ret = reinterpret_cast<decltype(control_hook)*>(control_orig)(_this, info);

		return ret;

	}


	void* controlarray_orig = nullptr;

	void* controlarray_hook(void* bodyObject, int controllerType)
	{
		printf("Something Pass ControlArray! \n");

		printf("Obj is %p \n", bodyObject);

		printf("Type is %p \n", controllerType);

		void* ret = reinterpret_cast<decltype(controlarray_hook)*>(controlarray_orig)(bodyObject, controllerType);

		printf("Retrun is %p \n", ret);

		return ret;

	}


	void* tobuild_orig = nullptr;

	CharacterBuildInfo* tobuild_hook(int cardId, int charaId, int dressId, int zekkenNo)
	{
		printf("Something Pass ToBuild! \n");

		CharacterBuildInfo* ret = reinterpret_cast<decltype(tobuild_hook)*>(tobuild_orig)(cardId, charaId, dressId, zekkenNo);

		return ret;

	}

	void* build_orig = nullptr;

	void* build_hook(CharacterBuildInfo* charInfo, void* headPrefab, void* bodyPrefab, void* tailPrefab, void* handle, bool isSync, void* modelBridge)
	{
		printf("Something Pass Build! \n");

		//charInfo = tobuild_hook(100101, 1001, 100101, 8);


		printf("Data is %p \n", charInfo->_cardId);
		printf("Data is %p \n", charInfo->_charaId);
		printf("Data is %p \n", charInfo->_dressId);
		printf("Data is %p \n", charInfo->_zekken);


		void* ret = reinterpret_cast<decltype(build_hook)*>(build_orig)(charInfo, headPrefab, bodyPrefab, tailPrefab, handle, isSync, modelBridge);

		return ret;

	}
	*/

	void* spring_orig = nullptr;

	void spring_hook(void* _this, float rate)
	{
		printf("Something Pass Spring! \n");

		reinterpret_cast<decltype(spring_hook)*>(spring_orig)(_this, rate);

		return;

	}

	void* gacha_orig = nullptr;

	void gacha_hook(void* _this, Owner* owner)
	{

		printf("Something Pass Gacha! \n");

		printf("Data is %p \n", owner->HorseIndex);
		printf("Data is %p \n", owner->SubKey);
		printf("Data is %p \n", owner->CharaId);
		printf("Data is %p \n", owner->CardId);

		reinterpret_cast<decltype(gacha_hook)*>(gacha_orig)(_this, owner);

		return;

	}

	void* gachacutin_orig = nullptr;

	bool gachacutin_hook(MoveNext* _this)
	{
		printf("Something Pass Cutin! \n");

		printf("Data is %p \n", _this);
		printf("Data is %p \n", _this->_this);
		printf("Data is %p \n", _this->_this->_context);

		bool ret = reinterpret_cast<decltype(gachacutin_hook)*>(gachacutin_orig)(_this);

		printf("Return is %p \n", ret);

		return ret;

	}

	void* gachachara_orig = nullptr;

	bool gachachara_hook(MoveNext* _this)
	{
		printf("Something Pass Chara! \n");

		printf("Data is %p \n", _this);
		printf("Data is %p \n", _this->_this);
		printf("Data is %p \n", _this->cardCount);
		printf("Data is %p \n", _this->cutCount);
		printf("Data is %p \n", _this->index);
		printf("Data is %p \n", _this->_this->_context);

		bool ret = reinterpret_cast<decltype(gachachara_hook)*>(gachachara_orig)(_this);

		printf("Chara work Completed! \n");

		return ret;

	}

	void* holder_orig = nullptr;

	void holder_hook(void* _this, int horseIndex, int cardId, int charaId, int dressId, int headId, void* root, bool isUseCache, bool isUseDressDataHeadModelSubId)
	{
		printf("Something Pass Holder! \n");

		//charaId = 1024;
		//dressId = 102401;
		//isUseCache = 0;

		printf("Data is %p \n", horseIndex);
		printf("Data is %p \n", cardId);
		printf("Data is %p \n", charaId);
		printf("Data is %p \n", dressId);
		printf("Data is %p \n", headId);
		printf("Data is %p \n", isUseCache);
		printf("Data is %p \n", isUseDressDataHeadModelSubId);

		reinterpret_cast<decltype(holder_hook)*>(holder_orig)(_this, horseIndex, cardId, charaId, dressId, headId, root, isUseCache, isUseDressDataHeadModelSubId);

		printf("Holder End! \n");

		return;

	}

	void* pre_orig = nullptr;

	void pre_hook(void* _this)
	{
		printf("Something Pass Pre! \n");

		reinterpret_cast<decltype(pre_hook)*>(pre_orig)(_this);

		return;

	}

	void* icon_orig = nullptr;

	umastring* icon_hook(umastring* cutinId)
	{
		printf("Something Pass Icon! \n");

		long long c_length = s2c_hook(cutinId)->length;
		short* c_start = &(s2c_hook(cutinId)->charstart);

		printf("CutinID Path is ");
		for (int i = 0; i <= c_length - 1; i++) {
			printf("%c", *(c_start++));
		}
		printf("\n");

		umastring* ret = reinterpret_cast<decltype(icon_hook)*>(icon_orig)(cutinId);

		long long length = s2c_hook(ret)->length;
		short* start = &(s2c_hook(ret)->charstart);

		printf("To char Path is ");
		for (int i = 0; i <= length - 1; i++) {
			printf("%c", *(start++));
		}
		printf("\n");

		//ret = (umastring*)il2cpp_symbols::get_string("Cutt/CutIn/Skill/crd103002_001/crd103002_001");

		return ret;

	}

	void* play_orig = nullptr;

	void play_hook(void* _this)
	{
		printf("Something Pass Play! \n");

		reinterpret_cast<decltype(play_hook)*>(play_orig)(_this);

		printf("Play End! \n");

		return;

	}

	void* clist_orig = nullptr;

	void clist_hook(void* _this)
	{
		printf("Something Pass Clist! \n");

		reinterpret_cast<decltype(clist_hook)*>(clist_orig)(_this);

		printf("Clist End! \n");

		return;

	}

	void* user_orig = nullptr;

	void* user_hook(void* _this, CutInCharacterCreateInfo* info)
	{
		printf("Something Pass User! \n");

		/*
		if (info->_characterType == 3 and info->_charaIndex == 0) {
			info->_charaId = info->_charaId;
		}
		else {
			info->_charaId = 1056;
			info->_clothId = 105601;
			info->_headId = 0;
		}
		*/

		info->_charaId = 1019;
		info->_clothId = 901019;
		info->_headId = 0;


		printf("Data is %p \n", info->_characterType);
		printf("Data is %p \n", info->_charaIndex);
		printf("Data is %p \n", info->_charaId);
		printf("Data is %p \n", info->_clothId);
		printf("Data is %p \n", info->_headId);
		printf("Data is %p \n", info->_zekkenNo);
		printf("Data is %p \n", info->OverrideClothCategory);
		printf("Data is %p \n", info->IsUseDressDataHeadModelSubId);




		void* ret = reinterpret_cast<decltype(user_hook)*>(user_orig)(_this, info);

		//spring_hook(ret, 100);

		printf("User End! \n");

		return ret;

	}

	void* limit_orig = nullptr;

	void limit_hook(void* _this, int cardId, int charaId, int dressId, int controllerType, int zekken = 0, int mobId = 0, int backDancerColorId = -1, int headId = 0, bool isUseDressDataHeadModelSubId = true)
	{
		printf("Something Pass Limit! \n");

		//charaId = 1024;
		//dressId = 102401;

		printf("Data is %p \n", cardId);
		printf("Data is %p \n", charaId);
		printf("Data is %p \n", dressId);
		printf("Data is %p \n", controllerType);
		printf("Data is %p \n", zekken);
		printf("Data is %p \n", mobId);
		printf("Data is %p \n", backDancerColorId);
		printf("Data is %p \n", headId);
		printf("Data is %p \n", isUseDressDataHeadModelSubId);

		reinterpret_cast<decltype(limit_hook)*>(limit_orig)(_this, cardId, charaId, dressId, controllerType, zekken, mobId, backDancerColorId, headId, isUseDressDataHeadModelSubId);

		printf("Limit End! \n");

		return;

	}

	void* player_orig = nullptr;

	void player_hook(void* _this, umastring* path, void* parent)
	{
		printf("Something Pass Player \n");

		reinterpret_cast<decltype(player_hook)*>(player_orig)(_this, path, parent);

		printf("Player End! \n");

		return;

	}

	void* onplayer_orig = nullptr;

	bool onplayer_hook(void* _this, umastring* loadPath, void* parent, void* camera, umastring* preInstantiateKey, int requireType = 0, int cuttIndex = 0)
	{
		printf("Something Pass Onplayer! \n");

		bool ret = reinterpret_cast<decltype(onplayer_hook)*>(onplayer_orig)(_this, loadPath, parent, camera, preInstantiateKey, requireType, cuttIndex);

		printf("Onplayer End! \n");

		return ret;

	}

	void* fps_orig = nullptr;

	void fps_hook(int value)
	{
		//printf("Something Pass FPS! FPS is %d\n", value);

		reinterpret_cast<decltype(fps_hook)*>(fps_orig)(global_fps);

		return;

	}

	float g_aspect_ratio = 16.f / 9.f;

	Resolution_t* (*get_resolution)(Resolution_t* buffer);

	void get_resolution_stub(Resolution_t* r)
	{
		*r = *get_resolution(r);

		int width = min(r->height, r->width) * g_aspect_ratio;
		if (r->width > r->height)
			r->width = width;
		else
			r->height = width;
	}

	bool (*is_virt)() = nullptr;

	void* res_orig = nullptr;

	void res_hook(int width, int height, bool fullscreen)
	{
		Resolution_t r;
		r = *get_resolution(&r);

		bool need_fullscreen = false;

		if (is_virt() && r.width / static_cast<double>(r.height) == (9.0 / 16.0))
			need_fullscreen = true;
		else if (!is_virt() && r.width / static_cast<double>(r.height) == (16.0 / 9.0))
			need_fullscreen = true;

		printf("width is %d, height is %d \n", width, height);

		width = 528;
		height = 940;

		printf("r.width is %d, r.height is %d \n", r.width, r.height);

		return reinterpret_cast<decltype(res_hook)*>(res_orig)(
			need_fullscreen ? r.width : width, need_fullscreen ? r.height : height, need_fullscreen
			);
	}
	/*
	void adjust_size()
	{
		thread([]() {
			auto tr = il2cpp_thread_attach(il2cpp_domain_get());

			Resolution_t r;
			get_resolution_stub(&r);

			auto target_height = r.height - 100;

			res_hook(target_height * 0.5625f, target_height, false);

			il2cpp_thread_detach(tr);
			}).detach();
	}


	void* getlist_orig = nullptr;

	int getlist_hook(void* _this)
	{

		int ret = reinterpret_cast<decltype(getlist_hook)*>(getlist_orig)(_this);

		return ret;

	}


	void* ratio_orig = nullptr;

	float ratio_hook()
	{
		printf("Something Pass Ratio! \n");

		float ret = reinterpret_cast<decltype(ratio_hook)*>(ratio_orig)();

		printf("Ratio is %f \n", ret);

		return ret;

	}

	void* scale_orig = nullptr;

	bool scale_hook()
	{
		printf("Something Pass Scale! \n");

		bool ret = reinterpret_cast<decltype(scale_hook)*>(scale_orig)();

		printf("Scale is %d \n", ret);

		return ret;

	}
	*/
	/*
	void* get_virt_size_orig = nullptr;
	Vector3_t* get_virt_size_hook(Vector3_t* pVec3, int width, int height)
	{
		auto size = reinterpret_cast<decltype(get_virt_size_hook)*>(get_virt_size_orig)(pVec3, width, height);

		printf("Something Pass Virt ! \n");
		printf("Height is %d, Width is %d \n", height, width);


		height = width * g_aspect_ratio;

		size->x = width;
		size->y = height;
		size->z = g_aspect_ratio;

		return size;
	}

	void* get_hori_size_orig = nullptr;
	Vector3_t* get_hori_size_hook(Vector3_t* pVec3, int width, int height)
	{
		auto size = reinterpret_cast<decltype(get_hori_size_hook)*>(get_hori_size_orig)(pVec3, width, height);

		printf("Something Pass Hori ! \n");
		printf("Height is %d, Width is %d \n", height, width);

		width = height * g_aspect_ratio;

		size->x = width;
		size->y = height;
		size->z = g_aspect_ratio;

		return size;
	}

	void* gallop_get_screenheight_orig;
	int gallop_get_screenheight_hook()
	{
		Resolution_t res;
		get_resolution_stub(&res);

		int w = max(res.width, res.height), h = min(res.width, res.height);

		printf("Something pass Height!!! \n");
		printf("Height is %d, Width is %d \n", h, w);

		//h = 1920;
		//w = 1080;
		//w = 10;

		return is_virt() ? w : h;
	}

	void* gallop_get_screenwidth_orig;
	int gallop_get_screenwidth_hook()
	{
		Resolution_t res;
		get_resolution_stub(&res);

		int w = max(res.width, res.height), h = min(res.width, res.height);

		return is_virt() ? h : w;
	}



	int last_height = 0, last_width = 0;


	void* wnd_orig = nullptr;

	LRESULT wnd_hook(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{


		if (uMsg == WM_SIZING)
		{
			printf("Something Pass WND!!!!! AND SIZING !!!!\n");

			RECT* rect = reinterpret_cast<RECT*>(lParam);

			float ratio = is_virt() ? 1.f / g_aspect_ratio : g_aspect_ratio;
			float height = rect->bottom - rect->top;
			float width = rect->right - rect->left;

			float new_ratio = width / height;

			if (new_ratio > ratio&& height >= last_height || width < last_width)
				height = width / ratio;
			else if (new_ratio < ratio && width >= last_width || height < last_height)
				width = height * ratio;

			switch (wParam)
			{
			case WMSZ_TOP:
			case WMSZ_TOPLEFT:
			case WMSZ_TOPRIGHT:
				rect->top = rect->bottom - height;
				break;
			default:
				rect->bottom = rect->top + height;
				break;
			}

			switch (wParam)
			{
			case WMSZ_LEFT:
			case WMSZ_TOPLEFT:
			case WMSZ_BOTTOMLEFT:
				rect->left = rect->right - width;
				break;
			default:
				rect->right = rect->left + width;
				break;
			}

			last_height = height;
			last_width = width;

			return TRUE;
		}

		return reinterpret_cast<decltype(wnd_hook)*>(wnd_orig)(hWnd, uMsg, wParam, lParam);

	}
	*/

	/*


	void* motion_orig = nullptr;

	void motion_hook(void* _this, int charaIndex, float currentTime, int targetFps, void* updateInfo)
	{

		reinterpret_cast<decltype(motion_hook)*>(motion_orig)(_this, charaIndex, currentTime, targetFps, updateInfo);

		if (charaIndex == 0) {
			printf("something happen at %d, time is %f, Fps is %d \n", charaIndex, currentTime, targetFps);
		}

		return;

	}

	

	void* index_orig = nullptr;

	int index_hook(void* _this)
	{

		int ret = reinterpret_cast<decltype(index_hook)*>(index_orig)(_this);

		return ret;

	}


	void* liveik_orig = nullptr;

	void liveik_hook(void* _this, LiveTimelineWorkSheet* sheet, int currentFrame)
	{

		//int index = index_hook(_this);

		if (first == true) {
			first = false;
		}

		printf("Motion list address is %p \n", sheet->charaMotSeqList);
		int count = getlist_hook(sheet->monitorControlList);
		printf("Motion list length is %d \n", count);

		reinterpret_cast<decltype(liveik_hook)*>(liveik_orig)(_this, sheet, currentFrame);

		printf("frame is %d \n", currentFrame);




		if (index == 0) {
			printf("index in %d \n", index);

			printf("something happen at %p \n", ret);

			Vector3 position = transform_hook(ret);

			printf("position is %f, %f, %f \n", position.x, position.y, position.z);
		}


		return;

	}
	*/

	void* LZ4_decompress_safe_ext_orig = nullptr;

	int LZ4_decompress_safe_ext_hook(
		char* src,
		char* dst,
		int compressedSize,
		int dstCapacity)
	{
		int ret = reinterpret_cast<decltype(LZ4_decompress_safe_ext_hook)*>(LZ4_decompress_safe_ext_orig)(
			src, dst, compressedSize, dstCapacity);
		printf("Start\n");



		//解包代码更改
		std::vector<char> buffer(dst, dst + ret);
		ojson s = msgpack::decode_msgpack<ojson>(buffer);
		std::ostringstream os;
		os << pretty_print(s);
		njson j = njson::parse(os.str());


		//封包代码更改
		std::vector<uint8_t> new_buffer;
		ojson tmp = ojson::parse(j.dump());
		msgpack::encode_msgpack(tmp, new_buffer);

		char* new_dst = reinterpret_cast<char*>(&new_buffer[0]);
		memset(dst, 0, dstCapacity);
		memcpy(dst, new_dst, new_buffer.size());
		ret = new_buffer.size();

		//原解包代码
		/*
		printf("Start! \n");
		std::vector<char> buffer(dst, dst + ret);
		json j = json::from_msgpack(buffer);
		*/

		//原修改已有角色代码
		/*
		if (j["data"].contains("common_define")) {
			printf("Info Get! \n");
			if (j["data"]["home_position_info"]["position1_chara_id"] == 1024) {
				printf("It is strange! \n");
			}
			j["data"]["card_list"][1]["card_id"] = 103901;
			j["data"]["card_list"][2]["card_id"] = 105801;
			j["data"]["card_list"][3]["card_id"] = 105901;
			j["data"]["card_list"][4]["card_id"] = 106001;
			j["data"]["card_list"][5]["card_id"] = 106101;
			j["data"]["card_list"][6]["card_id"] = 106901;
			j["data"]["card_list"][7]["card_id"] = 104002;
			j["data"]["card_list"][8]["card_id"] = 104101;
			j["data"]["card_list"][9]["card_id"] = 104501;
			j["data"]["card_list"][10]["card_id"] = 104502;
			j["data"]["card_list"][11]["card_id"] = 104601;
			j["data"]["card_list"][12]["card_id"] = 104801;
			j["data"]["card_list"][13]["card_id"] = 105001;
			j["data"]["card_list"][14]["card_id"] = 105201;
			j["data"]["card_list"][15]["card_id"] = 105202;
			j["data"]["card_list"][16]["card_id"] = 105601;
		}
		*/

		//原封包代码
		/*
		std::vector<uint8_t> new_buffer = json::to_msgpack(j);
		*/

		auto out_path = std::string("CarrotJuicer\\").append(current_time()).append("R.msgpack");
		write_file(out_path, dst, ret);
		printf("wrote response to %s\n", out_path.c_str());

		std::string data(dst, ret);
		responses::print_response_additional_info(data);


		printf("Return!\n");

		return ret;
	}

	void* LZ4_compress_default_ext_orig = nullptr;

	int LZ4_compress_default_ext_hook(
		char* src,
		char* dst,
		int srcSize,
		int dstCapacity)
	{
		//解包代码更改
		std::vector<char> buffer(src + 170, src + srcSize);
		ojson s = msgpack::decode_msgpack<ojson>(buffer);
		std::ostringstream os;
		os << pretty_print(s);
		njson j = njson::parse(os.str());

		if (j.contains("live_theater_save_info")) {
			for (int i = 0; i < j["live_theater_save_info"]["member_info_array"].size(); i++) {
				j["live_theater_save_info"]["member_info_array"][i]["chara_id"] = 0;
				j["live_theater_save_info"]["member_info_array"][i]["mob_id"] = 8590 + i;
				j["live_theater_save_info"]["member_info_array"][i]["dress_id"] = 7;
			}
			//封包代码更改
			std::vector<uint8_t> new_buffer;
			ojson tmp = ojson::parse(j.dump());
			msgpack::encode_msgpack(tmp, new_buffer);

			char* new_src = reinterpret_cast<char*>(&new_buffer[0]);
			memset(src + 170, 0, srcSize - 170);
			memcpy(src + 170, new_src, new_buffer.size());

			srcSize = new_buffer.size() + 170;

		}

		int ret = reinterpret_cast<decltype(LZ4_compress_default_ext_hook)*>(LZ4_compress_default_ext_orig)(
			src, dst, srcSize, dstCapacity);

		auto out_path = std::string("CarrotJuicer\\").append(current_time()).append("Q.msgpack");
		write_file(out_path, src + 170, srcSize - 170);
		//printf("wrote request to %s\n", out_path.c_str());



		return ret;
	}




	void bootstrap_carrot_juicer()
	{
		std::filesystem::create_directory("CarrotJuicer");

		auto libnative_module = GetModuleHandle(L"libnative.dll");
		printf("libnative.dll at %p\n", libnative_module);
		if (libnative_module == nullptr)
		{
			return;
		}

		ifstream OpenFile("fps.txt");
		if (!OpenFile.fail()) {
			OpenFile.getline(file_fps, 100);
			global_fps = atoi(file_fps);
			printf("FPS is %d\n", global_fps);
		}
		else {
			printf("Missing fps.txt\n");
		}

		auto LZ4_decompress_safe_ext_ptr = GetProcAddress(libnative_module, "LZ4_decompress_safe_ext");
		printf("LZ4_decompress_safe_ext at %p\n", LZ4_decompress_safe_ext_ptr);
		if (LZ4_decompress_safe_ext_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(LZ4_decompress_safe_ext_ptr, LZ4_decompress_safe_ext_hook, &LZ4_decompress_safe_ext_orig);
		MH_EnableHook(LZ4_decompress_safe_ext_ptr);

		auto LZ4_compress_default_ext_ptr = GetProcAddress(libnative_module, "LZ4_compress_default_ext");
		printf("LZ4_compress_default_ext at %p\n", LZ4_compress_default_ext_ptr);
		if (LZ4_compress_default_ext_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(LZ4_compress_default_ext_ptr, LZ4_compress_default_ext_hook, &LZ4_compress_default_ext_orig);
		MH_EnableHook(LZ4_compress_default_ext_ptr);

		printf("Trying to patch GameAssembly.dll...\n");

		auto il2cpp_module = GetModuleHandle(L"GameAssembly.dll");

		il2cpp_symbols::init(il2cpp_module);

		auto wndproc_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"StandaloneWindowResize", "WndProc", 4
		);

		printf("wndproc_addr at %p\n", wndproc_addr);
		/*
		auto race_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"RaceResultCutInHelper", "LoadBodyMotion", 6
		);

		printf("race_addr at %p\n", race_addr);

		MH_CreateHook((LPVOID)race_addr, race_hook, &race_orig);
		MH_EnableHook((LPVOID)race_addr);


		auto cutin_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetCharacterRaceResultMotionPath", 6
		);

		printf("cutin_addr at %p\n", cutin_addr);

		MH_CreateHook((LPVOID)cutin_addr, cutin_hook, &cutin_orig);
		MH_EnableHook((LPVOID)cutin_addr);



		auto camera_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetRaceResultCameraPath", 6
		);

		printf("camera_addr at %p\n", camera_addr);

		MH_CreateHook((LPVOID)camera_addr, camera_hook, &camera_orig);
		MH_EnableHook((LPVOID)camera_addr);

		auto facial_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetCharacterRaceResultFacialPath", 6
		);

		printf("facial_addr at %p\n", facial_addr);

		MH_CreateHook((LPVOID)facial_addr, facial_hook, &facial_orig);
		MH_EnableHook((LPVOID)facial_addr);

		auto ear_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetCharacterRaceResultEarPath", 6
		);

		printf("ear_addr at %p\n", ear_addr);

		MH_CreateHook((LPVOID)ear_addr, ear_hook, &ear_orig);
		MH_EnableHook((LPVOID)ear_addr);

		auto music_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetRaceResultCuttPath", 6
		);

		printf("music_addr at %p\n", music_addr);

		MH_CreateHook((LPVOID)music_addr, music_hook, &music_orig);
		MH_EnableHook((LPVOID)music_addr);

		auto sheet_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"AudioManager", "PlaySystemVoice_RaceResult", 6
		);

		printf("sheet_addr at %p\n", sheet_addr);

		MH_CreateHook((LPVOID)sheet_addr, sheet_hook, &sheet_orig);
		MH_EnableHook((LPVOID)sheet_addr);

		auto sound_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetRaceResultCuttSeName", 1
		);

		printf("sound_addr at %p\n", sound_addr);

		MH_CreateHook((LPVOID)sound_addr, sound_hook, &sound_orig);
		MH_EnableHook((LPVOID)sound_addr);
		*/
		/*
		auto model_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"CharacterBuildInfo", "CreateModel", 1
		);

		printf("model_addr at %p\n", model_addr);

		MH_CreateHook((LPVOID)model_addr, model_hook, &model_orig);
		MH_EnableHook((LPVOID)model_addr);

		auto object_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"RaceResultCutInHelper", "OnPreSetupCharacterModel", 1
		);

		printf("object_addr at %p\n", object_addr);

		MH_CreateHook((LPVOID)object_addr, object_hook, &object_orig);
		MH_EnableHook((LPVOID)object_addr);

		auto info_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.CutIn",
			"CutInCharacter", "EntryModel", 2
		);

		printf("info_addr at %p\n", info_addr);

		MH_CreateHook((LPVOID)info_addr, info_hook, &info_orig);
		MH_EnableHook((LPVOID)info_addr);

		auto create_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"CutInHelper", "OnCreateCharacterModel", 1
		);

		printf("create_addr at %p\n", create_addr);

		MH_CreateHook((LPVOID)create_addr, create_hook, &create_orig);
		MH_EnableHook((LPVOID)create_addr);

		auto chara_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.CutIn.Cutt",
			"TimelineCharacter", "CreateCharacterModel", 1
		);

		printf("chara_addr at %p\n", chara_addr);

		MH_CreateHook((LPVOID)chara_addr, chara_hook, &chara_orig);
		MH_EnableHook((LPVOID)chara_addr);

		auto setup_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.CutIn",
			"CutInCharacter", "SetupModelComponent", 1
		);

		printf("setup_addr at %p\n", setup_addr);

		MH_CreateHook((LPVOID)setup_addr, setup_hook, &setup_orig);
		MH_EnableHook((LPVOID)setup_addr);

		auto backup_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.CutIn",
			"CutInCharacter", "BackupModelPosture", 0
		);

		printf("backup_addr at %p\n", backup_addr);

		MH_CreateHook((LPVOID)backup_addr, backup_hook, &backup_orig);
		MH_EnableHook((LPVOID)backup_addr);

		auto control_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"RaceResultCutInHelper", "GetModelController", 1
		);

		printf("control_addr at %p\n", control_addr);

		MH_CreateHook((LPVOID)control_addr, control_hook, &control_orig);
		MH_EnableHook((LPVOID)control_addr);

		auto controlarray_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ModelLoader", "AddModelController", 2
		);

		printf("controlarray_addr at %p\n", controlarray_addr);

		MH_CreateHook((LPVOID)controlarray_addr, controlarray_hook, &controlarray_orig);
		MH_EnableHook((LPVOID)controlarray_addr);

		auto build_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ModelLoader", "BuildCustomModelSetup", 7
		);

		printf("build_addr at %p\n", build_addr);

		MH_CreateHook((LPVOID)build_addr, build_hook, &build_orig);
		MH_EnableHook((LPVOID)build_addr);

		auto tobuild_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"RaceUtil", "CreateCharacterBuildInfo", 4
		);

		printf("tobuild_addr at %p\n", tobuild_addr);

		MH_CreateHook((LPVOID)tobuild_addr, tobuild_hook, &tobuild_orig);
		MH_EnableHook((LPVOID)tobuild_addr);
		*/
		/*
		auto gacha_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"RaceSkillCutInHelper", "InitForGacha", 1
		);

		printf("gacha_addr at %p\n", gacha_addr);

		MH_CreateHook((LPVOID)gacha_addr, gacha_hook, &gacha_orig);
		MH_EnableHook((LPVOID)gacha_addr);
		*/

		/*
		auto gachacutin_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"<InitializeView>d__46", "MoveNext", 0, 3647
		);

		printf("gachacutin_addr at %p\n", gachacutin_addr);

		MH_CreateHook((LPVOID)gachacutin_addr, gachacutin_hook, &gachacutin_orig);
		MH_EnableHook((LPVOID)gachacutin_addr);

		auto gachachara_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"<InitializeView>d__46", "MoveNext", 0, 3648
		);

		printf("gachachara_addr at %p\n", gachachara_addr);

		MH_CreateHook((LPVOID)gachachara_addr, gachachara_hook, &gachachara_orig);
		MH_EnableHook((LPVOID)gachachara_addr);

		auto holder_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"GachaCharaHolder", "CreateAdd", 8
		);

		printf("holder_addr at %p\n", holder_addr);

		MH_CreateHook((LPVOID)holder_addr, holder_hook, &holder_orig);
		MH_EnableHook((LPVOID)holder_addr);

		auto pre_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"RaceSkillCutInHelper", "PreInstantiateForGacha", 0
		);

		printf("pre_addr at %p\n", pre_addr);

		MH_CreateHook((LPVOID)pre_addr, pre_hook, &pre_orig);
		MH_EnableHook((LPVOID)pre_addr);

		auto icon_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ResourcePath", "GetSkillCutInTimelineControlPath", 1
		);

		printf("icon_addr at %p\n", icon_addr);

		MH_CreateHook((LPVOID)icon_addr, icon_hook, &icon_orig);
		MH_EnableHook((LPVOID)icon_addr);

		auto play_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"GachaCutInR3SkillCutIn", "Play", 0
		);

		printf("play_addr at %p\n", play_addr);

		MH_CreateHook((LPVOID)play_addr, play_hook, &play_orig);
		MH_EnableHook((LPVOID)play_addr);

		auto clist_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"GachaMainViewController", "CreateCutInInfoListForChara", 0
		);

		printf("clist_addr at %p\n", clist_addr);

		MH_CreateHook((LPVOID)clist_addr, clist_hook, &clist_orig);
		MH_EnableHook((LPVOID)clist_addr);

		*/
		/*
		auto user_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"CutInOwner", "GetUserModel", 1, 3646
		);

		printf("user_addr at %p\n", user_addr);

		MH_CreateHook((LPVOID)user_addr, user_hook, &user_orig);
		MH_EnableHook((LPVOID)user_addr);
		*/
		/*
		auto limit_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"EditableCharacterBuildInfo", ".ctor", 9
		);

		printf("limit_addr at %p\n", limit_addr);

		MH_CreateHook((LPVOID)limit_addr, limit_hook, &limit_orig);
		MH_EnableHook((LPVOID)limit_addr);

		auto player_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"CutInHelper", "Play", 2
		);

		printf("player_addr at %p\n", player_addr);

		MH_CreateHook((LPVOID)player_addr, player_hook, &player_orig);
		MH_EnableHook((LPVOID)player_addr);

		auto onplayer_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"CutInHelper", "InstantiateTimeline", 6
		);

		printf("onplayer_addr at %p\n", onplayer_addr);

		MH_CreateHook((LPVOID)onplayer_addr, onplayer_hook, &onplayer_orig);
		MH_EnableHook((LPVOID)onplayer_addr);

		auto spring_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"ModelController", "SetCySpringRate", 1
		);

		printf("spring_addr at %p\n", spring_addr);

		MH_CreateHook((LPVOID)spring_addr, spring_hook, &spring_orig);
		MH_EnableHook((LPVOID)spring_addr);
		*/
		auto fps_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Application", "set_targetFrameRate", 1
		);

		printf("fps_addr at %p\n", fps_addr);

		MH_CreateHook((LPVOID)fps_addr, fps_hook, &fps_orig);
		MH_EnableHook((LPVOID)fps_addr);
		/*
		auto res_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Screen", "SetResolution", 3
		);

		printf("res_addr at %p\n", res_addr);

		MH_CreateHook((LPVOID)res_addr, res_hook, &res_orig);
		MH_EnableHook((LPVOID)res_addr);

		is_virt = reinterpret_cast<bool(*)()>(
			il2cpp_symbols::get_method_pointer(
				"umamusume.dll", "Gallop",
				"StandaloneWindowResize", "get_IsVirt", 0
			));

		get_resolution = reinterpret_cast<Resolution_t * (*)(Resolution_t*)>(
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.CoreModule.dll", "UnityEngine",
				"Screen", "get_currentResolution", 0
			)
			);
		*/
		//adjust_size();



		/*
		auto get_virt_size_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"StandaloneWindowResize", "getOptimizedWindowSizeVirt", 2
		);

		printf("get_virt_size_addr at %p\n", get_virt_size_addr);

		MH_CreateHook((LPVOID)get_virt_size_addr, get_virt_size_hook, &get_virt_size_orig);
		MH_EnableHook((LPVOID)get_virt_size_addr);

		auto get_hori_size_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"StandaloneWindowResize", "getOptimizedWindowSizeHori", 2
		);

		printf("get_hori_size_addr at %p\n", get_hori_size_addr);

		MH_CreateHook((LPVOID)get_hori_size_addr, get_hori_size_hook, &get_hori_size_orig);
		MH_EnableHook((LPVOID)get_hori_size_addr);

		auto gallop_get_screenheight_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"Screen", "get_Height", 0
		);

		printf("gallop_get_screenheight_addr at %p\n", gallop_get_screenheight_addr);

		MH_CreateHook((LPVOID)gallop_get_screenheight_addr, gallop_get_screenheight_hook, &gallop_get_screenheight_orig);
		MH_EnableHook((LPVOID)gallop_get_screenheight_addr);

		auto gallop_get_screenwidth_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"Screen", "get_Width", 0
		);

		printf("gallop_get_screenwidth_addr at %p\n", gallop_get_screenwidth_addr);

		MH_CreateHook((LPVOID)gallop_get_screenwidth_addr, gallop_get_screenwidth_hook, &gallop_get_screenwidth_orig);
		MH_EnableHook((LPVOID)gallop_get_screenwidth_addr);


		*/
		/*
		auto ratio_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"StandaloneWindowResize", "get_AspectRatio", 0
		);

		printf("ratio_addr at %p\n", ratio_addr);

		MH_CreateHook((LPVOID)ratio_addr, ratio_hook, &ratio_orig);
		MH_EnableHook((LPVOID)ratio_addr);

		auto scale_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"StandaloneWindowResize", "get_IsPreventReShape", 0
		);

		printf("scale_addr at %p\n", scale_addr);

		MH_CreateHook((LPVOID)scale_addr, scale_hook, &scale_orig);
		MH_EnableHook((LPVOID)scale_addr);


		auto wnd_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop",
			"StandaloneWindowResize", "WndProc", 4
		);

		printf("wnd_addr at %p\n", wnd_addr);

		MH_CreateHook((LPVOID)wnd_addr, wnd_hook, &wnd_orig);
		MH_EnableHook((LPVOID)wnd_addr);

		is_virt = reinterpret_cast<bool(*)()>(
			il2cpp_symbols::get_method_pointer(
				"umamusume.dll", "Gallop",
				"StandaloneWindowResize", "get_IsVirt", 0
			));
		*/

		/*
		auto liveik_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.Live.Cutt",
			"LiveTimelineControl", "AlterUpdate_CharaMotionSequence", 2
		);

		printf("liveik_addr at %p\n", liveik_addr);

		MH_CreateHook((LPVOID)liveik_addr, liveik_hook, &liveik_orig);
		MH_EnableHook((LPVOID)liveik_addr);


		auto index_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.Live",
			"CharacterObject", "get_CharacterDataIndex", 0
		);

		printf("index_addr at %p\n", index_addr);

		MH_CreateHook((LPVOID)index_addr, index_hook, &index_orig);
		MH_EnableHook((LPVOID)index_addr);

		auto motion_addr = il2cpp_symbols::get_method_pointer(
			"umamusume.dll", "Gallop.Live",
			"LiveFaceController", "AlterUpdateFacialNew", 4
		);

		printf("motion_addr at %p\n", index_addr);

		MH_CreateHook((LPVOID)motion_addr, motion_hook, &motion_orig);
		MH_EnableHook((LPVOID)motion_addr);

		auto list_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System.Collections.Generic",
			"List`1", "get_Capacity", 0
		);

		printf("list_addr at %p\n", list_addr);

		MH_CreateHook((LPVOID)list_addr, list_hook, &list_orig);
		MH_EnableHook((LPVOID)list_addr);

		auto getlist_addr = (LPVOID)((size_t)il2cpp_symbols::get_method_pointer_base(
			"umamusume.dll", "Gallop.Live.Cutt",
			"LiveTimelineControl", "AlterUpdate_CharaMotionSequence", 2, 0x34B740
		)+0x308A40);

		printf("getlist_addr at %p\n", getlist_addr);

		MH_CreateHook((LPVOID)getlist_addr, getlist_hook, &getlist_orig);
		MH_EnableHook((LPVOID)getlist_addr);

		size_t field_offset = il2cpp_symbols::get_field_offset(
			"umamusume.dll", "Gallop.Live.Cutt",
			"LiveTimelineWorkSheet", "effectList"
		);

		printf("field offset is %p\n", field_offset);
		*/


		//开始尝试获取Object

		auto object_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Object", "FindObjectsOfType", 2
		);

		printf("object_addr at %p\n", object_addr);

		MH_CreateHook((LPVOID)object_addr, object_hook, &object_orig);
		MH_EnableHook((LPVOID)object_addr);

		//开始尝试获取Type

		auto type_addr = il2cpp_symbols::get_method_pointer(
			"Plugins.dll", "RuntimeInspectorNamespace",
			"RuntimeInspectorUtils", "GetType", 1
		);

		printf("type_addr at %p\n", type_addr);

		MH_CreateHook((LPVOID)type_addr, type_hook, &type_orig);
		MH_EnableHook((LPVOID)type_addr);

		//获取获得Array内部数据的方法

		auto arrayindex_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System",
			"Array", "GetValue", 1
		);

		printf("arrayindex_addr at %p\n", arrayindex_addr);

		MH_CreateHook((LPVOID)arrayindex_addr, arrayindex_hook, &arrayindex_orig);
		MH_EnableHook((LPVOID)arrayindex_addr);

		//获取获得Object名称的方法

		auto objectname_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Object", "ToString", 0
		);

		printf("objectname_addr at %p\n", objectname_addr);

		MH_CreateHook((LPVOID)objectname_addr, objectname_hook, &objectname_orig);
		MH_EnableHook((LPVOID)objectname_addr);

		//将字符串转为字节数组

		auto s2c_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System",
			"String", "ToCharArray", 0
		);

		printf("s2b_addr at %p\n", s2c_addr);

		MH_CreateHook((LPVOID)s2c_addr, s2c_hook, &s2c_orig);
		MH_EnableHook((LPVOID)s2c_addr);

		//获取父节点

		auto parent_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Transform", "GetParent", 0
		);

		printf("parent_addr at %p\n", parent_addr);

		MH_CreateHook((LPVOID)parent_addr, parent_hook, &parent_orig);
		MH_EnableHook((LPVOID)parent_addr);

		//从Transform获取GameObject

		auto gameobject_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Component", "get_gameObject", 0
		);

		printf("gameobject_addr at %p\n", gameobject_addr);

		MH_CreateHook((LPVOID)gameobject_addr, gameobject_hook, &gameobject_orig);
		MH_EnableHook((LPVOID)gameobject_addr);

		//从GameObject获取Scene---貌似无法获得真正的Scene地址

		auto scene_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"GameObject", "get_scene", 0
		);

		printf("scene_addr at %p\n", scene_addr);

		MH_CreateHook((LPVOID)scene_addr, scene_hook, &scene_orig);
		MH_EnableHook((LPVOID)scene_addr);

		//从Scene获取名字

		auto scenename_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine.SceneManagement",
			"Scene", "get_name", 0
		);

		printf("scenename_addr at %p\n", scenename_addr);

		MH_CreateHook((LPVOID)scenename_addr, scenename_hook, &scenename_orig);
		MH_EnableHook((LPVOID)scenename_addr);

		//获取激活的Scene---貌似无法获得真正的Scene地址

		auto activescene_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine.SceneManagement",
			"SceneManager", "GetActiveScene", 0
		);

		printf("activescene_addr at %p\n", activescene_addr);

		MH_CreateHook((LPVOID)activescene_addr, activescene_hook, &activescene_orig);
		MH_EnableHook((LPVOID)activescene_addr);

		//获取Transform的子节点个数

		auto childcount_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Transform", "get_childCount", 0
		);

		printf("childcount_addr at %p\n", childcount_addr);

		MH_CreateHook((LPVOID)childcount_addr, childcount_hook, &childcount_orig);
		MH_EnableHook((LPVOID)childcount_addr);

		//根据index获取child的子节点
		auto child_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Transform", "GetChild", 1
		);

		printf("child_addr at %p\n", child_addr);

		MH_CreateHook((LPVOID)child_addr, child_hook, &child_orig);
		MH_EnableHook((LPVOID)child_addr);

		//获取object激活状态（如果父级不激活，显示为未激活）
		auto hierarchyActive_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"GameObject", "get_activeInHierarchy", 0
		);

		printf("hierarchyActive_addr at %p\n", hierarchyActive_addr);

		MH_CreateHook((LPVOID)hierarchyActive_addr, hierarchyActive_hook, &hierarchyActive_orig);
		MH_EnableHook((LPVOID)hierarchyActive_addr);

		//获取object激活状态（真实激活状态）
		auto activeSelf_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"GameObject", "get_activeSelf", 0
		);

		printf("activeSelf_addr at %p\n", activeSelf_addr);

		MH_CreateHook((LPVOID)activeSelf_addr, activeSelf_hook, &activeSelf_orig);
		MH_EnableHook((LPVOID)activeSelf_addr);

		//设置激活状态（真实激活状态）
		auto setActive_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"GameObject", "SetActive", 1
		);

		printf("setActive_addr at %p\n", setActive_addr);

		MH_CreateHook((LPVOID)setActive_addr, setActive_hook, &setActive_orig);
		MH_EnableHook((LPVOID)setActive_addr);

		//从Transform获取本地Position
		auto position_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Transform", "get_localPosition", 0
		);

		printf("position_addr at %p\n", position_addr);

		MH_CreateHook((LPVOID)position_addr, position_hook, &position_orig);
		MH_EnableHook((LPVOID)position_addr);

		//从Object获取Instance
		auto obj_inst_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Object", "GetInstanceID", 0
		);

		printf("obj_inst_addr at %p\n", obj_inst_addr);

		MH_CreateHook((LPVOID)obj_inst_addr, obj_inst_hook, &obj_inst_orig);
		MH_EnableHook((LPVOID)obj_inst_addr);

		//从Instance获取Object
		auto inst_obj_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Object", "FindObjectFromInstanceID", 1
		);

		printf("inst_obj_addr at %p\n", inst_obj_addr);

		MH_CreateHook((LPVOID)inst_obj_addr, inst_obj_hook, &inst_obj_orig);
		MH_EnableHook((LPVOID)inst_obj_addr);

		//从Transform获取本地欧拉旋转
		auto rotation_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Transform", "get_localEulerAngles", 0
		);

		printf("rotation_addr at %p\n", rotation_addr);

		MH_CreateHook((LPVOID)rotation_addr, rotation_hook, &rotation_orig);
		MH_EnableHook((LPVOID)rotation_addr);

		//从Transform获取本地缩放
		auto scale_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"Transform", "get_localScale", 0
		);

		printf("scale_addr at %p\n", scale_addr);

		MH_CreateHook((LPVOID)scale_addr, scale_hook, &scale_orig);
		MH_EnableHook((LPVOID)scale_addr);

		//通过反射获取Type(泛型Hook处理)

		auto reftype_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System.Reflection",
			"Assembly", "GetType", 1
		);

		printf("reftype_addr at %p\n", reftype_addr);

		MH_CreateHook((LPVOID)reftype_addr, reftype_hook, &reftype_orig);
		MH_EnableHook((LPVOID)reftype_addr);

		//加载该类型所在的Dll(泛型Hook处理)

		auto refload_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System.Reflection",
			"Assembly", "Load", 1
		);

		printf("refload_addr at %p\n", refload_addr);

		MH_CreateHook((LPVOID)refload_addr, refload_hook, &refload_orig);
		MH_EnableHook((LPVOID)refload_addr);

		//通过反射获取Method(泛型Hook处理)

		auto refmethod_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System",
			"Type", "GetMethod", 2
		);

		printf("refmethod_addr at %p\n", refmethod_addr);

		MH_CreateHook((LPVOID)refmethod_addr, refmethod_hook, &refmethod_orig);
		MH_EnableHook((LPVOID)refmethod_addr);

		//获取设置Array数据的方法

		auto arrayset_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System",
			"Array", "SetValue", 2
		);

		printf("arrayset_addr at %p\n", arrayset_addr);

		MH_CreateHook((LPVOID)arrayset_addr, arrayset_hook, &arrayset_orig);
		MH_EnableHook((LPVOID)arrayset_addr);

		//尝试创建新物体

		auto create_addr = il2cpp_symbols::get_method_pointer(
			"mscorlib.dll", "System.Reflection",
			"Assembly", "CreateInstance", 1
		);

		printf("create_addr at %p\n", create_addr);

		MH_CreateHook((LPVOID)create_addr, create_hook, &create_orig);
		MH_EnableHook((LPVOID)create_addr);

		//尝试获取Components

		auto components_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"GameObject", "GetComponentsInternal", 6
		);

		printf("components_addr at %p\n", components_addr);

		MH_CreateHook((LPVOID)components_addr, components_hook, &components_orig);
		MH_EnableHook((LPVOID)components_addr);


		//执行GUI程序
		thread([]() {
			auto tr = il2cpp_thread_attach(il2cpp_domain_get());

			printf("I am Running In Here!!!\n");
			imguiwindow();

			il2cpp_thread_detach(tr);
			}).detach();


	}

	void* load_library_w_orig = nullptr;

	HMODULE __stdcall load_library_w_hook(const wchar_t* path)
	{
		printf("Saw %ls\n", path);

		// GameAssembly.dll code must be loaded and decrypted while loading criware library
		if (path == L"cri_ware_unity.dll"s)
		{
			bootstrap_carrot_juicer();

			MH_DisableHook(LoadLibraryW);
			MH_RemoveHook(LoadLibraryW);

			return LoadLibraryW(path);
		}

		return reinterpret_cast<decltype(LoadLibraryW)*>(load_library_w_orig)(path);
	}
}

static flat_hash_map<void*, ObjectTree> ObjDic;
static vector<void*> rootObjList;
static bool show_info_window = false;
static void* selected_obj = 0;
static bool show_active_box = false;


//从名称中获取类型名
string getTypeName(string name) {
	int left = name.rfind('(') + 1;
	int right = name.rfind(')');

	return name.substr(left, right-left);
}

//这边是创建新物体以及直接使用方法的测试，不过暂时用不到
void* getGenericMethod(string dll, string reftype) {
	void* assembly = refload_hook((umastring*)il2cpp_symbols::get_string(dll.c_str()));
	printf("Get Assembly OK at %p\n", assembly);
	void* type = reftype_hook(assembly, (umastring*)il2cpp_symbols::get_string(reftype.c_str()));
	printf("Get Type OK at %p\n", type);
	void* _class = il2cpp_symbols::get_type_class(type);
	printf("Get Class OK at %p\n", _class);
	auto method = il2cpp_symbols::class_get_method(_class, "get_Capacity", 0);
	auto method_Add = il2cpp_symbols::class_get_method(_class, "Add", 1);
	printf("Create Method OK at %p\n", method);

	typedef int (*Method_ftn)(void*);
	typedef void (*Method_Add_ftn)(void*, int);

	void* obj = create_hook(assembly, (umastring*)il2cpp_symbols::get_string(reftype.c_str()));

	//((Method_Add_ftn)method_add)(obj, 1);

	int num = ((Method_ftn)method)(obj);

	printf("Number OK is %d\n", num);

	printf("Create Obj OK at %p\n", obj);
	
	
	return obj;
}

void refreashObject() {
	ObjDic = {};
	rootObjList = {};

	//有新的获取Type的方式了，不过暂时保留
	void* Component_type = type_hook((umastring*)il2cpp_symbols::get_string("UnityEngine.Component, UnityEngine"));


	void* Transform_type = type_hook((umastring*)il2cpp_symbols::get_string("UnityEngine.Transform, UnityEngine"));
	void* Object_list = object_hook(Transform_type, 1);
	int ObjLength = il2cpp_symbols::get_array_length(Object_list);
	for (int i = 0; i < ObjLength; i++) {
		void* Obj = arrayindex_hook(Object_list, i);
		void* gameObj = gameobject_hook(Obj);

		//void* new_list = getGenericMethod("mscorlib", "System.Collections.Generic.List`1[[UnityEngine.Object, UnityEngine]]");
		void* component = components_hook(gameObj, Component_type);
		int ComLength = il2cpp_symbols::get_array_length(component);
		
		vector<void*> components;
		for (int j = 0; j < ComLength; j++) {
			components.push_back(arrayindex_hook(component, j));
		}

		//printf("Get Array Success at %p\n", components);
		//printf("Array Size is %d\n", il2cpp_symbols::get_array_length(components));
		
		//void* new_list = getGenericMethod("mscorlib", "System.Object");
		//components_hook(gameObj, Component_type, new_list);
		//printf("At List Once!");

		vector<void*> children;
		int childCount = childcount_hook(Obj);
		for (int j = 0; j < childCount; j++) {
			children.push_back(child_hook(Obj, j));
		}


		ObjectTree node;
		node.name = UmaGetString(objectname_hook(gameObj));
		node.gameObj = gameObj;
		node.instanceID = obj_inst_hook(Obj);
		node.components = components;
		node.children = children;
		node.activeSelf = activeSelf_hook(gameObj);
		node.activeInHierarchy = hierarchyActive_hook(gameObj);


		ObjDic[Obj] = node;

		//获取根Obj
		void* ObjParent = parent_hook(Obj);


		if (!ObjParent) {
			rootObjList.push_back(Obj);
		}

	}

	//这边是Object测试，保留备用
	/*
	int objListLength = ObjList.size();

	for (int i = 0; i < ObjChildList.size(); i++) {
		for (int j = 0; j < ObjChildList[i].size(); j++) {
			int objIndex = find(ObjList.begin(), ObjList.end(), ObjChildList[i][j]) - ObjList.begin();
			if (objIndex == objListLength) {
				printf("Missing Child Object is %p\n", ObjChildList[i][j]);
			}
		}
	}

	for (int i = 0; i < ObjParentList.size(); i++) {
		int objIndex = find(ObjList.begin(), ObjList.end(), ObjParentList[i]) - ObjList.begin();
		if (objIndex == objListLength) {
			printf("Missing Parent Object is %p\n", ObjParentList[i]);
		}
	}
	*/
}


void objRecursion(void* currentObj, ImGuiTreeNodeFlags base_flags) {
	ImGuiTreeNodeFlags node_flags = base_flags;

	ObjectTree* currentNode = &ObjDic[currentObj];

	bool activeSelf = currentNode->activeSelf;
	bool activeInHierarchy = currentNode->activeInHierarchy;
	void* gameObj = currentNode->gameObj;

	ImGui::BeginDisabled(!show_active_box);
	ImGui::Checkbox(("##" + currentNode->name).c_str(), &activeSelf);
	ImGui::SameLine();

	if (activeSelf != currentNode->activeSelf) {
		printf("Something is Change! The Value is %d\n", activeSelf);
		setActive_hook(gameObj, activeSelf);
		currentNode->activeSelf = activeSelf;
		printf("Maybe GetObjDic manually is better?\n");
	}
	ImGui::EndDisabled();

	if (currentNode->children.size() != 0) {
		if (!activeInHierarchy) ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
		bool node_open = ImGui::TreeNodeEx(currentObj, node_flags, currentNode->name.c_str());
		if (!activeInHierarchy) ImGui::PopStyleColor();
		if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen()) {
			show_info_window = 1;
			selected_obj = currentObj;
		}
		if (node_open)
		{
			for (int index = 0; index < currentNode->children.size(); index++) {
				objRecursion(currentNode->children[index], base_flags);
			}
			ImGui::TreePop();
		}
	}
	else {
		node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen; // ImGuiTreeNodeFlags_Bullet
		if (!activeInHierarchy) ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
		ImGui::TreeNodeEx(currentObj, node_flags, currentNode->name.c_str());
		if (!activeInHierarchy) ImGui::PopStyleColor();
		if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen()) {
			show_info_window = 1;
			selected_obj = currentObj;
		}
	}
};

//显示组件
void show_components(void* currentObj) {
	ObjectTree* currentNode = &ObjDic[currentObj];
	vector<void*> components = currentNode->components;
	for (int i = 0; i < components.size(); i++) {
		if (ImGui::TreeNode(components[i], getTypeName(UmaGetString(objectname_hook(components[i]))).c_str())) {
			ImGui::TreePop();
		};
	}
}

//************************************************************************************************************
static ID3D11Device* g_pd3dDevice = NULL;
static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
static IDXGISwapChain* g_pSwapChain = NULL;
static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int imguiwindow()
{
	// Create application window
	//ImGui_ImplWin32_EnableDpiAwareness();

	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("UmaExplorer"), NULL };
	::RegisterClassEx(&wc);
	HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("UmaExplorer V0.05"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

	// Initialize Direct3D
	if (!CreateDeviceD3D(hwnd))
	{
		CleanupDeviceD3D();
		::UnregisterClass(wc.lpszClassName, wc.hInstance);
		return 1;
	}

	// Show the window
	::ShowWindow(hwnd, SW_SHOWDEFAULT);
	::UpdateWindow(hwnd);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
	// - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
	// - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
	// - Read 'docs/FONTS.md' for more instructions and details.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//IM_ASSERT(font != NULL);

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	bool show_obj_window = false;

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);



	// Main loop
	bool done = false;
	while (!done)
	{
		// Poll and handle messages (inputs, window resize, etc.)
		// See the WndProc() function below for our to dispatch events to the Win32 backend.
		MSG msg;
		while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done)
			break;

		// Start the Dear ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);
			ImGui::Checkbox("Obj Window", &show_obj_window);
			ImGui::Checkbox("Enable ActiveBox", &show_active_box);


			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("GetObjDic"))                           // Buttons return true when clicked (most widgets return true when edited/activated)
			{
				refreashObject();
				
				//getGenericMethod("mscorlib", "System.Collections.Generic.List`1[[UnityEngine.Component, UnityEngine]]");
				//getGenericMethod("mscorlib", "System.Int32");

				//数组测试成功，特此保留(疑点:Hook的按名字查找到底发生了什么)
				/*
				void* c_type = type_hook((umastring*)il2cpp_symbols::get_string("UnityEngine.Component, UnityEngine"));

				void* c_class = il2cpp_symbols::get_class("mscorlib.dll", "System", "Type");
				printf("Get Class OK at %p\n", c_class);
				void* c_array = il2cpp_symbols::new_array(c_class, 0);
				printf("Get Array OK at %p\n", c_array);
				
				int c_size = il2cpp_symbols::get_array_length(c_array);
				printf("Get Size OK is %d\n", c_size);
				
				printf("Obj OK at %p\n", c_type);
				arrayset_hook(c_array, c_type, 0);
				printf("Set Array OK\n");
				void* c_result = arrayindex_hook(c_array, 0);
				printf("Get Obj OK is %p\n", c_result);
				
				void* c_method = refmethod_hook(c_type, (umastring*)il2cpp_symbols::get_string("GetComponent"), c_array);
				printf("Get Method OK is %p\n", c_method);
				*/


			}



			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}

		// 3. Show another simple window.
		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		if (show_obj_window)
		{
			ImGui::Begin("Obj Window", &show_obj_window);

			//建立树状结构
			static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

			for (int i = 0; i < rootObjList.size(); i++)
			{

				void* currentObj = rootObjList[i];

				//设置一些东西
				ImGuiTreeNodeFlags node_flags = base_flags;

				objRecursion(currentObj, base_flags);
				/*
				if (ObjDic[currentObj].children.size() != 0) {
					bool node_open = ImGui::TreeNodeEx(currentObj, node_flags, ObjDic[currentObj].name.c_str());
					if (node_open)
					{
						ImGui::BulletText(to_string(ObjDic[currentObj].children.size()).c_str());
						ImGui::TreePop();
					}
				}
				else {
					node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen; // ImGuiTreeNodeFlags_Bullet
					ImGui::TreeNodeEx(currentObj, node_flags, ObjDic[currentObj].name.c_str());
				}
				*/
			}

			
			ImGui::End();
		}

		if (show_info_window) {
			if (inst_obj_hook(ObjDic[selected_obj].instanceID) == selected_obj) {
				ImGui::Begin("Info Window", &show_info_window);
				ImGui::Text(("Object Name: " + ObjDic[selected_obj].name).c_str());
				Vector3 V_pos = position_hook(selected_obj);
				Vector3 V_rot = rotation_hook(selected_obj);
				Vector3 V_scale = scale_hook(selected_obj);
				float position[] = { V_pos.x, V_pos.y, V_pos.z };
				float rotation[] = { V_rot.x, V_rot.y, V_rot.z };
				float scale[] = { V_scale.x, V_scale.y, V_scale.z };
				ImGui::InputFloat3("Position", position, "%.5f", ImGuiInputTextFlags_ReadOnly);
				ImGui::InputFloat3("Rotation", rotation, "%.5f", ImGuiInputTextFlags_ReadOnly);
				ImGui::InputFloat3("Scale", scale, "%.5f", ImGuiInputTextFlags_ReadOnly);
				show_components(selected_obj);
				ImGui::End();
			}
			else {
				show_info_window = false;
				refreashObject();
			}
		}


		// Rendering
		ImGui::Render();
		const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
		g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
		g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		g_pSwapChain->Present(1, 0); // Present with vsync
		//g_pSwapChain->Present(0, 0); // Present without vsync
	}

	// Cleanup
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupDeviceD3D();
	::DestroyWindow(hwnd);
	::UnregisterClass(wc.lpszClassName, wc.hInstance);

	return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
	// Setup swap chain
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
		return false;

	CreateRenderTarget();
	return true;
}

void CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
	pBackBuffer->Release();
}

void CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			CleanupRenderTarget();
			g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateRenderTarget();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

//关于如何召唤出win32API
/*
//************************************************************************************************************

//尝试创建窗口
#define IDC_BUTTON_CLICK 150

void OnButtonClick() {
	//::MessageBox(NULL, L"恭喜！你成功获得了Transform数据...大概", L"Happy Uma Day!", MB_OK);


	void* Transform_type = type_hook((umastring*)il2cpp_symbols::get_string("UnityEngine.Transform, UnityEngine"));
	printf("Transform type address is : %p\n", Transform_type);
	void* Object_list = object_hook(Transform_type, 1);
	printf("ObjectList address is : %p\n", Object_list);
	int ObjLength = il2cpp_symbols::get_array_length(Object_list);
	printf("ObjectList length is : %d\n", il2cpp_symbols::get_array_length(Object_list));

	for (int i = 0; i < ObjLength; i++) {
		void* Obj = arrayindex_hook(Object_list, i);
		string ObjName = UmaGetString(objectname_hook(Obj));

		printf("Object name is : %s\n", ObjName.c_str());
		void* ObjParent = parent_hook(Obj);
		if (ObjParent) {
			string ObjParentName = UmaGetString(objectname_hook(ObjParent));

		}
		else {

		}
	}

}

LRESULT CALLBACK __WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_CREATE:
		CreateWindow(L"button",
			L"点我",
			WS_CHILD | WS_VISIBLE,
			200, 200, 50, 30,
			hwnd, (HMENU)IDC_BUTTON_CLICK,
			((LPCREATESTRUCT)lParam)->hInstance, NULL
		);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		if (wParam == IDC_BUTTON_CLICK) {
			OnButtonClick();
		}
		break;
	default:
		DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 1;
}


int usewindow() {

	HINSTANCE hIns = GetModuleHandle(0);
	::WNDCLASSEXW winClass;
	winClass.lpszClassName = L"Raster";
	winClass.cbSize = sizeof(::WNDCLASSEX);
	winClass.style = CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = __WndProc;
	winClass.hInstance = hIns;
	winClass.hIcon = 0;
	winClass.hIconSm = 0;
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)(BLACK_BRUSH);
	winClass.lpszMenuName = NULL;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;

	const wchar_t* wndName = L"UmaExplorer V0.01";

	RegisterClassEx(&winClass);


	HWND hWnd = CreateWindowEx(
		NULL,
		L"Raster",
		wndName,
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		0,
		0,
		480,
		320,
		0,
		0,
		hIns,
		0
	);

	UpdateWindow(hWnd);
	ShowWindow(hWnd, SW_SHOW);


	MSG msg = { 0 };
	while (true)
	{
		if (msg.message == WM_DESTROY
			|| msg.message == WM_CLOSE
			|| msg.message == WM_QUIT)
		{
			break;
		}

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage((&msg));
		}
	}

	return 0;
}

//
*/





void attach()
{
	create_debug_console();

	if (MH_Initialize() != MH_OK)
	{
		printf("Failed to initialize MinHook.\n");
		return;
	}
	printf("MinHook initialized.\n");

	MH_CreateHook(LoadLibraryW, load_library_w_hook, &load_library_w_orig);
	MH_EnableHook(LoadLibraryW);

	std::thread(edb::init).detach();
}

void detach()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}
