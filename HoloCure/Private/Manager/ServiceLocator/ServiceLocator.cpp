#include "pch.h"
#include "Manager/ServiceLocator/ServiceLocator.h"

ServiceLocator& ServiceLocator::getInstance()
{
    static ServiceLocator instance;
    return instance;
}

