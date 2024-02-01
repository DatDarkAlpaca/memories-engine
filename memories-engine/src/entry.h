#pragma once
#include "core/memory/memory.h"
#include "core/Engine/memories_engine.h"

extern mem::mem_unique<mem::MemoriesEngine> CreateApplication();

int main(int argc, char** argv)
{
	using namespace mem;

	mem_unique<MemoriesEngine> engine = CreateApplication();
	engine->run();
}