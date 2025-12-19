#pragma once

#ifdef _DEBUG

#include "./VisualLeakDetector/vld.h"
#include "./VisualLeakDetector/vld_def.h"

#endif



#include <stdint.h>
#include <SDKDDKVer.h>
// #define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <typeindex>

#include <memory>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <array>
#include <queue>
#include <stack>

#include <type_traits>
#include <future>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <utility>

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;
#include "Global/GlobalVariables.h"
#include "Global/GlobalFunction.h"

#include "Level/ILevel.h"
#include "Manager/IManager.h"
#include "GameObject/IGameObject.h"
#include "Component/IComponent.h"

// Manager
#include "Manager/ServiceLocator/ServiceLocator.h"

#include "Manager/ThreadManager/ManagerThread.h"
#include "Manager/InputManager/ManagerInput.h"
#include "Manager/TimeManager/ManagerTime.h"
#include "Manager/LevelManager/ManagerLevel.h"
#include "Manager/ObjectManager/ManagerObject.h"
#include "Manager/RenderManager/ManagerRender.h"
#include "Manager/ImageManager/ManagerImage.h"
#include "Manager/ThreadManager/ManagerThread.h"
#include "Manager/GameManager/ManagerGame.h"

// Componenet
#include "Component/Sprite/ComponentSprite.h"
#include "Component/Sprite/ComponentBmp.h"





